#pragma once

#include "ir-param.h"
#include "../ir-type.h"

using namespace std;

namespace IR
{
    class IRReg : public IRParam
    {
    public:
        IRReg * set_size(Size size);
        Size get_size();
    private:
        Size size = DWord;
    };

    class IRRegA : public IRReg
    {
    public:
        void gen_asm(ostream& o) override;
    };

    class IRRegB : public IRReg
    {
    public:
        void gen_asm(ostream& o) override;
    };

    class IRRegC : public IRReg
    {
    public:
        void gen_asm(ostream& o) override;
    };

    class IRRegD : public IRReg
    {
    public:
        void gen_asm(ostream& o) override;
    };

    class IRRegStack : public IRReg
    {
    public:
        void gen_asm(ostream& o) override;
    };

    class IRRegDest : public IRReg
    {
    public:
        void gen_asm(ostream& o) override;
    };

    class IRRegSrc : public IRReg
    {
    public:
        void gen_asm(ostream& o) override;
    };

    class IRReg8 : public IRReg
    {
    public:
        void gen_asm(ostream& o) override;
    };

    class IRReg9 : public IRReg
    {
    public:
        void gen_asm(ostream& o) override;
    };
};
