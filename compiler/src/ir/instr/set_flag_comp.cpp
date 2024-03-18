#include "set_flag_comp.h"

namespace IR
{
    void IRInstrSetFlagComp::gen_asm(ostream& o)
    {
        if      (symbol == "==" or symbol == "!")    { o << "\tsete " << dest << endl; } 
        else if (symbol == "!=")    { o << "\tsetne " << dest << endl; }
        else if (symbol == ">")     { o << "\tsetg " << dest << endl; }
        else if (symbol == "<")     { o << "\tsetl " << dest << endl; }
        else if (symbol == ">=")    { o << "\tsetge " << dest << endl; }
        else if (symbol == "<=")    { o << "\tsetle " << dest << endl; }
    }
}


