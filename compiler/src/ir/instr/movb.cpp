#include "movb.h"

namespace IR
{
    void IRInstrMovb::gen_asm(ostream& o)
    {
        o << "\tmovb "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}


