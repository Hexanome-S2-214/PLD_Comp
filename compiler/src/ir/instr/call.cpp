#include "call.h"

namespace IR
{
    void IRInstrCall::gen_asm_x86(ostream& o)
    {
        o << "\tcall " << literal;

        if (literal == "getchar" || literal == "putchar"){
            o << "@PLT";
        }

        o << endl;
    }

    void IRInstrCall::gen_asm_arm(ostream& o)
    {
        
    }
    
}


