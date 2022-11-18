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

GtkWidget *da;
void closeApp(GtkWidget *window, gpointer data) { gtk_main_quit(); }

void calc(GtkWidget *button, gpointer data) {
  char funcstr[MAX_ENTRY_SIZE * 4] = {'\0'};
  char rs[MAX_ENTRY_SIZE * 4] = {'\0'};
  const char *fc = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));
  char *prs = parse_oper(funcstr, fc);
  long double resul = cal_oper(prs);
  sprintf(rs, "%.2Lf", resul);
  debug(prs, resul);
  gtk_label_set_text(GTK_LABEL(result), rs);
}

// gfloat f (gfloat x, const char * parser)//, char* parser)
// {
//   // printf("%s IS AA\n",fc);
//   char funcstr[MAX_ENTRY_SIZE] = {'\0'};
//   char *newstr;
//   char rs[MAX_ENTRY_SIZE * 4] = {'\0'};
//   snprintf(rs, sizeof(rs), "%.2f", x);
//   newstr = str_replace((char*) parser, "x", rs);
//   char *prs = parse_oper(funcstr, newstr);
//   double my_res = cal_oper(prs);
//   free(newstr);
//   return my_res;
// }
//
//
// static gboolean
// on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data)
// {
//   GdkRectangle da;            /* GtkDrawingArea size */
//   gdouble dx = 5.0, dy = 5.0; /* Pixels between each point */
//   gdouble i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
//   GdkWindow *window = gtk_widget_get_window(widget);
//
//   /* Determine GtkDrawingArea dimensions */
//   gdk_window_get_geometry (window,
//                            &da.x,
//                            &da.y,
//                            &da.width,
//                            &da.height);
//
//   /* Draw on a black background */
//   cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
//   cairo_paint (cr);
//
//   /* Change the transformation matrix */
//   cairo_translate (cr, da.width / 2, da.height / 2);
//   cairo_scale (cr, ZOOM_X, -ZOOM_Y);
//
//   /* Determine the data points to calculate (ie. those in the clipping zone
//   */ cairo_device_to_user_distance (cr, &dx, &dy); cairo_clip_extents (cr,
//   &clip_x1, &clip_y1, &clip_x2, &clip_y2); cairo_set_line_width (cr, dx);
//
//   /* Draws x and y axis */
//   cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
//   cairo_move_to (cr, clip_x1, 0.0);
//   cairo_line_to (cr, clip_x2, 0.0);
//   cairo_move_to (cr, 0.0, clip_y1);
//   cairo_line_to (cr, 0.0, clip_y2);
//   cairo_stroke (cr);
//
//   /* Link each data point */
//   const char *fc = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)user_data));
//   for (i = clip_x1; i < clip_x2; i += dx)
//     cairo_line_to (cr, i, f (i, fc));
//
//   /* Draw the curve */
//   cairo_set_source_rgba (cr, 3, 0.2, 0.2, 0.6);
//   cairo_stroke (cr);
//
//   return FALSE;
// }
//
// void startdraw(GtkWidget *window, gpointer data) {
//   g_signal_connect (G_OBJECT (da), "draw", G_CALLBACK (on_draw),
//   graph_entry);
// }

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *q_button;
  GtkWidget *f_button;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Artemii's Calculator");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 800);
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

  da = gtk_drawing_area_new();
  gtk_box_pack_start(GTK_BOX(hbox3), draw_button, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(hbox3), graph_entry, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(hbox4), da, TRUE, TRUE, 50);
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
  g_signal_connect(G_OBJECT(draw_button), "clicked", G_CALLBACK(startdraw),
                   password_entry);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
