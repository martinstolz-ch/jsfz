/**
 * martin stolz - (c) noizplay.com
 */

#pragma once

#include <optional>

#include <JuceHeader.h>

#include "../common/simpleTypes.h"

#include "x3.h"
#include "ParserListener.h"
#include "parserRules.h"
#include "TokenMeta.h"
#include "SfzHeader.h"

namespace jsfz {

class Parser final {
public:
    explicit Parser (ParserListener& sequencer)
        : _sequencer {sequencer} {}

    ParsingResult process (const std::wstring& input) {

        // initialise sequencer & parser
        _beginIt = _parseIt = input.cbegin();

        // parse
        const auto parsingDone {x3::phrase_parse (

            // initialise iterators
            _parseIt,
            input.cend(),

            // parsing begin
            x3::eps [( [this] () {
                _sequencer.onParsingBegin();
            })] >>

            // grammar starts here...
            *(x3::lexeme [

                // a token begins here: staging tick and char position
                x3::eps [( [this] () {
                    _tokenStage.initialise();
                    _tokenStage.charPos = _currentParserPos();
                })] >>

                // ...sfz rules
                (

                    // header
                    headerRule[([this](const auto& context) {
                        // const auto& attr = static_cast<SfzHeader>(x3::_attr(context));
                        _sequencer.onHeader(x3::_attr(context));
                    })]

                ) >>

                // token end reached
                x3::eps [( [this] () {
                    _tokenStage.charLen = _currentParserPos() - _tokenStage.charPos;
                    _sequencer.onToken(_tokenStage);
                })]

            ]) >>

            // end of parsing
            x3::eps [( [this] () {
                _sequencer.onParsingEnd();
            })],

            // skipper
            x3_wide::space | commentSkipRule
        )};

        // evaluate processing result
        if (!parsingDone)
            return ParsingResult::failed;
        if (_parseIt != input.end())
            return ParsingResult::incomplete;
        return ParsingResult::complete;
    }

private:
    long _currentParserPos() const noexcept {
        return std::distance (_beginIt, _parseIt);
    }

    std::wstring::const_iterator _beginIt{};
    std::wstring::const_iterator _parseIt{};

    ParserListener& _sequencer;

    TokenMeta _tokenStage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Parser)
};

}
