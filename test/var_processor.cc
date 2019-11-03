#include <var_processor.h>
#include <iostream>
#include <vector>
#include <cassert>


void update_vars()
{
    std::cout << "Update vars:\n";
    std::vector<blackboard::VarProcessor::VarList> vars = {
        {
            {"a", "1"},
            {"foo", "22"},
            {"bar", "44"}
        },

        {
            {"foo", "11"}
        },

        {
            {"a", "5"},
            {"foo", "2"},
            {"bar", "44"},
            {"b", "98"}
        },
    };

    blackboard::VarProcessor vp;
    int i = 0;

    for (auto &v : vars)
    {
        vp.update(v);
        for (const auto &[name, val] : v)
        {

            std::cout << name << " -> "
                      << val << " = "
                      << vp.get_vars()[name] << "\n";

            assert(val == vp.get_vars()[name]);
        }
        std::cout << "--------------------------------\n";
        ++i;
    }
}

void simple_replace()
{
    std::cout << "\nSimple replace:\n";

    std::vector<std::string> commands = {
        "bar - a",
        "foo - bar",
        "a - 3"
    };

    blackboard::VarProcessor::VarList vars = {
        {"a", "1"},
        {"foo", "22"},
        {"bar", "44"}
    };

    std::vector<std::string> results = {
        "44 - 1",
        "22 - 44",
        "1 - 3"
    };

    blackboard::VarProcessor vp;
    vp.update(vars);

    for (unsigned i = 0; i < commands.size(); ++i)
    {
        vp.replace(commands[i]);
        std::cout << commands[i]  << " = " << results[i] << "\n";
        assert(commands[i] == results[i]);
    }
}

void complex_replace()
{
    std::cout << "\nComplex replace:\n";
    std::vector<std::string> commands = {
        "bar -a * 7+6+bar",
        "44s /foo - bar",
        "x*2a - 3+s"
    };

    blackboard::VarProcessor::VarList vars = {
        {"bar", "zx"},
        {"zx", "p"},
        {"foo", "1"},
        {"s", "20"},
        {"a", "11"},
        {"p", "30"}
    };

    std::vector<std::string> results = {
        "30 -11 * 7+6+30",
        "44s /1 - 30",
        "x*2a - 3+20"
    };

    blackboard::VarProcessor vp;
    vp.update(vars);

    for (unsigned i = 0; i < commands.size(); ++i)
    {
        vp.replace(commands[i]);
        std::cout << commands[i] << " = " << results[i] << "\n";
        assert(commands[i] == results[i]);
    }
}

void add()
{
    std::cout << "\nAdd:\n";

    blackboard::VarProcessor::VarList vars = {
        {"a", "1"},
        {"foo", "22"},
        {"bar", "44"}
    };

    blackboard::VarProcessor vp;

    for (const auto &[name, value] : vars)
        vp.add(name, value);

    for (const auto &[name, value] : vp.get_vars())
    {
        std::cout << name << " = " << value << "\n";
        assert(value == vars[name]);
    }
}

void erase()
{
    std::cout << "\nErase:\n";

     blackboard::VarProcessor::VarList vars = {
        {"a", "1"},
        {"foo", "22"},
        {"bar", "44"}
    };

    blackboard::VarProcessor vp;
    vp.update(vars);

    vp.erase("foo");
    assert(vp.get_vars().find("foo") == vp.get_vars().end());

    vp.erase("a");
    assert(vp.get_vars().find("a") == vp.get_vars().end());

    for (const auto &[name, value] : vp.get_vars())
        std::cout << name << " = " << value << "\n";
}


int main()
{
    update_vars();
    simple_replace();
    complex_replace();
    add();
    erase();
}
