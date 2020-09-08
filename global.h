#ifndef HELLO_WORLD_GLOBAL_H
#define HELLO_WORLD_GLOBAL_H

#include <gtk/gtk.h>
#include <json-c/json.h>
//#include <gst/gst.h>

const char* CONFIG_JSON_PATH = "/home/eduard_h/Desktop/Kerpak/kerpak_ui/trio_iq_ui_config.json";

const char* WELCOME_PAGE_GLADE_PATH = "/home/eduard_h/Desktop/Kerpak/kerpak_ui/data/main.glade";
const char* MAIN_WINDOW_ID = "main_window";
const char* KERPAK_INFO_BUTTON_ID = "kerpak_info_button";

const char* KERPAK_ABOUT_GLADE_PATH = "/home/eduard_h/Desktop/Kerpak/kerpak_ui/data/about.glade";
const char* KERPAK_ABOUT_WINDOW_ID = "main_window";
const char* KERPAK_ABOUT_BACK_BUTTON = "about_back_button";

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
const char* getWelcomeTextFromConfigJson(const char* file_path);


#endif //HELLO_WORLD_GLOBAL_H
