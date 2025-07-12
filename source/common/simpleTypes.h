/**
 * martin stolz - (c) noizplay.com
 */

#pragma once

#include <type_traits>

namespace jsfz {

enum class ParsingResult {complete, undefined, failed, incomplete};

template<typename EnumType>
constexpr auto val(EnumType enumValue) noexcept
    -> std::enable_if_t<std::is_enum_v<EnumType>, std::underlying_type_t<EnumType>> {
    return static_cast<std::underlying_type_t<EnumType>>(enumValue);
}

}