#pragma once

#include <ostream>
#include <string>

using namespace std;

namespace IR
{
    class IRBase
    {
    public:
        ~IRBase() = default;

        virtual void gen_asm(ostream& o) = 0;
        string get_asm_str();
    };
};
