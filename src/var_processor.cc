#include "var_processor.h"
#include <cctype>


namespace bb
{
    class VarProcessor::Impl
    {
    public:
        Impl();

        void update(const VarList &vars);
        void replace(std::string &cmd);
        void erase(const std::string &name);

        VarList variables;
    };
}

// Internal implementation
bb::VarProcessor::Impl::Impl()
{
}

void bb::VarProcessor::Impl::update(const VarList &vars)
{
    for (auto &[name, value] : vars)
        variables[name] = value;
}

void bb::VarProcessor::Impl::replace(std::string &cmd)
{
    bool replaced;

    do
    {
        replaced = false;
        for (auto &[name, value] : variables)
        {
            auto pos = cmd.find(name);
            if (pos == std::string::npos)
                continue;

            if (pos > 0
                && !std::ispunct(cmd[pos - 1])
                && !std::isspace(cmd[pos - 1]))
            {
                continue;
            }
            cmd.replace(pos, name.size(), value);
            replaced = true;
        }
    }
    while (replaced);
}

void bb::VarProcessor::Impl::erase(const std::string &name)
{
    auto it = variables.find(name);
    if (it == variables.end())
        return;

    variables.erase(it);
}

// Public API

bb::VarProcessor::~VarProcessor() = default;

bb::VarProcessor::VarProcessor()
    : pimpl(std::make_unique<Impl>())
{
}


void bb::VarProcessor::update(const VarList &vars)
{
    pimpl->update(vars);
}

void bb::VarProcessor::add(const std::string &name,
                                   const std::string &value)
{
    pimpl->variables.insert({name, value});
}

void bb::VarProcessor::replace(std::string &cmd)
{
    pimpl->replace(cmd);
}

void bb::VarProcessor::erase(const std::string &name)
{
    pimpl->erase(name);
}

bb::VarProcessor::VarList &bb::VarProcessor::get_vars() const
{
    return pimpl->variables;
}
