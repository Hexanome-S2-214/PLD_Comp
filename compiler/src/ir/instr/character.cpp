#include "character.h"
#include "movb.h"
#include "../ir-basic-block.h"
#include "../ir-cfg.h"
#include "../params/ir-reg.h"

namespace IR
{
    void IRInstrCharacter::gen_asm(ostream& o)
    {
        paste_properties(
            (new IRInstrMovb)
                ->set_src(value)
                ->set_dest((new IR::IRRegA)->set_size(IR::Byte))
        )->gen_asm(o);
    }
}