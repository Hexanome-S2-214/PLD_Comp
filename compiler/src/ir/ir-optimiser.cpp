#include "ir-optimiser.h"
#include "ir-basic-block.h"
#include "instr/mov.h"

namespace IR
{
    bool optimise_mov(IRInstrMov *curr, IRInstrMov *next)
    {
        cerr << "optimise_mov " << curr->get_dest()->get_asm_str() << " - " << next->get_src()->get_asm_str() << endl;
        // if (curr->get_dest()->get_asm_str() == next->get_src()->get_asm_str())
        // {
        //     curr->set_dest(next->get_dest());
        //     next->set_src(nullptr);
        //     return true;
        // }

        if (typeid(*curr) == typeid(*next))
        {
            cerr << "\toptimise_mov " << curr->get_dest()->get_asm_str() << " - " << next->get_src()->get_asm_str() << endl;
            curr->set_dest(next->get_dest());
            next->set_src(nullptr);
            return true;
        }

        return false;
    }

    bool optimize_instr_pair(IRInstr *instr, IRInstr *next_instr)
    {
        if (typeid(*instr) == typeid(IRInstrMov) && typeid(*next_instr) == typeid(IRInstrMov))
        {
            IRInstrMov *curr = static_cast<IRInstrMov *>(instr);
            IRInstrMov *next = static_cast<IRInstrMov *>(next_instr);

            if (optimise_mov(curr, next))
            {
                return true;
            }
        }

        return false;
    }

    bool optimize_instr(IRInstr *instr)
    {
        if (typeid(*instr) == typeid(IRInstrMov))
        {
            IRInstrMov *mov = static_cast<IRInstrMov *>(instr);

            if (mov->get_src()->get_asm_str() == mov->get_dest()->get_asm_str())
            {
                return true;
            }
        }

        return false;
    }

    void optimize_bb(BasicBlock *bb)
    {
        int i = 0;
        vector<IRInstr *> *instrs = bb->get_instrs();

        while (i < instrs->size() - 1)
        {
            IRInstr *instr = instrs->at(i);
            IRInstr *next_instr = instrs->at(i + 1);

            if (optimize_instr_pair(instr, next_instr))
            {
                instrs->erase(instrs->begin() + i + 1);
            }

            i++;
        }

        i = 0;
        while (i < instrs->size())
        {
            IRInstr *instr = instrs->at(i);

            if (optimize_instr(instr))
            {
                instrs->erase(instrs->begin() + i);
            }

            i++;
        }
    }

    void IROptimiser::optimise(CFG *cfg)
    {
        for (BasicBlock *bb : cfg->get_blocks())
        {
            optimize_bb(bb);
        }
    }
}