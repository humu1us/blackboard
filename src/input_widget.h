#ifndef BLACK_BOARD_INPUT_WIDGET_H
#define BLACK_BOARD_INPUT_WIDGET_H

#include <gtkmm/scrolledwindow.h>

#include <memory>

namespace bb
{
    class InputWidget : public Gtk::ScrolledWindow
    {
    public:
        InputWidget();
        virtual ~InputWidget();
        Glib::RefPtr<Gtk::TextBuffer> get_buffer();

    private:
        class Impl;
        std::unique_ptr<Impl> pimpl;
    };
}

#endif
