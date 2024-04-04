#pragma once

#include "../ir-instr-comp.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrExprCst : public IRInstrComposition, public IRAttrValue<IRInstrExprCst>
    {
    public:
        vector<IRInstr *> get_instrs() override;
    };
}
