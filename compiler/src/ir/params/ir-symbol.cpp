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
        o << (new IRRegStack)->set_offset(-offset)->get_asm_str();
    }

    SymbolT::SymbolT(int index, Symbol *symbol)
    {
        this->index = index;
        this->offset = symbol->offset;
        this->id = symbol->id;
        this->type = symbol->type;
        this->used = symbol->used;
    }

    void SymbolT::gen_asm_x86(ostream &o)
    {
        o << offset - index * type.size / 8 << (new IRRegStack)->get_asm_str();
    }
}