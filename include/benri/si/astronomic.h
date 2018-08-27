#pragma once
#include <benri/units/macros.h>
#include <benri/units/dimensions.h>
#include <benri/units/prefix.h>
#include <benri/units/systems.h>
#include <benri/quantity.h>

namespace benri
{
namespace astronomic
{
using si::si;
#pragma region distances
implement_unit(si, astronomic, astronomical_unit, _astronomical_unit, dim::length_t, make_fraction_list_t<149597870700>);
#pragma endregion
} // namespace astronomic
} // namespace benri