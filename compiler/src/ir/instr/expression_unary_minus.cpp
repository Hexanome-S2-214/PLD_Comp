#include "expression_unary_minus.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrExprUnaryMinus::gen_asm_x86(ostream& o)
    {
        o << "\tnegl " << (new IRRegA)->get_asm_str() << endl;
    }
    
    void IRInstrExprUnaryMinus::gen_asm_arm(ostream& o)
    {
        
        o << "\tneg " << (new IRRegA)->get_asm_str() << ", " << (new IRRegA)->get_asm_str() << "\n";
    }
}
