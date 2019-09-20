#pragma once

namespace benri
{
#ifndef BENRI_PRECISION
using Precision = double;
#else
using Precision = BENRI_PRECISION;
#endif
//Fix for msvc. clang and gcc handle [[nodiscard]] just fine, even when not in c++17 mode,
//but msvc will not compile.
#ifdef _WIN32
#if __cplusplus >= 201703L
//Everything alright, nothing to do.
#else
//Remove the nodiscard attribute.
#define nodiscard
#endif
#endif
} // namespace benri