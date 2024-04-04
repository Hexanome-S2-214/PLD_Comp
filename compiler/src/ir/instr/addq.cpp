#include "addq.h"
#include "ir-reg.h"

namespace IR
{
    void IRInstrAddq::gen_asm_x86(ostream& o)
    {
        o << "\taddq\t"<< src->get_asm_str() << endl;
    }

    void IRInstrAddq::gen_asm_arm(ostream& o)
    {
       o << "\t\tadd" << (new IRRegA)->get_asm_str() << ", " << dst->get_asm_str() << ", " << src->get_asm_str() << "\n"; 
    }
}