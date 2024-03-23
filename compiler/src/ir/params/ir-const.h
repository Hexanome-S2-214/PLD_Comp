#pragma once

#include "ir-param.h"

using namespace std;

namespace IR
{
    class IRConst : public IRParam
    {
    public:
        void gen_asm(ostream& o) override;

        IRConst * set_value(string value);
        string get_value();
    private:
        string value;
    };
}