#include <gtk/gtk.h>
#include "../smartcalc.h"
#include "gui.h"

static void 
calculat (GtkWidget* widget, gpointer data)
{
  (void) widget;
  calc* input = (calc*) data;
  const char *val = gtk_editable_get_text(GTK_EDITABLE(input->entry_text));
  char res[128] = {0};
  long double v = 0;
  calculate(val, &v);
  sprintf(res, "%Lf", v);
  gtk_label_set_label(GTK_LABEL(input->label_empty), res);
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  (void)user_data;
  GtkWidget *window;
  GtkWidget *label_text;
  GtkWidget *text_box_H, *text_box_V, *text_box_Hor, *text_box_Hor2, *text_box_Vert;
  calc *calc_data = malloc(sizeof(*calc_data));
  GtkWidget *grid, *grid_numb;
  GtkWidget *button_calc, *button_q;
  GtkWidget *n1_button, *n2_button, *n3_button, *n4_button;
  GtkWidget *n5_button, *n6_button, *n7_button, *n8_button;
  GtkWidget *n9_button, *n0_button;

  window = gtk_application_window_new (app);
  calc_data->entry_text = gtk_entry_new();
  label_text = gtk_label_new("Enter your infix string: ");
  calc_data->label_empty = gtk_label_new("");
  text_box_V = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  text_box_H = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  text_box_Hor2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 30);
  text_box_Hor = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 30);
  text_box_Vert = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  grid = gtk_grid_new ();
  grid_numb = gtk_grid_new ();
  button_calc = gtk_button_new_with_label ("=");
  n1_button = gtk_button_new_with_label ("1");
  n2_button = gtk_button_new_with_label ("2");
  n3_button = gtk_button_new_with_label ("3");
  n4_button = gtk_button_new_with_label ("4");
  n5_button = gtk_button_new_with_label ("5");
  n6_button = gtk_button_new_with_label ("6");
  n7_button = gtk_button_new_with_label ("7");
  n8_button = gtk_button_new_with_label ("8");
  n9_button = gtk_button_new_with_label ("9");
  n0_button = gtk_button_new_with_label ("0");
  button_q = gtk_button_new_with_label ("Quit");
  g_signal_connect (button_calc, "clicked", G_CALLBACK(calculat), calc_data); 
  g_signal_connect_swapped (button_q, "clicked", G_CALLBACK(gtk_window_destroy), GTK_WINDOW(window)); 
  gtk_grid_attach (GTK_GRID (grid), button_calc, 1, 1, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), button_q, 2, 1, 1, 1);

  gtk_grid_attach (GTK_GRID (grid_numb), n1_button, 1, 3, 1, 1);
  gtk_grid_attach (GTK_GRID (grid_numb), n2_button, 2, 3, 1, 1);
  gtk_grid_attach (GTK_GRID (grid_numb), n3_button, 3, 3, 1, 1);

  gtk_grid_attach (GTK_GRID (grid_numb), n4_button, 1, 2, 1, 1);
  gtk_grid_attach (GTK_GRID (grid_numb), n5_button, 2, 2, 1, 1);
  gtk_grid_attach (GTK_GRID (grid_numb), n6_button, 3, 2, 1, 1);

  gtk_grid_attach (GTK_GRID (grid_numb), n7_button, 1, 1, 1, 1);
  gtk_grid_attach (GTK_GRID (grid_numb), n8_button, 2, 1, 1, 1);
  gtk_grid_attach (GTK_GRID (grid_numb), n9_button, 3, 1, 1, 1);

  gtk_grid_attach (GTK_GRID (grid_numb), n0_button, 1, 4, 2, 1);
  gtk_box_set_homogeneous(GTK_BOX(text_box_H), FALSE);
  gtk_widget_set_halign(label_text, GTK_ALIGN_CENTER);
  // gtk_widget_set_valign(text_box_V, GTK_ALIGN_CENTER);
  //
  // gtk_widget_set_valign(text_box_H, GTK_ALIGN_CENTER);
  // gtk_widget_set_valign(text_box_Hor, GTK_ALIGN_CENTER);
  gtk_widget_set_halign(text_box_V, GTK_ALIGN_END);
  gtk_widget_set_halign(text_box_H, GTK_ALIGN_CENTER);
  gtk_widget_set_halign(text_box_Hor, GTK_ALIGN_CENTER);
  gtk_widget_set_hexpand(label_text, TRUE);
  gtk_box_prepend(GTK_BOX(text_box_V), GTK_WIDGET(calc_data->label_empty));
  gtk_box_prepend(GTK_BOX(text_box_V), GTK_WIDGET(label_text));
  gtk_box_prepend(GTK_BOX(text_box_H), GTK_WIDGET(calc_data->entry_text));
  gtk_box_prepend(GTK_BOX(text_box_Hor2), GTK_WIDGET(grid));
  gtk_box_prepend(GTK_BOX(text_box_Hor), GTK_WIDGET(text_box_Hor2));
  gtk_box_prepend(GTK_BOX(text_box_Hor), GTK_WIDGET(text_box_H));
  gtk_box_prepend(GTK_BOX(text_box_Hor), GTK_WIDGET(text_box_V));
  gtk_box_prepend(GTK_BOX(text_box_Vert), GTK_WIDGET(grid_numb));
  gtk_box_prepend(GTK_BOX(text_box_Vert), GTK_WIDGET(text_box_Hor));
  gtk_window_set_child(GTK_WINDOW (window), text_box_Vert);
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

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
