/**
 * martin stolz - (c) noizplay.com
 */

#pragma once

namespace jsfz {

struct TokenMeta {
    long charPos{0};
    long charLen{0};

    void initialise() noexcept {
        charPos = 0;
        charLen = 0;
    }
};

}