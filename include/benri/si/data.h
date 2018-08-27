#pragma once
#include <benri/units/macros.h>
#include <benri/units/dimensions.h>
#include <benri/units/prefix.h>
#include <benri/units/systems.h>
#include <benri/quantity.h>

namespace benri
{
namespace data
{
using si::si;
#pragma region screen screen position
implement_unit(si, data, px, _px, dim::screen_position_t, prefix::one);
#pragma endregion
#pragma region screen screen resolution
implement_unit(si, data, pixel, _Pixel, dim::screen_resolution_t, prefix::one);
implement_unit(si, data, kilopixel, _kiloPixel, dim::screen_resolution_t, prefix::kilo);
implement_unit(si, data, megapixel, _MegaPixel, dim::screen_resolution_t, prefix::mega);
implement_unit(si, data, gigapixel, _GigaPixel, dim::screen_resolution_t, prefix::giga);
implement_unit(si, data, terapixel, _TeraPixel, dim::screen_resolution_t, prefix::tera);
implement_unit(si, data, petapixel, _PetaPixel, dim::screen_resolution_t, prefix::peta);
implement_unit(si, data, exapixel, _ExaPixel, dim::screen_resolution_t, prefix::exa);
implement_unit(si, data, zettapixel, _ZettaPixel, dim::screen_resolution_t, prefix::zetta);
implement_unit(si, data, yottapixel, _YottaPixel, dim::screen_resolution_t, prefix::yotta);
#pragma endregion
#pragma region amount of data
//bytes
implement_unit(si, data, byte, _Byte, dim::amount_of_data_t, prefix::one);
implement_unit(si, data, kilobyte, _kiloByte, dim::amount_of_data_t, prefix::kilo);
implement_unit(si, data, megabyte, _MegaByte, dim::amount_of_data_t, prefix::mega);
implement_unit(si, data, gigabyte, _GigaByte, dim::amount_of_data_t, prefix::giga);
implement_unit(si, data, terabyte, _TeraByte, dim::amount_of_data_t, prefix::tera);
implement_unit(si, data, petabyte, _PetaByte, dim::amount_of_data_t, prefix::peta);
implement_unit(si, data, exabyte, _ExaByte, dim::amount_of_data_t, prefix::exa);
implement_unit(si, data, zettabyte, _ZettaByte, dim::amount_of_data_t, prefix::zetta);
implement_unit(si, data, yottabyte, _YottaByte, dim::amount_of_data_t, prefix::yotta);
implement_unit(si, data, kibibyte, _KibiByte, dim::amount_of_data_t, prefix::kibi);
implement_unit(si, data, mebibyte, _MibiByte, dim::amount_of_data_t, prefix::mebi);
implement_unit(si, data, gibibyte, _GibiByte, dim::amount_of_data_t, prefix::gibi);
implement_unit(si, data, tebibyte, _TibiByte, dim::amount_of_data_t, prefix::tebi);
implement_unit(si, data, pebibyte, _PibiByte, dim::amount_of_data_t, prefix::pebi);
implement_unit(si, data, exbibyte, _EibiByte, dim::amount_of_data_t, prefix::exbi);
implement_unit(si, data, zebibyte, _ZibiByte, dim::amount_of_data_t, prefix::zebi);
implement_unit(si, data, yobibyte, _YibiByte, dim::amount_of_data_t, prefix::yobi);
//bits
implement_unit(si, data, bit, _bit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::one>));
implement_unit(si, data, kilobit, _kilobit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::kilo>));
implement_unit(si, data, megabit, _Megabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::mega>));
implement_unit(si, data, gigabit, _Gigabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::giga>));
implement_unit(si, data, terabit, _Terabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::tera>));
implement_unit(si, data, petabit, _Petabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::peta>));
implement_unit(si, data, exabit, _Exabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::exa>));
implement_unit(si, data, zettabit, _Zettabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::zetta>));
implement_unit(si, data, yottabit, _Yottabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::yotta>));
implement_unit(si, data, kibibit, _Kibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::kibi>));
implement_unit(si, data, mebibit, _Mibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::mebi>));
implement_unit(si, data, gibibit, _Gibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::gibi>));
implement_unit(si, data, tebibit, _Tibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::tebi>));
implement_unit(si, data, pebibit, _Pibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::pebi>));
implement_unit(si, data, exbibit, _Eibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::exbi>));
implement_unit(si, data, zebibit, _Zibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::zebi>));
implement_unit(si, data, yobibit, _Yibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::yobi>));
#pragma endregion
#pragma region datarate
//bytes
implement_unit(si, data, byte_per_second, _Byte_per_second, dim::datarate_t, prefix::one);
implement_unit(si, data, kilobyte_per_second, _kiloByte_per_second, dim::datarate_t, prefix::kilo);
implement_unit(si, data, megabyte_per_second, _MegaByte_per_second, dim::datarate_t, prefix::mega);
implement_unit(si, data, gigabyte_per_second, _GigaByte_per_second, dim::datarate_t, prefix::giga);
implement_unit(si, data, terabyte_per_second, _TeraByte_per_second, dim::datarate_t, prefix::tera);
implement_unit(si, data, petabyte_per_second, _PetaByte_per_second, dim::datarate_t, prefix::peta);
implement_unit(si, data, exabyte_per_second, _ExaByte_per_second, dim::datarate_t, prefix::exa);
implement_unit(si, data, zettabyte_per_second, _ZettaByte_per_second, dim::datarate_t, prefix::zetta);
implement_unit(si, data, yottabyte_per_second, _YottaByte_per_second, dim::datarate_t, prefix::yotta);
implement_unit(si, data, kibibyte_per_second, _KibiByte_per_second, dim::datarate_t, prefix::kibi);
implement_unit(si, data, mebibyte_per_second, _MibiByte_per_second, dim::datarate_t, prefix::mebi);
implement_unit(si, data, gibibyte_per_second, _GibiByte_per_second, dim::datarate_t, prefix::gibi);
implement_unit(si, data, tebibyte_per_second, _TibiByte_per_second, dim::datarate_t, prefix::tebi);
implement_unit(si, data, pebibyte_per_second, _PibiByte_per_second, dim::datarate_t, prefix::pebi);
implement_unit(si, data, exbibyte_per_second, _EibiByte_per_second, dim::datarate_t, prefix::exbi);
implement_unit(si, data, zebibyte_per_second, _ZibiByte_per_second, dim::datarate_t, prefix::zebi);
implement_unit(si, data, yobibyte_per_second, _YibiByte_per_second, dim::datarate_t, prefix::yobi);
//bits
implement_unit(si, data, bit_per_second, _bit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::one>));
implement_unit(si, data, kilobit_per_second, _kilobit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::kilo>));
implement_unit(si, data, megabit_per_second, _Megabit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::mega>));
implement_unit(si, data, gigabit_per_second, _Gigabit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::giga>));
implement_unit(si, data, terabit_per_second, _Terabit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::tera>));
implement_unit(si, data, petabit_per_second, _Petabit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::peta>));
implement_unit(si, data, exabit_per_second, _Exabit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::exa>));
implement_unit(si, data, zettabit_per_second, _Zettabit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::zetta>));
implement_unit(si, data, yottabit_per_second, _Yottabit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::yotta>));
implement_unit(si, data, kibibit_per_second, _Kibibit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::kibi>));
implement_unit(si, data, mebibit_per_second, _Mibibit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::mebi>));
implement_unit(si, data, gibibit_per_second, _Gibibit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::gibi>));
implement_unit(si, data, tebibit_per_second, _Tibibit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::tebi>));
implement_unit(si, data, pebibit_per_second, _Pibibit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::pebi>));
implement_unit(si, data, exbibit_per_second, _Eibibit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::exbi>));
implement_unit(si, data, zebibit_per_second, _Zibibit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::zebi>));
implement_unit(si, data, yobibit_per_second, _Yibibit_per_second, dim::datarate_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::yobi>));
#pragma endregion
} // namespace data
} // namespace benri