#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "../ir-attr.h"

namespace IR
{
    class IRInstrAssignTable : public IRInstr, public IRAttrSymbol<IRInstrAssignTable>
    {
    public:
        IRInstrAssignTable(int index) : index(index){};
        void gen_asm_x86(ostream& o) override;
    protected:
        int index;
    };
}
