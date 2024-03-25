#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr-comp.h"
#include "../ir-attr.h"
#include "../params/ir-reg.h"

namespace IR
{
    class IRInstrAssign : public IRInstrComposition, public IRAttrSymbol<IRInstrAssign>, public IRAttrSrc<IRInstrAssign>
    {
    public:
        IRInstrAssign() { set_src(new IR::IRRegA); }
        vector<IRInstr *> get_instrs() override;
    };
}
