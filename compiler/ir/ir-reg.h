#pragma once

#include <string>
#include "ir-base.h"

using namespace std;

namespace IR
{
    class IRReg : public IRBase {};

    class IRRegA : public IRReg
    {
    public:
        void gen_asm(ostream& o) override
        {
            o << "%eax";
        }
    };

    class IRRegB : public IRReg
    {
    public:
        void gen_asm(ostream& o) override
        {
            o << "%ebx";
        }
    };

    class IRRegC : public IRReg
    {
    public:
        void gen_asm(ostream& o) override
        {
            o << "%ecx";
        }
    };

    class IRRegStack : public IRReg
    {
    public:
        void gen_asm(ostream& o) override
        {
            o << "(%esp)";
        }
    };

    IRRegA * reg_a = new IRRegA();
    IRRegB * reg_b = new IRRegB();
    IRRegC * reg_c = new IRRegC();
    IRRegStack * reg_stack = new IRRegStack();
};
