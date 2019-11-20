#ifndef BLACKBOARD_OUTPUT_WIDGET_H
#define BLACKBOARD_OUTPUT_WIDGET_H

#include <gtkmm/scrolledwindow.h>

#include <string>

namespace bb
{
    class OutputWidget : public Gtk::ScrolledWindow
    {
    public:
        OutputWidget();
        virtual ~OutputWidget();
        void set_line(int line, const std::string &text);

    private:
        class Impl;
        std::unique_ptr<Impl> pimpl;
    };
}

#endif
