#include "ir-cfg.h"
#include "ir-basic-block.h"
#include "ir-symbol-table.h"
#include "instr/epilogue.h"

int IR::CFG::bb_count = 2;

IR::CFG::CFG(string name)
{
    fname = name;
    nb_param = 0;

    symbol_table = new SymbolTable();

    //Create epilogue BB -> we store it apart from the other because we need to write it at the end
    epilogue_label = get_next_bb_label();
    this->epilogue_bb = new BasicBlock(this, epilogue_label, nullptr, nullptr);
    this->epilogue_bb->add_instr((new IR::IRInstrEpilogue));

    //Create BB to write beginning of the function in -> the order of the blocks doesn't matter since we store epilogue_label
    BasicBlock * new_bb = new BasicBlock(this, get_next_bb_label(), nullptr, nullptr);
    add_bb(new_bb);
}

IR::CFG::~CFG()
{
    delete symbol_table;

    for (BasicBlock * block : blocks)
    {
        delete block;
    }
}

IR::IRBase * IR::CFG::set_error_reporter(ErrorReporter::ErrorReporter * error_reporter)
{
    IRBase::set_error_reporter(error_reporter);
    symbol_table->error_reporter = error_reporter;

    return this;
}

void IR::CFG::gen_asm_x86(ostream& o)
{
    gen_asm_x86_prologue(o);

    for (auto block : blocks)
    {
        block->gen_asm_x86(o);
    }

    gen_asm_x86_epilogue(o);
}

void IR::CFG::gen_asm_arm(ostream& o)
{
    gen_asm_arm_prologue(o);

    for (auto block : blocks)
    {
        block->gen_asm_arm(o);
    }

    // gen_asm_arm_epilogue(o);
}

void IR::CFG::gen_asm_arm_prologue(ostream& o){
    o << ".globl main\n";
    o << "main:\n";
    o << "    push {fp, lr}\n";
    o << "    add fp, sp, #4\n";
}

// void IR::CFG::gen_asm_arm_epilogue(ostream& o){
//     o << "    pop {fp, pc}\n";
// }

void IR::CFG::gen_asm_x86_prologue(ostream& o)
{
    o << endl;
    o << ".globl " << fname << endl;
    o << fname << ":" << endl;
    o << "\tpushq %rbp\n" ;
    o << "\tmovq %rsp, %rbp\n" ;
    //TODO : handle this via an instr ?
    o << "\tsubq $" << calc_st_size() << ", %rsp" << endl;
}

void IR::CFG::gen_asm_x86_epilogue(ostream& o)
{
    this->epilogue_bb->gen_asm_x86(o);
}

int IR::CFG::calc_st_size() {
    int offset = symbol_table->get_symbol_offset();

    if (offset == 0) {
        return 0;
    } else {
        return ((-offset / 16)+1)*16;
    }
}

void IR::CFG::add_instr(IR::IRBase * instr)
{
    get_current_bb()->add_instr(instr);
}

IR::SymbolTable * IR::CFG::get_symbol_table()
{
    return symbol_table;
}

void IR::CFG::set_current_bb(IR::BasicBlock * bb)
{
    current_bb = bb;
}

string IR::CFG::get_fname() {
    return fname;
}

int IR::CFG::get_nb_param() {
    return nb_param;
}

void IR::CFG::incr_nb_param() {
    this->nb_param++;
    cerr << "nb param func : " << this->nb_param << endl;
}

IR::BasicBlock * IR::CFG::get_current_bb()
{
    return current_bb;
}

/**
 * Retourne la boucle la plus proche dans laquelle est le bloc passé en paramètre
 * Retourne une erreur sinon -> appelé lors des break/continue
 * @param label : label du block dont on veut l'indentation par rapport à une boucle
 * @return bloc "boucle"
*/
IR::BasicBlock * IR::CFG::get_loop_parent(string label) {
    std::stack<IR::BasicBlock *> ret_label;
    cerr << "entrée get_loop_parent" << endl;

    for (auto bb : blocks) {
        cerr << bb->get_bb_id() << endl;
        cerr << "1" << endl; 
        switch(bb->get_bb_id()) {
            case BB_WHILE:
                cerr << "psg while" << endl;
                ret_label.push(bb);
                break;
            
            case BB_END_WHILE:
                cerr << "psg end while" << endl;
                ret_label.pop();
                break;
            
            case 0:
                cerr << "instruction block" << endl;
        }
    }

    if (ret_label.empty()){
        throw runtime_error("break/continue must be used inside a loop");
    }

    return ret_label.top();
}

vector<IR::BasicBlock *> IR::CFG::get_blocks()
{
    return blocks;
}

string IR::CFG::get_next_bb_label()
{
    string label = ".L" + to_string(IR::CFG::bb_count);
    IR::CFG::bb_count++;
    return label;
}

string IR::CFG::get_epilogue_label() {
    return epilogue_label;
}

void IR::CFG::add_bb(IR::BasicBlock * bb)
{
    blocks.push_back(bb);
    set_current_bb(bb);
}

// IR::BasicBlock * IR::CFG::create_bb(IR::BasicBlock * exit_true, IR::BasicBlock * exit_false)
// {
//     string label = ".L" + to_string(IR::CFG::bb_count);
//     IR::CFG::bb_count++;

//     BasicBlock * new_bb = new BasicBlock(this, label, exit_true, exit_false);

//     blocks.push_back(new_bb);
//     current_bb = new_bb;
    
//     return new_bb;
// }