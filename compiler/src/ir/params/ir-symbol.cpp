#include "ir-symbol.h"
#include "ir-reg.h"

namespace IR
{
    Size IR::Symbol::get_size()
    {
        return type.size;
    }

    void IR::Symbol::set_value(int value) {
        this->value = value;
    }

    void IR::Symbol::gen_asm_x86(ostream& o)
    {
        o << offset << (new IRRegStack)->set_size(type.size)->get_asm_str();
    }
    
    void IR::Symbol::gen_asm_arm(ostream& o)
    {
    }
}