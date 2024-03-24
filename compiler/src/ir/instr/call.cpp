#include "call.h"

namespace IR
{
    void IRInstrCall::gen_asm(ostream& o)
    {
        o << "\tcall " << call;

        if (call == "getchar" || call == "putchar"){
            o << "@PLT";
        }

        o << endl;
    }
}


