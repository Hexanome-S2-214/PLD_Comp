#include "mov.h"

namespace IR
{
    void IRInstrMov::gen_asm(ostream& o)
    {
        o << "\tmovl "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}


