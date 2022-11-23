#include <gtk/gtk.h>
#include <math.h>

#include "../smartcalc.h"
#include "gui_header.h"

#define ZOOM_X 100.0
#define ZOOM_Y 100.0

gfloat f(gfloat x, const char *parser) {
  char *newstr;
  char rs[MAX_ENTRY_SIZE * 4] = {'\0'};
  snprintf(rs, sizeof(rs), "%.2f", x);
  newstr = str_replace((char *)parser, "x", rs);
  double my_res = calculate(newstr);
  free(newstr);
  return my_res;
}

gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  if (!user_data) {
    return FALSE;
  }
  GdkRectangle da;            /* GtkDrawingArea size */
  gdouble dx = 5.0, dy = 5.0; /* Pixels between each point */
  gdouble i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
  GdkWindow *window = gtk_widget_get_window(widget);
  cairo_select_font_face(cr, "monospace", CAIRO_FONT_SLANT_NORMAL,
                         CAIRO_FONT_WEIGHT_NORMAL);

  /* Determine GtkDrawingArea dimensions */
  gdk_window_get_geometry(window, &da.x, &da.y, &da.width, &da.height);

  /* Draw on a black background */
  cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
  cairo_paint(cr);

  codomains *user = (codomains *)user_data;
  GtkEntry *codomain1 = (GtkEntry *)user->codomain1;
  GtkEntry *codomain2 = (GtkEntry *)user->codomain2;
  GtkEntry *codomain3 = (GtkEntry *)user->codomain3;
  GtkEntry *codomain4 = (GtkEntry *)user->codomain4;
  GtkEntry *data = (GtkEntry *)user->data;
  /* Change the transformation matrix */
  const char *x1_c = gtk_entry_get_text(GTK_ENTRY(codomain1));
  const char *x2_c = gtk_entry_get_text(GTK_ENTRY(codomain2));
  const char *y1_c = gtk_entry_get_text(GTK_ENTRY(codomain3));
  const char *y2_c = gtk_entry_get_text(GTK_ENTRY(codomain4));
  long double f1, f2, f3, f4;
  f1 = fabs(calculate(x1_c));
  f2 = fabs(calculate(x2_c));
  f3 = fabs(calculate(y1_c));
  f4 = fabs(calculate(y2_c));
  cairo_translate(cr, da.width / f1, da.height / f2);
  cairo_scale(cr, ZOOM_X / f3, ZOOM_Y / f4);

  /* Determine the data points to calculate (ie. those in the clipping zone */
  cairo_device_to_user_distance(cr, &dx, &dy);
  cairo_clip_extents(cr, &clip_x1, &clip_y1, &clip_x2, &clip_y2);
  cairo_set_line_width(cr, dx);

  /* Draws x and y axis */
  cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
  cairo_move_to(cr, clip_x1, 0.0);
  cairo_line_to(cr, clip_x2, 0.0);
  cairo_move_to(cr, 0.0, clip_y1);
  cairo_line_to(cr, 0.0, clip_y2);
  cairo_stroke(cr);

  char legend[33];
  cairo_set_source_rgba(cr, 82.0, 56, 112.0, 0.3);
  cairo_set_font_size(cr, 0.3);
  for (i = -da.width; i < da.width; i += 1) {
    if (fabs(i - 1) > 1) {
      cairo_move_to(cr, i, -da.height / f2);
      cairo_line_to(cr, i, +da.height / f2);
      cairo_move_to(cr, -i, -da.height / f2);
      cairo_line_to(cr, -i, +da.height / f2);
      cairo_move_to(cr, i, 0);
      sprintf(legend, "%g", i);
      cairo_show_text(cr, legend);
      cairo_move_to(cr, -i, 0);
      sprintf(legend, "%g", -i);
      cairo_show_text(cr, legend);
    }
  }
  cairo_set_source_rgba(cr, 82.0, 56, 112.0, 0.3);
  cairo_stroke(cr);
  for (i = -da.height; i < da.height; i += 1) {
    if (fabs(i - 1) > 1) {
      cairo_move_to(cr, -da.width / f1, i);
      cairo_line_to(cr, +da.width / f1, i);
      cairo_move_to(cr, -da.width / f1, -i);
      cairo_line_to(cr, +da.width / f1, -i);
      cairo_move_to(cr, 0, -i);
      sprintf(legend, "%g", i);
      cairo_show_text(cr, legend);
      cairo_move_to(cr, 0, i);
      sprintf(legend, "%g", -i);
      cairo_show_text(cr, legend);
    }
  }
  cairo_move_to(cr, 0.7, 0.3);
  cairo_show_text(cr, "x");

  cairo_move_to(cr, 0.3, -0.7);
  cairo_show_text(cr, "y");

  cairo_stroke(cr);

  /* Link each data point */
  const char *fc = gtk_entry_get_text(GTK_ENTRY(data));
  for (i = clip_x1; i < clip_x2; i += dx) {
    long double dot = f(i, fc);
    if ((isnan(dot)) || (isinf(dot))) {
      cairo_new_sub_path(cr);
    } else {
      cairo_line_to(cr, i, -dot);
    }
  }

  /* Draw the curve */
  cairo_set_source_rgba(cr, 3, 0.2, 0.2, 0.6);
  cairo_stroke(cr);

  return FALSE;
}

GtkWidget *dra;

void comeon(GtkWidget *window, gpointer user_data) {
  g_signal_connect(G_OBJECT(dra), "draw", G_CALLBACK(on_draw), user_data);
}
void closeFunc(GtkWidget *window, gpointer data) {
  codomains *check = (codomains *)data;
  GtkWidget *destroy_window = check->window;
  free(check);
  gtk_widget_destroy(destroy_window);
}

void draw_create_entry(GtkWidget *button, gpointer data) {
  GtkWidget *hbox, *hbox_entrys, *windw;
  GtkEntryBuffer *def1, *def2, *def3, *def4;
  GtkWidget *label_codomain1, *label_codomain2, *label_codomain3,
      *label_codomain4;
  GtkWidget *butn, *q_butn, *codomain1, *codomain2, *codomain3, *codomain4;
  codomains *forms = malloc(sizeof(codomains) * 1);
  dra = gtk_drawing_area_new();
  windw = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  forms->window = windw;
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  hbox_entrys = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  def1 = gtk_entry_buffer_new("2", 1);
  def2 = gtk_entry_buffer_new("2", 1);
  def3 = gtk_entry_buffer_new("1", 1);
  def4 = gtk_entry_buffer_new("1", 1);
  codomain1 = gtk_entry_new_with_buffer(def1);
  codomain2 = gtk_entry_new_with_buffer(def2);
  codomain3 = gtk_entry_new_with_buffer(def3);
  codomain4 = gtk_entry_new_with_buffer(def4);
  forms->data = (GtkEntry *)data;
  forms->codomain1 = codomain1;
  forms->codomain2 = codomain2;
  forms->codomain3 = codomain3;
  forms->codomain4 = codomain4;
  label_codomain1 = gtk_label_new("X");
  label_codomain2 = gtk_label_new("Y");
  label_codomain3 = gtk_label_new("X");
  label_codomain4 = gtk_label_new("Y");
  butn = gtk_button_new_with_label("Redraw");
  q_butn = gtk_button_new_with_label("Quit");
  gtk_window_set_title(GTK_WINDOW(windw), "Function graphic");
  gtk_window_set_position(GTK_WINDOW(windw), GTK_WIN_POS_CENTER);
  gtk_container_set_border_width(GTK_CONTAINER(windw), 10);
  gtk_window_set_default_size(GTK_WINDOW(windw), 870, 350);

  gtk_box_pack_start(GTK_BOX(hbox_entrys), forms->codomain1, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox_entrys), label_codomain1, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox_entrys), forms->codomain2, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox_entrys), label_codomain2, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox_entrys), forms->codomain3, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox_entrys), label_codomain3, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox_entrys), forms->codomain4, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox_entrys), label_codomain4, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox_entrys), butn, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox_entrys), q_butn, FALSE, FALSE, 3);
  gtk_box_pack_start(GTK_BOX(hbox), dra, TRUE, TRUE, 50);
  gtk_box_pack_start(GTK_BOX(hbox), hbox_entrys, TRUE, TRUE, 2);
  gtk_container_add(GTK_CONTAINER(windw), hbox);
  g_signal_connect(G_OBJECT(dra), "draw", G_CALLBACK(on_draw), forms);
  g_signal_connect(G_OBJECT(butn), "clicked", G_CALLBACK(comeon), forms);
  g_signal_connect(G_OBJECT(q_butn), "clicked", G_CALLBACK(closeFunc), forms);
  gtk_widget_show_all(windw);
}
