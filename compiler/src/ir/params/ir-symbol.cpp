#include "ir-symbol.h"
#include "ir-reg.h"

namespace IR
{
    Size IR::Symbol::get_size()
    {
        return type.size;
    }

    void IR::Symbol::gen_asm_x86(ostream& o)
    {
        o << offset << (new IRRegStack)->set_size(type.size)->get_asm_str();
    }
    
    void IR::Symbol::gen_asm_arm(ostream& o)
    {
    }

    SymbolT::SymbolT(int index, Symbol *symbol)
    {
        index = index;
        offset = symbol->offset;
        id = symbol->id;
        type = symbol->type;
        used = symbol->used;
    }

    void SymbolT::gen_asm_x86(ostream &o)
    {
        o << offset + index * type.size << (new IRRegStack)->get_asm_str();
    }
}