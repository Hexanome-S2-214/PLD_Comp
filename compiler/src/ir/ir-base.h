#pragma once

#include <ostream>
#include <string>

#include "antlr4-runtime.h"
#include "ir-arch.h"
#include "../error-reporter/error-reporter.h"

using namespace std;

namespace IR
{
    class IRBase
    {
    public:
        IRBase();
        ~IRBase() = default;

        void gen_asm(ostream& o);
        virtual void gen_asm_x86(ostream& o)=0;
        virtual void gen_asm_arm(ostream &o) = 0;
        string get_asm_str();

        IRBase * set_ctx(antlr4::ParserRuleContext * ctx);
        IRBase * set_error_reporter(ErrorReporter::ErrorReporter * error_reporter);
        IRBase * set_parent(IRBase * parent);

        IRBase * paste_properties(IRBase * other);

        template<typename T = IRBase>
        T * get_parent();
        antlr4::ParserRuleContext * get_ctx();
        ErrorReporter::ErrorReporter * get_error_reporter();
    private:
        IRBase * parent;
        antlr4::ParserRuleContext * ctx;
        ErrorReporter::ErrorReporter * error_reporter;
    };
};
