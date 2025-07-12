/**
 * martin stolz - (c) noizplay.com
 */

#pragma once

#include "x3.h"
#include "SFZheader.h"

namespace jsfz {

using enum SfzHeader;
static const x3_wide::symbols <SfzHeader> SfzHeaderSymbols {
    {L"<global>", global}, {L"<Global>", global}, {L"<GLOBAL>", global},
    {L"<group>",  group},  {L"<Group>",  group},  {L"<GROUP>",  group},
    {L"<region>", region}, {L"<Region>", region}, {L"<REGION>", region},
    {L"<master>", master}, {L"<Master>", master}, {L"<MASTER>", master},
    {L"<curve>",  curve},  {L"<Curve>",  curve},  {L"<CURVE>",  curve},
    {L"<effect>", effect}, {L"<Effect>", effect}, {L"<EFFECT>", effect}
};

}
