#include "main_window.h"

blackboard::MainWindow::~MainWindow() = default;

blackboard::MainWindow::MainWindow()
    : Window()
{
    paned.add1(input);

    out.add(output);
    paned.add2(out);

    this->add(paned);
}

Glib::RefPtr<Gtk::TextBuffer> blackboard::MainWindow::get_input_buffer()
{
    return input.get_buffer();
}

Gtk::TextView *blackboard::MainWindow::get_output_widget()
{
    return &output;
}
