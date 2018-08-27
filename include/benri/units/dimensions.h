#pragma once
#include <benri/impl/unit.h>
#include <benri/impl/list.h>

namespace benri
{
namespace dim
{
#pragma region base types
struct L; //length
struct M; //mass
struct T; //time
struct I; //current
struct H; //temperature
struct N; //amount of substance
struct J; //luminous intensity
struct A; //angle
struct D; //amount of data
struct X; //screen position
struct C; //number of events (count)
struct G; //helper for Gray based units
struct S; //helper for Sievert based units
#pragma endregion
#pragma region base dimensions.
create_and_register_dimension(dimensionless);
create_and_register_dimension(time, atom<T>);
create_and_register_dimension(electric_current, atom<I>);
create_and_register_dimension(luminous_intensity, atom<J>);
#pragma endregion
#pragma region data dimensions
create_and_register_dimension(amount_of_data, atom<D>);
create_and_register_dimension(datarate, atom<D>, atom<T, std::ratio<-1>>);
create_and_register_dimension(screen_position, atom<X>);
create_and_register_dimension(screen_resolution, atom<X, std::ratio<2>>);
#pragma endregion
//The list of quantities is taken from: https://en.wikipedia.org/wiki/List_of_physical_quantities/
// - Quantities which cannot be properly implemented right now are commented out.
// - Also esoteric quantities of chemistry and engineering are commented out.
// - All occurences of 'electrical' have been renamed to 'electric' for more consistency.
// - Some units with somewhat similar meanings are added as create_property_and_dimension
#pragma region angles
//measurements
create_and_register_dimension(plane_angle, atom<A>);
create_and_register_dimension(solid_angle, atom<A, std::ratio<2>>);
//movement
create_and_register_dimension(angular_velocity, atom<A>, atom<T, std::ratio<-1>>);
create_and_register_dimension(angular_acceleration, atom<A>, atom<T, std::ratio<-2>>);
//quantities
create_and_register_dimension(angular_momentum, atom<A>, atom<M>, atom<L, std::ratio<2>>, atom<T, std::ratio<-1>>);
create_and_register_dimension(torque, atom<A>, atom<M>, atom<L, std::ratio<2>>, atom<T, std::ratio<-2>>);
create_and_register_dimension(moment_of_inertia, atom<M>, atom<L, std::ratio<2>>);
#pragma endregion
#pragma region mechanics
//movement
create_and_register_dimension(absement, atom<L>, atom<T, std::ratio<1>>);
create_and_register_dimension(velocity, atom<L>, atom<T, std::ratio<-1>>);
create_and_register_dimension(acceleration, atom<L>, atom<T, std::ratio<-2>>);
create_and_register_dimension(jerk, atom<L>, atom<T, std::ratio<-3>>);
create_and_register_dimension(snap, atom<L>, atom<T, std::ratio<-4>>);
create_and_register_dimension(crackle, atom<L>, atom<T, std::ratio<-5>>);
create_and_register_dimension(pop, atom<L>, atom<T, std::ratio<-6>>);
//measurements
create_and_register_dimension(length, atom<L>);
create_and_register_dimension(area, atom<L, std::ratio<2>>);
create_and_register_dimension(volume, atom<L, std::ratio<3>>);
create_and_register_dimension(mass, atom<M>);
create_and_register_dimension(line_density, atom<M>, atom<L, std::ratio<-1>>);
create_and_register_dimension(area_density, atom<M>, atom<L, std::ratio<-2>>);
create_and_register_dimension(density, atom<M>, atom<L, std::ratio<-3>>);
create_and_register_dimension(specific_volume, atom<M, std::ratio<-1>>, atom<L, std::ratio<3>>);
//quantities
create_and_register_dimension(momentum, atom<M>, atom<L>, atom<T, std::ratio<-1>>);
create_and_register_dimension(force, atom<M>, atom<L>, atom<T, std::ratio<-2>>);
create_and_register_dimension(pressure, atom<M>, atom<L, std::ratio<-1>>, atom<T, std::ratio<-2>>);
create_and_register_dimension(energy, atom<M>, atom<L, std::ratio<2>>, atom<T, std::ratio<-2>>);
create_and_register_dimension(power, atom<M>, atom<L, std::ratio<2>>, atom<T, std::ratio<-3>>);
//fluids
// using dynamic_viscosity = list<helper<mass_d>, helper<length_d, -1>, helper<time_d, -1>>;
// using surface_tension = list<helper<mass_d>, helper<time_d, -2>>;
#pragma endregion
#pragma region thermodynamics
create_and_register_dimension(temperature, atom<H>);
// using entropy = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -2>, helper<temperature_d, -1>>;
// // using heat                             = list<helper<mass_d>,helper<length_d,2>,helper<time_d,-2>>;
// using heat_capacity = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -2>, helper<temperature_d, -1>>;
// // using heat_flux_density                = list<helper<mass_d>,helper<time_d,-3>>;
// using specific_energy = list<helper<length_d, 2>, helper<time_d, -2>>;
// using specific_heat_capcity = list<helper<length_d, 2>, helper<time_d, -2>, helper<temperature_d, -1>>;
// using thermal_conductivity = list<helper<mass_d>, helper<length_d>, helper<time_d, -3>, helper<temperature_d, -1>>;
#pragma endregion
#pragma region electrodynamics
//electronics
// using capacitance = list<helper<mass_d, -1>, helper<length_d, -2>, helper<time_d, 4>, helper<electric_current_d, 2>>;
//electromagnetism
// using electric_current_density = list<helper<length_d, -2>, helper<electric_current_d>>;
// using impedance = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -3>, helper<electric_current_d, -2>>;
// using inductance = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -2>, helper<electric_current_d, -2>>;
// using magnetic_field_strength = list<helper<length_d, -1>, helper<electric_current_d>>;
// using magnetic_flux = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -2>, helper<electric_current_d, -1>>;
// using magnetic_flux_density = list<helper<mass_d>, helper<time_d, -2>, helper<electric_current_d, -1>>;
// using magnetization = list<helper<length_d, -1>, helper<electric_current_d>>;
// using permeability = list<helper<mass_d>, helper<length_d>, helper<time_d, -2>, helper<electric_current_d, -2>>;
// using permittivity = list<helper<mass_d, -1>, helper<length_d, -3>, helper<time_d, 4>, helper<electric_current_d, 2>>;
// using electric_charge = list<helper<time_d>, helper<electric_current_d>>;
// using electric_charge_density = list<helper<length_d, -3>, helper<time_d>, helper<electric_current_d>>;
// using electric_displacement = list<helper<length_d, -2>, helper<time_d>, helper<electric_current_d>>;
// using electric_field_strength = list<helper<mass_d>, helper<length_d>, helper<time_d, -3>, helper<electric_current_d, -1>>;
// using electric_conductance = list<helper<mass_d, -1>, helper<length_d, -2>, helper<time_d, 3>, helper<electric_current_d, 2>>;
// using electric_conductivity = list<helper<mass_d, -1>, helper<length_d, -3>, helper<time_d, 3>, helper<electric_current_d, 2>>;
// using electric_potential = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -3>, helper<electric_current_d, -1>>;
// using electric_resistance = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -3>, helper<electric_current_d, -2>>;
// using electric_resistivity = list<helper<mass_d>, helper<length_d, 3>, helper<time_d, -3>, helper<electric_current_d, -2>>;
#pragma endregion
#pragma region chemisty
create_and_register_dimension(amount_of_substance, atom<N>);
// using catalytic_activity = list<helper<time_d, -1>, helper<amount_of_substance_d>>;
// using catalytic_activity_concentration = list<helper<length_d, -3>, helper<time_d, -1>, helper<amount_of_substance_d>>;
// using chemical_potential = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -2>, helper<amount_of_substance_d, -1>>;
// using molar_concentration = list<helper<length_d, -3>, helper<amount_of_substance_d>>;
// using molar_energy = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -2>, helper<amount_of_substance_d, -1>>;
// using molar_entropy = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -2>, helper<temperature_d, -1>, helper<amount_of_substance_d, -1>>;
// using molar_heat_capacity = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -2>, helper<temperature_d, -1>, helper<amount_of_substance_d, -1>>;
// using reaction_rate = list<helper<amount_of_substance_d>, helper<length_d, -3>, helper<time_d, -1>>;
#pragma endregion
#pragma region optics
// using frequency = list<helper<time_d, -1>>;
// using illuminance = list<helper<length_d, -2>, helper<luminous_intensity_d>>;
// using radiance = list<helper<mass_d>, helper<time_d, -3>, helper<angle_d, -2>>;
// using radian_intensity = list<helper<mass_d>, helper<length_d, 2>, helper<time_d, -3>, helper<angle_d, -2>>;
// // using irradiance                       = list<helper<mass_d>,helper<time_d,-3>>;
// using intensity = list<helper<mass_d>, helper<time_d, -3>>;
// // using luminous_flux                    = list<helper<luminous_intensity_d>>;
// // using luminous_power                   = luminous_flux;
// using wavenumber = list<helper<length_d, -1>>;
#pragma endregion
#pragma region atomic physics
create_and_register_dimension(half_life, atom<C, std::ratio<-1>>, atom<T>);
create_and_register_dimension(activity, atom<C>, atom<T, std::ratio<-1>>);
create_and_register_dimension(absorbed_dose_rate, atom<G>, atom<L, std::ratio<2>>, atom<T, std::ratio<-3>>);
create_and_register_dimension(absorbed_dose, atom<G>, atom<L, std::ratio<2>>, atom<T, std::ratio<-2>>);
create_and_register_dimension(dose_equivalent, atom<S>, atom<L, std::ratio<2>>, atom<T, std::ratio<-2>>);
#pragma endregion
} // namespace dim
} // namespace benri