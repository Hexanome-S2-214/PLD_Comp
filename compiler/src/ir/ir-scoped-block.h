#pragma once

#include <string>
#include "ir-symbol-table.h"

namespace IR
{
    class IRScopedBlock
    {
    public:
        Symbol * declare_symbol(IRBase * parent, string id, Type type, antlr4::ParserRuleContext * ctx = nullptr, int personalized_offset = 0);
        Symbol * get_symbol(string id, antlr4::ParserRuleContext * ctx = nullptr);

        Symbol * declare_tmp(IRBase * parent, Type type, antlr4::ParserRuleContext * ctx = nullptr);

        int get_st_size();

        void set_parent_scope(IRScopedBlock * parent);
        IRScopedBlock * get_parent_scope() { return parentScope; }

    private:
        SymbolTable symbolTable;
        IRScopedBlock * parentScope = nullptr;
    };
}
