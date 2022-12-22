#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>

#include "../smartcalc.h"
#include "gui.h"

#define STACK 64

void closeWin(GtkWidget *button, gpointer data) {
  (void)button;
  finance_i *check = (finance_i *)data;
  GtkWidget *destroy_window = check->window;
  free(check->types1);
  free(check->types2);
  free(check->types3);
  free(check->types4);
  free(check);
  gtk_window_close(GTK_WINDOW(destroy_window));
}

static void addNum(GtkWidget *button, gpointer data) {
  finance_i *calc_data = (finance_i *)data;
  finance_t tmp = {0};
  const char *tt = gtk_editable_get_text(GTK_EDITABLE(calc_data->total_amount));
  const char *trm = gtk_editable_get_text(GTK_EDITABLE(calc_data->term));
  const char *intrst =
      gtk_editable_get_text(GTK_EDITABLE(calc_data->interest_rate));
  char type = 'a';
  if (gtk_check_button_get_active(GTK_CHECK_BUTTON(calc_data->type_credit2))) {
    type = 'b';
  }
  long double a1 = 0;
  long double b1 = 0;
  long double c1 = 0;
  calculate(tt, &a1);
  calculate(trm, &b1);
  calculate(intrst, &c1);

  tmp = put_data(a1, b1, c1, type, 1);
  while (gtk_string_list_get_string(calc_data->sl, 0)) {
    gtk_string_list_remove(calc_data->sl, 0);
  }
  if (type == 'a') {
    while (tmp.remainder_credit > -100) {
      char total[STACK] = {0};
      char month[STACK] = {0};
      char over[STACK] = {0};
      char rem[STACK] = {0};
      char res[STACK * 4] = {0};
      tmp = credit_calculate(tmp);
      snprintf(total, 20, "%.2Lf", tmp.monthly_payment);
      snprintf(month, 20, "%.2Lf", tmp.monthly_payment - tmp.overpayment);
      snprintf(over, 20, "%.2Lf", tmp.overpayment);
      snprintf(rem, 20, "%.2Lf", tmp.remainder_credit);
      strcat(res, total);
      strcat(res, "_");
      strcat(res, month);
      strcat(res, ":");
      strcat(res, over);
      strcat(res, "|");
      strcat(res, rem);
      gtk_string_list_append(calc_data->sl, res);
    }
  } else if (type == 'b') {
    while (tmp.remainder_credit > 0) {
      char total[STACK] = {0};
      char month[STACK] = {0};
      char over[STACK] = {0};
      char rem[STACK] = {0};
      char res[STACK * 4] = {0};
      tmp = credit_calculate(tmp);
      snprintf(total, 20, "%.2Lf", tmp.monthly_payment);
      snprintf(month, 20, "%.2Lf", tmp.diff_payment_part);
      snprintf(over, 20, "%.2Lf", tmp.percent_sum);
      snprintf(rem, 20, "%.2Lf", tmp.remainder_credit);
      strcat(res, total);
      strcat(res, "_");
      strcat(res, month);
      strcat(res, ":");
      strcat(res, over);
      strcat(res, "|");
      strcat(res, rem);
      if (tmp.total_payment <= 0) break;
      gtk_string_list_append(calc_data->sl, res);
    }
  }
}

static void setup_cb(GtkListItemFactory *factory, GtkListItem *listitem,
                     gpointer user_data) {
  GtkWidget *lb = gtk_label_new(NULL);
  gtk_list_item_set_child(listitem, lb);
}

static void bind_cb(GtkSignalListItemFactory *self, GtkListItem *listitem,
                    gpointer user_data) {
  int *data = (int *)user_data;
  GtkWidget *lb = gtk_list_item_get_child(listitem);
  GtkStringObject *strobj = gtk_list_item_get_item(listitem);
  const char *text = gtk_string_object_get_string(strobj);
  char *total = calloc(STACK, sizeof(*total));
  char *month = calloc(STACK, sizeof(*total));
  char *over = calloc(STACK, sizeof(*total));
  char *rem = calloc(STACK, sizeof(*total));
  for (int i = 0; *text != '\0' && *text != '_'; text++, i++) {
    total[i] = *text;
  }
  if (*text != '\0') text++;
  for (int i = 0; *text != '\0' && *text != ':'; text++, i++) {
    month[i] = *text;
  }
  if (*text != '\0') text++;
  for (int i = 0; *text != '\0' && *text != '|'; text++, i++) {
    over[i] = *text;
  }
  if (*text != '\0') text++;
  for (int i = 0; *text != '\0'; text++, i++) {
    rem[i] = *text;
  }
  if (*data == 1) {
    gtk_label_set_text(GTK_LABEL(lb), total);
  } else if (*data == 2) {
    gtk_label_set_text(GTK_LABEL(lb), month);
  } else if (*data == 3) {
    gtk_label_set_text(GTK_LABEL(lb), over);
  } else {
    gtk_label_set_text(GTK_LABEL(lb), rem);
  }
  free(total);
  free(month);
  free(over);
  free(rem);
}

static void unbind_cb(GtkSignalListItemFactory *self, GtkListItem *listitem,
                      gpointer user_data) {}

static void teardown_cb(GtkListItemFactory *factory, GtkListItem *listitem,
                        gpointer user_data) {
  gtk_list_item_set_child(listitem, NULL);
}

static void factory_build(GtkListItemFactory *factory, int *type) {
  g_signal_connect(factory, "setup", G_CALLBACK(setup_cb), type);
  g_signal_connect(factory, "bind", G_CALLBACK(bind_cb), type);
  g_signal_connect(factory, "unbind", G_CALLBACK(unbind_cb), type);
  g_signal_connect(factory, "teardown", G_CALLBACK(teardown_cb), type);
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
  GtkListItemFactory *sums = gtk_signal_list_item_factory_new();

  GtkListItemFactory *signf = gtk_signal_list_item_factory_new();
  GtkListItemFactory *paypercent = gtk_signal_list_item_factory_new();
  GtkListItemFactory *debt_remain = gtk_signal_list_item_factory_new();

  finance_i *calc_data = calloc(1, sizeof(*calc_data));
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

  (calc_data->types1) = calloc(1, sizeof(int));
  (calc_data->types2) = calloc(1, sizeof(int));
  (calc_data->types3) = calloc(1, sizeof(int));
  (calc_data->types4) = calloc(1, sizeof(int));
  *(calc_data->types1) = 1;
  *(calc_data->types2) = 2;
  *(calc_data->types3) = 3;
  *(calc_data->types4) = 4;

  GtkEntryBuffer *total_b = gtk_entry_buffer_new(NULL, -1);
  GtkEntryBuffer *term_b = gtk_entry_buffer_new(NULL, -1);
  GtkEntryBuffer *interest_b = gtk_entry_buffer_new(NULL, -1);

  gtk_check_button_set_active(GTK_CHECK_BUTTON(calc_data->type_credit2), true);
  gtk_entry_set_buffer(GTK_ENTRY(calc_data->total_amount),
                       GTK_ENTRY_BUFFER(total_b));
  gtk_entry_set_buffer(GTK_ENTRY(calc_data->term), GTK_ENTRY_BUFFER(term_b));
  gtk_entry_set_buffer(GTK_ENTRY(calc_data->interest_rate),
                       GTK_ENTRY_BUFFER(interest_b));

  gtk_entry_buffer_insert_text(GTK_ENTRY_BUFFER(total_b), 0, "100000", 7);

  gtk_entry_buffer_insert_text(GTK_ENTRY_BUFFER(term_b), 0, "12", 3);

  gtk_entry_buffer_insert_text(GTK_ENTRY_BUFFER(interest_b), 0, "5", 2);

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
  char *array[] = {"0", "0", "0", "0", NULL};
  calc_data->sl = gtk_string_list_new((const char *const *)array);
  GtkNoSelection *ns = gtk_no_selection_new(G_LIST_MODEL(calc_data->sl));

  factory_build(sums, calc_data->types1);
  factory_build(signf, calc_data->types2);
  factory_build(paypercent, calc_data->types3);
  factory_build(debt_remain, calc_data->types4);

  GtkWidget *lv = gtk_column_view_new(GTK_SELECTION_MODEL(ns));  //, factory);
  GtkColumnViewColumn *sumpay =
      gtk_column_view_column_new("Сумма платежа", sums);
  GtkColumnViewColumn *paysignf =
      gtk_column_view_column_new("Платеж по осн. долгу", signf);
  GtkColumnViewColumn *payperc =
      gtk_column_view_column_new("Платеж по процентам", paypercent);
  GtkColumnViewColumn *debt_remainder =
      gtk_column_view_column_new("Остаток долга", debt_remain);
  gtk_column_view_append_column(GTK_COLUMN_VIEW(lv), sumpay);
  gtk_column_view_append_column(GTK_COLUMN_VIEW(lv), paysignf);
  gtk_column_view_append_column(GTK_COLUMN_VIEW(lv), payperc);
  gtk_column_view_append_column(GTK_COLUMN_VIEW(lv), debt_remainder);

  gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(calc_data->s_window),
                                GTK_WIDGET(lv));
  gtk_scrolled_window_set_min_content_height(
      GTK_SCROLLED_WINDOW(calc_data->s_window), 250);
  gtk_scrolled_window_set_min_content_width(
      GTK_SCROLLED_WINDOW(calc_data->s_window), 240);
  gtk_window_set_default_size(GTK_WINDOW(calc_data->window), 500, 300);
  gtk_box_prepend(GTK_BOX(box_l), calc_data->s_window);
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
