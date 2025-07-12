/**
 * martin stolz - (c) noizplay.com
 */

#pragma once

#include "TokenMeta.h"
#include "SfzHeader.h"

namespace jsfz {

class ParserListener {
public:
    virtual ~ParserListener() = default;

    virtual void onParsingBegin() = 0;
    virtual void onParsingEnd() = 0;

    virtual void onHeader(SfzHeader header) = 0;

    virtual void onToken(TokenMeta& token) = 0;
};

}
