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
#pragma region poise(dynamic viscosity)
implement_subunit(si, si, cgs, yoctopoise, _yoctopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::yocto>));
implement_subunit(si, si, cgs, zeptopoise, _zeptopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::zepto>));
implement_subunit(si, si, cgs, attopoise, _attopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::atto>));
implement_subunit(si, si, cgs, femtopoise, _femtopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::femto>));
implement_subunit(si, si, cgs, picopoise, _picopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::pico>));
implement_subunit(si, si, cgs, nanopoise, _nanopoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::nano>));
implement_subunit(si, si, cgs, micropoise, _micropoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::micro>));
implement_subunit(si, si, cgs, millipoise, _millipoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::milli>));
link_unit(centipoise, _centipoise, millipascal_second);
link_unit(decipoise, _decipoise, centipascal_second);
link_unit(poise, _poise, decipascal_second);
link_unit(decapoise, _decapoise, pascal_second);
link_unit(hectopoise, _hectopoise, decapascal_second);
link_unit(kilopoise, _kilopoise, hectopascal_second);
implement_subunit(si, si, cgs, megapoise, _megapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::mega>));
implement_subunit(si, si, cgs, gigapoise, _gigapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::giga>));
implement_subunit(si, si, cgs, terapoise, _terapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::tera>));
implement_subunit(si, si, cgs, petapoise, _petapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::peta>));
implement_subunit(si, si, cgs, exapoise, _exapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::exa>));
implement_subunit(si, si, cgs, zettapoise, _zettapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::zetta>));
implement_subunit(si, si, cgs, yottapoise, _yottapoise, dim::dynamic_viscosity_t, fix(impl::multiply_lists_t<prefix::deci, prefix::yotta>));
#pragma endregion
#pragma region maxwell(magnetic flux)
implement_subunit(si, si, cgs, yoctomaxwell, _yoctomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptomaxwell, _zeptomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::zepto>));
implement_subunit(si, si, cgs, attomaxwell, _attomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::atto>));
implement_subunit(si, si, cgs, femtomaxwell, _femtomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::femto>));
implement_subunit(si, si, cgs, picomaxwell, _picomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::pico>));
implement_subunit(si, si, cgs, nanomaxwell, _nanomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::nano>));
implement_subunit(si, si, cgs, micromaxwell, _micromaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::micro>));
implement_subunit(si, si, cgs, millimaxwell, _millimaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::milli>));
implement_subunit(si, si, cgs, centimaxwell, _centimaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::centi>));
link_unit(decimaxwell, _decimaxwell, nanoweber);
implement_subunit(si, si, cgs, maxwell, _maxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::one>));
implement_subunit(si, si, cgs, decamaxwell, _decamaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::deca>));
link_unit(hectomaxwell, _hectomaxwell, microweber);
implement_subunit(si, si, cgs, kilomaxwell, _kilomaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::kilo>));
link_unit(megamaxwell, _megamaxwell, centiweber);
link_unit(gigamaxwell, _gigamaxwell, decaweber);
implement_subunit(si, si, cgs, teramaxwell, _teramaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::tera>));
implement_subunit(si, si, cgs, petamaxwell, _petamaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::peta>));
implement_subunit(si, si, cgs, examaxwell, _examaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::exa>));
implement_subunit(si, si, cgs, zettamaxwell, _zettamaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::zetta>));
implement_subunit(si, si, cgs, yottamaxwell, _yottamaxwell, dim::magnetic_flux_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::deca>,prefix::yotta>));
#pragma endregion
#pragma region gauss(magentic flux density)
implement_subunit(si, si, cgs, yoctogauss, _yoctogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::yocto>));
implement_subunit(si, si, cgs, zeptogauss, _zeptogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::zepto>));
implement_subunit(si, si, cgs, attogauss, _attogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::atto>));
implement_subunit(si, si, cgs, femtogauss, _femtogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::femto>));
implement_subunit(si, si, cgs, picogauss, _picogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::pico>));
implement_subunit(si, si, cgs, nanogauss, _nanogauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::nano>));
implement_subunit(si, si, cgs, microgauss, _microgauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::micro>));
implement_subunit(si, si, cgs, milligauss, _milligauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::milli>));
link_unit(centigauss, _centigauss, microtesla);
implement_subunit(si, si, cgs, decigauss, _decigauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::deci>));
implement_subunit(si, si, cgs, gauss, _gauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::one>));
link_unit(decagauss, _decagauss, millitesla);
link_unit(hectogauss, _hectogauss, centitesla);
link_unit(kilogauss, _kilogauss, decitesla);
link_unit(megagauss, _megagauss, hectotesla);
implement_subunit(si, si, cgs, gigagauss, _gigagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::giga>));
implement_subunit(si, si, cgs, teragauss, _teragauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::tera>));
implement_subunit(si, si, cgs, petagauss, _petagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::peta>));
implement_subunit(si, si, cgs, exagauss, _exagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::exa>));
implement_subunit(si, si, cgs, zettagauss, _zettagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::zetta>));
implement_subunit(si, si, cgs, yottagauss, _yottagauss, dim::magnetic_flux_density_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::milli,prefix::deci>, prefix::yotta>));
#pragma endregion
#pragma region erg(energy)
implement_subunit(si, si, cgs, yoctoerg, _yoctoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptoerg, _zeptoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::zepto>));
implement_subunit(si, si, cgs, attoerg, _attoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::atto>));
implement_subunit(si, si, cgs, femtoerg, _femtoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::femto>));
implement_subunit(si, si, cgs, picoerg, _picoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::pico>));
implement_subunit(si, si, cgs, nanoerg, _nanoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::nano>));
implement_subunit(si, si, cgs, microerg, _microerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::micro>));
implement_subunit(si, si, cgs, millierg, _millierg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::milli>));
link_unit(centierg, _centierg, nanojoule);
implement_subunit(si, si, cgs, decierg, _decierg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::deci>));
implement_subunit(si, si, cgs, erg, _erg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::one>));
link_unit(decaerg, _decaerg, microjoule);
implement_subunit(si, si, cgs, hectoerg, _hectoerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::hecto>));
implement_subunit(si, si, cgs, kiloerg, _kiloerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::kilo>));
link_unit(megaerg, _megaerg, decijoule);
link_unit(gigaerg, _gigaerg, hectojoule);
implement_subunit(si, si, cgs, teraerg, _teraerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::tera>));
implement_subunit(si, si, cgs, petaerg, _petaerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::peta>));
implement_subunit(si, si, cgs, exaerg, _exaerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::exa>));
implement_subunit(si, si, cgs, zettaerg, _zettaerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::zetta>));
implement_subunit(si, si, cgs, yottaerg, _yottaerg, dim::energy_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::nano,prefix::hecto>,prefix::yotta>));
#pragma endregion
#pragma region dyne(force)
implement_subunit(si, si, cgs, yoctodyne, _yoctodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptodyne, _zeptodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::zepto>));
implement_subunit(si, si, cgs, attodyne, _attodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::atto>));
implement_subunit(si, si, cgs, femtodyne, _femtodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::femto>));
implement_subunit(si, si, cgs, picodyne, _picodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::pico>));
implement_subunit(si, si, cgs, nanodyne, _nanodyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::nano>));
implement_subunit(si, si, cgs, microdyne, _microdyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::micro>));
implement_subunit(si, si, cgs, millidyne, _millidyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::milli>));
implement_subunit(si, si, cgs, centidyne, _centidyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::centi>));
link_unit(decidyne, _decidyne, micronewton);
implement_subunit(si, si, cgs, dyne, _dyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::one>));
implement_subunit(si, si, cgs, decadyne, _decadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::deca>));
link_unit(hectodyne, _hectodyne, millinewton);
link_unit(kilodyne, _kilodyne, centinewton);
link_unit(megadyne, _megadyne, decanewton);
implement_subunit(si, si, cgs, gigadyne, _gigadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::giga>));
implement_subunit(si, si, cgs, teradyne, _teradyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::tera>));
implement_subunit(si, si, cgs, petadyne, _petadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::peta>));
implement_subunit(si, si, cgs, exadyne, _exadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::exa>));
implement_subunit(si, si, cgs, zettadyne, _zettadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::zetta>));
implement_subunit(si, si, cgs, yottadyne, _yottadyne, dim::force_t, fix(impl::multiply_lists_t<impl::multiply_lists_t<prefix::micro,prefix::deca>,prefix::yotta>));
#pragma endregion
#pragma region oersted(magnetic field strength)
implement_subunit(si, si, cgs, yoctooersted, _yoctooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptooersted, _zeptooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::zepto>));
implement_subunit(si, si, cgs, attooersted, _attooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::atto>));
implement_subunit(si, si, cgs, femtooersted, _femtooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::femto>));
implement_subunit(si, si, cgs, picooersted, _picooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::pico>));
implement_subunit(si, si, cgs, nanooersted, _nanooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::nano>));
implement_subunit(si, si, cgs, microoersted, _microoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::micro>));
implement_subunit(si, si, cgs, millioersted, _millioersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::milli>));
implement_subunit(si, si, cgs, centioersted, _centioersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::centi>));
implement_subunit(si, si, cgs, decioersted, _decioersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::deci>));
implement_subunit(si, si, cgs, oersted, _oersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::one>));
implement_subunit(si, si, cgs, decaoersted, _decaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::deca>));
implement_subunit(si, si, cgs, hectooersted, _hectooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::hecto>));
implement_subunit(si, si, cgs, kilooersted, _kilooersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::kilo>));
implement_subunit(si, si, cgs, megaoersted, _megaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::mega>));
implement_subunit(si, si, cgs, gigaoersted, _gigaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::giga>));
implement_subunit(si, si, cgs, teraoersted, _teraoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::tera>));
implement_subunit(si, si, cgs, petaoersted, _petaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::peta>));
implement_subunit(si, si, cgs, exaoersted, _exaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::exa>));
implement_subunit(si, si, cgs, zettaoersted, _zettaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::zetta>));
implement_subunit(si, si, cgs, yottaoersted, _yottaoersted, dim::magnetic_field_strength_t, fix(impl::multiply_lists_t<impl::divide_lists_t<prefix::kilo,impl::multiply_lists_t<make_fraction_list_t<4>,prefix::pi_t>>,prefix::yotta>));
#pragma endregion
#pragma region stilb(luminance)
implement_subunit(si, si, cgs, yoctostilb, _yoctostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::yocto>));
implement_subunit(si, si, cgs, zeptostilb, _zeptostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::zepto>));
implement_subunit(si, si, cgs, attostilb, _attostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::atto>));
implement_subunit(si, si, cgs, femtostilb, _femtostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::femto>));
implement_subunit(si, si, cgs, picostilb, _picostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::pico>));
implement_subunit(si, si, cgs, nanostilb, _nanostilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::nano>));
implement_subunit(si, si, cgs, microstilb, _microstilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::micro>));
implement_subunit(si, si, cgs, millistilb, _millistilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::milli>));
link_unit(centistilb, _centistilb, microcandela_per_square_metre);
implement_subunit(si, si, cgs, decistilb, _decistilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::deci>));
implement_subunit(si, si, cgs, stilb, _stilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::one>));
link_unit(decastilb, _decastilb, millicandela_per_square_metre);
link_unit(hectostilb, _hectostilb, centicandela_per_square_metre);
link_unit(kilostilb, _kilostilb, decicandela_per_square_metre);
link_unit(megastilb, _megastilb, hectocandela_per_square_metre);
implement_subunit(si, si, cgs, gigastilb, _gigastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::giga>));
implement_subunit(si, si, cgs, terastilb, _terastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::tera>));
implement_subunit(si, si, cgs, petastilb, _petastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::peta>));
implement_subunit(si, si, cgs, exastilb, _exastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::exa>));
implement_subunit(si, si, cgs, zettastilb, _zettastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::zetta>));
implement_subunit(si, si, cgs, yottastilb, _yottastilb, dim::luminance_t, fix(impl::multiply_lists_t<make_power_list_t<-4>,prefix::yotta>));
#pragma endregion
} // namespace cgs
} // namespace si
} // namespace benri