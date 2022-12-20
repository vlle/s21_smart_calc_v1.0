#include <gtk/gtk.h>

int main(int argc, char **argv) {
  gtk_init();

  GtkWidget *area = gtk_drawing_area_new();
  gtk_drawing_area_set_content_width(GTK_DRAWING_AREA(area), 100);
  gtk_drawing_area_set_content_height(GTK_DRAWING_AREA(area), 100);
  gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(area), draw_function, NULL,
                                 NULL);
  return 0;
}
