#include "output_widget.h"

#include <gtkmm/textview.h>

#include <memory>

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
        Glib::RefPtr<Gtk::TextBuffer> buffer;
    };
}

// Internal implementation

bb::OutputWidget::Impl::Impl()
{
    tv.set_can_focus(false);
    buffer = tv.get_buffer();
}

void bb::OutputWidget::Impl::set_line(int line, const std::string &text)
{
    int last_line = buffer->get_line_count() - 1;
    if (line > last_line)
    {
        create_empty_lines(line - last_line);
    }
    delete_line(line);
    auto iter = buffer->get_iter_at_line(line);
    buffer->insert(iter, text);
}

void bb::OutputWidget::Impl::create_empty_lines(int n)
{
    std::string new_lines(n * 2, ' ');
    for (int i = 1; i < n * 2; i += 2)
        new_lines[i] = '\n';
    auto iter = buffer->end();
    buffer->insert(iter, new_lines);
}

void bb::OutputWidget::Impl::delete_line(int line)
{
    auto beg_iter = buffer->get_iter_at_line(line);
    auto end_iter = beg_iter;
    end_iter.forward_to_line_end();
    buffer->erase(beg_iter, end_iter);
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
