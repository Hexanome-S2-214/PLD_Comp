#include "pushq.h"

namespace IR
{
    void IRInstrPushq::gen_asm_x86(ostream& o)
    {
        o << "\tpushq\t"<< src->get_asm_str() << endl;
    }

    void IRInstrPushq::gen_asm_arm(ostream& o)
    {
        o << "\tstr " << src->get_asm_str() << ", [sp, #-8]!\n";
    }
}


