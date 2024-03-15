#include "error-listener.h"
#include "compiler-error-token.h"

void ErrorReporter::ErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t charPositionInLine,
                             const string &msg, std::exception_ptr e)
{
    if (offendingSymbol == nullptr) {
        CompilerErrorToken error(ERROR, msg, line, charPositionInLine);
        this->error_reporter->reportError(&error);
    } else {
        CompilerErrorToken error(ERROR, msg, offendingSymbol);
        this->error_reporter->reportError(&error);
    }
}
