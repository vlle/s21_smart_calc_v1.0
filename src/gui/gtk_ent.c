#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smartcalc.h"
#include "gui_header.h"

#define WIDTH 640
#define HEIGHT 480

GtkWidget *result_label, *calc_label, *result;
GtkWidget *infix_entry;

void closeApp() { gtk_main_quit(); }

void calc() {
  char rs[128 * 4] = {0};
  const char *infix_string = gtk_entry_get_text(GTK_ENTRY(infix_entry));
  long double result_num = calculate(infix_string);
  sprintf(rs, "%Lf", result_num);
  gtk_label_set_text(GTK_LABEL(result), rs);
}

void smartcalc() {
  GtkWidget *window;
  GtkWidget *ok_button, *draw_button;
  GtkWidget *hbox1, *hbox2, *hbox3;
  GtkWidget *vbox;
  GtkWidget *list;

  GtkWidget *q_button;
  GtkWidget *f_button;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Artemii's Calculator");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 470, 250);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(closeApp), NULL);

  result_label = gtk_label_new("Result: ");
  result = gtk_label_new("?");
  calc_label = gtk_label_new("Calculate: ");

  gtk_label_set_width_chars(GTK_LABEL(result_label), 12);
  gtk_label_set_width_chars(GTK_LABEL(calc_label), 12);

  infix_entry = gtk_entry_new();
  gtk_entry_set_visibility(GTK_ENTRY(infix_entry), TRUE);

  ok_button = gtk_button_new_with_label("=");
  draw_button = gtk_button_new_with_label("Draw");
  g_signal_connect(G_OBJECT(ok_button), "clicked", G_CALLBACK(calc),
                   infix_entry);
  list = gtk_tree_view_new();
  gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), FALSE);
  hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  hbox3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

  gtk_box_pack_start(GTK_BOX(hbox1), result_label, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox1), result, FALSE, FALSE, 5);

  gtk_box_pack_start(GTK_BOX(hbox2), calc_label, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox2), infix_entry, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox2), ok_button, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox2), draw_button, FALSE, FALSE, 5);

  gtk_box_pack_start(GTK_BOX(vbox), hbox2, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), hbox1, FALSE, FALSE, 5);

  gtk_box_pack_start(GTK_BOX(vbox), hbox3, FALSE, FALSE, 5);
  q_button = gtk_button_new_with_label("Quit   ");
  f_button = gtk_button_new_with_label("Finance");
  gtk_container_set_border_width(GTK_CONTAINER(q_button), 10);
  gtk_box_pack_start(GTK_BOX(vbox), f_button, FALSE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(vbox), q_button, FALSE, FALSE, 10);

  /* Событие, которое отрабатывает на нажатие кнопки */
  g_signal_connect(GTK_BUTTON(q_button), "clicked", G_CALLBACK(closeApp), NULL);
  g_signal_connect(GTK_BUTTON(f_button), "clicked", G_CALLBACK(cb_create_entry),
                   NULL);
  g_signal_connect(G_OBJECT(draw_button), "clicked",
                   G_CALLBACK(draw_create_entry), GTK_ENTRY(infix_entry));

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

  gtk_main();
}

int main(int argc, char *argv[]) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(smartcalc), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
