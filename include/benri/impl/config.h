#pragma once

namespace benri
{
#ifndef BENRI_PRECISION
using Precision = double;
#else
using Precision = BENRI_PRECISION;
#endif
//The following is a fix for msvc: clang and gcc handle
//[[nodiscard]] just fine, even when not in c++17 mode,
//but msvc will not compile.
#ifdef _WIN32
#if __cplusplus >= 201703L
//everything alright, nothing to do
#else
//remove the nodiscard attribute
#define nodiscard
#endif
#endif
} // namespace benri