#pragma once

#include "../ir-base.h"
#include "../ir-type.h"

using namespace std;

namespace IR
{
    class IRParam : public IRBase {
    public:
        virtual Size get_size() = 0;
    };
}
