#include "jump.h"

namespace IR
{
    void IRInstrJump::gen_asm_x86(ostream& o)
    {
        o << "\t" << op << " " << label << endl;
    }
    
    void IRInstrJump::gen_asm_arm(ostream& o)
    {
    }
}


