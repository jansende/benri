#pragma once
#include <benri/si/system.h>
#include <benri/units/dimensions.h>
#include <benri/units/macros.h>
#include <benri/units/prefix.h>

namespace benri
{
namespace si
{
namespace data
{
#pragma region pixel(screen position)
implement_subunit(si, si, data, px, _px, dim::screen_position_t, prefix::one);
#pragma endregion
#pragma region pixel(screen area)
implement_subunit(si, si, data, pixel, _pixel, dim::screen_area_t, prefix::one);
implement_subunit(si, si, data, kilopixel, _kilopixel, dim::screen_area_t, prefix::kilo);
implement_subunit(si, si, data, megapixel, _megapixel, dim::screen_area_t, prefix::mega);
implement_subunit(si, si, data, gigapixel, _gigapixel, dim::screen_area_t, prefix::giga);
implement_subunit(si, si, data, terapixel, _terapixel, dim::screen_area_t, prefix::tera);
implement_subunit(si, si, data, petapixel, _petapixel, dim::screen_area_t, prefix::peta);
implement_subunit(si, si, data, exapixel, _exapixel, dim::screen_area_t, prefix::exa);
implement_subunit(si, si, data, zettapixel, _zettapixel, dim::screen_area_t, prefix::zetta);
implement_subunit(si, si, data, yottapixel, _yottapixel, dim::screen_area_t, prefix::yotta);
#pragma endregion
#pragma region bytes(amount of data)
implement_subunit(si, si, data, byte, _byte, dim::amount_of_data_t, prefix::one);
implement_subunit(si, si, data, kilobyte, _kilobyte, dim::amount_of_data_t, prefix::kilo);
implement_subunit(si, si, data, megabyte, _megabyte, dim::amount_of_data_t, prefix::mega);
implement_subunit(si, si, data, gigabyte, _gigabyte, dim::amount_of_data_t, prefix::giga);
implement_subunit(si, si, data, terabyte, _terabyte, dim::amount_of_data_t, prefix::tera);
implement_subunit(si, si, data, petabyte, _petabyte, dim::amount_of_data_t, prefix::peta);
implement_subunit(si, si, data, exabyte, _exabyte, dim::amount_of_data_t, prefix::exa);
implement_subunit(si, si, data, zettabyte, _zettabyte, dim::amount_of_data_t, prefix::zetta);
implement_subunit(si, si, data, yottabyte, _yottabyte, dim::amount_of_data_t, prefix::yotta);
implement_subunit(si, si, data, kibibyte, _kibibyte, dim::amount_of_data_t, prefix::kibi);
implement_subunit(si, si, data, mebibyte, _mibibyte, dim::amount_of_data_t, prefix::mebi);
implement_subunit(si, si, data, gibibyte, _gibibyte, dim::amount_of_data_t, prefix::gibi);
implement_subunit(si, si, data, tebibyte, _tibibyte, dim::amount_of_data_t, prefix::tebi);
implement_subunit(si, si, data, pebibyte, _pibibyte, dim::amount_of_data_t, prefix::pebi);
implement_subunit(si, si, data, exbibyte, _eibibyte, dim::amount_of_data_t, prefix::exbi);
implement_subunit(si, si, data, zebibyte, _zibibyte, dim::amount_of_data_t, prefix::zebi);
implement_subunit(si, si, data, yobibyte, _yibibyte, dim::amount_of_data_t, prefix::yobi);
#pragma endregion
#pragma region bits(amount of data)
implement_subunit(si, si, data, bit, _bit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::one>));
implement_subunit(si, si, data, kilobit, _kilobit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::kilo>));
implement_subunit(si, si, data, megabit, _megabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::mega>));
implement_subunit(si, si, data, gigabit, _gigabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::giga>));
implement_subunit(si, si, data, terabit, _terabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::tera>));
implement_subunit(si, si, data, petabit, _petabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::peta>));
implement_subunit(si, si, data, exabit, _exabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::exa>));
implement_subunit(si, si, data, zettabit, _zettabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::zetta>));
implement_subunit(si, si, data, yottabit, _yottabit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::yotta>));
implement_subunit(si, si, data, kibibit, _kibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::kibi>));
implement_subunit(si, si, data, mebibit, _mibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::mebi>));
implement_subunit(si, si, data, gibibit, _gibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::gibi>));
implement_subunit(si, si, data, tebibit, _tibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::tebi>));
implement_subunit(si, si, data, pebibit, _pibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::pebi>));
implement_subunit(si, si, data, exbibit, _eibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::exbi>));
implement_subunit(si, si, data, zebibit, _zibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::zebi>));
implement_subunit(si, si, data, yobibit, _yibibit, dim::amount_of_data_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::yobi>));
#pragma endregion
#pragma region bytes per second(bandwidth)
implement_subunit(si, si, data, byte_per_second, _byte_per_second, dim::data_bandwitdth_t, prefix::one);
implement_subunit(si, si, data, kilobyte_per_second, _kilobyte_per_second, dim::data_bandwitdth_t, prefix::kilo);
implement_subunit(si, si, data, megabyte_per_second, _megabyte_per_second, dim::data_bandwitdth_t, prefix::mega);
implement_subunit(si, si, data, gigabyte_per_second, _gigabyte_per_second, dim::data_bandwitdth_t, prefix::giga);
implement_subunit(si, si, data, terabyte_per_second, _terabyte_per_second, dim::data_bandwitdth_t, prefix::tera);
implement_subunit(si, si, data, petabyte_per_second, _petabyte_per_second, dim::data_bandwitdth_t, prefix::peta);
implement_subunit(si, si, data, exabyte_per_second, _exabyte_per_second, dim::data_bandwitdth_t, prefix::exa);
implement_subunit(si, si, data, zettabyte_per_second, _zettabyte_per_second, dim::data_bandwitdth_t, prefix::zetta);
implement_subunit(si, si, data, yottabyte_per_second, _yottabyte_per_second, dim::data_bandwitdth_t, prefix::yotta);
implement_subunit(si, si, data, kibibyte_per_second, _kibibyte_per_second, dim::data_bandwitdth_t, prefix::kibi);
implement_subunit(si, si, data, mebibyte_per_second, _mibibyte_per_second, dim::data_bandwitdth_t, prefix::mebi);
implement_subunit(si, si, data, gibibyte_per_second, _gibibyte_per_second, dim::data_bandwitdth_t, prefix::gibi);
implement_subunit(si, si, data, tebibyte_per_second, _tibibyte_per_second, dim::data_bandwitdth_t, prefix::tebi);
implement_subunit(si, si, data, pebibyte_per_second, _pibibyte_per_second, dim::data_bandwitdth_t, prefix::pebi);
implement_subunit(si, si, data, exbibyte_per_second, _eibibyte_per_second, dim::data_bandwitdth_t, prefix::exbi);
implement_subunit(si, si, data, zebibyte_per_second, _zibibyte_per_second, dim::data_bandwitdth_t, prefix::zebi);
implement_subunit(si, si, data, yobibyte_per_second, _yibibyte_per_second, dim::data_bandwitdth_t, prefix::yobi);
#pragma endregion
#pragma region bits per second(bandwidth)
implement_subunit(si, si, data, bit_per_second, _bit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::one>));
implement_subunit(si, si, data, kilobit_per_second, _kilobit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::kilo>));
implement_subunit(si, si, data, megabit_per_second, _megabit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::mega>));
implement_subunit(si, si, data, gigabit_per_second, _gigabit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::giga>));
implement_subunit(si, si, data, terabit_per_second, _terabit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::tera>));
implement_subunit(si, si, data, petabit_per_second, _petabit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::peta>));
implement_subunit(si, si, data, exabit_per_second, _exabit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::exa>));
implement_subunit(si, si, data, zettabit_per_second, _zettabit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::zetta>));
implement_subunit(si, si, data, yottabit_per_second, _yottabit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::yotta>));
implement_subunit(si, si, data, kibibit_per_second, _kibibit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::kibi>));
implement_subunit(si, si, data, mebibit_per_second, _mibibit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::mebi>));
implement_subunit(si, si, data, gibibit_per_second, _gibibit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::gibi>));
implement_subunit(si, si, data, tebibit_per_second, _tibibit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::tebi>));
implement_subunit(si, si, data, pebibit_per_second, _pibibit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::pebi>));
implement_subunit(si, si, data, exbibit_per_second, _eibibit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::exbi>));
implement_subunit(si, si, data, zebibit_per_second, _zibibit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::zebi>));
implement_subunit(si, si, data, yobibit_per_second, _yibibit_per_second, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, prefix::yobi>));
#pragma endregion
#pragma region bytes per minute(bandwidth)
implement_subunit(si, si, data, byte_per_minute, _byte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::one, prefix::minute>));
implement_subunit(si, si, data, kilobyte_per_minute, _kilobyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::kilo, prefix::minute>));
implement_subunit(si, si, data, megabyte_per_minute, _megabyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::mega, prefix::minute>));
implement_subunit(si, si, data, gigabyte_per_minute, _gigabyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::giga, prefix::minute>));
implement_subunit(si, si, data, terabyte_per_minute, _terabyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::tera, prefix::minute>));
implement_subunit(si, si, data, petabyte_per_minute, _petabyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::peta, prefix::minute>));
implement_subunit(si, si, data, exabyte_per_minute, _exabyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::exa, prefix::minute>));
implement_subunit(si, si, data, zettabyte_per_minute, _zettabyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::zetta, prefix::minute>));
implement_subunit(si, si, data, yottabyte_per_minute, _yottabyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::yotta, prefix::minute>));
implement_subunit(si, si, data, kibibyte_per_minute, _kibibyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::kibi, prefix::minute>));
implement_subunit(si, si, data, mebibyte_per_minute, _mibibyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::mebi, prefix::minute>));
implement_subunit(si, si, data, gibibyte_per_minute, _gibibyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::gibi, prefix::minute>));
implement_subunit(si, si, data, tebibyte_per_minute, _tibibyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::tebi, prefix::minute>));
implement_subunit(si, si, data, pebibyte_per_minute, _pibibyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::pebi, prefix::minute>));
implement_subunit(si, si, data, exbibyte_per_minute, _eibibyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::exbi, prefix::minute>));
implement_subunit(si, si, data, zebibyte_per_minute, _zibibyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::zebi, prefix::minute>));
implement_subunit(si, si, data, yobibyte_per_minute, _yibibyte_per_minute, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::yobi, prefix::minute>));
#pragma endregion
#pragma region bits per minute(bandwidth)
implement_subunit(si, si, data, bit_per_minute, _bit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::one, prefix::minute>>));
implement_subunit(si, si, data, kilobit_per_minute, _kilobit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::kilo, prefix::minute>>));
implement_subunit(si, si, data, megabit_per_minute, _megabit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::mega, prefix::minute>>));
implement_subunit(si, si, data, gigabit_per_minute, _gigabit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::giga, prefix::minute>>));
implement_subunit(si, si, data, terabit_per_minute, _terabit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::tera, prefix::minute>>));
implement_subunit(si, si, data, petabit_per_minute, _petabit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::peta, prefix::minute>>));
implement_subunit(si, si, data, exabit_per_minute, _exabit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::exa, prefix::minute>>));
implement_subunit(si, si, data, zettabit_per_minute, _zettabit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::zetta, prefix::minute>>));
implement_subunit(si, si, data, yottabit_per_minute, _yottabit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::yotta, prefix::minute>>));
implement_subunit(si, si, data, kibibit_per_minute, _kibibit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::kibi, prefix::minute>>));
implement_subunit(si, si, data, mebibit_per_minute, _mibibit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::mebi, prefix::minute>>));
implement_subunit(si, si, data, gibibit_per_minute, _gibibit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::gibi, prefix::minute>>));
implement_subunit(si, si, data, tebibit_per_minute, _tibibit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::tebi, prefix::minute>>));
implement_subunit(si, si, data, pebibit_per_minute, _pibibit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::pebi, prefix::minute>>));
implement_subunit(si, si, data, exbibit_per_minute, _eibibit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::exbi, prefix::minute>>));
implement_subunit(si, si, data, zebibit_per_minute, _zibibit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::zebi, prefix::minute>>));
implement_subunit(si, si, data, yobibit_per_minute, _yibibit_per_minute, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::yobi, prefix::minute>>));
#pragma endregion
#pragma region bytes per hour(bandwidth)
implement_subunit(si, si, data, byte_per_hour, _byte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::one, prefix::hour>));
implement_subunit(si, si, data, kilobyte_per_hour, _kilobyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::kilo, prefix::hour>));
implement_subunit(si, si, data, megabyte_per_hour, _megabyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::mega, prefix::hour>));
implement_subunit(si, si, data, gigabyte_per_hour, _gigabyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::giga, prefix::hour>));
implement_subunit(si, si, data, terabyte_per_hour, _terabyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::tera, prefix::hour>));
implement_subunit(si, si, data, petabyte_per_hour, _petabyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::peta, prefix::hour>));
implement_subunit(si, si, data, exabyte_per_hour, _exabyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::exa, prefix::hour>));
implement_subunit(si, si, data, zettabyte_per_hour, _zettabyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::zetta, prefix::hour>));
implement_subunit(si, si, data, yottabyte_per_hour, _yottabyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::yotta, prefix::hour>));
implement_subunit(si, si, data, kibibyte_per_hour, _kibibyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::kibi, prefix::hour>));
implement_subunit(si, si, data, mebibyte_per_hour, _mibibyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::mebi, prefix::hour>));
implement_subunit(si, si, data, gibibyte_per_hour, _gibibyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::gibi, prefix::hour>));
implement_subunit(si, si, data, tebibyte_per_hour, _tibibyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::tebi, prefix::hour>));
implement_subunit(si, si, data, pebibyte_per_hour, _pibibyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::pebi, prefix::hour>));
implement_subunit(si, si, data, exbibyte_per_hour, _eibibyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::exbi, prefix::hour>));
implement_subunit(si, si, data, zebibyte_per_hour, _zibibyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::zebi, prefix::hour>));
implement_subunit(si, si, data, yobibyte_per_hour, _yibibyte_per_hour, dim::data_bandwitdth_t, fix(impl::divide_lists_t<prefix::yobi, prefix::hour>));
#pragma endregion
#pragma region bits per hour(bandwidth)
implement_subunit(si, si, data, bit_per_hour, _bit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::one, prefix::hour>>));
implement_subunit(si, si, data, kilobit_per_hour, _kilobit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::kilo, prefix::hour>>));
implement_subunit(si, si, data, megabit_per_hour, _megabit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::mega, prefix::hour>>));
implement_subunit(si, si, data, gigabit_per_hour, _gigabit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::giga, prefix::hour>>));
implement_subunit(si, si, data, terabit_per_hour, _terabit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::tera, prefix::hour>>));
implement_subunit(si, si, data, petabit_per_hour, _petabit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::peta, prefix::hour>>));
implement_subunit(si, si, data, exabit_per_hour, _exabit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::exa, prefix::hour>>));
implement_subunit(si, si, data, zettabit_per_hour, _zettabit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::zetta, prefix::hour>>));
implement_subunit(si, si, data, yottabit_per_hour, _yottabit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::yotta, prefix::hour>>));
implement_subunit(si, si, data, kibibit_per_hour, _kibibit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::kibi, prefix::hour>>));
implement_subunit(si, si, data, mebibit_per_hour, _mibibit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::mebi, prefix::hour>>));
implement_subunit(si, si, data, gibibit_per_hour, _gibibit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::gibi, prefix::hour>>));
implement_subunit(si, si, data, tebibit_per_hour, _tibibit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::tebi, prefix::hour>>));
implement_subunit(si, si, data, pebibit_per_hour, _pibibit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::pebi, prefix::hour>>));
implement_subunit(si, si, data, exbibit_per_hour, _eibibit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::exbi, prefix::hour>>));
implement_subunit(si, si, data, zebibit_per_hour, _zibibit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::zebi, prefix::hour>>));
implement_subunit(si, si, data, yobibit_per_hour, _yibibit_per_hour, dim::data_bandwitdth_t, fix(impl::multiply_lists_t<make_fraction_list_t<1, 8>, impl::divide_lists_t<prefix::yobi, prefix::hour>>));
#pragma endregion
} // namespace data
#pragma region symbols
namespace symbol
{
#pragma region prefixes
create_symbol(si, kibi, dim::dimensionless_t, prefix::kibi);
create_symbol(si, mebi, dim::dimensionless_t, prefix::mebi);
create_symbol(si, gibi, dim::dimensionless_t, prefix::gibi);
create_symbol(si, tebi, dim::dimensionless_t, prefix::tebi);
create_symbol(si, pebi, dim::dimensionless_t, prefix::pebi);
create_symbol(si, exbi, dim::dimensionless_t, prefix::exbi);
create_symbol(si, zebi, dim::dimensionless_t, prefix::zebi);
create_symbol(si, yobi, dim::dimensionless_t, prefix::yobi);
#pragma endregion
} // namespace symbol
#pragma endregion
} // namespace si
} // namespace benri