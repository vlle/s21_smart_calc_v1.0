#include <gtk/gtk.h>

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  (void)user_data;
  GtkWidget *window;
  GtkWidget *entry_text;
  GtkWidget *text_box_H;

  window = gtk_application_window_new (app);
  entry_text = gtk_entry_new();
  text_box_H = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  gtk_box_prepend(GTK_BOX(text_box_H), GTK_WIDGET(entry_text));
  gtk_window_set_child(GTK_WINDOW (window), text_box_H);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
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
