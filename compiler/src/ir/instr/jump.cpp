#include "jump.h"

namespace IR
{
    void IRInstrJump::gen_asm(ostream& o)
    {
        o << "\t" << op << " " << label << endl;
    }
}


