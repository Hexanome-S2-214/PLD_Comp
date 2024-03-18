#include "assignTable.h"
#include "mov.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../ir-reg.h"

namespace IR
{
    void IRInstrAssignTable::gen_asm(ostream& o)
    {
        Symbol * symbol = this->get_bb()->get_cfg()->get_symbol_table()->get_symbol(this->id, get_ctx());
        SymbolT* symbolT = new SymbolT(symbol->get_parent(), symbol->id, symbol->offset, symbol->type, symbol->get_ctx(), index);

        paste_properties(
            (new IRInstrMov)
                ->set_src(IR::IRRegA(this).get_asm_str())
                ->set_dest(symbolT->get_asm_str())
        )->gen_asm(o);
    }
}
