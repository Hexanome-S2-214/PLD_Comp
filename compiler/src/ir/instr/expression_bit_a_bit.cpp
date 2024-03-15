#include "expression_bit_a_bit.h"

namespace IR
{
    void IRInstrExprBitABit::gen_asm(ostream& o)
    {
        if      (symbol == "&")    { o << "\tandl " << src << ", " << dest << endl; } 
        else if (symbol == "^")    { o << "\txorl " << src << ", " << dest << endl; }
        else if (symbol == "|")    { o << "\torl " << src << ", " << dest << endl; }
    }
}


