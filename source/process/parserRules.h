/**
 * martin stolz - (c) noizplay.com
 */

#pragma once

#include "x3.h"
#include "parserSymbols.h"

namespace jsfz {

static const auto headerRule {SfzHeaderSymbols};
static const auto opCodeRule {x3_wide::string() >> *(x3::char_ - x3::eol) >> '=' >> *space >> value;};

static constexpr auto commentSkipRule {
    x3::omit [x3::lexeme [x3::lit(L"//") >> *(x3::char_ - x3::eol) >> (x3::eol | x3::eoi)]]
};

/*
// chord parameters
static const auto chordRootRule {noteOffsetSymbols};
static const auto chordQualityRule {chordQualitySymbols};
static const auto chordBassRule{x3::lexeme [x3_wide::lit (L'/') >> noteOffsetSymbols]};

// no chord
static const auto noChordRule {noChordSymbols};

// go forward aka play
static constexpr auto _8notePlayRule {x3_wide::lit (',')};
static constexpr auto _4notePlayRule {x3_wide::lit ('.')};
static constexpr auto fullBarsPlayRule {
    x3::lexeme [
        -(x3::uint_
            [([](auto& context) {
                if (x3::_attr (context) == 0) x3::_pass (context) = false;
            })]
        ) >>
        x3_wide::lit(L'%')]
};

// tempo
static constexpr auto bpmTempoRule  {x3::lexeme [x3::double_ >> x3_wide::lit (L"bpm")]};
static const     auto noteValueTempoRule {x3::lexeme [noteValueTempoSymbols >> x3::double_]};

// time signature
static constexpr auto timeSigRule {x3::lexeme [x3::uint_ >> x3_wide::lit (L'/') >> x3::uint_]};
static constexpr auto timeSigAccentGroupsRule {
    x3::lexeme [x3_wide::lit (L'(') >> x3::uint_ >> *((x3_wide::lit(L'.') | x3_wide::lit(L'+')) >> x3::uint_) >> x3_wide::lit (L')')]
};

// metronome mute / unmute
static const auto metroMuteRule {metroMuteSymbols};


*/
}
