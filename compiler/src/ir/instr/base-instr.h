#pragma once

#include <string>
#include "../params/ir-param.h"

using namespace std;

namespace IR
{
    template <class Ref>
    class IRInstrBaseSrc
    {
    public:
        ~IRInstrBaseSrc() {
            delete src;
        }

        Ref* set_src(IRParam * src) {
            src->set_parent(static_cast<Ref*>(this));
            this->src = src;
            return static_cast<Ref*>(this);
        }
    protected:
        IRParam * src;
    };

    template <class Ref>
    class IRInstrBaseDest
    {
    public:
        ~IRInstrBaseDest() {
            delete dest;
        }
        
        Ref * set_dest(IRParam * dest) {
            dest->set_parent(static_cast<Ref*>(this));
            this->dest = dest;
            return static_cast<Ref*>(this);
        }
    protected:
        IRParam * dest;
    };

    template <class Ref>
    class IRInstrBaseValue
    {
    public:
        ~IRInstrBaseValue() {
            delete value;
        }

        Ref * set_value(IRParam * value) {
            value->set_parent(static_cast<Ref*>(this));
            this->value = value;
            return static_cast<Ref*>(this);
        }
    protected:
        IRParam * value;
    };

    template <class Ref>
    class IRInstrBaseSymbol
    {
    public:
        ~IRInstrBaseSymbol() {
            delete symbol;
        }
        
        Ref * set_symbol(IRParam * symbol) {
            symbol->set_parent(static_cast<Ref*>(this));
            this->symbol = symbol;
            return static_cast<Ref*>(this);
        }
    protected:
        IRParam * symbol;
    };

    template <class Ref>
    class IRInstrBaseOp
    {
    public:
        Ref * set_op(string op) {
            this->op = op;
            return static_cast<Ref*>(this);
        }
    protected:
        string op;
    };

    template<class Ref>
    class IRInstrBaseLabel
    {
    public:
        Ref * set_label(string label) {
            this->label = label;
            return static_cast<Ref*>(this);
        }
    protected:
        string label;
    };

    template<class Ref>
    class IRInstrBaseCall
    {
        public:
            Ref * set_call(string call) {
                this->call = call;
                return static_cast<Ref*>(this);
            }
        protected:
            string call;
    };
}