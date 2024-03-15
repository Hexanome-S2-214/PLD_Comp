#include "expression_mult.h"

namespace IR
{
    void IRInstrExprMult::gen_asm(ostream& o)
    {
        o << "\timull " << src << ", " << dest << endl;
    }
}
