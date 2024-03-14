#pragma once

namespace IR
{
    class SymbolTable;
}

#include "ir-base.h"
#include "ir-basic-block.h"
#include "antlr4-runtime.h"

using namespace std;

namespace IR
{
    class IRInstr : public IRBase
    {
    public:
        IRInstr(BasicBlock * bb, antlr4::ParserRuleContext * ctx) : IRBase(bb), bb(bb), ctx(ctx) {}
        ~IRInstr() = default;

        BasicBlock * get_bb() { return bb; };
        SymbolTable * get_symbol_table();
        antlr4::ParserRuleContext * get_ctx();
    private:
        BasicBlock * bb;
        antlr4::ParserRuleContext * ctx;
    };
};
