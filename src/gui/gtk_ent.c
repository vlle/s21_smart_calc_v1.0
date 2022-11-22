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

// #define ZOOM_X  100.0
// #define ZOOM_Y  100.0

GtkWidget *window;
GtkWidget *result_label, *calc_label, *result;
GtkWidget *password_entry, *graph_entry;
GtkWidget *ok_button, *draw_button;
GtkWidget *hbox1, *hbox2, *hbox3, *hbox4, *hbox5;
GtkWidget *vbox;
GtkWidget *list;
GtkWidget *label;
GtkTreeSelection *selection;

GtkWidget *graph_enter;
GtkWidget *dra;

void closeApp() { gtk_main_quit(); }

// void startdraw(int argc, char**argv) {
//   g_signal_connect(G_OBJECT(dra), "draw", G_CALLBACK(fin_create_entry(argc, argv)),
//                    graph_entry);  //, graph_enter);
// }

void calc() {
  char rs[128*4] = {0};
  const char *infix_string = gtk_entry_get_text(GTK_ENTRY(password_entry));
  long double result_num = calculate(infix_string);
  sprintf(rs, "%.2Lf", result_num);
  gtk_label_set_text(GTK_LABEL(result), rs);
}

void smartcalc() {
  GtkWidget *q_button;
  GtkWidget *f_button;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Artemii's Calculator");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 770, 650);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(closeApp), NULL);

  result_label = gtk_label_new("Result: ");
  result = gtk_label_new("?");
  calc_label = gtk_label_new("Calculate: ");

  gtk_label_set_width_chars(GTK_LABEL(result_label), 0);
  gtk_label_set_width_chars(GTK_LABEL(calc_label), 12);

  password_entry = gtk_entry_new();
  graph_entry = gtk_entry_new();
  gtk_entry_set_visibility(GTK_ENTRY(password_entry), TRUE);
  gtk_entry_set_visibility(GTK_ENTRY(graph_entry), TRUE);

  ok_button = gtk_button_new_with_label("=");
  draw_button = gtk_button_new_with_label("Draw");
  g_signal_connect(G_OBJECT(ok_button), "clicked", G_CALLBACK(calc),
                   password_entry);
  list = gtk_tree_view_new();
  gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), FALSE);
  hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  hbox3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  hbox4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

  gtk_box_pack_start(GTK_BOX(hbox1), result_label, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox1), result, FALSE, FALSE, 5);

  gtk_box_pack_start(GTK_BOX(hbox2), calc_label, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox2), password_entry, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox2), ok_button, FALSE, FALSE, 5);

  gtk_box_pack_start(GTK_BOX(vbox), hbox2, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), hbox1, FALSE, FALSE, 5);
  // gtk_box_pack_start(GTK_BOX(vbox), ok_button, FALSE, FALSE, 5);

  dra = gtk_drawing_area_new();
  gtk_box_pack_start(GTK_BOX(hbox3), draw_button, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(hbox3), graph_entry, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(hbox4), dra, TRUE, TRUE, 50);
  gtk_box_pack_start(GTK_BOX(vbox), hbox3, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), hbox4, TRUE, TRUE, 5);
  q_button = gtk_button_new_with_label("Quit   ");
  f_button = gtk_button_new_with_label("Finance");
  gtk_container_set_border_width(GTK_CONTAINER(q_button), 10);
  gtk_box_pack_start(GTK_BOX(vbox), f_button, FALSE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(vbox), q_button, FALSE, FALSE, 10);

  /* Событие, которое отрабатывает на нажатие кнопки */
  g_signal_connect(GTK_BUTTON(q_button), "clicked", G_CALLBACK(closeApp), NULL);
  g_signal_connect(GTK_BUTTON(f_button), "clicked", G_CALLBACK(cb_create_entry),
                   NULL);
  g_signal_connect(G_OBJECT(draw_button), "clicked", G_CALLBACK(draw_create_entry),
                   GTK_ENTRY(graph_entry));

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

  gtk_main();
}

int main(int argc, char *argv[]) {
  GtkApplication *app;
  int status;
  
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (smartcalc), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);


  return status;
}
