#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrExprMinus : public IRInstr
    {
    public:
        IRInstrExprMinus(BasicBlock * bb, string src, string dest) : IRInstr(bb), src(src), dest(dest) {};

        void gen_asm(ostream& o) override;
    private:
        string src;
        string dest; 
    };
}
