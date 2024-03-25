#include "comp.h"

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

    void IRInstrComp::gen_asm(ostream& o)
    {
        if (src->get_size() != dest->get_size())
        {
            cerr << "Error: comparison between different sizes" << endl;
        }

        o << "\t" << get_op(src->get_size()) << " "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
}


