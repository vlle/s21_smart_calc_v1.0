#include <gtk/gtk.h>
#include "../smartcalc.h"
#include "gui_header.h"

GtkWidget *da;
GtkWidget *graph_entry;


gfloat f (gfloat x, const char * parser) {
  char funcstr[MAX_ENTRY_SIZE] = {'\0'};
  char *newstr;
  char rs[MAX_ENTRY_SIZE * 4] = {'\0'};
  snprintf(rs, sizeof(rs), "%.2f", x);
  newstr = str_replace((char*) parser, "x", rs);
  char *prs = parse_oper(funcstr, newstr);
  double my_res = cal_oper(prs);
  free(newstr);
  return my_res;
}


static gboolean
on_draw (GtkWidget *widget, cairo_t *cr, gpointer user_data) {
  GdkRectangle da;            /* GtkDrawingArea size */
  gdouble dx = 5.0, dy = 5.0; /* Pixels between each point */
  gdouble i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
  GdkWindow *window = gtk_widget_get_window(widget);

  /* Determine GtkDrawingArea dimensions */
  gdk_window_get_geometry (window,
                           &da.x,
                           &da.y,
                           &da.width,
                           &da.height);

  /* Draw on a black background */
  cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
  cairo_paint (cr);

  /* Change the transformation matrix */
  cairo_translate (cr, da.width / 2, da.height / 2);
  cairo_scale (cr, ZOOM_X, -ZOOM_Y);

  /* Determine the data points to calculate (ie. those in the clipping zone */
  cairo_device_to_user_distance (cr, &dx, &dy);
  cairo_clip_extents (cr, &clip_x1, &clip_y1, &clip_x2, &clip_y2);
  cairo_set_line_width (cr, dx);

  /* Draws x and y axis */
  cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
  cairo_move_to (cr, clip_x1, 0.0);
  cairo_line_to (cr, clip_x2, 0.0);
  cairo_move_to (cr, 0.0, clip_y1);
  cairo_line_to (cr, 0.0, clip_y2);
  cairo_stroke (cr);

  /* Link each data point */
  const char *fc = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)user_data));
  for (i = clip_x1; i < clip_x2; i += dx)
    cairo_line_to (cr, i, f (i, fc));

  /* Draw the curve */
  cairo_set_source_rgba (cr, 3, 0.2, 0.2, 0.6);
  cairo_stroke (cr);

  return FALSE;
}

void startdraw(GtkWidget *window, gpointer data) {
  g_signal_connect (G_OBJECT (da), "draw", G_CALLBACK (on_draw), graph_entry);
}

