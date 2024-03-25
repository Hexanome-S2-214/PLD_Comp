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

        void gen_asm(ostream& o) override;
        Size get_size() override;

        string id;
        int offset;
        bool used = false;
        Type type;
    };
}