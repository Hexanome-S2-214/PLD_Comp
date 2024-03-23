#include "expression_bit_a_bit.h"

namespace IR
{
    void IRInstrExprBitABit::gen_asm(ostream& o)
    {
        if      (op == "&")    { o << "\tandl " << src->get_asm_str() << ", " << dest->get_asm_str() << endl; } 
        else if (op == "^")    { o << "\txorl " << src->get_asm_str() << ", " << dest->get_asm_str() << endl; }
        else if (op == "|")    { o << "\torl " << src->get_asm_str() << ", " << dest->get_asm_str() << endl; }
    }
}


