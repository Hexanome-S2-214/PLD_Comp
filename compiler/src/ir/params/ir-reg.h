#pragma once

#include "ir-param.h"
#include "../ir-type.h"
#include "../ir-attr.h"

using namespace std;

namespace IR
{
    class IRReg : public IRParam, public IRAttrSize<IRReg> {
    public:
        Size get_size() override;
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
        IRRegStack* set_offset(int offset);
    private:
        int offset = 0;
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
