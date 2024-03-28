#include "expression_mult.h"

namespace IR
{
    void IRInstrExprMult::gen_asm_x86(ostream& o)
    {
        o << "\timull " << src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
    
    void IRInstrExprMult::gen_asm_arm(ostream& o)
    {
    }
}
