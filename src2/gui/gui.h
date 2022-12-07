#ifndef SRC_GUI_GUI_H_
#define SRC_GUI_GUI_H_

typedef struct calc {
  GtkWidget *label_empty;
  GtkWidget *entry_text;
  int i;
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

  GtkWidget *buttSq;
  GtkWidget *buttL;
  GtkWidget *buttl;
  GtkEntryBuffer *buff;
} calc;

#endif // SRC_GUI_GUI_H_
