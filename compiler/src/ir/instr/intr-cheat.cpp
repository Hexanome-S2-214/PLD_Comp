#include "intr-cheat.h"

namespace IR
{
    IRInstrCheat * IRInstrCheat::set_instr(string instr)
    {
        this->instr = instr;
        return this;
    }

    void IRInstrCheat::gen_asm(ostream& o)
    {
        o << "\t" << instr << endl;
    }
}


