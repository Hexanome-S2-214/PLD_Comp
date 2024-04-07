#pragma once

#include <stdexcept>

namespace IR
{
    class IRSymbolError : public std::runtime_error {
    public:
        IRSymbolError(const std::string &msg) : std::runtime_error(msg) {}
    };

    class IRLoopError : public std::runtime_error {
    public:
        IRLoopError(const std::string &msg) : std::runtime_error(msg) {}
    };
} // namespace IR
