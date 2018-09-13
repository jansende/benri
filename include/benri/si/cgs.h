#pragma once
#include <benri/si/system.h>
#include <benri/units/dimensions.h>
#include <benri/units/macros.h>
#include <benri/units/prefix.h>

namespace benri
{
namespace si
{
namespace cgs
{
#pragma region gal(acceleration)
implement_subunit(si, si, cgs, yoctogal, _yoctogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::deci>));
implement_subunit(si, si, cgs, zeptogal, _zeptogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::deci>));
implement_subunit(si, si, cgs, attogal, _attogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::atto, prefix::deci>));
implement_subunit(si, si, cgs, femtogal, _femtogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::femto, prefix::deci>));
implement_subunit(si, si, cgs, picogal, _picogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::pico, prefix::deci>));
implement_subunit(si, si, cgs, nanogal, _nanogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::nano, prefix::deci>));
implement_subunit(si, si, cgs, microgal, _microgal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::micro, prefix::deci>));
implement_subunit(si, si, cgs, milligal, _milligal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::milli, prefix::deci>));
link_unit(centigal, _centigal, millimetre_per_square_second);
link_unit(decigal, _decigal, centimetre_per_square_second);
link_unit(gal, _gal, decimetre_per_square_second);
link_unit(decagal, _decagal, metre_per_square_second);
link_unit(hectogal, _hectogal, decametre_per_square_second);
link_unit(kilogal, _kilogal, hectometre_per_square_second);
implement_subunit(si, si, cgs, megagal, _megagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::mega, prefix::deci>));
implement_subunit(si, si, cgs, gigagal, _gigagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::giga, prefix::deci>));
implement_subunit(si, si, cgs, teragal, _teragal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::tera, prefix::deci>));
implement_subunit(si, si, cgs, petagal, _petagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::peta, prefix::deci>));
implement_subunit(si, si, cgs, exagal, _exagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::exa, prefix::deci>));
implement_subunit(si, si, cgs, zettagal, _zettagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::deci>));
implement_subunit(si, si, cgs, yottagal, _yottagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::deci>));
#pragma endregion
} // namespace cgs
} // namespace si
} // namespace benri