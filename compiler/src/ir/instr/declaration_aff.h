#pragma once

namespace IR
{
    class BasicBlock;
}

#include "../ir-instr.h"

namespace IR
{
    class IRInstrDeclaAff : public IRInstr
    {
    public:
        IRInstrDeclaAff(BasicBlock * bb, string id) : IRInstr(bb), id(id) {};

        void gen_asm(ostream& o) override;
    private:
        string id;
    };
}
