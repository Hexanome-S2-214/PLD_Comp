#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrExprMult : public IRInstr
    {
    public:
        IRInstrExprMult(BasicBlock * bb, string tmpVar) : IRInstr(bb), tmpVar(tmpVar) {};

        void gen_asm(ostream& o) override;
    private:
        string tmpVar;
    };
}
