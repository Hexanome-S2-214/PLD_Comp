#pragma once

#include <vector>
#include "compiler-error.h"
#include "compiler-error-token.h"

namespace ErrorReporter
{
    class ErrorReporter
    {
    public:
        ErrorReporter() = default;
        ErrorReporter(bool printErrors);
        ~ErrorReporter();

        static ErrorReporter * getInstance();

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
        static ErrorReporter * instance;
        vector<CompilerError *> errors;
        bool shouldThrow = false;
        bool printErrors = true;
    };
}

