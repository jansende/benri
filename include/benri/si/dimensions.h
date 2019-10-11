#pragma once
#include <benri/impl/type/list.h>
#include <benri/impl/type/sort.h>
#include <benri/impl/unit.h>
#include <benri/si/macros.h>

namespace benri
{
namespace dimension
{
#pragma region dimension symbols
// si
struct L
{
    static constexpr auto name = meta::static_string{"L"};
}; // length
struct M
{
    static constexpr auto name = meta::static_string{"M"};
}; // mass
struct T
{
    static constexpr auto name = meta::static_string{"T"};
}; // time, duration
struct I
{
    static constexpr auto name = meta::static_string{"I"};
}; // current
struct H
{
    static constexpr auto name = meta::static_string{"H"};
}; // thermodynamic temperature (actually this should be a Θ, but H looks
   // similar)
struct N
{
    static constexpr auto name = meta::static_string{"N"};
}; // amount of substance
struct J
{
    static constexpr auto name = meta::static_string{"J"};
}; // luminous intensity
// special symbols
struct A
{
    static constexpr auto name = meta::static_string{"A"};
}; // angle
struct C
{
    static constexpr auto name = meta::static_string{"C"};
}; // number of events (count)
struct S
{
    static constexpr auto name = meta::static_string{"S"};
}; // helper for Sievert based units
struct B
{
    static constexpr auto name = meta::static_string{"B"};
}; // amount of data
struct X
{
    static constexpr auto name = meta::static_string{"X"};
}; // screen position
struct degC
{
    static constexpr auto name = meta::static_string{"degC"};
}; // absolute degree celsius
struct degF
{
    static constexpr auto name = meta::static_string{"degF"};
}; // absolute degree fahrenheit
#pragma endregion
#pragma region atom helper
template <class Dimension, intmax_t Power = 1>
using helper = dim<Dimension, std::ratio<Power>>;
#pragma endregion
#pragma region base dimensions
using length_t                       = make_dimension<helper<L>>;
using mass_t                         = make_dimension<helper<M>>;
using time_t                         = make_dimension<helper<T>>;
using electric_current_t             = make_dimension<helper<I>>;
using thermodynamic_temperature_t    = make_dimension<helper<H>>;
using celsius_temperature_t          = make_dimension<helper<degC>>;
using fahrenheit_temperature_t       = make_dimension<helper<degF>>;
using amount_of_substance_t          = make_dimension<helper<N>>;
using luminous_intensity_t           = make_dimension<helper<J>>;
using plane_angle_t                  = make_dimension<helper<A>>;
using number_of_radioactive_events_t = make_dimension<helper<C>>;
using radiation_weighting_factor_t   = make_dimension<helper<S>>;
using dimensionless_t                = make_dimension<>;
using amount_of_data_t               = make_dimension<helper<B>>;
using screen_position_t              = make_dimension<helper<X>>;
#pragma endregion
#pragma region derived dimensions
using area_t                    = make_dimension<helper<L, 2>>;
using volume_t                  = make_dimension<helper<L, 3>>;
using velocity_t                = make_dimension<helper<L>, helper<T, -1>>;
using acceleration_t            = make_dimension<helper<L>, helper<T, -2>>;
using wavenumber_t              = make_dimension<helper<L, -1>>;
using density_t                 = make_dimension<helper<L, -3>, helper<M>>;
using area_density_t            = make_dimension<helper<L, -2>, helper<M>>;
using line_density_t            = make_dimension<helper<L, -1>, helper<M>>;
using specific_volume_t         = make_dimension<helper<L, 3>, helper<M, -1>>;
using current_density_t         = make_dimension<helper<L, -2>, helper<I>>;
using magnetic_field_strength_t = make_dimension<helper<L, -1>, helper<I>>;
using concentration_t           = make_dimension<helper<L, -3>, helper<N>>;
using luminance_t               = make_dimension<helper<L, -2>, helper<J>>;
using solid_angle_t             = make_dimension<helper<A, 2>>;
using frequency_t               = make_dimension<helper<T, -1>>;
using force_t                   = make_dimension<helper<L>, helper<M>, helper<T, -2>>;
using pressure_t                = make_dimension<helper<L, -1>, helper<M>, helper<T, -2>>;
using energy_t                  = make_dimension<helper<L, 2>, helper<M>, helper<T, -2>>;
using power_t                   = make_dimension<helper<L, 2>, helper<M>, helper<T, -3>>;
using electric_charge_t         = make_dimension<helper<T>, helper<I>>;
using electric_potential_t =
    make_dimension<helper<L, 2>, helper<M>, helper<T, -3>, helper<I, -1>>;
using capacitance_t =
    make_dimension<helper<L, -2>, helper<M, -1>, helper<T, 4>, helper<I, 2>>;
using electric_resistance_t =
    make_dimension<helper<L, 2>, helper<M>, helper<T, -3>, helper<I, -2>>;
using electric_conductance_t =
    make_dimension<helper<L, -2>, helper<M, -1>, helper<T, 3>, helper<I, 2>>;
using magnetic_flux_t =
    make_dimension<helper<L, 2>, helper<M>, helper<T, -2>, helper<I, -1>>;
using magnetic_flux_density_t = make_dimension<helper<M>, helper<T, -2>, helper<I, -1>>;
using inductance_t =
    make_dimension<helper<L, 2>, helper<M>, helper<T, -2>, helper<I, -2>>;
using luminous_flux_t = make_dimension<helper<J>, helper<A, 2>>;
using illuminance_t   = make_dimension<helper<L, -2>, helper<J>, helper<A, 2>>;
using luminosity_t = make_dimension<helper<L, 2>, helper<M>, helper<T, -3>, helper<A, 2>>;
using activity_of_radionuclide_t = make_dimension<helper<T, -1>, helper<C>>;
using absorbed_dose_t            = make_dimension<helper<L, 2>, helper<T, -2>>;
using dose_equivalent_t          = make_dimension<helper<S>, helper<L, 2>, helper<T, -2>>;
using catalytic_activity_t       = make_dimension<helper<T, -1>, helper<N>>;
using dynamic_viscosity_t = make_dimension<helper<L, -1>, helper<M>, helper<T, -1>>;
using torque_t = make_dimension<helper<L>, helper<M>, helper<T, -2>, helper<A, -1>>;
using surface_tension_t      = make_dimension<helper<M>, helper<T, -2>>;
using angular_velocity_t     = make_dimension<helper<T, -1>, helper<A>>;
using angular_acceleration_t = make_dimension<helper<T, -2>, helper<A>>;
using heat_flux_density_t    = make_dimension<helper<M>, helper<T, -3>>;
using heat_capacity_t =
    make_dimension<helper<L, 2>, helper<M>, helper<T, -2>, helper<H, -1>>;
using specific_heat_capacity_t =
    make_dimension<helper<L, 2>, helper<T, -2>, helper<H, -1>>;
using thermal_conductivity_t =
    make_dimension<helper<L>, helper<M>, helper<T, -3>, helper<H, -1>>;
using electric_field_strength_t =
    make_dimension<helper<L>, helper<M>, helper<T, -3>, helper<I, -1>>;
using electric_charge_density_t = make_dimension<helper<L, -3>, helper<T>, helper<I>>;
using electric_flux_density_t   = make_dimension<helper<L, -2>, helper<T>, helper<I>>;
using permittivity_t =
    make_dimension<helper<L, -3>, helper<M, -1>, helper<T, 4>, helper<I, 2>>;
using permeability_t = make_dimension<helper<L>, helper<M>, helper<T, -2>, helper<I, -2>>;
using molar_energy_t =
    make_dimension<helper<L, 2>, helper<M>, helper<T, -2>, helper<N, -1>>;
using molar_heat_capacity_t =
    make_dimension<helper<L, 2>, helper<M>, helper<T, -2>, helper<H, -1>, helper<N, -1>>;
using radioactive_exposure_t = make_dimension<helper<M, -1>, helper<T>, helper<I>>;
using absorbed_dose_rate_t   = make_dimension<helper<L, 2>, helper<T, -3>>;
using radiance_t             = make_dimension<helper<M>, helper<T, -3>, helper<A, 2>>;
using catalytic_activity_concentration =
    make_dimension<helper<L, -3>, helper<T, -1>, helper<N>>;
using action_t              = make_dimension<helper<L, 2>, helper<M>, helper<T, -1>>;
using kinematic_viscosity_t = make_dimension<helper<L, 2>, helper<T, -1>>;
using data_bandwitdth_t     = make_dimension<helper<T, -1>, helper<B>>;
using screen_area_t         = make_dimension<helper<X, 2>>;
using electric_conductivity_t =
    make_dimension<helper<L, -3>, helper<M, -1>, helper<T, 3>, helper<I, 2>>;
using electric_resistivity_t =
    make_dimension<helper<L, 3>, helper<M>, helper<T, -3>, helper<I, -2>>;
using momentum_t         = make_dimension<helper<L>, helper<M>, helper<T, -1>>;
using angular_momentum_t = make_dimension<helper<L, 2>, helper<M>>;
using moment_of_inertia_t =
    make_dimension<helper<L, 2>, helper<M>, helper<T, -1>, helper<A>>;
using absement_t = make_dimension<helper<L>, helper<T>>;
using jerk_t     = make_dimension<helper<L>, helper<T, -3>>;
using snap_t     = make_dimension<helper<L>, helper<T, -4>>;
using crackle_t  = make_dimension<helper<L>, helper<T, -5>>;
using pop_t      = make_dimension<helper<L>, helper<T, -6>>;
using massloss_t = make_dimension<helper<M>, helper<T, -1>>;
#pragma endregion
} // namespace dimension
} // namespace benri