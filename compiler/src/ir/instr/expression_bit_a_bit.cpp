#include "expression_bit_a_bit.h"
#include "../params/ir-reg.h"
#include "mov.h"

namespace IR
{
    void IRInstrExprBitABit::gen_asm_x86(ostream& o)
    {
        if      (op == "&")    { o << "\tandl " << src->get_asm_str() << ", " << dest->get_asm_str() << endl; } 
        else if (op == "^")    { o << "\txorl " << src->get_asm_str() << ", " << dest->get_asm_str() << endl; }
        else if (op == "|")    { o << "\torl " << src->get_asm_str() << ", " << dest->get_asm_str() << endl; }
    }
    void IRInstrExprBitABit::gen_asm_arm(ostream& o)
    {
        paste_properties(
                (new IRInstrMov)
                    ->set_src(new IRRegArmTemp1)
                    ->set_dest(src)
            )->gen_asm(o); 

        paste_properties(
                (new IRInstrMov)
                    ->set_src(new IRRegArmTemp2)
                    ->set_dest(dest)
            )->gen_asm(o); 

        if (op == "&") {
            o << "\tand " << (new IRRegA)->get_asm_str() << ", " << (new IRRegArmTemp2)->get_asm_str() << ", " << (new IRRegArmTemp1)->get_asm_str() << "\n";
        } else if (op == "^") {
            o << "\teor " << (new IRRegA)->get_asm_str() << ", " << (new IRRegArmTemp2)->get_asm_str() << ", " << (new IRRegArmTemp1)->get_asm_str() << "\n";
        } else if (op == "|") {
            o << "\torr " << (new IRRegA)->get_asm_str() << ", " << (new IRRegArmTemp2)->get_asm_str() << ", " << (new IRRegArmTemp1)->get_asm_str() << "\n";
        } else {
            cerr << "Error: unsupported operator" << endl;
        }
    }
}


