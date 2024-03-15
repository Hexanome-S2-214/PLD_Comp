#include "expression_minus.h"

namespace IR
{
    void IRInstrExprMinus::gen_asm(ostream& o)
    {
        o << "\tsubl " << src << ", " << dest << endl;
    }
}
