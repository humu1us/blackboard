#include "var_processor.h"
#include <cctype>


namespace blackboard
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
blackboard::VarProcessor::Impl::Impl()
{
}

void blackboard::VarProcessor::Impl::update(const VarList &vars)
{
    for (auto &[name, value] : vars)
        variables[name] = value;
}

void blackboard::VarProcessor::Impl::replace(std::string &cmd)
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

void blackboard::VarProcessor::Impl::erase(const std::string &name)
{
    auto it = variables.find(name);
    if (it == variables.end())
        return;

    variables.erase(it);
}

// Public API

blackboard::VarProcessor::~VarProcessor() = default;

blackboard::VarProcessor::VarProcessor()
    : pimpl(std::make_unique<Impl>())
{
}


void blackboard::VarProcessor::update(const VarList &vars)
{
    pimpl->update(vars);
}

void blackboard::VarProcessor::add(const std::string &name,
                                   const std::string &value)
{
    pimpl->variables.insert({name, value});
}

void blackboard::VarProcessor::replace(std::string &cmd)
{
    pimpl->replace(cmd);
}

void blackboard::VarProcessor::erase(const std::string &name)
{
    pimpl->erase(name);
}

blackboard::VarProcessor::VarList &blackboard::VarProcessor::get_vars() const
{
    return pimpl->variables;
}
