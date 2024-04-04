#include "expression_div.h"
#include "mov.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrExprDiv::gen_asm_x86(ostream& o)
    {
        o << "\tcltd" << endl;
        o << "\tidivl " << (new IRRegB)->get_asm_str() << endl;
    }
    void IRInstrExprDiv::gen_asm_arm(ostream& o)
    {
        
    }
}
