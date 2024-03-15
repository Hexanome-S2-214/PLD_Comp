#pragma once

#include <string>

using namespace std;

namespace IR
{
    template <class Ref>
    class IRInstrBaseSrc
    {
    public:
        Ref* set_src(string src) {
            this->src = src;
            return static_cast<Ref*>(this);
        }
    protected:
        string src;
    };

    template <class Ref>
    class IRInstrBaseDest
    {
    public:
        Ref * set_dest(string dest) {
            this->dest = dest;
            return static_cast<Ref*>(this);
        }
    protected:
        string dest;
    };

    template <class Ref>
    class IRInstrBaseId
    {
    public:
        Ref * set_id(string id) {
            this->id = id;
            return static_cast<Ref*>(this);
        }
    protected:
        string id;
    };

    template <class Ref>
    class IRInstrBaseValue
    {
    public:
        Ref * set_value(string value) {
            this->value = value;
            return static_cast<Ref*>(this);
        }
    protected:
        string value;
    };
}