#include "set_flag_comp.h"

namespace IR
{
    void IRInstrSetFlagComp::gen_asm(ostream& o)
    {
        if      (op == "==" or op == "!")    { o << "\tsete " << dest->get_asm_str() << endl; } 
        else if (op == "!=")    { o << "\tsetne " << dest->get_asm_str() << endl; }
        else if (op == ">")     { o << "\tsetg " << dest->get_asm_str() << endl; }
        else if (op == "<")     { o << "\tsetl " << dest->get_asm_str() << endl; }
        else if (op == ">=")    { o << "\tsetge " << dest->get_asm_str() << endl; }
        else if (op == "<=")    { o << "\tsetle " << dest->get_asm_str() << endl; }
    }
}


