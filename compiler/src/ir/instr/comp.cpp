#include "comp.h"
#include "mov.h"
#include "../../error-reporter/compiler-error-token.h"
#include "../params/ir-reg.h"

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
        if (src->get_size() != dest->get_size())
        {
            cerr << "Error: comparison between different sizes" << endl;
            return;
        }

        paste_properties(
                (new IRInstrMov)
                    ->set_dest((new IRRegArmTemp1)->set_size(src->get_size()))
                    ->set_src(src)
            )->gen_asm(o); 

        paste_properties(
                (new IRInstrMov)
                    ->set_dest((new IRRegArmTemp2)->set_size(dest->get_size()))
                    ->set_src(dest)
            )->gen_asm(o); 

        //string comp_op = get_op(src->get_size());
        o << "\tcmp " << " " << (new IRRegArmTemp1)->get_asm_str() << ", " << (new IRRegArmTemp2)->get_asm_str() << "\n";
        
    }
}


