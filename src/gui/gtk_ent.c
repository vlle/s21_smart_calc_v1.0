#include <gtk/gtk.h>
#include "../smartcalc.h"
#include <stdio.h>
#include <string.h>

GtkWidget *window;
GtkWidget *username_label, *password_label, *result;
GtkWidget *username_entry, *password_entry;
GtkWidget *ok_button;
GtkWidget *hbox1, *hbox2;
GtkWidget *vbox;


void calc(GtkWidget *button, gpointer data) {
  char funcstr[40] = {0};
  char *fc = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));
  char *prs = parse_oper(funcstr, fc);
  g_print("%s\n", prs);
  double my_res = cal_oper(prs);
  g_print("%f\n", my_res);
  char rs[100];
  sprintf(rs, "%.2f", my_res);
  gtk_label_set_text(GTK_LABEL (result), rs);
}

const char *password = "secret";

void closeApp(GtkWidget *window, gpointer data)
{
  gtk_main_quit();
}

void button_clicked(GtkWidget *button, gpointer data)
{
  const char *password_text = gtk_entry_get_text(GTK_ENTRY((GtkWidget *)data));

  if (strcmp(password_text, password) == 0)
    printf("Access granted!\n");
  else
    printf("Access denied!\n");
}

int main(int argc, char *argv[])
{

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Artemii's Calculator");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(closeApp), NULL);

  username_label = gtk_label_new("Result: ");
  result = gtk_label_new("?");
  password_label = gtk_label_new("Calculate: ");

  gtk_label_set_width_chars(GTK_LABEL(username_label), 12);
  gtk_label_set_width_chars(GTK_LABEL(password_label), 12);

  username_entry = gtk_entry_new();
  password_entry = gtk_entry_new();
  gtk_entry_set_visibility(GTK_ENTRY(password_entry), TRUE);

  ok_button = gtk_button_new_with_label("OK");

  g_signal_connect(G_OBJECT(ok_button), "clicked", G_CALLBACK(calc), password_entry);
  // g_signal_connect_swapped(G_OBJECT(ok_button), "clicked", G_CALLBACK(gtk_label_set_text(GTK_LABEL (username_label), "")), "Button is pressed!\n");

  hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

  gtk_box_pack_start(GTK_BOX(hbox1), username_label, TRUE, FALSE, 5);

  gtk_box_pack_start(GTK_BOX(hbox2), password_label, TRUE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox2), password_entry, TRUE, FALSE, 5);

  gtk_box_pack_start(GTK_BOX(vbox), hbox2, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), hbox1, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), result, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), ok_button, FALSE, FALSE, 5);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}