#pragma once

#include <string>
#include "ir-base.h"

using namespace std;

namespace IR
{
    class IRReg : public IRBase {
    public:
        IRReg() {};
        ~IRReg() = default;
    };

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

    class IRRegD : public IRReg
    {
    public:
        void gen_asm(ostream& o) override
        {
            o << "%edx";
        }
    };

    class IRRegStack : public IRReg
    {
    public:
        void gen_asm(ostream& o) override
        {
            o << "(%rbp)";
        }
    };
};
