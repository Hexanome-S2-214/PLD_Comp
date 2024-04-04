#include "expression_plus.h"
#include "../params/ir-reg.h"
#include "../../error-reporter/compiler-error-token.h"
#include "mov.h"

namespace IR
{
    void IRInstrExprPlus::gen_asm_x86(ostream& o)
    {
        cerr <<"1" << endl;
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
        cerr <<"2" << endl;
        o << "\t" << op << " "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
        cerr <<"3" << endl;
    }
    
    void IRInstrExprPlus::gen_asm_arm(ostream& o)
    {
        if (src->get_size() != dest->get_size())
        {
            get_error_reporter()->reportError(
                new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Addition between different sizes", get_ctx())
            );
        }

        paste_properties(
                (new IRInstrMov)
                    ->set_src((new IRRegArmTemp1)->set_size(src->get_size()))
                    ->set_dest(src)
            )->gen_asm(o); 

        paste_properties(
                (new IRInstrMov)
                    ->set_src((new IRRegArmTemp2)->set_size(dest->get_size()))
                    ->set_dest(dest)
            )->gen_asm(o);  

        o << "\tadd " << (new IRRegA)->get_asm_str() << ", " << (new IRRegArmTemp2)->get_asm_str() << ", " << (new IRRegArmTemp1)->get_asm_str() << "\n";
    }
}



