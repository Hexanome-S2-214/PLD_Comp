#include "comp.h"
#include "../../error-reporter/compiler-error-token.h"

namespace IR
{
    string get_op(Size size)
    {
        switch (size)
        {
            case Byte:
                return "cmpb";
            case Word:
                return "cmpw";
            case DWord:
                return "cmpl";
            case QWord:
                return "cmpq";
        }
        return "";
    }

    void IRInstrComp::gen_asm_x86(ostream& o)
    {
        if (src->get_size() != dest->get_size())
        {
            this->get_error_reporter()->reportError(
                new ErrorReporter::CompilerErrorToken(ErrorReporter::ERROR, "Comparison between different sizes", this->get_ctx())
            );
        }

        o << "\t" << get_op(src->get_size()) << " "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }

    void IRInstrComp::gen_asm_arm(ostream& o)
    {
        
    }
}


