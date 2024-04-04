#include "push.h"

namespace IR
{
    void IRInstrPush::gen_asm_x86(ostream& o)
    {
        string op;

        switch (src->get_size())
        {
        case Size::Byte:
            op = "pushb";
            break;
        case Size::Word:
            op = "pushw";
            break;
        case Size::DWord:
            op = "pushl";
            break;
        case Size::QWord:
            op = "pushq";
            break;
        }

        o << "\t" << op << " " << src->get_asm_str() << endl;
    }

    void IRInstrPush::gen_asm_arm(ostream& o)
    {
        
    }
}


