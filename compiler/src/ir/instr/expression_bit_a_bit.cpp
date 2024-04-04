#include "expression_bit_a_bit.h"
#include "../params/ir-reg.h"

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
        
        if (op == "&") {
            o << "\t\tand " << (new IRRegA)->get_asm_str() << ", " << dest->get_asm_str() << ", " << src->get_asm_str() << "\n";
        } else if (op == "^") {
            o << "\t\teor " << (new IRRegA)->get_asm_str() << ", " << dest->get_asm_str() << ", " << src->get_asm_str() << "\n";
        } else if (op == "|") {
            o << "\t\torr " << (new IRRegA)->get_asm_str() << ", " << dest->get_asm_str() << ", " << src->get_asm_str() << "\n";
        } else {
            cerr << "Error: unsupported operator" << endl;
        }
    }
}


