#include "movsbl.h"

namespace IR
{
    void IRInstrMovsbl::gen_asm(ostream& o)
    {
        o << "\tmovsbl "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}


