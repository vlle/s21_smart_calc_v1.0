#include <gtk/gtk.h>
#include "../smartcalc.h"

static void 
calculat (GtkWidget* widget, gpointer data)
{
  (void) widget;
  (void) data;
  g_print("Hello A\n");
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  (void)user_data;
  GtkWidget *window;
  GtkWidget *entry_text, *label_text;
  GtkWidget *text_box_H, *text_box_V, *text_box_Hor;
  GtkWidget *grid;
  GtkWidget *button_calc, *button_q;

  window = gtk_application_window_new (app);
  entry_text = gtk_entry_new();
  label_text = gtk_label_new("Enter your infix string: ");
  text_box_V = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  text_box_H = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
  text_box_Hor = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  grid = gtk_grid_new ();
  button_calc = gtk_button_new_with_label ("=");
  button_q = gtk_button_new_with_label ("Quit");
  g_signal_connect (button_calc, "clicked", G_CALLBACK(calculat), NULL); 
  g_signal_connect_swapped (button_q, "clicked", G_CALLBACK(gtk_window_destroy), GTK_WINDOW(window)); 
  gtk_grid_attach (GTK_GRID (grid), button_calc, 1, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), button_q, 0, 1, 2, 1);
  gtk_box_set_homogeneous(GTK_BOX(text_box_H), FALSE);
  // gtk_widget_set_valign(text_box_V, GTK_ALIGN_CENTER);
  // gtk_widget_set_valign(text_box_H, GTK_ALIGN_CENTER);
  // gtk_widget_set_valign(text_box_Hor, GTK_ALIGN_CENTER);
  gtk_widget_set_halign(text_box_V, GTK_ALIGN_CENTER);
  gtk_widget_set_halign(text_box_H, GTK_ALIGN_CENTER);
  gtk_widget_set_halign(text_box_Hor, GTK_ALIGN_CENTER);
  gtk_box_prepend(GTK_BOX(text_box_V), GTK_WIDGET(label_text));
  gtk_box_prepend(GTK_BOX(text_box_H), GTK_WIDGET(entry_text));
  gtk_box_prepend(GTK_BOX(text_box_Hor), GTK_WIDGET(text_box_H));
  gtk_box_prepend(GTK_BOX(text_box_Hor), GTK_WIDGET(grid));
  gtk_box_prepend(GTK_BOX(text_box_Hor), GTK_WIDGET(text_box_V));
  gtk_window_set_child(GTK_WINDOW (window), text_box_Hor);
  gtk_window_set_title (GTK_WINDOW (window), "Smartcalc Artemii");
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);
  gtk_widget_show (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
