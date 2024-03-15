#include "comp.h"

namespace IR
{
    void IRInstrComp::gen_asm(ostream& o)
    {
        o << "\tcmpl "<< src << ", " << dest << endl;
    }
}


