#include "compb.h"

namespace IR
{
    void IRInstrCompb::gen_asm(ostream& o)
    {
        o << "\tcmpb "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}


