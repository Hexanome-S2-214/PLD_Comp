#pragma once

#include <string>
#include "antlr4-runtime.h"

using namespace std;

namespace ErrorReporter {
    enum CompilerErrorLevel
    {
        INFO = -1,
        WARNING = 0,
        ERROR = 1,
    };

    class CompilerError
    {
    public:
        CompilerError(CompilerErrorLevel level, string message);
        virtual ~CompilerError() = default;

        CompilerErrorLevel getLevel() { return this->level; }
        string getMessage() { return this->message; }

        /*
        * Check if this error should cause the compiler to exit with an error.
        *
        * @return bool
        */
        bool shouldThrow();

        /*
        * Get the string representation of the error.
        *
        * @return string
        */
        virtual string toString();

        /*
        * Get the string representation of the error level.
        *
        * @return string
        */
        string getLevelString();

    private:
        CompilerErrorLevel level;
        std::string message;
    };
}
