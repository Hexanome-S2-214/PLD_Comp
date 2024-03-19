#include "ir-const.h"

namespace IR
{
    void IRConst::gen_asm(ostream& o) {
        o << "$" << value;
    }

    IRConst * IRConst::set_value(string value) {
        this->value = value;
        return this;
    }

    string IRConst::get_value() {
        return value;
    }
}