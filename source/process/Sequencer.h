/**
 * martin stolz - (c) noizplay.com
 */

#pragma once

#include <JuceHeader.h>

#include "../common/simpleTypes.h"

#include "ParserListener.h"
#include "TokenMeta.h"
#include "SequencerState.h"

namespace jsfz {

class Sequencer final
    : public ParserListener {

public:
    explicit Sequencer() = default;
    ~Sequencer() override = default;

    // event handler
    void onParsingBegin() override {
        DBG("Parsing started");
    }

    void onParsingEnd() override {
        DBG("Parsing ended");
    }

    void onToken(TokenMeta& /*token*/) override {
        DBG("Token");
    }

    void onHeader(const SfzHeader header) override {
        DBG("header: " << val(header));
    }

private:
    SequencerState                _seqState{};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Sequencer)
};

}
