#include "expression_minus.h"

namespace IR
{
    void IRInstrExprMinus::gen_asm_x86(ostream& o)
    {
        o << "\tsubl " << src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }

    void IRInstrExprMinus::gen_asm_arm(ostream& o)
    {
    }
}
