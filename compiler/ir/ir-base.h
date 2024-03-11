#pragma once

#include <ostream>
#include <string>

using namespace std;

namespace IR
{
    class IRBase
    {
    public:
        virtual void gen_asm(ostream& o);
        string get_asm_str();
    };
};
