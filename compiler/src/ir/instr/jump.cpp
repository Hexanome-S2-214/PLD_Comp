#include "jump.h"
#include "../../error-reporter/compiler-error-token.h"

namespace IR
{
    void IRInstrJump::gen_asm_x86(ostream& o)
    {
        string op;

        switch (get_jump())
        {
            case JumpType::Jump:
                op = "jmp";
                break;
            case JumpType::IfEqual:
                op = "je";
                break;
            case JumpType::IfNotEqual:
                op = "jne";
                break;
            default:
                get_error_reporter()->reportError(
                    new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Invalid jump type", get_ctx())
                );
        }

        o << "\t" << op << " " << label << endl;
    }
    
    void IRInstrJump::gen_asm_arm(ostream& o)
    {
        string op;

        switch (get_jump())
        {
            case JumpType::Jump:
                op = "b";
                break;
            case JumpType::IfEqual:
                op = "beq";
                break;
            case JumpType::IfNotEqual:
                op = "bne";
                break;
            default:
                get_error_reporter()->reportError(
                    new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Invalid jump type", get_ctx())
                );
        }

        o << "\t" << op << " " << label << endl;
    }
}


