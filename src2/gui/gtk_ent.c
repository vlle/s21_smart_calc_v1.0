#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>

#include "../smartcalc.h"
#include "gui.h"

#define ZOOM_X 100
#define ZOOM_Y 100


char *calculat(GtkWidget *widget, gpointer data) {
  (void)widget;
  calc *input = (calc *)data;
  const char *val = gtk_editable_get_text(GTK_EDITABLE(input->entry_text));
  char *res = calloc(sizeof(*res), 64);
  long double v = 0;
  calculate(val, &v);
  if (v == (int) v) {
    snprintf(res, 64, "%0.Lf", v);
  } else {
    snprintf(res, 64, "%Lf", v);
  }
  return res;
}

void insert_text(GtkWidget *widget, gpointer data) {
  (void)widget;
  calc *input = (calc *)data;
  g_print("%s\n", gtk_button_get_label(GTK_BUTTON(widget)));
  int f = gtk_entry_buffer_get_length(GTK_ENTRY_BUFFER(input->buff));
  g_print("%d", f);
  const char *text = gtk_button_get_label(GTK_BUTTON(widget));
  const char *status = gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(input->buff));
  int len = 1;
  int pos = f + 1;
  char *enter = calloc(sizeof(*enter), 255);
  strcpy(enter, text);
  if (strcmp(enter, "AC") == 0) {
    gtk_entry_buffer_delete_text(GTK_ENTRY_BUFFER(input->buff), 0, -1);
    free(enter);
    return;
  } else if (strcmp(enter, "=") == 0) {
    char *res = calculat(widget, data);
    gtk_entry_buffer_delete_text(GTK_ENTRY_BUFFER(input->buff), 0, -1);
    gtk_entry_buffer_insert_text(GTK_ENTRY_BUFFER(input->buff), pos, res,
                                 strlen(res));
    free(enter);
    free(res);
    return;
  }

  if (strcmp(enter, "÷") == 0) {
    enter[0] = '/';
  }
  if ((strcmp(enter, "cos") == 0) || (strcmp(enter, "sin") == 0) ||
      (strcmp(enter, "tan") == 0) || (strcmp(enter, "log") == 0) ||
      (strcmp(enter, "sqrt") == 0) || (strcmp(enter, "ln") == 0)) {
    if (strcmp(enter, "sqrt") == 0) len = 6;
    if (strcmp(enter, "ln") == 0) len = 4;
    else len = 5;
    strcat(enter, "()");
  }
  if (strstr(status, "()")) {
    pos = f - 1;
  }

  gtk_entry_buffer_insert_text(GTK_ENTRY_BUFFER(input->buff), pos, enter, len);
  free(enter);
}

void redraw(GtkWidget *widget, gpointer data) {
  (void)widget;
  gtk_widget_queue_draw(GTK_WIDGET(data));
}

void delete(GtkWidget *widget, gpointer data) {
  (void)widget;
  calc* to_del = (calc*) data;
  GtkWidget * win = to_del->window;
  gtk_window_destroy(GTK_WINDOW(win));
  free(to_del);
}
void
draw_function (GtkDrawingArea *area,
               cairo_t        *cr,
               int             width,
               int             height,
               gpointer        data)
{
  (void) data;
  GdkRGBA color;
  GtkStyleContext *context;

  context = gtk_widget_get_style_context (GTK_WIDGET (area));

  cairo_set_line_width(cr, 1.0);

  // zoom below
  int f1 = 3;
  int f2 = 3;
  cairo_scale(cr, f1, f2);
  gtk_style_context_get_color (context,
                               &color);
  gdk_cairo_set_source_rgba (cr, &color);
  int lx = -width/f1;
  int rx = width/f1;
  int dy = -height/f1;
  int uy = height/f1;
  for (double i = lx; i<rx; i+=1) {
    cairo_line_to(cr, i, height/(f1*2));
  }
  cairo_stroke(cr);
  for (double i = dy; i < uy; i+=1) {
    cairo_line_to(cr, width/(f2*2), i);
  }
  cairo_stroke(cr);
  long double val = 0;
  cairo_scale(cr, f1/2, f2/2);
  calc *input = (calc *)data;
  const char *text = gtk_editable_get_text(GTK_EDITABLE(input->entry_text));
  for (double i = lx; i < rx; i+= 0.1) {
    calculate_x(text, i, &val);
    cairo_line_to(cr, i, height/(f1*2)+val);
  }
  cairo_stroke(cr);

  cairo_stroke(cr);

}

void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *area = gtk_drawing_area_new ();
  (void)user_data;
  GtkWidget *finance_button, *draw_button;
  GtkWidget *label_align;
  GtkWidget *text_box_H, *text_box_V, *text_box_Hor, *text_box_Hor2,
  *text_box_Vert, *text_box_Grid, *endgame;
  GtkWidget *grid_numb;
  GtkWidget *button_calc;
  calc *calc_data = malloc(sizeof(*calc_data));
  calc_data->window = gtk_application_window_new(app);
  calc_data->entry_text = gtk_entry_new();
  label_align = gtk_label_new("\n\nEnter your infix string:");
  text_box_V = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  text_box_H = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 30);
  text_box_Hor2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  text_box_Hor = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 30);
  text_box_Vert = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
  endgame = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 30);
  text_box_Grid = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 30);
  grid_numb = gtk_grid_new();
  calc_data->buff = gtk_entry_buffer_new(NULL, -1);
  button_calc = gtk_button_new_with_label("=");
  finance_button = gtk_button_new_with_label("FIN");
  draw_button = gtk_button_new_with_label("DRAW");
  calc_data->n1_button = gtk_button_new_with_label("1");
  calc_data->n2_button = gtk_button_new_with_label("2");
  calc_data->n3_button = gtk_button_new_with_label("3");
  calc_data->n4_button = gtk_button_new_with_label("4");
  calc_data->n5_button = gtk_button_new_with_label("5");
  calc_data->n6_button = gtk_button_new_with_label("6");
  calc_data->n7_button = gtk_button_new_with_label("7");
  calc_data->n8_button = gtk_button_new_with_label("8");
  calc_data->n9_button = gtk_button_new_with_label("9");
  calc_data->n0_button = gtk_button_new_with_label("0");
  calc_data->fl_button = gtk_button_new_with_label(",");
  calc_data->sin_button = gtk_button_new_with_label("sin");
  calc_data->cos_button = gtk_button_new_with_label("cos");
  calc_data->tan_button = gtk_button_new_with_label("tan");
  calc_data->div_button = gtk_button_new_with_label("÷");
  calc_data->plus_button = gtk_button_new_with_label("+");
  calc_data->minus_button = gtk_button_new_with_label("-");
  calc_data->mult_button = gtk_button_new_with_label("*");
  calc_data->clear_button = gtk_button_new_with_label("AC");
  calc_data->sqrt_button = gtk_button_new_with_label("sqrt");
  calc_data->log_button = gtk_button_new_with_label("log");
  calc_data->ln_button = gtk_button_new_with_label("ln");
  calc_data->clear_button = gtk_button_new_with_label("AC");
  calc_data->button_q = gtk_button_new_with_label("Quit");
  gtk_entry_set_buffer(GTK_ENTRY(calc_data->entry_text),
                       GTK_ENTRY_BUFFER(calc_data->buff));
  g_signal_connect(button_calc, "clicked", G_CALLBACK(insert_text), calc_data);
  g_signal_connect(draw_button, "clicked", G_CALLBACK(redraw), area);
  g_signal_connect(calc_data->button_q, "clicked", G_CALLBACK(delete),
                   calc_data);
  gtk_drawing_area_set_content_width (GTK_DRAWING_AREA (area), 300);
  gtk_drawing_area_set_content_height (GTK_DRAWING_AREA (area), 300);
  gtk_drawing_area_set_draw_func (GTK_DRAWING_AREA (area),
                                  draw_function,
                                  calc_data, NULL);

  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n1_button, 1, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n2_button, 2, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n3_button, 3, 4, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->plus_button, 4, 4, 1, 1);

  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n4_button, 1, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n5_button, 2, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n6_button, 3, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->minus_button, 4, 3, 1, 1);

  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n7_button, 1, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->clear_button, 1, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n8_button, 2, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n9_button, 3, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->mult_button, 4, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->div_button, 4, 1, 1, 1);

  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->sqrt_button, 0, 2, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->ln_button, 0, 3, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->log_button, 0, 4, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grid_numb),finance_button, calc_data->clear_button,  GTK_POS_LEFT, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grid_numb),draw_button, finance_button,  GTK_POS_LEFT, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grid_numb), calc_data->sin_button, calc_data->sqrt_button, GTK_POS_LEFT, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grid_numb), calc_data->cos_button, calc_data->ln_button, GTK_POS_LEFT, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(grid_numb), calc_data->tan_button, calc_data->log_button, GTK_POS_LEFT, 1, 1);

  g_signal_connect(calc_data->n1_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->n2_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->n3_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->n4_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->n5_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->n6_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->n7_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->n8_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->n9_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->n0_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);

  g_signal_connect(calc_data->plus_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->minus_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->mult_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->div_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->sin_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->cos_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->tan_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->clear_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->sqrt_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->ln_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->log_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(calc_data->fl_button, "clicked", G_CALLBACK(insert_text),
                   calc_data);
  g_signal_connect(finance_button, "clicked", G_CALLBACK(cb_create),
                   NULL);

  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->button_q, 0, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->n0_button, 1, 5, 2, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), calc_data->fl_button, 3, 5, 1, 1);
  gtk_grid_attach(GTK_GRID(grid_numb), button_calc, 4, 5, 1, 1);
  gtk_box_set_homogeneous(GTK_BOX(text_box_H), FALSE);
  gtk_widget_set_halign(calc_data->entry_text, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(calc_data->entry_text, GTK_ALIGN_CENTER);
  gtk_widget_set_halign(grid_numb, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(grid_numb, GTK_ALIGN_CENTER);
  gtk_widget_set_halign(text_box_V, GTK_ALIGN_END);
  gtk_widget_set_halign(text_box_H, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(text_box_H, GTK_ALIGN_CENTER);
  gtk_widget_set_halign(text_box_Hor, GTK_ALIGN_CENTER);
  gtk_widget_set_vexpand(grid_numb, TRUE);
  gtk_widget_set_hexpand(grid_numb, TRUE);
  gtk_box_prepend(GTK_BOX(text_box_H), GTK_WIDGET(calc_data->entry_text));
  gtk_box_prepend(GTK_BOX(text_box_Hor2), GTK_WIDGET(text_box_H));
  gtk_box_prepend(GTK_BOX(text_box_Hor2), GTK_WIDGET(label_align));
  gtk_box_prepend(GTK_BOX(text_box_Hor), GTK_WIDGET(text_box_V));
  gtk_box_prepend(GTK_BOX(text_box_Grid), GTK_WIDGET(grid_numb));
  gtk_box_prepend(GTK_BOX(endgame), GTK_WIDGET(area));
  gtk_box_prepend(GTK_BOX(endgame), GTK_WIDGET(text_box_Grid));
  gtk_box_prepend(GTK_BOX(text_box_Vert), GTK_WIDGET(endgame));
  gtk_box_prepend(GTK_BOX(text_box_Vert), GTK_WIDGET(text_box_Hor2));
  gtk_window_set_child(GTK_WINDOW(calc_data->window), text_box_Vert);
  gtk_window_set_title(GTK_WINDOW(calc_data->window), "Smartcalc Artemii");
  gtk_window_set_default_size(GTK_WINDOW(calc_data->window), 340, 300);
  gtk_widget_show(calc_data->window);
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
