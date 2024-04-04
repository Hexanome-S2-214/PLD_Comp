#include "ir-cfg-set.h"

void IR::CfgSet::gen_asm_x86(ostream& o)
{
    for (auto cfg : cfgs) {
        cfg->gen_asm(o);
    }
}

void IR::CfgSet::gen_asm_arm(ostream& o)
{
    
}

void IR::CfgSet::set_current_cfg(IR::CFG * cfg)
{
    current_cfg = cfg;
}

IR::CFG * IR::CfgSet::get_current_cfg()
{
    return current_cfg;
}

IR::CFG * IR::CfgSet::get_cfg_by_fname(string fname) {
    for (auto cfg : cfgs) {
        if (cfg->get_fname() == fname) {
            return cfg;
        }
    }

    throw runtime_error("function not declared");
}

/** 
 * Adds CFG to the list of cfgs AND sets current_cfg to CFG passed as parameter
*/
void IR::CfgSet::add_cfg(IR::CFG * cfg)
{
    cfgs.push_back(cfg);
    set_current_cfg(cfg);
}