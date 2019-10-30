#include "main_window.h"

#include <gtkmm.h>
#include <libqalculate/Calculator.h>

#include <iostream>

Glib::RefPtr<Gtk::TextBuffer> in_buf;
Glib::RefPtr<Gtk::TextBuffer> out_buf;

void calculate()
{
    auto txt = in_buf->get_text();

    if (txt[txt.size() - 1] == 0xa)
    {
        auto t = out_buf->get_text() += "\n";
        out_buf->set_text(t);
        return;
    }

    auto c = std::make_unique<Calculator>();
    c->loadGlobalDefinitions();
    c->loadLocalDefinitions();

    auto line = in_buf->get_insert()->get_iter().get_line();

    Glib::ustring::size_type beg = 0;

    for (auto i = 0; i < line; ++i)
        beg = txt.find("\n", beg) + 1;

    auto end = txt.find("\n", beg);
    auto r = c->calculateAndPrint(txt.substr(beg, end), 2000);

    auto it_beg = out_buf->get_iter_at_line(line);
    auto it_end = it_beg;
    it_end.forward_to_line_end();

    out_buf->erase(it_beg, it_end);


    it_beg = out_buf->get_iter_at_line(line);
    out_buf->insert(it_beg, r);
}


int main(int argc, char **argv)
{
    auto app = Gtk::Application::create(argc, argv);
    blackboard::MainWindow main;

    main.resize(800, 600);

    in_buf = main.get_input_buffer();
    out_buf = main.get_output_widget()->get_buffer();

    in_buf->signal_changed().connect(sigc::ptr_fun(&calculate));

    main.show_all();
    app->run(main);


    return 0;
}
