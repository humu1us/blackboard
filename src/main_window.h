#ifndef BLACK_BOARD_MAIN_WINDOW_H
#define BLACK_BOARD_MAIN_WINDOW_H

#include <gtkmm.h>

namespace blackboard
{
    class MainWindow : public Gtk::Window
    {
    public:
        MainWindow();
        ~MainWindow();

        Gtk::TextView *get_input_widget();
        Gtk::TextView *get_output_widget();

    private:
        Gtk::HPaned paned;
        Gtk::ScrolledWindow in;
        Gtk::ScrolledWindow out;
        Gtk::TextView input;
        Gtk::TextView output;
    };
}

#endif
