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
        o << "\t\tadr x16, " << literal << "\n"; // mettre l'addresse du literal dans x16
        o << "\t\tblr x16\n"; // brancher sur l'adresse de x16
    }
    
}


