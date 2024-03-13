#pragma once

#include <string>
#include <map>
#include "antlr4-runtime.h"
#include "ir-type.h"
#include "ir-base.h"

#define SYMBOL_SIZE 4

using namespace std;

namespace IR
{
    class Symbol : public IR::IRBase
    {
    public:
        Symbol(string id, int offset, Type type, antlr4::ParserRuleContext * ctx = nullptr);
        Symbol() {};
        ~Symbol() = default;

        void gen_asm(ostream& o) override;

        string id;
        int offset;
        bool used = false;
        Type type;
        antlr4::ParserRuleContext * ctx;
    };

    class SymbolTable
    {
    public:
        SymbolTable() {};
        ~SymbolTable() = default;

        Symbol * declare_symbol(string id, Type type, antlr4::ParserRuleContext * ctx = nullptr);
        Symbol * get_symbol(string id, antlr4::ParserRuleContext * ctx = nullptr);

        Symbol * declare_tmp(Type type, antlr4::ParserRuleContext * ctx = nullptr);

        string get_next_tmp();
    private:
        map<string, Symbol> symbols;
        int symbol_offset = -SYMBOL_SIZE;
        int tmp_offset = 0;
    };
}
