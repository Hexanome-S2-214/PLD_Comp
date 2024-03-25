#include "addq.h"

namespace IR
{
    void IRInstrAddq::gen_asm(ostream& o)
    {
        o << "\taddq\t"<< src->get_asm_str() << endl;
    }
}