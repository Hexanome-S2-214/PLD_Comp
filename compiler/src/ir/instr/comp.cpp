#include "comp.h"

namespace IR
{
    void IRInstrComp::gen_asm(ostream& o)
    {
        o << "\tcmpl "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}


