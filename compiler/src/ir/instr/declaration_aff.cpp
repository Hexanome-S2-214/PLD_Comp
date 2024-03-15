#include "declaration_aff.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

namespace IR
{
    void IRInstrDeclaAff::gen_asm(ostream& o)
    {
        Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->id, get_ctx());

        paste_properties(
            (new IRInstrMov())
                ->set_src(IR::IRRegA(this).get_asm_str())
                ->set_dest(symbol->get_asm_str())
        )->gen_asm(o);
    }
}
