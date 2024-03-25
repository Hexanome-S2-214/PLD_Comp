#include "ir-cfg-set.h"

void IR::CfgSet::gen_asm(ostream& o)
{
    for (auto cfg : cfgs) {
        cfg->gen_asm(o);
    }
}

void IR::CfgSet::set_current_cfg(IR::CFG * cfg)
{
    current_cfg = cfg;
}

IR::CFG * IR::CfgSet::get_current_cfg()
{
    return current_cfg;
}

/** 
 * Adds CFG to the list of cfgs AND sets current_cfg to CFG passed as parameter
*/
void IR::CfgSet::add_cfg(IR::CFG * cfg)
{
    cfgs.push_back(cfg);
    set_current_cfg(cfg);
}