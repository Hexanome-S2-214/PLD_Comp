#pragma once

#include <string>
#include <map>
#include "antlr4-runtime.h"
#include "ir-type.h"
#include "ir-base.h"
#include "../error-reporter/error-reporter.h"
#include "params/ir-symbol.h"

#define INT_SIZE 4
#define CHAR_SIZE 1

using namespace std;

namespace IR
{
    class SymbolTable
    {
    public:
        SymbolTable() {};
        ~SymbolTable();

        Symbol * declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx = nullptr, int tableSize = -1);
        Symbol * get_symbol(string id, antlr4::ParserRuleContext * ctx = nullptr);

        Symbol * declare_tmp(IRBase * parent, Type type, antlr4::ParserRuleContext * ctx = nullptr);

        string get_next_tmp();

        ErrorReporter::ErrorReporter * error_reporter;
    private:
        map<string, Symbol *> symbols;
        int symbol_offset = 0;
        int tmp_offset = 0;
    };
}
