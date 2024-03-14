#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrExprCst : public IRInstr
    {
    public:
        IRInstrExprCst(BasicBlock * bb, antlr4::ParserRuleContext * ctx, string value) : IRInstr(bb, ctx), value(value) {};

        void gen_asm(ostream& o) override;
    private:
        string value;
    };
}
