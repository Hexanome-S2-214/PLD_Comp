#pragma once

#include <ostream>
#include <string>

#include "ir-arch.h"

using namespace std;

namespace IR
{
    
    class IRBase
    {
    public:
        IRBase(IRBase * parent);
        IRBase(IRArch arch);
        ~IRBase() = default;

        virtual void gen_asm(ostream& o) = 0;
        string get_asm_str();
    private:
        IRBase * parent;
        IRArch arch;
    };
};