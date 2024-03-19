#include "call.h"

namespace IR
{
    void IRInstrCall::gen_asm(ostream& o)
    {
        o << "\tcall " << symbol;

        if (symbol == "getchar" || symbol == "putchar"){
            o << "@PLT";
        }

        o << endl;
    }
}


