#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>

#include "../smartcalc.h"

void cb_create() {
  GtkWidget* window;
  window = gtk_window_new();
  gtk_widget_show(window);
}
