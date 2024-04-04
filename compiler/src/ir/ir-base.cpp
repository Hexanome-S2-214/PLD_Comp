#include <sstream>
#include "ir-base.h"
#include "ir-cfg.h"
#include "ir-basic-block.h"
#include "ir-instr.h"

using namespace std;

namespace IR
{
    IRBase::IRBase() : parent(nullptr), arch(ARM), ctx(nullptr), error_reporter(nullptr) {}

    void IRBase::gen_asm(ostream& o){
        switch(arch){
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

    IRBase * IRBase::set_arch(IRArch arch)
    {
        this->arch = arch;

        return this;
    }

    IRBase * IRBase::set_ctx(antlr4::ParserRuleContext * ctx)
    {
        this->ctx = ctx;

        return this;
    }

    IRBase * IRBase::set_error_reporter(ErrorReporter::ErrorReporter * error_reporter)
    {
        this->error_reporter = error_reporter;

        return this;
    }

    IRBase * IRBase::set_parent(IRBase * parent)
    {
        this->parent = parent;

        this->arch = parent->arch;

        if (this->ctx == nullptr)
            this->ctx = parent->ctx;

        if (this->error_reporter == nullptr)
            this->error_reporter = parent->error_reporter;

        return this;
    }

    IRBase * IRBase::paste_properties(IRBase * other)
    {
        other->set_arch(arch);
        other->set_ctx(ctx);
        other->set_error_reporter(error_reporter);
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

    ErrorReporter::ErrorReporter * IRBase::get_error_reporter()
    {
        return error_reporter;
    }
}
