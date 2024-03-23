#pragma once

#include <string>

namespace IR
{
    struct Type
    {
        std::string name;
        int size;

        bool operator==(const Type& other) const
        {
            return name == other.name && size == other.size;
        }
    };

    const Type Int = {"Int", 4};
    const Type Bool = {"Bool", 1};
    const Type Char = {"Char", 1};

    enum Size
    {
        Byte = 8,
        Word = 16,
        DWord = 32,
        QWord = 64,
    };
};
