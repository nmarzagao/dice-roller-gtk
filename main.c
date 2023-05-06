// version = 1.0
/*
TODO:

    Check if the gtk_builder_new() function returns NULL, indicating that the builder could not be created.
    Check if the gtk_builder_add_from_file() function returns FALSE, indicating that the UI file could not be loaded.
    Check if the gtk_combo_box_get_active_id() function returns NULL, indicating that no item is selected in the combo box.
    Check if the gtk_label_set_text() function returns FALSE, indicating that the label could not be updated.
    
*/

#include <gtk/gtk.h>
#include <glib/gstdio.h>
#include <time.h>
#include <string.h>

GtkBuilder* builder;
GObject* window;
GObject* dice_type;
GObject* button;
GObject* result_label;

static int get_dice_type() 
{
  const char* str = gtk_combo_box_get_active_id(GTK_COMBO_BOX(dice_type));
  if (str == NULL) return 0;
  else if (strcmp(str, "d4") == 0) return 4;
  else if (strcmp(str, "d6") == 0) return 6;
  else if (strcmp(str, "d8") == 0) return 8;
  else if (strcmp(str, "d10") == 0) return 10;
  else if (strcmp(str, "d12") == 0) return 12;
  else if (strcmp(str, "d20") == 0) return 20;
  else if (strcmp(str, "d100") == 0) return 100;
  else return 0;
}

static void roll() 
{
  int max = get_dice_type();
  if (max == 0) 
  {
    g_print("Invalid Option\n");
    return;
  }

  int roll = (rand() % max) + 1;
  char value[100];
  sprintf(value, "%d", roll);
  gtk_label_set_text(GTK_LABEL(result_label), (const char*) value);
}

static void activate(GtkApplication *app, gpointer user_data)
{
  builder = gtk_builder_new();

  gtk_builder_add_from_file(builder, "builder.ui", NULL);

  window = gtk_builder_get_object(builder, "window");
  gtk_window_set_application(GTK_WINDOW(window), app);

  dice_type = gtk_builder_get_object(builder, "dice-type");

  result_label = gtk_builder_get_object(builder, "result-label");

  button = gtk_builder_get_object(builder, "button");
  g_signal_connect (button, "clicked", G_CALLBACK(roll), NULL);

  gtk_widget_show(GTK_WIDGET(window));
  g_object_unref(builder);
}

int main(int argc, char *argv[]) 
{
  #ifdef GTK_SRCDIR
    g_chdir (GTK_SRCDIR);
  #endif

  srand(time(NULL));

  GtkApplication* app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  int status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

// By https://github.com/nmarzagao