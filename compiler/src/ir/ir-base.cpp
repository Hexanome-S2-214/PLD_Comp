#include <sstream>
#include "ir-base.h"

using namespace std;

IR::IRBase::IRBase(IRBase * parent) : parent(parent), arch(parent->arch) {}

IR::IRBase::IRBase(IRArch arch, ErrorReporter::ErrorReporter * error_reporter) : parent(nullptr), arch(arch), error_reporter(error_reporter) {}

string IR::IRBase::get_asm_str()
{
    stringstream ss;

    gen_asm(ss);
    
    return ss.str();
}

IR::IRBase * IR::IRBase::get_parent()
{
    return parent;
}

ErrorReporter::ErrorReporter * IR::IRBase::get_error_reporter()
{
    return error_reporter;
}