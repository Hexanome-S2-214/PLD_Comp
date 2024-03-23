#include <iostream>
#include "error-reporter.h"
#include "compiler-error-token.h"

ErrorReporter::ErrorReporter::ErrorReporter(bool printErrors) : printErrors(printErrors) {}

ErrorReporter::ErrorReporter::~ErrorReporter()
{
    for (CompilerError * error : this->errors)
    {
        delete error;
    }
}

void ErrorReporter::ErrorReporter::reportError(CompilerError * error)
{
    this->errors.push_back(error);
    this->shouldThrow = this->shouldThrow || error->shouldThrow();

    if (this->printErrors)
    {
        std::cerr << error->toString();
    }
}

vector<ErrorReporter::CompilerError *> ErrorReporter::ErrorReporter::getErrors()
{
    return this->errors;
}

bool ErrorReporter::ErrorReporter::getShouldThrow() const
{
    return this->shouldThrow;
}
