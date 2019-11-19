#ifndef BLACK_BOARD_VAR_PROCESSOR_H
#define BLACK_BOARD_VAR_PROCESSOR_H

#include <memory>
#include <unordered_map>
#include <string>

namespace bb
{
    class VarProcessor
    {
    public:
        using VarList = std::unordered_map<std::string, std::string>;

        VarProcessor();
        ~VarProcessor();

        void update(const VarList &vars);
        void add(const std::string &name, const std::string &value);
        void replace(std::string &cmd);
        void erase(const std::string &name);

        VarList &get_vars() const;

    private:
        class Impl;
        std::unique_ptr<Impl> pimpl;
    };
}

#endif
