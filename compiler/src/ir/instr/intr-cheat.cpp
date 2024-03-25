#include "intr-cheat.h"

namespace IR
{
    IRInstrCheat * IRInstrCheat::set_instr(string instr)
    {
        this->instr = instr;
        return this;
    }

    void IRInstrCheat::gen_asm_x86(ostream& o)
    {
        o << "\t" << instr << endl;
    }
    
    void IRInstrCheat::gen_asm_arm(ostream& o)
    {
    }
}


