#include <sstream>
#include "ir-base.h"

using namespace std;

string IR::IRBase::get_asm_str()
{
    stringstream ss;

    gen_asm(ss);
    
    return ss.str();
}
