#include "expression_unary_minus.h"
#include "../ir-reg.h"

namespace IR
{
    void IRInstrExprUnaryMinus::gen_asm(ostream& o)
    {
        o << "\tnegl " << IR::IRRegA().get_asm_str() << endl;
    }
}
