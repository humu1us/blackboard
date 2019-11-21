#include "cmd_processor.h"

#include <libqalculate/Calculator.h>

namespace bb
{
    class CMDProcessor::Impl
    {
    public:
        Impl();
        std::string process(const std::string &cmd);

        Calculator *calc;
    };
}

// Internal implementation

bb::CMDProcessor::Impl::Impl()
    : calc(new Calculator())
{
    calc->useIntervalArithmetic(false);
    calc->loadExchangeRates();
    calc->loadGlobalCurrencies();
    calc->loadGlobalDefinitions();
    calc->loadLocalDefinitions();
}

std::string bb::CMDProcessor::Impl::process(const std::string &cmd)
{
    return calc->calculateAndPrint(calc->unlocalizeExpression(cmd));
}

// Public API

bb::CMDProcessor::~CMDProcessor() = default;

bb::CMDProcessor::CMDProcessor()
    : pimpl(std::make_unique<Impl>())
{
}

std::string bb::CMDProcessor::process(const std::string &cmd)
{
    return pimpl->process(cmd);
}
