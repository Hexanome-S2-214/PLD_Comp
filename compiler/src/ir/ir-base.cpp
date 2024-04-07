#include <sstream>
#include "ir-base.h"
#include "ir-cfg.h"
#include "ir-basic-block.h"
#include "ir-instr.h"

using namespace std;

namespace IR
{
    IRBase::IRBase() : parent(nullptr), ctx(nullptr), error_reporter(nullptr) {}

    void IRBase::gen_asm(ostream& o){
        switch(asm_arch){
            case IR::IRArch::X86:
                gen_asm_x86(o);
                break;
            case IR::IRArch::ARM:
                gen_asm_arm(o);
                break;
            default:
                throw runtime_error("Undefined architecture");
        }
    }

    string IRBase::get_asm_str()
    {
        stringstream ss;

        gen_asm(ss);
        
        return ss.str();
    }

    IRBase * IRBase::set_ctx(antlr4::ParserRuleContext * ctx)
    {
        this->ctx = ctx;

        return this;
    }

    IRBase * IRBase::set_parent(IRBase * parent)
    {
        this->parent = parent;

        if (this->ctx == nullptr)
            this->ctx = parent->ctx;

        return this;
    }

    IRBase * IRBase::paste_properties(IRBase * other)
    {
        other->set_ctx(ctx);
        other->set_parent(parent);

        return other;
    }

    template<>
    IRBase * IRBase::get_parent()
    {
        return parent;
    }

    template<>
    CFG* IRBase::get_parent()
    {
        return dynamic_cast<CFG *>(parent);
    }

    template<>
    BasicBlock* IRBase::get_parent()
    {
        return dynamic_cast<BasicBlock *>(parent);
    }

    template<>
    IRInstr* IRBase::get_parent()
    {
        return dynamic_cast<IRInstr *>(parent);
    }

    antlr4::ParserRuleContext* IRBase::get_ctx()
    {
        return ctx;
    }
}
