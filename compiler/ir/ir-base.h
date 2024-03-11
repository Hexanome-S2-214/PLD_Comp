#pragma once

#include <ostream>

using namespace std;

namespace IR
{
    class IRBase
    {
    public:
        virtual void gen_asm(ostream& o);
    };
};
