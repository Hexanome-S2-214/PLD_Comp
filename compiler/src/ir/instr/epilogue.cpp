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
        o << "\tadd	sp, sp, 16\n";
        o << "\tret\n";
        //o << "\tpop {fp, pc}\n";

        //o << "\t\tldp x29, x30, [sp], #16\n"; 
        //o << "\t\tret\n";
    }
}


