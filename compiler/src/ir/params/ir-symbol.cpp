#include "ir-symbol.h"
#include "ir-reg.h"

namespace IR
{
    void IR::Symbol::gen_asm(ostream& o)
    {
        o << offset << (new IRRegStack)->get_asm_str();
    }

    void SymbolT::gen_asm(ostream &o)
    {
        o << offset + index * type.size << (new IRRegStack)->get_asm_str();
    }
}