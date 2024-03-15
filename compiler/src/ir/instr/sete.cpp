#include "sete.h"

namespace IR
{
    void IRInstrSete::gen_asm(ostream& o)
    {
        o << "\tsete " << dest << endl;
    }
}


