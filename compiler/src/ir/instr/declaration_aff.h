#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrDeclaAff : public IRInstr, public IRInstrBaseId<IRInstrDeclaAff>
    {
    public:
        void gen_asm(ostream& o) override;
    };
}
