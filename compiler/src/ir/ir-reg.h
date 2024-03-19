#pragma once

#include <string>
#include "ir-base.h"

using namespace std;

namespace IR
{
    class IRReg : public IRBase {
    public:
        IRReg(IRBase * parent) {
            set_parent(parent);
        };
        ~IRReg() = default;
    };

    class IRRegA : public IRReg
    {
    public:
        IRRegA(IRBase * parent) : IRReg(parent) {};

        void gen_asm(ostream& o) override
        {
            o << "%eax";
        }
    };

    class IRRegB : public IRReg
    {
    public:
        IRRegB(IRBase * parent) : IRReg(parent) {};

        void gen_asm(ostream& o) override
        {
            o << "%ebx";
        }
    };

    class IRRegC : public IRReg
    {
    public:
        IRRegC(IRBase * parent) : IRReg(parent) {};

        void gen_asm(ostream& o) override
        {
            o << "%ecx";
        }
    };

    class IRRegD : public IRReg
    {
    public:
        IRRegD(IRBase * parent) : IRReg(parent) {};

        void gen_asm(ostream& o) override
        {
            o << "%edx";
        }
    };

    class IRRegStack : public IRReg
    {
    public:
        IRRegStack(IRBase * parent) : IRReg(parent) {};
        
        void gen_asm(ostream& o) override
        {
            o << "(%rbp)";
        }
    };

    class IRRegAL : public IRReg
    {
    public:
        IRRegAL(IRBase * parent) : IRReg(parent) {};
        
        void gen_asm(ostream& o) override
        {
            o << "%al";
        }
    };

    class IRRegEDI : public IRReg
    {
    public:
        IRRegEDI(IRBase * parent) : IRReg(parent) {};
        
        void gen_asm(ostream& o) override
        {
            o << "%edi";
        }
    };

    class IRRegESI : public IRReg
    {
    public:
        IRRegESI(IRBase * parent) : IRReg(parent) {};
        
        void gen_asm(ostream& o) override
        {
            o << "%esi";
        }
    };
};
