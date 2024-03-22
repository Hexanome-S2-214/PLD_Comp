#pragma once

namespace IR
{
    class BasicBlock;
}

#include <vector>
#include "ir-base.h"
#include "ir-symbol-table.h"
#include "ir-cfg.h"
#include "../error-reporter/error-reporter.h"

using namespace std;

namespace IR
{
    class CfgSet : public IRBase
    {
    public:
        CfgSet() {}
        ~CfgSet() = default;

        void gen_asm(ostream& o) override;

        void add_cfg(CFG * cfg);

        CFG * get_current_cfg();
        void set_current_cfg(CFG * cfg);
        vector<string> stack; // TODO: Make private and add push/pop methods (also maybe rename to something that means something)
    private:
        vector<CFG *> cfgs;
        CFG * current_cfg;
    };
};
