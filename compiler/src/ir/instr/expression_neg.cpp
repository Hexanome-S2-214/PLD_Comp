#include "expression_neg.h"
#include "../ir-reg.h"

namespace IR
{
    void IRInstrExprNeg::gen_asm(ostream& o)
    {
        o << "\tnegl " << IR::IRRegA(this).get_asm_str() << endl;
    }
}
