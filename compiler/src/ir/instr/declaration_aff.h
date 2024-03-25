#pragma once

#include "../ir-instr-comp.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrDeclaAff : public IRInstrComposition, public IRAttrSymbol<IRInstrDeclaAff>
    {
    public:
        vector<IRInstr *> get_instrs() override;
    };
}
