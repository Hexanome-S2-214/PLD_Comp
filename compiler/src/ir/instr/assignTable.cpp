#include "assignTable.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrAssignTable::gen_asm_x86(ostream& o)
    {
        // o << ">>AssignTable" << std::endl;
        IR::Symbol* symbol_casted = dynamic_cast<IR::Symbol*>(symbol);
        if(symbol_casted == nullptr) {
            // o << "<<AssignTable" << std::endl;
            return;
        }

        if(symbol_casted->type == Int){
            paste_properties(
                (new IRInstrMov)
                    ->set_src(new IRRegA)
                    ->set_dest(symbol)
            )->gen_asm(o); 
        }else if(symbol_casted->type == ::IR::Char){
            paste_properties(
                (new IRInstrMov)
                    ->set_src((new IR::IRRegA)->set_size(IR::Byte))
                    ->set_dest(symbol)
            )->gen_asm(o);
        }
        // o << "<<AssignTable" << std::endl;
        return;
    }

    void IRInstrAssignTable::gen_asm_arm(ostream &o)
    {
    }
}