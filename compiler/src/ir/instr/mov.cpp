#include "mov.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrMov::gen_asm_x86(ostream& o)
    {
        o << "\t" << get_op() << " "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
    
    void IRInstrMov::gen_asm_arm(ostream& o)
    {
        if (dynamic_cast<IRReg*>(dest) && dynamic_cast<IRReg*>(src)) {
            o << "\tmov " << dest->get_asm_str() << ", " << src->get_asm_str() << "\n";
        } else if (dynamic_cast<IRReg*>(dest)) {
            o << "\tstr " << src->get_asm_str() << ", [" << dest->get_asm_str() << "]\n";
        }else {
            o << "\tldr " << dest->get_asm_str() << ", [" << src->get_asm_str() << "]\n";
        }
    }

    string IRInstrMov::get_op()
    {
        string op;

        if (src->get_size() == dest->get_size())
        {
            switch (src->get_size())
            {
            case Byte:
                op = "movb";
                break;
            case Word:
                op = "movw";
                break;
            case DWord:
                op = "movl";
                break;
            case QWord:
                op = "movq";
                break;
            default:
                break;
            }
        }
        else
        {
            switch (src->get_size())
            {
            case Byte: {
                switch (dest->get_size())
                {
                case Word:
                    op = "movzbw";
                    break;
                case DWord:
                    op = "movzbl";
                    break;
                case QWord:
                    op = "movzbq";
                    break;
                default:
                    break;
                }
                break;
            }
            case Word: {
                switch (dest->get_size())
                {
                case Byte:
                    op = "movzwl";
                    break;
                case DWord:
                    op = "movzlq";
                    break;
                case QWord:
                    op = "movzwq";
                    break;
                default:
                    break;
                }
                break;
            }
            case DWord: {
                switch (dest->get_size())
                {
                case Byte:
                    op = "movzlq";
                    break;
                case Word:
                    op = "movslq";
                    break;
                case QWord:
                    op = "movslq";
                    break;
                default:
                    break;
                }
                break;
            }
            case QWord:
                switch (dest->get_size())
                {
                case Byte:
                    op = "mov";
                    break;
                case Word:
                    op = "mov";
                    break;
                case DWord:
                    op = "mov";
                    break;
                default:
                    break;
                }
                break;
            }
        }

        return op;
    }
}


