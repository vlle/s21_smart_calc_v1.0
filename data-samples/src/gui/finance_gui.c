#include <gtk/gtk.h>

#include "../smartcalc.h"
#include "gui_header.h"

GtkWidget *lst;

void init_list(GtkWidget *lst) {
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *total, *month, *over;
  GtkListStore *store;

  renderer = gtk_cell_renderer_text_new();
  g_object_set(G_OBJECT(renderer), "foreground", "red", NULL);
  total = gtk_tree_view_column_new_with_attributes("Total Credit", renderer,
                                                   "text", TOTAL_CREDIT, NULL);
  gtk_tree_view_column_set_title(total, "Total Credit");
  gtk_tree_view_append_column(GTK_TREE_VIEW(lst), total);
  month = gtk_tree_view_column_new_with_attributes(
      "Monthly Payment", renderer, "text", MONTHLY_PAYMENT, NULL);
  gtk_tree_view_column_set_title(month, "Monthly Payment");
  gtk_tree_view_append_column(GTK_TREE_VIEW(lst), month);
  over = gtk_tree_view_column_new_with_attributes("Overpayment", renderer,
                                                  "text", OVERPAYMENT, NULL);
  gtk_tree_view_column_set_title(over, "Overpayment");
  gtk_tree_view_append_column(GTK_TREE_VIEW(lst), over);

  store = gtk_list_store_new(N_COLUMNS, G_TYPE_STRING, G_TYPE_STRING,
                             G_TYPE_STRING);

  gtk_tree_view_set_model(GTK_TREE_VIEW(lst), GTK_TREE_MODEL(store));

  g_object_unref(store);
}

void add_to_list(GtkWidget *lst, const gchar *total, const gchar *month,
                 const gchar *over) {
  GtkListStore *store;
  GtkTreeIter iter;

  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(lst)));

  gtk_list_store_append(store, &iter);
  gtk_list_store_set(store, &iter, TOTAL_CREDIT, total, MONTHLY_PAYMENT, month,
                     OVERPAYMENT, over, -1);
}

void on_changed(GtkWidget *widget, gpointer label) {
  GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *value;
  char total_cred[128];
  strcpy(total_cred, "Total credit: ");

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model,
                                      &iter)) {
    gtk_tree_model_get(model, &iter, TOTAL_CREDIT, &value, -1);
    strcat(total_cred, (char *)value);
    gtk_label_set_text(GTK_LABEL(label), (gchar *)total_cred);
    g_free(value);
  }
}

void finances(GtkWidget *button, gpointer data) {
  (void)button;
  if (!data) {
    exit(1);
  }
  char total[256];
  char month[256];
  char over[256];
  char type;

  finance_i *stuff = (finance_i *)data;
  finance_info tmp = {0};
  GtkWidget *total_amount = stuff->total_amount;
  GtkWidget *term = stuff->term;
  GtkWidget *interest_rate = stuff->interest_rate;
  GtkWidget *type_credit = stuff->type_credit;
  GtkListStore *store;

  store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(lst)));
  gtk_list_store_clear(store);
  const char *tt = gtk_editable_get_text (GTK_EDITABLE(total_amount));
  const char *trm = gtk_editable_get_text (GTK_EDITABLE(term));
  const char *intrst = gtk_editable_get_text (GTK_EDITABLE(interest_rate));
  if (gtk_check_button_get_active(GTK_CHECK_BUTTON(type_credit))) {
    type = 'a';
  } else {
    type = 'b';
  }
  long double a1 = calculate(tt);
  long double b1 = calculate(trm);
  long double c1 = calculate(intrst);
  tmp = put_data(a1, b1, c1, type, 1);
  tmp = credit_calculate(tmp);
  sprintf(total, "%.2Lf", tmp.total_payment);
  sprintf(month, "%.2Lf", tmp.monthly_payment);
  sprintf(over, "%.2Lf", tmp.overpayment);
  add_to_list(lst, total, month, over);
  int cnt = 0;
  if (type == 'a') {
    while (tmp.total_payment > 0) {
      tmp.total_payment -= tmp.monthly_payment;
      sprintf(total, "%.2Lf", tmp.total_payment);
      sprintf(month, "%.2Lf", tmp.monthly_payment);
      sprintf(over, "%.2Lf", tmp.overpayment);
      if (tmp.total_payment == 0) break;
      add_to_list(lst, total, month, over);
    }
  } else if (type == 'b') {
    while (tmp.total_credit_amount > 0) {
      cnt += 1;
      tmp = credit_calculate(tmp);
      sprintf(total, "%.2Lf", tmp.total_payment);
      sprintf(month, "%.2Lf", tmp.monthly_payment);
      sprintf(over, "%.2Lf", tmp.overpayment);
      if (tmp.total_payment <= 0) break;
      add_to_list(lst, total, month, over);
      if (cnt > tmp.term * 2) break;
    }
  }
}

void closeWin(GtkWidget *button, gpointer data) {
  (void)button;
  finance_i *check = (finance_i *)data;
  GtkWidget *destroy_window = check->window;
  free(check);
  gtk_window_destroy(GTK_WINDOW(destroy_window));
}

void cb_create_entry() {
  GtkEntryBuffer *def1, *def2, *def3;
  GtkWidget *windw, *labl;
  GtkWidget *total_amount_label, *term_label, *interest_rate_label;
  GtkWidget *hbox_t, *hbox_term, *hbox_intr;
  GtkWidget *vbox_e, *vbox_radio, *vbox_upper;
  GtkWidget *fineq, *scroll, *q_butn;
  GtkWidget *total_amount, *term, *interest_rate;

  GtkTreeSelection *selecton;
  finance_i *data = malloc(sizeof(finance_i) * 1);
  scroll = gtk_scrolled_window_new();
  gtk_widget_set_hexpand(scroll, TRUE);
  gtk_widget_set_vexpand(scroll, TRUE);

  windw = gtk_window_new();
  data->window = windw;
  lst = gtk_tree_view_new();
  gtk_window_set_title(GTK_WINDOW(windw), "Finance Calculation");
  gtk_window_set_default_size(GTK_WINDOW(windw), 670, 450);

  gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(lst), TRUE);
  def1 = gtk_entry_buffer_new("100000", 6);
  def2 = gtk_entry_buffer_new("24", 2);
  def3 = gtk_entry_buffer_new("51", 2);
  total_amount = gtk_entry_new_with_buffer(def1);
  term = gtk_entry_new_with_buffer(def2);
  interest_rate = gtk_entry_new_with_buffer(def3);
  fineq = gtk_button_new_with_label("Calculate");
  q_butn = gtk_button_new_with_label("Quit");
  gtk_entry_set_visibility(GTK_ENTRY(total_amount), TRUE);
  gtk_entry_set_visibility(GTK_ENTRY(term), TRUE);
  gtk_entry_set_visibility(GTK_ENTRY(interest_rate), TRUE);
  vbox_e = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  vbox_upper = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  hbox_t = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  hbox_term = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  hbox_intr = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  vbox_radio = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
  gtk_box_set_homogeneous(GTK_BOX(vbox_radio), TRUE);

  total_amount_label = gtk_label_new("Total money amount");
  term_label = gtk_label_new("Term");
  interest_rate_label = gtk_label_new("Interest rate");
  data->total_amount = total_amount;
  data->term = term;
  data->interest_rate = interest_rate;
  data->type_credit = gtk_check_button_new_with_label("Annuity type");
  data->type_credit2 = gtk_check_button_new_with_label("Differentiated type");
  gtk_check_button_set_group(GTK_CHECK_BUTTON(data->type_credit), GTK_CHECK_BUTTON(data->type_credit2));
  gtk_box_append(GTK_BOX(hbox_t), total_amount);
  gtk_box_append(GTK_BOX(hbox_t), total_amount_label);
  gtk_box_append(GTK_BOX(hbox_term), term);
  gtk_box_append(GTK_BOX(hbox_term), term_label);
  gtk_box_append(GTK_BOX(hbox_intr), interest_rate);
  gtk_box_append(GTK_BOX(hbox_intr), interest_rate_label);

  gtk_box_append(GTK_BOX(scroll), lst);
  gtk_box_append(GTK_BOX(hbox_intr), data->type_credit);
  gtk_box_append(GTK_BOX(hbox_intr), data->type_credit2);

  gtk_box_append(GTK_BOX(vbox_upper), hbox_t);
  gtk_box_append(GTK_BOX(vbox_upper), hbox_term);
  gtk_box_append(GTK_BOX(vbox_upper), hbox_intr);

  labl = gtk_label_new("");
  gtk_box_append(GTK_BOX(vbox_e), vbox_upper);
  gtk_box_append(GTK_BOX(vbox_e), fineq);
  gtk_box_append(GTK_BOX(vbox_e), scroll);
  gtk_box_prepend(GTK_BOX(vbox_e), q_butn);
  gtk_box_append(GTK_BOX(vbox_e), labl);

  gtk_box_append(GTK_BOX(windw), vbox_e);

  init_list(lst);

  selecton = gtk_tree_view_get_selection(GTK_TREE_VIEW(lst));

  g_signal_connect(selecton, "changed", G_CALLBACK(on_changed), labl);
  g_signal_connect(fineq, "clicked", G_CALLBACK(finances), data);
  g_signal_connect(G_OBJECT(q_butn), "clicked", G_CALLBACK(closeWin), data);
  gtk_widget_show(windw);
}