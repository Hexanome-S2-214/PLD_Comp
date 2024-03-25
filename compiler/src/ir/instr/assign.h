#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../params/ir-reg.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrAssign : public IRInstr, public IRInstrBaseSymbol<IRInstrAssign>, public IRInstrBaseSrc<IRInstrAssign>
    {
    public:
        IRInstrAssign() { this->set_src(new IR::IRRegA); }
        void gen_asm(ostream& o) override;
    };
}
