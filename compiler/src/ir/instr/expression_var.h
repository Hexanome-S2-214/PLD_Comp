#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr-comp.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprVar : public IRInstrComposition, public IRAttrSymbol<IRInstrExprVar>
    {
    public:
        vector<IRInstr *> get_instrs() override;
    };
}
