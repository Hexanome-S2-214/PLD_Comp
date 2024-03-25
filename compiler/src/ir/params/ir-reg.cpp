#include "ir-reg.h"

namespace IR
{
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
        if (offset != 0) {
           o << offset; 
        }
        o << "(%rbp)";
    }

    IRRegStack* IRRegStack::set_offset(int offset)
    {
        this->offset = offset;
        return this;
    }

    void IRRegDest::gen_asm(ostream& o)
    {
        switch (get_size())
        {
        case Byte:
            o << "%dil";
            break;
        case Word:
            o << "%di";
            break;
        case DWord:
            o << "%edi";
            break;
        case QWord:
            o << "%rdi";
            break;
        default:
            break;
        }
    }

    void IRRegSrc::gen_asm(ostream& o)
    {
        switch (get_size())
        {
        case Byte:
            o << "%sil";
            break;
        case Word:
            o << "%si";
            break;
        case DWord:
            o << "%esi";
            break;
        case QWord:
            o << "%rsi";
            break;
        default:
            break;
        }
    }

    void IRReg8::gen_asm(ostream& o)
    {
        switch (get_size())
        {
        case Byte:
            o << "%r8b";
            break;
        case Word:
            o << "%r8w";
            break;
        case DWord:
            o << "%r8d";
            break;
        case QWord:
            o << "%r8";
            break;
        default:
            break;
        }
    }

    void IRReg9::gen_asm(ostream& o)
    {
        switch (get_size())
        {
        case Byte:
            o << "%r9b";
            break;
        case Word:
            o << "%r9w";
            break;
        case DWord:
            o << "%r9d";
            break;
        case QWord:
            o << "%r9";
            break;
        default:
            break;
        }
    }
}