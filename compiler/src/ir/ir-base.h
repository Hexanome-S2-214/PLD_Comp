#pragma once

#include <ostream>
#include <string>

#include "ir-arch.h"
#include "../error-reporter/error-reporter.h"

using namespace std;

namespace IR
{
    
    class IRBase
    {
    public:
        IRBase(IRBase * parent);
        IRBase(IRArch arch, ErrorReporter::ErrorReporter * error_reporter);
        ~IRBase() = default;

        virtual void gen_asm(ostream& o) = 0;
        string get_asm_str();

        IRBase * get_parent();
        ErrorReporter::ErrorReporter * get_error_reporter();
    private:
        IRBase * parent;
        IRArch arch;
        ErrorReporter::ErrorReporter * error_reporter;
    };
};
