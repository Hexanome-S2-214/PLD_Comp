#include "set_flag_comp.h"
#include "../params/ir-reg.h"
#include "mov.h"

namespace IR
{
    void IRInstrSetFlagComp::gen_asm_x86(ostream& o)
    {
        if      (op == "==" or op == "!")    { o << "\tsete " << dest->get_asm_str() << endl; } 
        else if (op == "!=")    { o << "\tsetne " << dest->get_asm_str() << endl; }
        else if (op == ">")     { o << "\tsetg " << dest->get_asm_str() << endl; }
        else if (op == "<")     { o << "\tsetl " << dest->get_asm_str() << endl; }
        else if (op == ">=")    { o << "\tsetge " << dest->get_asm_str() << endl; }
        else if (op == "<=")    { o << "\tsetle " << dest->get_asm_str() << endl; }
    }
    
    void IRInstrSetFlagComp::gen_asm_arm(ostream& o)
    {
        paste_properties(
            (new IRInstrMov)
                ->set_src(new IRRegArmTemp2)
                ->set_dest(dest)
        )->gen_asm(o);

        if      (op == "==" or op == "!")    { o << "\tcset " << (new IRRegArmTemp2)->get_asm_str() << ", EQ\n"; } 
        else if (op == "!=")    { o << "\tcset " << (new IRRegArmTemp2)->get_asm_str() << ", NE\n"; }
        else if (op == ">")     { o << "\tcset " << (new IRRegArmTemp2)->get_asm_str() << ", GT\n"; }
        else if (op == "<")     { o << "\tcset " << (new IRRegArmTemp2)->get_asm_str() << ", LT\n"; }
        else if (op == ">=")    { o << "\tcset " << (new IRRegArmTemp2)->get_asm_str() << ", GE\n"; }
        else if (op == "<=")    { o << "\tcset " << (new IRRegArmTemp2)->get_asm_str() << ", LE\n"; }
    }
}


