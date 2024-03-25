#include "ir-const.h"

namespace IR
{
    void IRConst::gen_asm(ostream& o) {
        o << "$" << literal;
    }
    
    Size IRConst::get_size() {
        return size;
    }
}