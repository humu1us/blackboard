#include "input_widget.h"

#include <gtkmm/textview.h>

namespace bb
{
    class InputWidget::Impl
    {
    public:
        Impl();

        Gtk::TextView tv;
    };
}

// Internal implementation

bb::InputWidget::Impl::Impl()
{
}

// Public API

bb::InputWidget::~InputWidget() = default;

bb::InputWidget::InputWidget()
    : ScrolledWindow()
    , pimpl(std::make_unique<Impl>())
{
    this->add(pimpl->tv);
}

Glib::RefPtr<Gtk::TextBuffer> bb::InputWidget::get_buffer()
{
    return pimpl->tv.get_buffer();
}
