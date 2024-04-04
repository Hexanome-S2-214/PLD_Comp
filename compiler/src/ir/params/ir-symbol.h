#pragma once

#include "ir-param.h"
#include "../ir-type.h"

namespace IR
{
    class Symbol : public IRParam
    {
    public:
        Symbol() {};
        ~Symbol() = default;

        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;
        Size get_size() override;

        void set_value(int value);

        string id;
        int offset;
        bool const_var;
        int value;
        bool used = false;
        Type type;
    };
}