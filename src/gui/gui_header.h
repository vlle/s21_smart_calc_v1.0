#ifndef SRC_GUI_GUI_HEADER_H_
#define SRC_GUI_GUI_HEADER_H_
#define MAX_ENTRY_SIZE 256

typedef struct {
  GtkWidget *codomain1;
  GtkWidget *codomain2;
  GtkWidget *codomain3;
  GtkWidget *codomain4;
  GtkEntry* data;
  GtkWidget* window;
} codomains;

char *str_replace(char *orig, char *rep, char *with);
void init_list(GtkWidget *list);
void add_to_list(GtkWidget *list, const gchar *total, const gchar *month,
                 const gchar *over);
void debug(char *prs, double my_res);
void on_changed(GtkWidget *widget, gpointer label);
void cb_create_entry();
gfloat f(gfloat x, const char *parser);  //, char* parse
void draw_create_entry(GtkWidget *button, gpointer data);
gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data);

void startdraw(int argc, char **argv);

#endif  // SRC_GUI_GUI_HEADER_H_
