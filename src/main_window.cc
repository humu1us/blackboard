#include "main_window.h"

bb::MainWindow::~MainWindow() = default;

bb::MainWindow::MainWindow()
    : Window()
{
    paned.add1(input);

    out.add(output);
    paned.add2(out);

    this->add(paned);
}

Glib::RefPtr<Gtk::TextBuffer> bb::MainWindow::get_input_buffer()
{
    return input.get_buffer();
}

Gtk::TextView *bb::MainWindow::get_output_widget()
{
    return &output;
}
