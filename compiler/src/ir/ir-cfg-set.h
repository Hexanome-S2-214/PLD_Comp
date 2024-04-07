#pragma once

namespace IR
{
    class BasicBlock;
}

#include <vector>
#include <map>
#include "ir-base.h"
#include "ir-symbol-table.h"
#include "ir-cfg.h"
#include "../error-reporter/error-reporter.h"

using namespace std;

namespace IR
{
    struct Func
    {
        string name;
        bool used;
        antlr4::ParserRuleContext * ctx;
    };

    class CfgSet : public IRBase
    {
    public:
        CfgSet() {}
        ~CfgSet() = default;

        void gen_asm_x86(ostream& o) override;
        void gen_asm_arm(ostream& o) override;

        void add_cfg(CFG * cfg);

        Func * declare_function(string name, antlr4::ParserRuleContext * ctx);
        void set_function_as_used(string name);
        vector<Func *> get_unused_functions();

        CFG * get_current_cfg();
        CFG * get_cfg_by_fname(string fname);
        void set_current_cfg(CFG * cfg);
        vector<string> stack; // TODO: Make private and add push/pop methods (also maybe rename to something that means something)
    private:
        vector<CFG *> cfgs;
        map<string, Func> functions;
        CFG * current_cfg;
    };
};
