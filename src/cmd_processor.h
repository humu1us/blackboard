#ifndef BLACKBOARD_CMDPROCESSOR_H
#define BLACKBOARD_CMDPROCESSOR_H

#include <memory>
#include <string>

namespace bb
{
    class CMDProcessor
    {
    public:
        CMDProcessor();
        virtual ~CMDProcessor();
        std::string process(const std::string &cmd);

    private:
        class Impl;
        std::unique_ptr<Impl> pimpl;
    };
}

#endif
