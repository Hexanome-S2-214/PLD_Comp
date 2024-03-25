#include "pushq.h"

namespace IR
{
    void IRInstrPushq::gen_asm(ostream& o)
    {
        o << "\tpushq\t"<< src->get_asm_str() << endl;
    }
}


