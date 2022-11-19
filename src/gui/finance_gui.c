#include <gtk/gtk.h>

#include "../smartcalc.h"

GtkWidget *lst;
GtkWidget *windw;
GtkWidget *labl;
GtkTreeSelection *selecton;

void debug(char *prs, double my_res) {
  g_print("%f\n", my_res);
  g_print("%s\n", prs);
}

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

  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model,
                                      &iter)) {
    gtk_tree_model_get(model, &iter, TOTAL_CREDIT, &value, -1);
    gtk_label_set_text(GTK_LABEL(label), value);
    g_free(value);
  }
}

void cb_create_entry(int argc, char *argv[]) {
  char total[1024];
  char month[1024];
  char over[1024];
  gtk_init(&argc, &argv);
  windw = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  lst = gtk_tree_view_new();
  gtk_window_set_title(GTK_WINDOW(windw), "List view");
  gtk_window_set_position(GTK_WINDOW(windw), GTK_WIN_POS_CENTER);
  gtk_container_set_border_width(GTK_CONTAINER(windw), 10);
  gtk_window_set_default_size(GTK_WINDOW(windw), 670, 450);

  gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(lst), TRUE);
  GtkWidget *total_amount, *term, *interest_rate;
  GtkWidget *total_amount_label, *term_label, *interest_rate_label;
  GtkWidget *vbox, *vbox_t, *vbox_term, *vbox_intr;
  GtkWidget *vbox_e;

  total_amount = gtk_entry_new();
  term = gtk_entry_new();
  interest_rate = gtk_entry_new();
  const char *tt = gtk_entry_get_text(GTK_ENTRY(total_amount));
  const char *trm = gtk_entry_get_text(GTK_ENTRY(term));
  const char *intrst = gtk_entry_get_text(GTK_ENTRY(interest_rate));
  gtk_entry_set_visibility(GTK_ENTRY(total_amount), TRUE);
  gtk_entry_set_visibility(GTK_ENTRY(term), TRUE);
  gtk_entry_set_visibility(GTK_ENTRY(interest_rate), TRUE);
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  vbox_e = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  vbox_t = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  vbox_term = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  vbox_intr = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

  total_amount_label = gtk_label_new("Total money amount");
  term_label = gtk_label_new("Term");
  interest_rate_label = gtk_label_new("Interest rate");
  gtk_box_pack_start(GTK_BOX(vbox_t), total_amount, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox_t), total_amount_label, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox_term), term, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox_term), term_label, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox_intr), interest_rate, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox_intr), interest_rate_label, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), lst, TRUE, TRUE, 5);

  labl = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(vbox_e), vbox_t, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox_e), vbox_term, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox_e), vbox_intr, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox_e), vbox, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox_e), labl, FALSE, FALSE, 5);

  gtk_container_add(GTK_CONTAINER(windw), vbox_e);
  // gtk_container_add(GTK_CONTAINER(window), hbox);

  init_list(lst);

  selecton = gtk_tree_view_get_selection(GTK_TREE_VIEW(lst));

  g_signal_connect(selecton, "changed", G_CALLBACK(on_changed), labl);
  finance_info tmp = {0};
  tmp = credit_calculate(100000, 24, 0.15, 'a');
  sprintf(total, "%.2Lf", tmp.total_payment);
  sprintf(month, "%.2Lf", tmp.monthly_payment);
  sprintf(over, "%.2Lf", tmp.overpayment);
  add_to_list(lst, total, month, over);
  g_print("%s", total);
  // g_signal_connect(G_OBJECT (window), "destroy",
  //     G_CALLBACK(), NULL);

  gtk_widget_show_all(windw);
}