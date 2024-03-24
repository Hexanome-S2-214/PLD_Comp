#include "expression_mult.h"

namespace IR
{
    void IRInstrExprMult::gen_asm(ostream& o)
    {
        o << "\timull " << src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}
