#pragma once

#include "antlr4-runtime.h"
#include "error-reporter.h"

using namespace std;

namespace ErrorReporter
{
    class ErrorListener : public antlr4::BaseErrorListener
    {
    public:
        ErrorListener(ErrorReporter *error_reporter) : error_reporter(error_reporter) {}

        void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token * offendingSymbol, size_t line, size_t charPositionInLine,
                                const string &msg, std::exception_ptr e) override;
    private:
        ErrorReporter *error_reporter;
    };    
} // namespace ErrorReporter

