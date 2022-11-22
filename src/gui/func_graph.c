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
  cairo_select_font_face(cr, "monospace", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);

  /* Determine GtkDrawingArea dimensions */
  gdk_window_get_geometry(window, &da.x, &da.y, &da.width, &da.height);

  /* Draw on a black background */
  cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
  cairo_paint(cr);

  /* Change the transformation matrix */
  long double f1, f2, f3, f4;
  f1 = 2;
  f2 = 2;
  f3 = 4;
  f4 = 4;
  cairo_translate(cr, da.width / f1, da.height / f2);
  cairo_scale(cr, ZOOM_X, -ZOOM_Y);

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

  double iterator_x = (fabs(f1)+fabs(f2))+10;
  double iterator_y = (fabs(f3)+fabs(f4))+10;
  // cairo_set_source_rgb(cr, 2.0, 1.0, 0.0);
  // cairo_set_source_rgba(cr, 255.0, 204, 0.0, 0.8);
  cairo_set_source_rgba(cr, 82.0, 56, 112.0, 0.3);
  for (i = -da.width; i < da.width; i += 1) {
    if (fabs(i-1) > 1) {
      cairo_move_to(cr, i, -da.height / 2);
      cairo_line_to(cr, i, +da.height / 2);
      cairo_move_to(cr, -i, -da.height / 2);
      cairo_line_to(cr, -i, +da.height / 2);
    }
  }
  cairo_set_source_rgba(cr, 82.0, 56, 112.0, 0.3);
  cairo_stroke(cr);
  for (i = -da.height; i < da.height; i += 1) {
    if (fabs(i-1) > 1) {
      cairo_move_to(cr, -da.width / 2, i) ;
      cairo_line_to(cr, +da.width / 2,i) ;
      cairo_move_to(cr,  -da.width / 2,-i);
      cairo_line_to(cr,  +da.width / 2, -i);

    }
  }

  cairo_stroke(cr);

  /* Link each data point */
  const char *fc = gtk_entry_get_text(GTK_ENTRY(user_data));
  for (i = clip_x1; i < clip_x2; i += dx) {
    long double dot = f(i, fc);
    if ((!isnan(dot)) && (!isinf(dot))) {
      cairo_line_to(cr, i, dot);
    }
  }

  /* Draw the curve */
  cairo_set_source_rgba(cr, 3, 0.2, 0.2, 0.6);
  cairo_stroke(cr);

  return FALSE;
}

void draw_create_entry(GtkWidget *button, gpointer data) {
  GtkWidget *dra, *hbox, *windw;
  dra = gtk_drawing_area_new();
  windw = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_window_set_title(GTK_WINDOW(windw), "Function graphic");
  gtk_window_set_position(GTK_WINDOW(windw), GTK_WIN_POS_CENTER);
  gtk_container_set_border_width(GTK_CONTAINER(windw), 10);
  gtk_window_set_default_size(GTK_WINDOW(windw), 670, 450);

  gtk_box_pack_start(GTK_BOX(hbox), dra, TRUE, TRUE, 50);
  gtk_container_add(GTK_CONTAINER(windw), hbox);
  g_signal_connect(G_OBJECT(dra), "draw", G_CALLBACK(on_draw), GTK_ENTRY(data));
  gtk_widget_show_all(windw);
}
