#pragma once

#include <string>

namespace IR
{
    enum Size
    {
        Byte = 8,
        Word = 16,
        DWord = 32,
        QWord = 64,
    };

    int to_bytes(Size size)
    {
        return size / 8;
    }

    struct Type
    {
        std::string name;
        Size size;

        bool operator==(const Type& other) const
        {
            return name == other.name && size == other.size;
        }
    };

    const Type Int = {"Int", DWord};
    const Type Bool = {"Bool", Byte};
    const Type Char = {"Char", Byte};
};
