#include "compiler-error-token.h"
#include "../utils/string.h"
#include "../utils/parser-context.h"

string ErrorReporter::CompilerErrorToken::toString() {
    stringstream buffer;

    buffer << this->getLevelString();

    size_t tokenLine = this->getLine();
    size_t tokenCharPositionInLine = this->getCharPositionInLine();

    if (tokenLine != -1 && tokenCharPositionInLine != -1) {
        buffer << " (Ln " << tokenLine << ", Col " << tokenCharPositionInLine + 1 << ")";
    }

    buffer << ": " << this->getMessage() << endl;

    antlr4::Token * startToken = this->getStart();
    antlr4::Token * stopToken = this->getStop();

    if (startToken != nullptr && stopToken != nullptr)
    {
        string lines = getLines(startToken->getInputStream(), startToken->getStartIndex(), stopToken->getStopIndex());
        vector<string> linesVector = split(lines, '\n');

        for (int i = 0; i < min((int)linesVector.size(), 3); i++)
        {
            buffer << padString(to_string(tokenLine + i), 4, ' ') << " | " << linesVector[i] << endl;

            if (i == 0)
            {
                int lenght = min(
                    stopToken->getStopIndex() - startToken->getStartIndex(),
                    linesVector[i].size() - tokenCharPositionInLine - 1
                );

                buffer
                        << padString("", 4, ' ') << " | "
                        << padString("", tokenCharPositionInLine, ' ')
                        << "^" << padString("", lenght, '~')
                        << endl;
            }
        }
        
        if (linesVector.size() > 1) {
            buffer << padString("", 4, ' ') << " | " << endl;
        }
    }

    return buffer.str();
}

antlr4::Token * ErrorReporter::CompilerErrorToken::getStart() {
    if (this->start != nullptr) {
        return this->start;
    }
    if (this->ctx != nullptr) {
        return this->ctx->getStart();
    }

    return nullptr;
}

antlr4::Token * ErrorReporter::CompilerErrorToken::getStop() {
    if (this->stop != nullptr) {
        return this->stop;
    }
    if (this->ctx != nullptr) {
        return this->ctx->getStop();
    }
    if (this->start != nullptr) {
        return this->start;
    }

    return nullptr;
}

size_t ErrorReporter::CompilerErrorToken::getLine() {
    if (this->line != -1) {
        return this->line;
    }

    antlr4::Token * startToken = this->getStart();
    if (startToken != nullptr) {
        return startToken->getLine();
    }

    return -1;
}

size_t ErrorReporter::CompilerErrorToken::getCharPositionInLine() {
    if (this->charPositionInLine != -1) {
        return this->charPositionInLine;
    }

    antlr4::Token * startToken = this->getStart();
    if (startToken != nullptr) {
        return startToken->getCharPositionInLine();
    }

    return -1;
}