#include "expression_var.h"
#include "mov.h"
#include "movb.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrExprVar::gen_asm(ostream& o)
    {
        IR::Symbol* symbol_casted = dynamic_cast<IR::Symbol*>(symbol);
        if(symbol_casted == nullptr) {
            return;
        }

        if(symbol_casted->type == ::IR::Int){
            paste_properties(
                (new IRInstrMov)
                    ->set_src(symbol)
                    ->set_dest(new IRRegA)
            )->gen_asm(o);
        }else if(symbol_casted->type == ::IR::Char){
            paste_properties(
                (new IRInstrMovb)
                    ->set_src(symbol)
                    ->set_dest((new IR::IRRegA)->set_size(IR::Byte))
            )->gen_asm(o);
        }
        return;
        
    }
}
