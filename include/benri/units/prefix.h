#pragma once
#include <benri/quantity.h>
#include <benri/unit.h>
#include <benri/impl/list.h>
namespace benri
{
namespace prefix
{
#pragma region si prefixes
using yocto = impl::multiply_lists_t<make_fraction_list_t<1, 1000000000000000>, make_fraction_list_t<1, 1000000000>>;
using zepto = impl::multiply_lists_t<make_fraction_list_t<1, 1000000000000000>, make_fraction_list_t<1, 1000000>>;
using atto = impl::multiply_lists_t<make_fraction_list_t<1, 1000000000000000>, make_fraction_list_t<1, 1000>>;
using femto = make_fraction_list_t<1, 1000000000000000>;
using pico = make_fraction_list_t<1, 1000000000000>;
using nano = make_fraction_list_t<1, 1000000000>;
using micro = make_fraction_list_t<1, 1000000>;
using milli = make_fraction_list_t<1, 1000>;
using centi = make_fraction_list_t<1, 100>;
using deci = make_fraction_list_t<1, 10>;
using one = make_fraction_list_t<>;
using deca = make_fraction_list_t<10>;
using hecto = make_fraction_list_t<100>;
using kilo = make_fraction_list_t<1000>;
using mega = make_fraction_list_t<1000000>;
using giga = make_fraction_list_t<1000000000>;
using tera = make_fraction_list_t<1000000000000>;
using peta = make_fraction_list_t<1000000000000000>;
using exa = impl::multiply_lists_t<make_fraction_list_t<1000000000000000>, make_fraction_list_t<1000>>;
using zetta = impl::multiply_lists_t<make_fraction_list_t<1000000000000000>, make_fraction_list_t<1000000>>;
using yotta = impl::multiply_lists_t<make_fraction_list_t<1000000000000000>, make_fraction_list_t<1000000000>>;
#pragma endregion
#pragma region data prefixes
using kibi = make_fraction_list_t<1024>;
using mebi = make_fraction_list_t<1048576>;
using gibi = make_fraction_list_t<1073741824>;
using tebi = make_fraction_list_t<1099511627776>;
using pebi = make_fraction_list_t<1125899906842624>;
using exbi = impl::multiply_lists_t<pebi, kibi>;
using zebi = impl::multiply_lists_t<pebi, mebi>;
using yobi = impl::multiply_lists_t<pebi, gibi>;
#pragma endregion
#pragma region time prefixes
using second = make_fraction_list_t<>;
using minute = impl::multiply_lists_t<second, make_fraction_list_t<60>>;
using hour = impl::multiply_lists_t<minute, make_fraction_list_t<60>>;
using day = impl::multiply_lists_t<hour, make_fraction_list_t<24>>;
using week = impl::multiply_lists_t<day, make_fraction_list_t<7>>;
using month = impl::multiply_lists_t<day, make_fraction_list_t<30>>;
using year = impl::multiply_lists_t<day, make_fraction_list_t<36525, 100>>;
#pragma endregion
#pragma region constants
using c = make_fraction_list_t<299792458>;
using k = impl::multiply_lists_t<make_fraction_list_t<138064852, 100000000>, impl::multiply_lists_t<deca, yocto>>;
using G = impl::multiply_lists_t<make_fraction_list_t<667408, 100000>, impl::multiply_lists_t<deci, tera>>;
#pragma endregion
} // namespace prefix
} // namespace benri