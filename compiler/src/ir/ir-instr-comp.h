#pragma once

#include <vector>

#include "ir-base.h"
#include "ir-instr.h"

using namespace std;

namespace IR
{
    class IRInstrComposition : public IRInstr
    {
    public:
        IRInstrComposition() {}
        ~IRInstrComposition() = default;

        void gen_asm(ostream &o) override;
        virtual vector<IRInstr *> get_instrs() = 0;
    };
}