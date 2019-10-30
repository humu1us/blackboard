#include "input_widget.h"

#include <gtkmm/textview.h>

namespace blackboard
{
    class InputWidget::Impl
    {
    public:
        Impl();

        Gtk::TextView tv;
    };
}

// Internal implementation

blackboard::InputWidget::Impl::Impl()
{
}

// Public API

blackboard::InputWidget::~InputWidget() = default;

blackboard::InputWidget::InputWidget()
    : ScrolledWindow()
    , pimpl(std::make_unique<Impl>())
{
    this->add(pimpl->tv);
}

Glib::RefPtr<Gtk::TextBuffer> blackboard::InputWidget::get_buffer()
{
    return pimpl->tv.get_buffer();
}
