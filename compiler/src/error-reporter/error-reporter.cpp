#include <iostream>
#include "error-reporter.h"

ErrorReporter::ErrorReporter* ErrorReporter::ErrorReporter::instance = nullptr;

ErrorReporter::ErrorReporter::ErrorReporter(bool printErrors) : printErrors(printErrors) {}

ErrorReporter::ErrorReporter::~ErrorReporter()
{
    for (CompilerError * error : this->errors)
    {
        delete error;
    }
}

ErrorReporter::ErrorReporter * ErrorReporter::ErrorReporter::getInstance()
{
    if (instance == nullptr)
    {
        instance = new ErrorReporter();
    }

    return instance;
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
