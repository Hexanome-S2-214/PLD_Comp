#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr-comp.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrAssign : public IRInstrComposition, public IRAttrSymbol<IRInstrAssign>
    {
    public:
        vector<IRInstr *> get_instrs() override;
    };
}
