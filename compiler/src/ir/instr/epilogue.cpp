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

        // o << "\t\tldp fp, lr, [sp], #16\n"; 
        // o << "\t\tret\n";                       //c'est plutot comme ca pour arm-v8 non ?
    }
}


