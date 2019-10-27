#include "main_window.h"

#include <gtkmm.h>

#include <memory>

int main(int argc, char **argv)
{
    auto app = Gtk::Application::create(argc, argv);
    blackboard::MainWindow main;

    main.resize(800, 600);
    main.show_all();
    app->run(main);


    return 0;
}
