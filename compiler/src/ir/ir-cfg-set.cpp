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

IR::Func * IR::CfgSet::declare_function(string name, antlr4::ParserRuleContext * ctx)
{
    if (functions.find(name) != functions.end()) {
        ErrorReporter::ErrorReporter::getInstance()->reportError(new ErrorReporter::CompilerErrorToken(
            ErrorReporter::ERROR,
            "function '" + name + "' already declared.",
            ctx
        ));
        ErrorReporter::ErrorReporter::getInstance()->reportError(new ErrorReporter::CompilerErrorToken(
            ErrorReporter::INFO,
            "other declaration of function '" + name + "' here:",
            functions[name].ctx
        ));

        return &functions[name];
    }

    bool used = name == "main";
    functions[name] = Func{name, used, ctx};

    return &functions[name];
}

vector<IR::Func *> IR::CfgSet::get_unused_functions()
{
    vector<IR::Func *> unused_functions;

    for (auto & [name, func] : functions) {
        if (!func.used) {
            unused_functions.push_back(&func);
        }
    }

    return unused_functions;
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