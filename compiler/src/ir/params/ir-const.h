#pragma once

#include "ir-param.h"
#include "../ir-attr.h"

using namespace std;

namespace IR
{
    class IRConst : public IRParam, public IRAttrLiteral<IRConst>, public IRAttrSize<IRConst>
    {
    public:
        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
        Size get_size() override;
    };
}