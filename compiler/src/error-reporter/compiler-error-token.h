#pragma once

#include "antlr4-runtime.h"
#include "compiler-error.h"

using namespace std;

namespace ErrorReporter
{
    class CompilerErrorToken : public CompilerError
    {
    public:
        CompilerErrorToken(CompilerErrorLevel level, string message, antlr4::ParserRuleContext *ctx)
                : CompilerError(level, message), ctx(ctx) {}

        CompilerErrorToken(CompilerErrorLevel level, string message, antlr4::Token *token)
            : CompilerError(level, message), start(token) {}

        CompilerErrorToken(CompilerErrorLevel level, string message, size_t line, size_t charPositionInLine)
                : CompilerError(level, message), line(line), charPositionInLine(charPositionInLine) {}

        ~CompilerErrorToken() override = default;

        string toString() override;
        size_t getLine();
        size_t getCharPositionInLine();
    private:
        antlr4::ParserRuleContext *ctx = nullptr;
        antlr4::Token *start = nullptr;
        antlr4::Token *stop = nullptr;
        size_t line = -1;
        size_t charPositionInLine = -1;

        antlr4::Token * getStart();
        antlr4::Token * getStop();
    };
}
