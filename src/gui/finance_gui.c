#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>

#include "../smartcalc.h"
#include "gui.h"

static
void closeWin(GtkWidget *button, gpointer data) {
  (void)button;
  finance_i *check = (finance_i *)data;
  GtkWidget *destroy_window = check->window;
  free(check);
  gtk_window_destroy(GTK_WINDOW(destroy_window));
}

static
void addNum(GtkWidget *button, gpointer data) {
  finance_i *calc_data = (finance_i*) data;
  while (gtk_string_list_get_string(calc_data->sl, 0)) {
    gtk_string_list_remove(calc_data->sl, 0);
  }
  const char *val = gtk_editable_get_text(GTK_EDITABLE(calc_data->term));
  gtk_string_list_append(calc_data->sl, val); 
}

static void
setup_cb (GtkListItemFactory *factory, GtkListItem *listitem, gpointer user_data) {
  GtkWidget *lb = gtk_label_new (NULL);
  gtk_list_item_set_child (listitem, lb);
}

static void
bind_cb (GtkSignalListItemFactory *self, GtkListItem *listitem, gpointer user_data) {
  int *data = (int*) user_data;
  GtkWidget *lb = gtk_list_item_get_child (listitem);
  GtkStringObject *strobj = gtk_list_item_get_item (listitem);
  const char *text = gtk_string_object_get_string (strobj);
  if (*data==1) {
    char example[128] = "1";
    strcat(example, text);
    gtk_label_set_text (GTK_LABEL (lb), example);
  } else if (*data==2) {
    char example[128] = "2";
    strcat(example, text);
    gtk_label_set_text (GTK_LABEL (lb), example);
  } else if (*data==3) {
    char example[128] = "3";
    strcat(example, text);
    gtk_label_set_text (GTK_LABEL (lb), example);
  } else {
    char example[128] = "4";
    strcat(example, text);
    gtk_label_set_text (GTK_LABEL (lb), example);
  }
}

static void
unbind_cb (GtkSignalListItemFactory *self, GtkListItem *listitem, gpointer user_data) {
}

static void
teardown_cb (GtkListItemFactory *factory, GtkListItem *listitem, gpointer user_data) {
  gtk_list_item_set_child (listitem, NULL);
}

static
void factory_build(GtkListItemFactory *factory, int* type) {
  g_signal_connect (factory, "setup", G_CALLBACK (setup_cb), type);
  g_signal_connect (factory, "bind", G_CALLBACK (bind_cb), type);
  g_signal_connect (factory, "unbind", G_CALLBACK (unbind_cb), type);
  g_signal_connect (factory, "teardown", G_CALLBACK (teardown_cb), type);
}


void cb_create() {
  GtkWidget *hbox_l;
  GtkWidget *hbox_l2;
  GtkWidget *hbox_l3;
  GtkWidget *hbox_l4;
  GtkWidget *box_l;
  GtkWidget *fineq;
  GtkWidget *q_butn;

  GtkWidget *total_amount_label, *term_label, *interest_rate_label;
  GtkListItemFactory *sums = gtk_signal_list_item_factory_new ();

  GtkListItemFactory *signf= gtk_signal_list_item_factory_new ();
  GtkListItemFactory *paypercent = gtk_signal_list_item_factory_new();
  GtkListItemFactory *debt_remain = gtk_signal_list_item_factory_new();

  finance_i *calc_data = malloc(sizeof(calc_data));
  calc_data->s_window = gtk_scrolled_window_new();

  calc_data->window = gtk_window_new();
  calc_data->total_amount = gtk_entry_new();
  calc_data->term = gtk_entry_new();
  calc_data->interest_rate = gtk_entry_new();
  calc_data->type_credit = gtk_check_button_new_with_label("Annuity type");
  calc_data->type_credit2 =
    gtk_check_button_new_with_label("Differentiated type");
  gtk_check_button_set_group(GTK_CHECK_BUTTON(calc_data->type_credit),
      GTK_CHECK_BUTTON(calc_data->type_credit2));

  temp_t* temp = malloc(sizeof(temp)*1);
  (temp->types1) = malloc(sizeof(temp->types1)*1);
  (temp->types2) = malloc(sizeof(temp->types2)*1);
  (temp->types3) = malloc(sizeof(temp->types3)*1);
  (temp->types4) = malloc(sizeof(temp->types4)*1);
  *(temp->types1) = 1;
  *(temp->types2) = 2;
  *(temp->types3) = 3;
  *(temp->types4) = 4;
  factory_build(sums,temp->types1);
  factory_build(signf,temp->types2);
  factory_build(paypercent,temp->types3);
  factory_build(debt_remain,temp->types4);
  fineq = gtk_button_new_with_label("Calculate");
  q_butn = gtk_button_new_with_label("Quit");

  total_amount_label = gtk_label_new("Total money amount");
  term_label = gtk_label_new("Term");
  interest_rate_label = gtk_label_new("Interest rate");

  hbox_l = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  hbox_l2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  hbox_l3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  hbox_l4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  box_l = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

  gtk_box_prepend(GTK_BOX(hbox_l), GTK_WIDGET(total_amount_label));
  gtk_box_prepend(GTK_BOX(hbox_l), GTK_WIDGET(calc_data->total_amount));
  gtk_box_prepend(GTK_BOX(hbox_l2), GTK_WIDGET(term_label));
  gtk_box_prepend(GTK_BOX(hbox_l2), GTK_WIDGET(calc_data->term));
  gtk_box_prepend(GTK_BOX(hbox_l3), GTK_WIDGET(interest_rate_label));
  gtk_box_prepend(GTK_BOX(hbox_l3), GTK_WIDGET(calc_data->type_credit));
  gtk_box_prepend(GTK_BOX(hbox_l3), GTK_WIDGET(calc_data->type_credit2));
  gtk_box_prepend(GTK_BOX(hbox_l3), GTK_WIDGET(calc_data->interest_rate));
  gtk_box_prepend(GTK_BOX(hbox_l4), GTK_WIDGET(fineq));
  gtk_box_prepend(GTK_BOX(hbox_l4), GTK_WIDGET(q_butn));

  gtk_widget_set_valign(hbox_l, GTK_ALIGN_START);
  gtk_widget_set_valign(hbox_l2, GTK_ALIGN_START);
  gtk_widget_set_valign(hbox_l3, GTK_ALIGN_START);
  gtk_widget_set_valign(hbox_l4, GTK_ALIGN_CENTER);
  char *array[] = {"21", "21", "21", "21", NULL};
  calc_data->sl = gtk_string_list_new ((const char * const *) array);
  GtkNoSelection *ns = gtk_no_selection_new (G_LIST_MODEL (calc_data->sl));


  GtkWidget *lv = gtk_column_view_new (GTK_SELECTION_MODEL (ns));//, factory);
  GtkColumnViewColumn* sumpay = gtk_column_view_column_new("Сумма платежа", sums);
  GtkColumnViewColumn* paysignf = gtk_column_view_column_new("Платеж по осн. долгу", signf);
  GtkColumnViewColumn* payperc = gtk_column_view_column_new("Платеж по процентам", paypercent);
  GtkColumnViewColumn* debt_remainder = gtk_column_view_column_new("Остаток долга", debt_remain);
  gtk_column_view_append_column(GTK_COLUMN_VIEW(lv), sumpay);
  gtk_column_view_append_column(GTK_COLUMN_VIEW(lv), paysignf);
  gtk_column_view_append_column(GTK_COLUMN_VIEW(lv), payperc);
  gtk_column_view_append_column(GTK_COLUMN_VIEW(lv), debt_remainder);

  gtk_box_prepend(GTK_BOX(box_l), GTK_WIDGET(lv));
  gtk_box_prepend(GTK_BOX(box_l), hbox_l4);
  gtk_box_prepend(GTK_BOX(box_l), hbox_l3);
  gtk_box_prepend(GTK_BOX(box_l), hbox_l2);
  gtk_box_prepend(GTK_BOX(box_l), hbox_l);


  g_signal_connect(fineq, "clicked", G_CALLBACK(addNum), calc_data);
  g_signal_connect(G_OBJECT(q_butn), "clicked", G_CALLBACK(closeWin),
      calc_data);

  gtk_window_set_child(GTK_WINDOW(calc_data->window), box_l);
  gtk_widget_show(calc_data->window);
}
