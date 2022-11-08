#include <gtk/gtk.h>
#include "../smartcalc.h"
#include <stdio.h>

static int count = 0;

void button_clicked(GtkWidget *button, gpointer data)
{
    printf("%s pressed %d time(s) \n", (char *)data, ++count);
}

void butt2(GtkWidget *button, gpointer data)
{
    printf("%d\n",  1);
}

void butt3(GtkWidget *button, gpointer data)
{
    printf("%d\n",  2);
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *b1, *b2, *b3;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    b1 = gtk_button_new_with_label("1");
    b2 = gtk_button_new_with_label("2");
    gtk_container_add(GTK_CONTAINER(window), b1);

    g_signal_connect(G_OBJECT(b1), "clicked", G_CALLBACK(butt2), "Button 1");
    g_signal_connect(G_OBJECT(b2), "clicked", G_CALLBACK(butt3), "Button 2");

    gtk_widget_show(b1);
    gtk_widget_show(b2);
    gtk_widget_show(window);

    gtk_main();

    return 0;
}
