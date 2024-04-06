#include "parser-context.h"

string getLines(antlr4::ParserRuleContext *ctx)
{
    return getLines(ctx->getStart()->getInputStream(), ctx->getStart()->getStartIndex(), ctx->getStop()->getStopIndex());
}

string getLines(antlr4::CharStream *stream, size_t pos)
{
    return getLines(stream, pos, pos);
}

string getLines(antlr4::CharStream *stream, size_t start, size_t stop)
{
    while (start > 0)
    {
        if (stream->getText(antlr4::misc::Interval(start, start)) == "\n")
        {
            start++; // Exclude the newline character
            break;
        }
        start--;
    }

    while (stream->size())
    {
        if (stream->getText(antlr4::misc::Interval(stop, stop)) == "\n")
        {
            stop--; // Exclude the newline character
            break;
        }
        if (stop == stream->size() - 1)
        {
            break;
        }
        
        stop++;
    }

    return stream->getText(antlr4::misc::Interval(start, stop));
}
