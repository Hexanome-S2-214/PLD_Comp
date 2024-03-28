#include "expression_plus.h"

namespace IR
{
    void IRInstrExprPlus::gen_asm_x86(ostream& o)
    {
        o << "\taddl "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
    
    void IRInstrExprPlus::gen_asm_arm(ostream& o)
    {
    }
}



