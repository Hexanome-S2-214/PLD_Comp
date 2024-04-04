#include "expression_plus.h"

namespace IR
{
    void IRInstrExprPlus::gen_asm_x86(ostream& o)
    {
        if (src->get_size() != dest->get_size())
        {
            get_error_reporter()->reportError(
                new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Addition between different sizes", get_ctx())
            );
        }
        
        string op;

        switch (src->get_size())
        {
            case Size::Byte:
                op = "addb";
                break;
            case Size::Word:
                op = "addw";
                break;
            case Size::DWord:
                op = "addl";
                break;
            case Size::QWord:
                op = "addq";
                break;
        }
        o << "\t" << op << " "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
    
    void IRInstrExprPlus::gen_asm_arm(ostream& o)
    {
    }
}



