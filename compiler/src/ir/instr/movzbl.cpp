#include "movzbl.h"

namespace IR
{
    void IRInstrMovzbl::gen_asm(ostream& o)
    {
        o << "\tmovzbl "<< src << ", " << dest << endl;
    }
}


