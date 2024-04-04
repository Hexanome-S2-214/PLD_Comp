#include "expression_mult.h"
#include "../params/ir-reg.h"
#include "mov.h"

namespace IR
{
    void IRInstrExprMult::gen_asm_x86(ostream& o)
    {
        o << "\timull " << src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
    
    void IRInstrExprMult::gen_asm_arm(ostream& o)
    {
        paste_properties(
                (new IRInstrMov)
                    ->set_src((new IRRegArmTemp1)->set_size(src->get_size()))
                    ->set_dest(src)
            )->gen_asm(o); 

        paste_properties(
                (new IRInstrMov)
                    ->set_src((new IRRegArmTemp2)->set_size(dest->get_size()))
                    ->set_dest(dest)
            )->gen_asm(o); 

        o << "\tmul " << (new IRRegA)->get_asm_str() << ", " << (new IRRegArmTemp2)->get_asm_str() << ", " << (new IRRegArmTemp1)->get_asm_str() << "\n";
    }
}
