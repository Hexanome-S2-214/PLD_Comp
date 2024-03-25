#include "expression_div.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrExprDiv::gen_asm(ostream& o)
    {
        o << "\tcltd" << endl;
        o << "\tidivl " << (new IRRegB)->get_asm_str() << endl;
    }
}
