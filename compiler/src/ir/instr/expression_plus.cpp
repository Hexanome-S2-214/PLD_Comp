#include "expression_plus.h"

namespace IR
{
    void IRInstrExprPlus::gen_asm(ostream& o)
    {
        o << "\taddl "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}



