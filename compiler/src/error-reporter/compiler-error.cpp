#include "compiler-error.h"
#include "../utils/string.h"
#include "../utils/parser-context.h"

ErrorReporter::CompilerError::CompilerError(CompilerErrorLevel level, string message) : level(level), message(message) {}

string ErrorReporter::CompilerError::toString()
{
    stringstream buffer;

    buffer << this->getLevelString() << ": " << this->message << endl;

    return buffer.str();
}

string ErrorReporter::CompilerError::getLevelString()
{
    switch (this->level)
    {
    case WARNING:
        return "Warning";
    case ERROR:
        return "Error";
    default:
        return "Unknown";
    }
}

bool ErrorReporter::CompilerError::shouldThrow()
{
    return this->level >= ERROR;
}
