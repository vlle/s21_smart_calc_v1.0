#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>

#include "../smartcalc.h"
#include "gui.h"

static void
setup_cb (GtkListItemFactory *factory, GtkListItem *listitem, gpointer user_data) {
  (void) factory;
  (void) user_data;
  GtkWidget *lb = gtk_label_new (NULL);
  gtk_list_item_set_child (listitem, lb);
}

static void
bind_cb (GtkSignalListItemFactory *self, GtkListItem *listitem, gpointer user_data) {
  (void) self;
  (void) user_data;
  GtkWidget *lb = gtk_list_item_get_child (listitem);
  GtkStringObject *strobj = gtk_list_item_get_item (listitem);
  const char *text = gtk_string_object_get_string (strobj);

  gtk_label_set_text (GTK_LABEL (lb), text);
}

static void
unbind_cb (GtkSignalListItemFactory *self, GtkListItem *listitem, gpointer user_data) {
  (void) self;
  (void) listitem;
  (void) user_data;
  /* There's nothing to do here. */
  /* If you does something like setting a signal in bind_cb, */
  /* then disconnecting the signal is necessary in unbind_cb. */
}

static void
teardown_cb (GtkListItemFactory *factory, GtkListItem *listitem, gpointer user_data) {
  (void) factory;
  (void) user_data;
  gtk_list_item_set_child (listitem, NULL);
/*  When the child of listitem is set to NULL, the reference to GtkLabel will be released and lb will be destroyed. */
/* Therefore, g_object_unref () for the GtkLabel object doesn't need in the user code. */
}

void closeWin(GtkWidget *button, gpointer data) {
  (void)button;
  finance_i *check = (finance_i *)data;
  GtkWidget *destroy_window = check->window;
  free(check);
  gtk_window_destroy(GTK_WINDOW(destroy_window));
}

void cb_create() {

  GtkWidget *hbox_l;
  GtkWidget *hbox_l2;
  GtkWidget *hbox_l3;
  GtkWidget *hbox_l4;
  GtkWidget *box_l;
  GtkWidget *fineq;
  GtkWidget *q_butn;

  char *array[] = {
    "one", "two", "three", "four",
    "one", "two", "three", "four",
    "one", "two", "three", "four",
    "one", "two", "three", "four", NULL
  };
  GtkStringList *sl = gtk_string_list_new ((const char * const *) array);
  GtkSingleSelection *ns = gtk_single_selection_new (G_LIST_MODEL (sl));

  GtkWidget *total_amount_label, *term_label, *interest_rate_label;

  finance_i* calc_data = malloc(sizeof(*calc_data));
  calc_data->s_window = gtk_scrolled_window_new();
  calc_data->window = gtk_window_new();
  gtk_window_set_default_size (GTK_WINDOW (calc_data->window), 600, 400);
  calc_data->total_amount = gtk_entry_new();
  calc_data->term = gtk_entry_new();
  calc_data->interest_rate = gtk_entry_new();
  calc_data->type_credit = gtk_check_button_new_with_label("Annuity type");
  calc_data->type_credit2 = gtk_check_button_new_with_label("Differentiated type");
  gtk_check_button_set_group(GTK_CHECK_BUTTON(calc_data->type_credit), GTK_CHECK_BUTTON(calc_data->type_credit2));

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

  // gtk_widget_set_halign(hbox_l, GTK_ALIGN_START);
  gtk_widget_set_valign(hbox_l, GTK_ALIGN_START);
  // gtk_widget_set_halign(hbox_l2, GTK_ALIGN_START);
  gtk_widget_set_valign(hbox_l2, GTK_ALIGN_START);
  // gtk_widget_set_halign(hbox_l3, GTK_ALIGN_START);
  gtk_widget_set_valign(hbox_l3, GTK_ALIGN_START);
  gtk_widget_set_valign(hbox_l4, GTK_ALIGN_CENTER);
  // gtk_widget_set_vexpand(grid_numb, TRUE);
  // gtk_widget_set_hexpand(grid_numb, TRUE);

  gtk_box_prepend(GTK_BOX(box_l), calc_data->s_window);
  gtk_box_prepend(GTK_BOX(box_l), hbox_l4);
  gtk_box_prepend(GTK_BOX(box_l), hbox_l3);
  gtk_box_prepend(GTK_BOX(box_l), hbox_l2);
  gtk_box_prepend(GTK_BOX(box_l), hbox_l);

  // g_signal_connect(fineq, "clicked", G_CALLBACK(finances), calc_data);
  GtkListItemFactory *factory = gtk_signal_list_item_factory_new ();
  g_signal_connect (factory, "setup", G_CALLBACK (setup_cb), NULL);
  g_signal_connect (factory, "bind", G_CALLBACK (bind_cb), NULL);
  g_signal_connect (factory, "unbind", G_CALLBACK (unbind_cb), NULL);
  g_signal_connect (factory, "teardown", G_CALLBACK (teardown_cb), NULL);

  GtkWidget *lv = gtk_list_view_new (GTK_SELECTION_MODEL (ns), factory);
  gtk_scrolled_window_set_child (GTK_SCROLLED_WINDOW (calc_data->s_window), lv);
  g_signal_connect(G_OBJECT(q_butn), "clicked", G_CALLBACK(closeWin), calc_data);

  gtk_window_set_child(GTK_WINDOW(calc_data->window), box_l);
  gtk_widget_show(calc_data->window);
}


