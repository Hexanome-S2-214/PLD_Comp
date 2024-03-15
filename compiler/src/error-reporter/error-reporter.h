#pragma once

#include <vector>
#include "compiler-error.h"

namespace ErrorReporter
{
    class ErrorReporter
    {
    public:
        ErrorReporter() = default;
        ErrorReporter(bool printErrors);

        /*
        * Add error to reporter
        *
        * @param error CompilerError
        */
        void reportError(CompilerError *error);

        /*
        * Get all errors
        *
        * @return vector<CompilerError>
        */
        vector<CompilerError *> getErrors();

        /*
        * Check if the reporter contains errors which should make the program exit with an error
        *
        * @return bool
        */
        bool getShouldThrow() const;

    private:
        vector<CompilerError *> errors;
        bool shouldThrow = false;
        bool printErrors = true;
    };
}

