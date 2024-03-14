#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrExprNeg : public IRInstr
    {
    public:
        IRInstrExprNeg(BasicBlock *bb, antlr4::ParserRuleContext * ctx) : IRInstr(bb, ctx) {};
        void gen_asm(ostream& o) override;
    };
}
