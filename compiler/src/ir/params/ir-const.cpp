#include "ir-const.h"

namespace IR
{
    void IRConst::gen_asm_x86(ostream& o) {
        o << "$" << literal;
    }
    
    void IRConst::gen_asm_arm(ostream& o) {
        o << "#" << literal;
    }
    
    Size IRConst::get_size() {
        return size;
    }
}