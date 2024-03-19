#include "expression_minus.h"

namespace IR
{
    void IRInstrExprMinus::gen_asm(ostream& o)
    {
        o << "\tsubl " << src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}
