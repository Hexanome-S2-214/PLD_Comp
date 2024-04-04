#include "push.h"
#include "../../error-reporter/compiler-error-token.h"
#include "../params/ir-reg.h"
#include "mov.h"
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
        string op = "str";
        paste_properties(
                (new IRInstrMov)
                    ->set_dest((new IRRegArmTemp1)->set_size(src->get_size()))
                    ->set_src(src)
            )->gen_asm(o); 

        // ARM only supports 32-bit and 64-bit push
        if (src->get_size() == Size::DWord || src->get_size() == Size::QWord)
        {
            o << "\tstr " << (new IRRegArmTemp1)->get_asm_str() << ", [sp, 4]!" << endl;
        }
        else
        {
            get_error_reporter()->reportError(
                new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Invalid push size", get_ctx())
            );
        }
    }
}


