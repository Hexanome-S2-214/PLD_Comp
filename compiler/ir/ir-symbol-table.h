#pragma once

#include <string>
#include <map>
#include "antlr4-runtime.h"
#include "ir-type.h"

#define SYMBOL_SIZE 4

using namespace std;

namespace IR
{
    
    struct Symbol
    {
        int offset;
        bool used;
        Type type;
        antlr4::ParserRuleContext * ctx;
    };

    class SymbolTable
    {
    public:
        SymbolTable();
        ~SymbolTable();

        Symbol * declare_symbol(string id, Type type, antlr4::ParserRuleContext * ctx);
        Symbol * get_symbol(string id, antlr4::ParserRuleContext * ctx);

        string get_next_tmp();
    private:
        map<string, Symbol> symbols;
        int symbol_offset = -SYMBOL_SIZE;
        int tmp_offset = 0;
    };
}
