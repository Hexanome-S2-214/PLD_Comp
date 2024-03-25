#include "call.h"

namespace IR
{
    void IRInstrCall::gen_asm(ostream& o)
    {
        o << "\tcall " << literal;

        if (literal == "getchar" || literal == "putchar"){
            o << "@PLT";
        }

        o << endl;
    }
}


