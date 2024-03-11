#pragma once

namespace IR
{
    class BasicBlock;
}

#include "ir-base.h"

using namespace std;

namespace IR
{
    class IRInstr : public IRBase
    {
    public:
        IRInstr(BasicBlock * bb) : bb(bb) {}
        ~IRInstr();

        BasicBlock * get_bb() { return bb; };
    private:
        BasicBlock * bb;
    };
};
