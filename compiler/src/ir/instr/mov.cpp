#include "mov.h"

namespace IR
{
    void IRInstrMov::gen_asm(ostream& o)
    {
        o << "\tmovl "<< src << ", " << dest << endl;
    }
}


