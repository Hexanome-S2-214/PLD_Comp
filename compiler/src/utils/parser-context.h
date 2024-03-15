#pragma once

#include <string>
#include "antlr4-runtime.h"

using namespace std;

/*
 * Get lines of code from a parser rule context which includes a start and stop position (defaults to context start and stop).
 *
 * @param stream The parser rule context.
 * 
 * @return The lines of code as a string.
 */
string getLines(antlr4::ParserRuleContext *ctx);

/*
 * Get lines of code from a parser rule context at a specific position.
 *
 * @param stream The input stream.
 * @param pos The position to get the line from.
 * 
 * @return The line of code as a string.
 */
string getLines(antlr4::CharStream *stream, size_t pos);

/*
 * Get lines of code from a parser rule context at a specific range.
 *
 * @param stream The input stream.
 * @param start The start position to get the line from.
 * @param stop The stop position to get the line from.
 * 
 * @return The lines of code as a string.
 */
string getLines(antlr4::CharStream *stream, size_t start, size_t stop);
