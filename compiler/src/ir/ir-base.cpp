#include <sstream>
#include "ir-base.h"

using namespace std;

IR::IRBase::IRBase(IRBase * parent) : parent(parent), arch(parent->arch) {}

IR::IRBase::IRBase(IRArch arch) : parent(nullptr), arch(arch) {}

string IR::IRBase::get_asm_str()
{
    stringstream ss;

    gen_asm(ss);
    
    return ss.str();
}
