#pragma once
#include <benri/si/astronomic.h>
#include <benri/si/base.h>
#include <benri/si/cgs.h>
#include <benri/si/data.h>
#include <benri/si/dimensions.h>
#include <benri/si/imperial.h>
#include <benri/si/macros.h>
#include <benri/si/prefixes.h>
#include <benri/si/si.h>
#include <benri/si/temperature.h>

namespace benri
{
namespace si
{
#pragma region constants
namespace constant
{
constexpr auto sakura =
    make_constant<typename decltype(centi * metre / second)::unit_type, prefix::sakura_t>;
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
constexpr auto sakura =
    make_symbol<dimension::velocity_t,
                type::multiply_lists<prefix::centi_t, prefix::sakura_t>>;
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri