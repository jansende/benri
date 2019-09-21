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
create_constant(sakura, prefix::sakura_t, typename decltype(centi * metre / second)::unit_type);
} // namespace constant
#pragma endregion
#pragma region symbols
namespace symbol
{
create_symbol(sakura, dimension::velocity_t, fix(type::multiply_lists<prefix::centi_t, prefix::sakura_t>));
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri