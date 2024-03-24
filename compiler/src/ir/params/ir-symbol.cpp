#include "ir-symbol.h"
#include "ir-reg.h"

namespace IR
{
    Size IR::Symbol::get_size()
    {
        return type.size;
    }

    void IR::Symbol::gen_asm(ostream& o)
    {
        o << offset << (new IRRegStack)->set_size(type.size)->get_asm_str();
    }
}