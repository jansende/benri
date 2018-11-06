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
implement_subunit(si, si, cgs, yoctogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::yocto, prefix::deci>));
implement_subunit(si, si, cgs, zeptogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::zepto, prefix::deci>));
implement_subunit(si, si, cgs, attogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::atto, prefix::deci>));
implement_subunit(si, si, cgs, femtogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::femto, prefix::deci>));
implement_subunit(si, si, cgs, picogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::pico, prefix::deci>));
implement_subunit(si, si, cgs, nanogal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::nano, prefix::deci>));
implement_subunit(si, si, cgs, microgal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::micro, prefix::deci>));
implement_subunit(si, si, cgs, milligal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::milli, prefix::deci>));
link_unit(centigal, millimetre_per_square_second);
link_unit(decigal, centimetre_per_square_second);
link_unit(gal, decimetre_per_square_second);
link_unit(decagal, metre_per_square_second);
link_unit(hectogal, decametre_per_square_second);
link_unit(kilogal, hectometre_per_square_second);
implement_subunit(si, si, cgs, megagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::mega, prefix::deci>));
implement_subunit(si, si, cgs, gigagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::giga, prefix::deci>));
implement_subunit(si, si, cgs, teragal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::tera, prefix::deci>));
implement_subunit(si, si, cgs, petagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::peta, prefix::deci>));
implement_subunit(si, si, cgs, exagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::exa, prefix::deci>));
implement_subunit(si, si, cgs, zettagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::zetta, prefix::deci>));
implement_subunit(si, si, cgs, yottagal, dim::acceleration_t, fix(impl::multiply_lists_t<prefix::yotta, prefix::deci>));
#pragma endregion
#pragma region poise(dynamic viscosity)
implement_subunit(si, si, cgs, yoctopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::yocto>));
implement_subunit(si, si, cgs, zeptopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::zepto>));
implement_subunit(si, si, cgs, attopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::atto>));
implement_subunit(si, si, cgs, femtopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::femto>));
implement_subunit(si, si, cgs, picopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::pico>));
implement_subunit(si, si, cgs, nanopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::nano>));
implement_subunit(si, si, cgs, micropoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::micro>));
implement_subunit(si, si, cgs, millipoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
link_unit(centipoise, millipascal_second);
link_unit(decipoise, centipascal_second);
link_unit(poise, decipascal_second);
link_unit(decapoise, pascal_second);
link_unit(hectopoise, decapascal_second);
link_unit(kilopoise, hectopascal_second);
implement_subunit(si, si, cgs, megapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::mega>));
implement_subunit(si, si, cgs, gigapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::giga>));
implement_subunit(si, si, cgs, terapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::tera>));
implement_subunit(si, si, cgs, petapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::peta>));
implement_subunit(si, si, cgs, exapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::exa>));
implement_subunit(si, si, cgs, zettapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::zetta>));
implement_subunit(si, si, cgs, yottapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::yotta>));
#pragma endregion
#pragma region maxwell(magnetic flux)
implement_subunit(si, si, cgs, yoctomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::zepto>));
implement_subunit(si, si, cgs, attomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::atto>));
implement_subunit(si, si, cgs, femtomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::femto>));
implement_subunit(si, si, cgs, picomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::pico>));
implement_subunit(si, si, cgs, nanomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::nano>));
implement_subunit(si, si, cgs, micromaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::micro>));
implement_subunit(si, si, cgs, millimaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::milli>));
implement_subunit(si, si, cgs, centimaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::centi>));
link_unit(decimaxwell, nanoweber);
implement_subunit(si, si, cgs, maxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::one>));
implement_subunit(si, si, cgs, decamaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::deca>));
link_unit(hectomaxwell, microweber);
implement_subunit(si, si, cgs, kilomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::kilo>));
link_unit(megamaxwell, centiweber);
link_unit(gigamaxwell, decaweber);
implement_subunit(si, si, cgs, teramaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::tera>));
implement_subunit(si, si, cgs, petamaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::peta>));
implement_subunit(si, si, cgs, examaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::exa>));
implement_subunit(si, si, cgs, zettamaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::zetta>));
implement_subunit(si, si, cgs, yottamaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::yotta>));
#pragma endregion
#pragma region gauss(magentic flux density)
implement_subunit(si, si, cgs, yoctogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::yocto>));
implement_subunit(si, si, cgs, zeptogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::zepto>));
implement_subunit(si, si, cgs, attogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::atto>));
implement_subunit(si, si, cgs, femtogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::femto>));
implement_subunit(si, si, cgs, picogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::pico>));
implement_subunit(si, si, cgs, nanogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::nano>));
implement_subunit(si, si, cgs, microgauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::micro>));
implement_subunit(si, si, cgs, milligauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::milli>));
link_unit(centigauss, microtesla);
implement_subunit(si, si, cgs, decigauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::deci>));
implement_subunit(si, si, cgs, gauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::one>));
link_unit(decagauss, millitesla);
link_unit(hectogauss, centitesla);
link_unit(kilogauss, decitesla);
link_unit(megagauss, hectotesla);
implement_subunit(si, si, cgs, gigagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::giga>));
implement_subunit(si, si, cgs, teragauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::tera>));
implement_subunit(si, si, cgs, petagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::peta>));
implement_subunit(si, si, cgs, exagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::exa>));
implement_subunit(si, si, cgs, zettagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::zetta>));
implement_subunit(si, si, cgs, yottagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::yotta>));
#pragma endregion
#pragma region erg(energy)
implement_subunit(si, si, cgs, yoctoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::zepto>));
implement_subunit(si, si, cgs, attoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::atto>));
implement_subunit(si, si, cgs, femtoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::femto>));
implement_subunit(si, si, cgs, picoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::pico>));
implement_subunit(si, si, cgs, nanoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::nano>));
implement_subunit(si, si, cgs, microerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::micro>));
implement_subunit(si, si, cgs, millierg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::milli>));
link_unit(centierg, nanojoule);
implement_subunit(si, si, cgs, decierg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::deci>));
implement_subunit(si, si, cgs, erg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::one>));
link_unit(decaerg, microjoule);
implement_subunit(si, si, cgs, hectoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::hecto>));
implement_subunit(si, si, cgs, kiloerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::kilo>));
link_unit(megaerg, decijoule);
link_unit(gigaerg, hectojoule);
implement_subunit(si, si, cgs, teraerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::tera>));
implement_subunit(si, si, cgs, petaerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::peta>));
implement_subunit(si, si, cgs, exaerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::exa>));
implement_subunit(si, si, cgs, zettaerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::zetta>));
implement_subunit(si, si, cgs, yottaerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::yotta>));
#pragma endregion
#pragma region erg/g(specific energy)
implement_subunit(si, si, cgs, yoctoerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptoerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::zepto>));
implement_subunit(si, si, cgs, attoerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::atto>));
implement_subunit(si, si, cgs, femtoerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::femto>));
implement_subunit(si, si, cgs, picoerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::pico>));
implement_subunit(si, si, cgs, nanoerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::nano>));
implement_subunit(si, si, cgs, microerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::micro>));
implement_subunit(si, si, cgs, millierg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::milli>));
link_unit(centierg_per_gram, picogray);
implement_subunit(si, si, cgs, decierg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::deci>));
implement_subunit(si, si, cgs, erg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::one>));
link_unit(decaerg_per_gram, decigray);
implement_subunit(si, si, cgs, hectoerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::hecto>));
implement_subunit(si, si, cgs, kiloerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::kilo>));
implement_subunit(si, si, cgs, megaerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::mega>));
link_unit(gigaerg_per_gram, decigray);
link_unit(teraerg_per_gram, nanogray);
implement_subunit(si, si, cgs, petaerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::peta>));
implement_subunit(si, si, cgs, exaerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::exa>));
implement_subunit(si, si, cgs, zettaerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::zetta>));
implement_subunit(si, si, cgs, yottaerg_per_gram, dim::absorbed_dose_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deci>,prefix::yotta>));
#pragma endregion
#pragma region dyne(force)
implement_subunit(si, si, cgs, yoctodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::zepto>));
implement_subunit(si, si, cgs, attodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::atto>));
implement_subunit(si, si, cgs, femtodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::femto>));
implement_subunit(si, si, cgs, picodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::pico>));
implement_subunit(si, si, cgs, nanodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::nano>));
implement_subunit(si, si, cgs, microdyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::micro>));
implement_subunit(si, si, cgs, millidyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::milli>));
implement_subunit(si, si, cgs, centidyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::centi>));
link_unit(decidyne, micronewton);
implement_subunit(si, si, cgs, dyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::one>));
implement_subunit(si, si, cgs, decadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::deca>));
link_unit(hectodyne, millinewton);
link_unit(kilodyne, centinewton);
link_unit(megadyne, decanewton);
implement_subunit(si, si, cgs, gigadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::giga>));
implement_subunit(si, si, cgs, teradyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::tera>));
implement_subunit(si, si, cgs, petadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::peta>));
implement_subunit(si, si, cgs, exadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::exa>));
implement_subunit(si, si, cgs, zettadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::zetta>));
implement_subunit(si, si, cgs, yottadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::yotta>));
#pragma endregion
#pragma region oersted(magnetic field strength)
implement_subunit(si, si, cgs, yoctooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::zepto>));
implement_subunit(si, si, cgs, attooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::atto>));
implement_subunit(si, si, cgs, femtooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::femto>));
implement_subunit(si, si, cgs, picooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::pico>));
implement_subunit(si, si, cgs, nanooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::nano>));
implement_subunit(si, si, cgs, microoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::micro>));
implement_subunit(si, si, cgs, millioersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::milli>));
implement_subunit(si, si, cgs, centioersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::centi>));
implement_subunit(si, si, cgs, decioersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::deci>));
implement_subunit(si, si, cgs, oersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::one>));
implement_subunit(si, si, cgs, decaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::deca>));
implement_subunit(si, si, cgs, hectooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::hecto>));
implement_subunit(si, si, cgs, kilooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::kilo>));
implement_subunit(si, si, cgs, megaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::mega>));
implement_subunit(si, si, cgs, gigaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::giga>));
implement_subunit(si, si, cgs, teraoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::tera>));
implement_subunit(si, si, cgs, petaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::peta>));
implement_subunit(si, si, cgs, exaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::exa>));
implement_subunit(si, si, cgs, zettaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::zetta>));
implement_subunit(si, si, cgs, yottaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::yotta>));
#pragma endregion
#pragma region stilb(luminance)
implement_subunit(si, si, cgs, yoctostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::zepto>));
implement_subunit(si, si, cgs, attostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::atto>));
implement_subunit(si, si, cgs, femtostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::femto>));
implement_subunit(si, si, cgs, picostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::pico>));
implement_subunit(si, si, cgs, nanostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::nano>));
implement_subunit(si, si, cgs, microstilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::micro>));
implement_subunit(si, si, cgs, millistilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::milli>));
link_unit(centistilb, microcandela_per_square_metre);
implement_subunit(si, si, cgs, decistilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::deci>));
implement_subunit(si, si, cgs, stilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::one>));
link_unit(decastilb, millicandela_per_square_metre);
link_unit(hectostilb, centicandela_per_square_metre);
link_unit(kilostilb, decicandela_per_square_metre);
link_unit(megastilb, hectocandela_per_square_metre);
implement_subunit(si, si, cgs, gigastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::giga>));
implement_subunit(si, si, cgs, terastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::tera>));
implement_subunit(si, si, cgs, petastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::peta>));
implement_subunit(si, si, cgs, exastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::exa>));
implement_subunit(si, si, cgs, zettastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::zetta>));
implement_subunit(si, si, cgs, yottastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::yotta>));
#pragma endregion
} // namespace cgs
} // namespace si
} // namespace benri