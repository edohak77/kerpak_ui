#include <gtk/gtk.h>


const char* WELCOME_PAGE_GLADE_PATH = "/home/eduard_h/Desktop/Kerpak/kerpak_ui/data/main.glade";
const char* MAIN_WINDOW_ID = "main_window";

const char* KERPAK_ABOUT_GLADE_PATH = "/home/eduard_h/Desktop/Kerpak/kerpak_ui/data/about.glade";
const char* KERPAK_ABOUT_WINDOW_ID = "main_window";

//#include <gst/gst.h>
GtkWidget  *g_lbl_provider_welcome_text;
GtkWidget  *g_lbl_open_door_manually_message;
GtkWidget  *g_lbl_provider_qr_id;

int WINDOW_WIDTH = 480;
int WINDOW_HEIGHT = 800;

struct WindowAndBuilder{
    GtkBuilder *gtkBuilder;
    GtkWidget *window;
};

void on_window_main_destroy();
struct WindowAndBuilder build_custom_window(const char* glade_file_path, const char* window_id );
void show_welcome_window();
void show_kerpak_about_window();
void on_kerpak_info_button_clicked();
void on_about_back_button_clicked();

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    show_welcome_window();

    return 0;
}

// called when window is closed
void on_window_main_destroy() {
    gtk_main_quit();
}

void show_welcome_window(){
    struct WindowAndBuilder window_builder = build_custom_window(WELCOME_PAGE_GLADE_PATH, MAIN_WINDOW_ID);
    GtkWidget *button_output_close;

    //get pointers to the labels
    g_lbl_provider_welcome_text = GTK_WIDGET(gtk_builder_get_object(window_builder.gtkBuilder, "g_lbl_provider_welcome_text"));
    g_lbl_open_door_manually_message = GTK_WIDGET(gtk_builder_get_object(window_builder.gtkBuilder, "g_lbl_open_door_manually_message"));
    g_lbl_provider_qr_id = GTK_WIDGET(gtk_builder_get_object(window_builder.gtkBuilder, "g_lbl_provider_qr_id"));

    gtk_label_set_text(GTK_LABEL(g_lbl_provider_welcome_text), "Welcome Text");
    gtk_label_set_text(GTK_LABEL(g_lbl_open_door_manually_message), "You can also open the door manually");
    gtk_label_set_text(GTK_LABEL(g_lbl_provider_qr_id), "123132212");
    button_output_close = GTK_WIDGET(
            gtk_builder_get_object(window_builder.gtkBuilder, "kerpak_info_button"));

    g_signal_connect(button_output_close, "clicked", G_CALLBACK (on_kerpak_info_button_clicked), NULL);

    g_object_unref(G_OBJECT(window_builder.gtkBuilder));
    gtk_widget_show(window_builder.window);
    gtk_main();
}

void show_kerpak_about_window(){
    struct WindowAndBuilder window_builder = build_custom_window(KERPAK_ABOUT_GLADE_PATH, KERPAK_ABOUT_WINDOW_ID);
    GtkWidget *button_output_close;

    button_output_close = GTK_WIDGET(
            gtk_builder_get_object(window_builder.gtkBuilder, "about_backbutton"));

    g_signal_connect(button_output_close, "clicked", G_CALLBACK (on_about_back_button_clicked), NULL);
    g_object_unref(G_OBJECT(window_builder.gtkBuilder));
    gtk_widget_show(window_builder.window);
    gtk_main();
}

struct WindowAndBuilder build_custom_window(const char* glade_file_path, const char* window_id ){
    GtkBuilder *gtkBuilder  = NULL;
    GtkWidget *window  = NULL;
    gtkBuilder = gtk_builder_new();
    gtk_builder_add_from_file(gtkBuilder, glade_file_path, NULL);
    window = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, window_id));
    gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    struct WindowAndBuilder window_builder;
    window_builder.gtkBuilder = gtkBuilder;
    window_builder.window = window;

    return window_builder;
}

// called when button is clicked
void on_kerpak_info_button_clicked(){
    show_kerpak_about_window();
}

void on_about_back_button_clicked(){
    show_welcome_window();
}

