#pragma once

namespace IR {
    enum IRArch {
        UNDEFINED,
        X86,
        ARM,
    };

    extern IRArch asm_arch;
}