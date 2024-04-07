#include "test.h"

namespace IR
{
    void IRInstrTest::gen_asm_x86(ostream& o)
    {
        o << "\ttest " << src->get_asm_str() << ", " << src->get_asm_str() << endl;
    }

    void IRInstrTest::gen_asm_arm(ostream& o)
    {
        
    }
    
}


