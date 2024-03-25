#include "ir-reg.h"

namespace IR
{
    Size IRReg::get_size()
    {
        return size;
    }

    void IRRegA::gen_asm_x86(ostream& o)
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

    void IRRegA::gen_asm_arm(ostream& o)
    {
        
    }

    void IRRegB::gen_asm_x86(ostream& o)
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

    void IRRegB::gen_asm_arm(ostream& o)
    {
        
    }

    void IRRegC::gen_asm_x86(ostream& o)
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

    void IRRegC::gen_asm_arm(ostream& o)
    {
        
    }

    void IRRegD::gen_asm_x86(ostream& o)
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

    void IRRegD::gen_asm_arm(ostream& o)
    {
        
    }

    void IRRegStack::gen_asm_x86(ostream& o)
    {
        o << "(%rbp)";
    }

    void IRRegStack::gen_asm_arm(ostream& o)
    {
        
    }
}