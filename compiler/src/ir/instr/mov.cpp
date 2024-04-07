#include "mov.h"
#include "../params/ir-reg.h"
#include "../params/ir-const.h"

namespace IR
{
    void IRInstrMov::gen_asm_x86(ostream& o)
    {
        o << "\t" << get_op() << " "<< src->get_asm_str() << ", " << dest->get_asm_str() << endl;
    }
    
    void IRInstrMov::gen_asm_arm(ostream& o)
    {
        IRRegStack * src_stack = dynamic_cast<IRRegStack*>(src);

        if (dynamic_cast<IRReg*>(dest) && (dynamic_cast<IRReg*>(src) || dynamic_cast<IRConst*>(src)) && src_stack == nullptr) {
            IRReg * dest_reg = dynamic_cast<IRReg*>(dest);
            IRReg * src_reg = dynamic_cast<IRReg*>(src);
            IRConst * src_const = dynamic_cast<IRConst*>(src);

            Size size = max(dest->get_size(), src->get_size());

            dest_reg->set_size(size);

            if (src_reg != nullptr)
            {
                src_reg->set_size(size);
                src = src_reg;
            }
            else if (src_const != nullptr)
            {
                src_const->set_size(size);
                src = src_const;
            }

            o << "\tmov " << dest_reg->get_asm_str() << ", " << src->get_asm_str() << "\n";
        } else if (dynamic_cast<IRReg*>(dest)) {
            o << "\tldr " << dest->get_asm_str() << ", " << src->get_asm_str() << "\n";
        }else {
            o << "\tstr " << src->get_asm_str() << ", " << dest->get_asm_str() << "\n";
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


