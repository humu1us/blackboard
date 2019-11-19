#ifndef BLACKBOARD_MAIN_WINDOW_H
#define BLACKBOARD_MAIN_WINDOW_H

#include "input_widget.h"
#include <gtkmm.h>

namespace bb
{
    class MainWindow : public Gtk::Window
    {
    public:
        MainWindow();
        ~MainWindow();

        Glib::RefPtr<Gtk::TextBuffer> get_input_buffer();
        Gtk::TextView *get_output_widget();

    private:
        Gtk::HPaned paned;
        Gtk::ScrolledWindow out;
        InputWidget input;
        Gtk::TextView output;
    };
}

#endif
