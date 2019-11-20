#include "output_widget.h"

#include <gtkmm/textview.h>

namespace bb
{
    class OutputWidget::Impl
    {
    public:
        Impl();
        void set_line(int line, const std::string &text);
        void create_empty_lines(int n);
        void delete_line(int line);

        Gtk::TextView tv;
        Gtk::TextBuffer *buffer;
    };
}

// Internal implementation

bb::OutputWidget::Impl::Impl()
    : buffer(tv.get_buffer().get())
{
    tv.set_can_focus(false);
}

void bb::OutputWidget::Impl::set_line(int line, const std::string &text)
{
    int last_line = buffer->get_line_count() - 1;
    if (line > last_line)
        create_empty_lines(line - last_line);

    delete_line(line);
    buffer->insert(buffer->get_iter_at_line(line), text);
}

void bb::OutputWidget::Impl::create_empty_lines(int n)
{
    std::string new_lines(n * 2, ' ');
    for (int i = 1; i < n * 2; i += 2)
        new_lines[i] = '\n';
    buffer->insert(buffer->end(), new_lines);
}

void bb::OutputWidget::Impl::delete_line(int line)
{
    auto end = buffer->get_iter_at_line(line);
    end.forward_to_line_end();
    buffer->erase(buffer->get_iter_at_line(line), end);
}

// Public API

bb::OutputWidget::~OutputWidget() = default;

bb::OutputWidget::OutputWidget()
    : ScrolledWindow()
    , pimpl(std::make_unique<Impl>())
{
    this->add(pimpl->tv);
}

void bb::OutputWidget::set_line(int line, const std::string &text)
{
    pimpl->set_line(line, text);
}
