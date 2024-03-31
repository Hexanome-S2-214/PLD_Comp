#include "epilogue.h"

namespace IR
{
    void IRInstrEpilogue::gen_asm_x86(ostream& o)
    {
        o << "\n";
        o << "\tleave\n";
        o << "\tret\n";
    }
    
    void IRInstrEpilogue::gen_asm_arm(ostream& o)
    {
        o << "\tpop {fp, pc}\n";
    }
}


