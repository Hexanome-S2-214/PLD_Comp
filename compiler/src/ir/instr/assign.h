#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrAssign : public IRInstr
    {
    public:
        IRInstrAssign(BasicBlock * bb, antlr4::ParserRuleContext * ctx, string id) : IRInstr(bb, ctx), id(id) {};

        void gen_asm(ostream& o) override;
    private:
        string id;
    };
}
