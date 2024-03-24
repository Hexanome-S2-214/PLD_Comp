#pragma once

#include "ir-cfg.h"

using namespace std;

namespace IR
{
    class IROptimiser
    {
    public:
        void optimise(CFG * cfg);
    };
}