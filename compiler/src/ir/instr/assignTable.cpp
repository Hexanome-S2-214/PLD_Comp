#include "assignTable.h"
#include "mov.h"
#include "movb.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrAssignTable::gen_asm(ostream& o)
    {
        IR::SymbolT* symbol_casted = dynamic_cast<IR::SymbolT*>(symbol);
        if(symbol_casted == nullptr) {
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
                (new IRInstrMovb)
                    ->set_src((new IR::IRRegA)->set_size(IR::Byte))
                    ->set_dest(symbol)
            )->gen_asm(o);
        }
        return;
    }
}
