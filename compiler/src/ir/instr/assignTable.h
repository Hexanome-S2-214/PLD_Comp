#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"
#include "base-instr.h"

namespace IR
{
    class IRInstrAssignTable : public IRInstr, public IRInstrBaseId<IRInstrAssignTable>
    {
    public:
        IRInstrAssignTable(int index) : index(index){};
        void gen_asm(ostream& o) override;
    protected:
        int index;
    };
}
