#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrExprDiv : public IRInstr
    {
    public:
        IRInstrExprDiv(BasicBlock * bb, antlr4::ParserRuleContext * ctx, string src) : IRInstr(bb, ctx), src(src) {};

        void gen_asm(ostream& o) override;
    private:
        string src;
    };
}
