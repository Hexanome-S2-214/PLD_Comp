#include "jump.h"

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
            case JumpType::IfFalse:
                op = "jz";
                break;
            case JumpType::IfTrue:
                op = "jnz";
                break;
            default:
                ErrorReporter::ErrorReporter::getInstance()->reportError(
                    new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Invalid jump type", get_ctx())
                );
        }

        o << "\t" << op << " " << label;

        if (get_comment() != "")
        {
            o << "\t\t# " << get_comment();
        }

        o << endl;
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
                ErrorReporter::ErrorReporter::getInstance()->reportError(
                    new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Invalid jump type", get_ctx()));
        }

        o << "\t" << op << " " << label << endl;
    }
}


