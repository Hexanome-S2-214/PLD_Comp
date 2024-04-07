#pragma once

#include <string>
#include <map>
#include <vector>
#include "antlr4-runtime.h"
#include "ir-type.h"
#include "ir-base.h"
#include "../error-reporter/error-reporter.h"
#include "params/ir-symbol.h"
#include "params/ir-reg.h"

#define INT_SIZE 4
#define CHAR_SIZE 1

using namespace std;

namespace IR
{

    class SymbolTable
    {
    public:
        SymbolTable();
        ~SymbolTable();

        Symbol * declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx = nullptr, bool const_var=false, int personalized_offset = 0);
        Symbol * get_symbol(string id, antlr4::ParserRuleContext * ctx = nullptr);

        Symbol * declare_tmp(IRBase * parent, Type type, antlr4::ParserRuleContext * ctx = nullptr);

        vector<Symbol *> get_unused_symbols();
        static vector<Symbol *> get_all_unused_symbols();

        string get_next_tmp();
        int get_symbol_offset() { return symbol_offset; }
    private:
        static int symbol_offset;
        static vector<SymbolTable *> symbol_tables;
        map<string, Symbol *> symbols;
        int tmp_offset = 0;
    };
}
