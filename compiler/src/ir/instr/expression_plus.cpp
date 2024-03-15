#include "expression_plus.h"

namespace IR
{
    void IRInstrExprPlus::gen_asm(ostream& o)
    {
        o << "\taddl "<< src << ", " << dest << endl;
    }
}



