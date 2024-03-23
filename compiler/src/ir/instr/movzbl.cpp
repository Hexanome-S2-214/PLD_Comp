#include "movzbl.h"

namespace IR
{
    void IRInstrMovzbl::gen_asm(ostream& o)
    {
        o << "\tmovzbl "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}


