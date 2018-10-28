#pragma once
#include <benri/unit.h>
#include <benri/impl/list.h>
#include <benri/units/macros.h>

namespace benri
{
namespace dim
{
#pragma region dimension symbols
//si
struct L; //length
struct M; //mass
struct T; //time, duration
struct I; //current
struct H; //thermodynamic temperature (actually this should be a Θ, but H looks similar)
struct N; //amount of substance
struct J; //luminous intensity
//special symbols
struct A;    //angle
struct C;    //number of events (count)
struct S;    //helper for Sievert based units
struct B;    //amount of data
struct X;    //screen position
struct degC; //absolute degree celsius
struct degF; //absolute degree fahrenheit
#pragma endregion
#pragma region atom helper
template <class Dimension, intmax_t Power = 1>
using helper = atom<Dimension, std::ratio<Power>>;
#pragma endregion
#pragma region base dimensions
create_and_register_dimension(length, helper<L>);
create_and_register_dimension(mass, helper<M>);
create_and_register_dimension(time, helper<T>);
create_and_register_dimension(electric_current, helper<I>);
create_and_register_dimension(thermodynamic_temperature, helper<H>);
create_and_register_dimension(celsius_temperature, helper<degC>);
create_and_register_dimension(fahrenheit_temperature, helper<degF>);
create_and_register_dimension(amount_of_substance, helper<N>);
create_and_register_dimension(luminous_intensity, helper<J>);
create_and_register_dimension(plane_angle, helper<A>);
create_and_register_dimension(number_of_radioactive_events, helper<C>);
create_and_register_dimension(radiation_weighting_factor, helper<S>);
create_and_register_dimension(dimensionless);
create_and_register_dimension(amount_of_data, helper<B>);
create_and_register_dimension(screen_position, helper<X>);
#pragma endregion
#pragma region derived dimensions
create_and_register_dimension(area, helper<L, 2>);
create_and_register_dimension(volume, helper<L, 3>);
create_and_register_dimension(velocity, helper<L>, helper<T, -1>);
create_and_register_dimension(acceleration, helper<L>, helper<T, -2>);
create_and_register_dimension(wavenumber, helper<L, -1>);
create_and_register_dimension(density, helper<L, -3>, helper<M>);
create_and_register_dimension(area_density, helper<L, -2>, helper<M>);
create_and_register_dimension(line_density, helper<L, -1>, helper<M>);
create_and_register_dimension(specific_volume, helper<L, 3>, helper<M, -1>);
create_and_register_dimension(current_density, helper<L, -2>, helper<I>);
create_and_register_dimension(magnetic_field_strength, helper<L, -1>, helper<I>);
create_and_register_dimension(concentration, helper<L, -3>, helper<N>);
create_and_register_dimension(luminance, helper<L, -2>, helper<J>);
create_and_register_dimension(solid_angle, helper<A, 2>);
create_and_register_dimension(frequency, helper<T, -1>);
create_and_register_dimension(force, helper<L>, helper<M>, helper<T, -2>);
create_and_register_dimension(pressure, helper<L, -1>, helper<M>, helper<T, -2>);
create_and_register_dimension(energy, helper<L, 2>, helper<M>, helper<T, -2>);
create_and_register_dimension(power, helper<L, 2>, helper<M>, helper<T, -3>);
create_and_register_dimension(electric_charge, helper<T>, helper<I>);
create_and_register_dimension(electric_potential, helper<L, 2>, helper<M>, helper<T, -3>, helper<I, -1>);
create_and_register_dimension(capacitance, helper<L, -2>, helper<M, -1>, helper<T, 4>, helper<I, 2>);
create_and_register_dimension(electric_resistance, helper<L, 2>, helper<M>, helper<T, -3>, helper<I, -2>);
create_and_register_dimension(electric_conductance, helper<L, -2>, helper<M, -1>, helper<T, 3>, helper<I, 2>);
create_and_register_dimension(magnetic_flux, helper<L, 2>, helper<M>, helper<T, -2>, helper<I, -1>);
create_and_register_dimension(magnetic_flux_density, helper<M>, helper<T, -2>, helper<I, -1>);
create_and_register_dimension(inductance, helper<L, 2>, helper<M>, helper<T, -2>, helper<I, -2>);
create_and_register_dimension(luminous_flux, helper<J>, helper<A, 2>);
create_and_register_dimension(illuminance, helper<L, -2>, helper<J>, helper<A, 2>);
create_and_register_dimension(luminosity, helper<L, 2>, helper<M>, helper<T, -3>, helper<A, 2>);
create_and_register_dimension(activity_of_radionuclide, helper<T, -1>, helper<C>);
create_and_register_dimension(absorbed_dose, helper<L, 2>, helper<T, -2>);
create_and_register_dimension(dose_equivalent, helper<S>, helper<L, 2>, helper<T, -2>);
create_and_register_dimension(catalytic_activity, helper<T, -1>, helper<N>);
create_and_register_dimension(dynamic_viscosity, helper<L, -1>, helper<M>, helper<T, -1>);
create_and_register_dimension(torque, helper<L>, helper<M>, helper<T, -2>, helper<A, -1>);
create_and_register_dimension(surface_tension, helper<M>, helper<T, -2>);
create_and_register_dimension(angular_velocity, helper<T, -1>, helper<A>);
create_and_register_dimension(angular_acceleration, helper<T, -2>, helper<A>);
create_and_register_dimension(heat_flux_density, helper<M>, helper<T, -3>);
create_and_register_dimension(heat_capacity, helper<L, 2>, helper<M>, helper<T, -2>, helper<H, -1>);
create_and_register_dimension(specific_heat_capacity, helper<L, 2>, helper<T, -2>, helper<H, -1>);
create_and_register_dimension(thermal_conductivity, helper<L>, helper<M>, helper<T, -3>, helper<H, -1>);
create_and_register_dimension(electric_field_strength, helper<L>, helper<M>, helper<T, -3>, helper<I, -1>);
create_and_register_dimension(electric_charge_density, helper<L, -3>, helper<T>, helper<I>);
create_and_register_dimension(electric_flux_density, helper<L, -2>, helper<T>, helper<I>);
create_and_register_dimension(permittivity, helper<L, -3>, helper<M, -1>, helper<T, 4>, helper<I, 2>);
create_and_register_dimension(permeability, helper<L>, helper<M>, helper<T, -2>, helper<I, -2>);
create_and_register_dimension(molar_energy, helper<L, 2>, helper<M>, helper<T, -2>, helper<N, -1>);
create_and_register_dimension(molar_heat_capacity, helper<L, 2>, helper<M>, helper<T, -2>, helper<H, -1>, helper<N, -1>);
create_and_register_dimension(radioactive_exposure, helper<M, -1>, helper<T>, helper<I>);
create_and_register_dimension(absorbed_dose_rate, helper<L, 2>, helper<T, -3>);
create_and_register_dimension(radiance, helper<M>, helper<T, -3>, helper<A, 2>);
create_and_register_dimension(catalytic_activity_concentration, helper<L, -3>, helper<T, -1>, helper<N>);
create_and_register_dimension(action, helper<L, 2>, helper<M>, helper<T, -1>);
create_and_register_dimension(kinematic_viscosity, helper<L, 2>, helper<T, -1>);
create_and_register_dimension(data_bandwitdth, helper<T, -1>, helper<B>);
create_and_register_dimension(screen_area, helper<X, 2>);
create_and_register_dimension(electric_conductivity, helper<L, -3>, helper<M, -1>, helper<T, 3>, helper<I, 2>);
create_and_register_dimension(electric_resistivity, helper<L, 3>, helper<M>, helper<T, -3>, helper<I, -2>);
create_and_register_dimension(momentum, helper<L>, helper<M>, helper<T, -1>);
create_and_register_dimension(angular_momentum, helper<L, 2>, helper<M>);
create_and_register_dimension(moment_of_inertia, helper<L, 2>, helper<M>, helper<T, -1>, helper<A>);
create_and_register_dimension(absement, helper<L>, helper<T>);
create_and_register_dimension(jerk, helper<L>, helper<T, -3>);
create_and_register_dimension(snap, helper<L>, helper<T, -4>);
create_and_register_dimension(crackle, helper<L>, helper<T, -5>);
create_and_register_dimension(pop, helper<L>, helper<T, -6>);
#pragma endregion
} // namespace dim
} // namespace benri