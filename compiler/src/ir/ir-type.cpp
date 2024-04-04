#include "ir-type.h"

namespace IR
{
    int type_to_bytes(Type * type)
    {
        return type->size / 8;
    }
    
    int size_to_bytes(Size size)
    {
        return size / 8;
    }
}