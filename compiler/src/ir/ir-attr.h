#pragma once

#include <string>
#include "params/ir-param.h"
#include "params/ir-symbol.h"
#include "ir-type.h"

using namespace std;

namespace IR
{
    template <class Ref>
    class IRAttrSrc
    {
    public:
        ~IRAttrSrc() {
            if (src != nullptr)
                delete src;
        }

        Ref* set_src(IRParam * src) {
            if (src == nullptr)
            {
                this->src = nullptr;
                return static_cast<Ref*>(this);
            }

            src->set_parent(static_cast<Ref*>(this));
            this->src = src;
            return static_cast<Ref*>(this);
        }

        IRParam * get_src() {
            return src;
        }
    protected:
        IRParam * src;
    };

    template <class Ref>
    class IRAttrDest
    {
    public:
        ~IRAttrDest() {
            if (dest != nullptr)
                delete dest;
        }
        
        Ref * set_dest(IRParam * dest) {
            if (dest == nullptr)
            {
                this->dest = nullptr;
                return static_cast<Ref*>(this);
            }

            dest->set_parent(static_cast<Ref*>(this));
            this->dest = dest;
            return static_cast<Ref*>(this);
        }

        IRParam * get_dest() {
            return dest;
        }
    protected:
        IRParam * dest;
    };

    template <class Ref>
    class IRAttrValue
    {
    public:
        ~IRAttrValue() {
            if (value != nullptr)
                delete value;
        }

        Ref * set_value(IRParam * value) {
            if (value == nullptr)
            {
                this->value = nullptr;
                return static_cast<Ref*>(this);
            }

            value->set_parent(static_cast<Ref*>(this));
            this->value = value;
            return static_cast<Ref*>(this);
        }

        IRParam * get_value() {
            return value;
        }
    protected:
        IRParam * value;
    };

    template <class Ref>
    class IRAttrSymbol
    {
    public:
        ~IRAttrSymbol() {
            if (symbol != nullptr)
                delete symbol;
        }
        
        Ref * set_symbol(Symbol * symbol) {
            if (symbol == nullptr)
            {
                this->symbol = nullptr;
                return static_cast<Ref*>(this);
            }
            
            symbol->set_parent(static_cast<Ref*>(this));
            this->symbol = symbol;
            return static_cast<Ref*>(this);
        }

        Symbol * get_symbol() {
            return symbol;
        }
    protected:
        Symbol * symbol;
    };

    template <class Ref>
    class IRAttrLiteral
    {
    public:
        Ref * set_literal(string literal) {
            this->literal = literal;
            return static_cast<Ref*>(this);
        }

        string get_literal() {
            return literal;
        }
    protected:
        string literal;
    };

    template <class Ref>
    class IRAttrSize
    {
    public:
        Ref * set_size(Size size) {
            this->size = size;
            return static_cast<Ref*>(this);
        }

        Size get_size() {
            return size;
        }
    protected:
        Size size = DWord;
    };

    template <class Ref>
    class IRAttrOp
    {
    public:
        Ref * set_op(string op) {
            this->op = op;
            return static_cast<Ref*>(this);
        }

        string get_op() {
            return op;
        }
    protected:
        string op;
    };

    template<class Ref>
    class IRAttrLabel
    {
    public:
        Ref * set_label(string label) {
            this->label = label;
            return static_cast<Ref*>(this);
        }

        string get_label() {
            return label;
        }
    protected:
        string label;
    };

    template<class Ref>
    class IRAttrJump
    {
    public:
        Ref * set_jump(JumpType jump) {
            this->jump = jump;
            return static_cast<Ref*>(this);
        }

        JumpType get_jump() {
            return jump;
        }
    protected:
        JumpType jump;
    };

    template<class Ref>
    class IRAttrComment
    {
    public:
        Ref * set_comment(string comment) {
            this->comment = comment;
            return static_cast<Ref*>(this);
        }

        string get_comment() {
            return comment;
        }
    protected:
        string comment;
    };
}