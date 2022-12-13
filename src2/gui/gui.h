#ifndef SRC_GUI_GUI_H_
#define SRC_GUI_GUI_H_

typedef struct calc {
  GtkWidget *label_empty;
  GtkWidget *entry_text;
  int i;
  GtkWidget *window;
  GtkWidget *n1_button;
  GtkWidget *n2_button;
  GtkWidget *n3_button;
  GtkWidget *n4_button;
  GtkWidget *n5_button;
  GtkWidget *n6_button;
  GtkWidget *n7_button;
  GtkWidget *n8_button;
  GtkWidget *n9_button;
  GtkWidget *n0_button;
  GtkWidget *fl_button;
  GtkWidget *sin_button;
  GtkWidget *cos_button;
  GtkWidget *tan_button;
  GtkWidget *div_button;
  GtkWidget *plus_button;
  GtkWidget *minus_button;
  GtkWidget *mult_button;
  GtkWidget *clear_button;
  GtkWidget *sqrt_button;
  GtkWidget *log_button;
  GtkWidget *ln_button;
  GtkWidget *button_q;

  GtkWidget *buttSq;
  GtkWidget *buttL;
  GtkWidget *buttl;
  GtkEntryBuffer *buff;
} calc;

void cb_create();
static void activate(GtkApplication *app, gpointer user_data);
void delete(GtkWidget *widget, gpointer data);
static void insert_text(GtkWidget *widget, gpointer data);
char *calculat(GtkWidget *widget, gpointer data);

#endif  // SRC_GUI_GUI_H_
