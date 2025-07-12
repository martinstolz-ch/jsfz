/**
 * martin stolz - (c) noizplay.com
 */

#pragma once

#include <boost/spirit/home/x3.hpp>
#include <boost/fusion/include/at_c.hpp>

namespace jsfz {

namespace x3      = boost::spirit::x3;
namespace x3_wide = x3::standard_wide; // ...for wide / unicode strings...
namespace fusion  = boost::fusion;

}