#include "expression_unary_minus.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrExprUnaryMinus::gen_asm(ostream& o)
    {
        o << "\tnegl " << (new IRRegA)->get_asm_str() << endl;
    }
}
