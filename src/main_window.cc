#include "main_window.h"

blackboard::MainWindow::~MainWindow() = default;

blackboard::MainWindow::MainWindow()
    : Window()
{
    in.add(input);
    paned.add1(in);

    out.add(output);
    paned.add2(out);

    this->add(paned);
}

Gtk::TextView *blackboard::MainWindow::get_input_widget()
{
    return &input;
}

Gtk::TextView *blackboard::MainWindow::get_output_widget()
{
    return &output;
}
