#include "ir-reg.h"

namespace IR
{
    IRReg * IRReg::set_size(Size size)
    {
        this->size = size;
        return this;
    }

    Size IRReg::get_size()
    {
        return size;
    }

    void IRRegA::gen_asm(ostream& o)
    {
        switch (get_size())
        {
        case Byte:
            o << "%al";
            break;
        case Word:
            o << "%ax";
            break;
        case DWord:
            o << "%eax";
            break;
        case QWord:
            o << "%rax";
            break;
        default:
            break;
        }
    }

    void IRRegB::gen_asm(ostream& o)
    {
        switch (get_size())
        {
        case Byte:
            o << "%bl";
            break;
        case Word:
            o << "%bx";
            break;
        case DWord:
            o << "%ebx";
            break;
        case QWord:
            o << "%rbx";
            break;
        default:
            break;
        }
    }

    void IRRegC::gen_asm(ostream& o)
    {
        switch (get_size())
        {
        case Byte:
            o << "%cl";
            break;
        case Word:
            o << "%cx";
            break;
        case DWord:
            o << "%ecx";
            break;
        case QWord:
            o << "%rcx";
            break;
        default:
            break;
        }
    }

    void IRRegD::gen_asm(ostream& o)
    {
        switch (get_size())
        {
        case Byte:
            o << "%dl";
            break;
        case Word:
            o << "%dx";
            break;
        case DWord:
            o << "%edx";
            break;
        case QWord:
            o << "%rdx";
            break;
        default:
            break;
        }
    }

    void IRRegStack::gen_asm(ostream& o)
    {
        o << "(%rbp)";
    }
}