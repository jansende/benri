#pragma once
#include <benri/impl/config.h>
#include <benri/impl/unit.h>

namespace benri
{
// quantity_point forward declaration
template <class Unit, class ValueType>
class quantity_point;
// quantity forward declaration
template <class Unit, class ValueType>
class quantity;
#pragma region value_type_cast
// The value_type_cast function lets you cast the value_type of a quantity/quantity_point
// to another value_type.
template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] [[deprecated]] constexpr auto
    value_type_cast(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> quantity<ArgumentUnit, ResultValueType>
{
    return quantity<ArgumentUnit, ResultValueType>{
        static_cast<ResultValueType>(rhs.value())};
}
template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] [[deprecated]] constexpr auto
    value_type_cast(const quantity_point<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> quantity<ArgumentUnit, ResultValueType>
{
    return quantity<ArgumentUnit, ResultValueType>{
        static_cast<ResultValueType>(rhs.value())};
}
#pragma endregion
#pragma region remove_prefix
// The remove_prefix function lets you get rid of the prefix of an arbitrary unit, by
// multiplying the value of the quantity/quantity_point with the prefix value. The
// remove_prefix function uses std::pow for the conversion. This allows it to remove arbi-
// trary roots, but makes it incompatible with compile time evaluation. The function is
// still marked constexpr, to be forward compatible with a constexpr std::pow implemen-
// tation. Furthermore, you can provide a ResultValueType for the function, in the case
// that the transformation would lead to conversion errors.
template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr auto
    remove_prefix(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> quantity<drop_unit_prefix<ArgumentUnit>, ResultValueType>
{
    using PrefixType  = typename ArgumentUnit::prefix;
    const auto factor = runtime_expand_prefix_list<ResultValueType>(PrefixType{});
    return quantity<drop_unit_prefix<ArgumentUnit>, ResultValueType>{
        static_cast<ResultValueType>(rhs.value()) * factor};
}
template <class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr auto
    remove_prefix(const quantity<ArgumentUnit, ArgumentValueType>& rhs) noexcept
{
    return remove_prefix<ArgumentValueType>(rhs);
}
template <class ResultValueType, class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr auto
    remove_prefix(const quantity_point<ArgumentUnit, ArgumentValueType>& rhs) noexcept
    -> quantity_point<drop_unit_prefix<ArgumentUnit>, ResultValueType>
{
    using PrefixType  = typename ArgumentUnit::prefix;
    const auto factor = runtime_expand_prefix_list<ResultValueType>(PrefixType{});
    return quantity_point<drop_unit_prefix<ArgumentUnit>, ResultValueType>{
        static_cast<ResultValueType>(rhs.value()) * factor};
}
template <class ArgumentUnit, class ArgumentValueType>
[[nodiscard]] constexpr auto
    remove_prefix(const quantity_point<ArgumentUnit, ArgumentValueType>& rhs) noexcept
{
    return remove_prefix<ArgumentValueType>(rhs);
}
#pragma endregion
#pragma region simple_cast
// The simple_cast function lets you cast one quantity/quantity_point to another unit
// and/or value_type. This is done by multiplying the value of the quantity/quantity_point
// with the right conversion constant. The simple_cast function relies on a custom imple-
// mentation of the power function, which allows it to be evaluated at compile time.
// However, the implementation has a restriction, that it is not compatible with roots of
// units.
template <class ResultUnit, class ResultValueType>
struct simple_cast_impl
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType>
struct simple_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                        void>
{
    // From quantity to quantity
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ArgumentPrefix>, ArgumentValueType>& rhs)
        const noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ArgumentPrefix>, ResultValueType>& rhs) const
        noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>{rhs.value()
                                                                              * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ResultPrefix>, ArgumentValueType>& rhs) const
        noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        return quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>& rhs) const
        noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From Other to quantity
    template <class Other>
    [[nodiscard]] constexpr auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>>,
            quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>>
    {
        return quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>{rhs};
    }
};
template <class ResultDimension, class ResultPrefix, class ResultValueType>
struct simple_cast_impl<
    quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>, void>
{
    // From quantity_point to quantity_point
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto
        operator()(const quantity_point<unit<ResultDimension, ArgumentPrefix>,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ArgumentValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr auto operator()(
        const quantity_point<unit<ResultDimension, ArgumentPrefix>, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        constexpr auto factor =
            expand_prefix_list<ResultValueType,
                               type::divide_lists<ArgumentPrefix, ResultPrefix>>;
        return quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity_point<unit<ResultDimension, ResultPrefix>, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        return quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr auto operator()(
        const quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From Other to quantity_point
    template <class Other>
    [[nodiscard]] constexpr auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>>,
            quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>>
    {
        return quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>{rhs};
    }
};
template <class ResultDimension, class ResultPrefix, class ResultValueType,
          class OtherResultValueType>
struct simple_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                        OtherResultValueType> :
    simple_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, OtherResultValueType>,
                     void>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType,
          class OtherResultValueType>
struct simple_cast_impl<OtherResultValueType,
                        quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>> :
    simple_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                     OtherResultValueType>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType,
          class OtherResultValueType>
struct simple_cast_impl<
    quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>,
    OtherResultValueType> :
    simple_cast_impl<
        quantity_point<unit<ResultDimension, ResultPrefix>, OtherResultValueType>, void>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType,
          class OtherResultValueType>
struct simple_cast_impl<
    OtherResultValueType,
    quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>> :
    simple_cast_impl<quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                     OtherResultValueType>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType>
struct simple_cast_impl<unit<ResultDimension, ResultPrefix>, ResultValueType> :
    simple_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                     void>,
    simple_cast_impl<quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                     void>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType>
struct simple_cast_impl<ResultValueType, unit<ResultDimension, ResultPrefix>> :
    simple_cast_impl<unit<ResultDimension, ResultPrefix>, ResultValueType>
{
};
template <class ResultDimension, class ResultPrefix>
struct simple_cast_impl<unit<ResultDimension, ResultPrefix>, void>
{
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ArgumentPrefix>, ArgumentValueType>& rhs)
        const noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity<unit<ResultDimension, ResultPrefix>, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto
        operator()(const quantity_point<unit<ResultDimension, ArgumentPrefix>,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<unit<ResultDimension, ResultPrefix>, ArgumentValueType>,
            void>{}(rhs);
    }
};
template <class ResultValueType>
struct simple_cast_impl<ResultValueType, void>
{
    template <class ArgumentDimension, class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ArgumentDimension, ArgumentPrefix>, ArgumentValueType>& rhs)
        const noexcept
        -> quantity<unit<ArgumentDimension, ArgumentPrefix>, ResultValueType>
    {
        return simple_cast_impl<
            quantity<unit<ArgumentDimension, ArgumentPrefix>, ResultValueType>, void>{}(
            rhs);
    }
    template <class ArgumentDimension, class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto
        operator()(const quantity_point<unit<ArgumentDimension, ArgumentPrefix>,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<unit<ArgumentDimension, ArgumentPrefix>, ArgumentValueType>
    {
        return simple_cast_impl<
            quantity_point<unit<ArgumentDimension, ArgumentPrefix>, ArgumentValueType>,
            void>{}(rhs);
    }
};

template <class ResultUnit, class ResultValueType = void>
constexpr simple_cast_impl<std::remove_cv_t<ResultUnit>,
                           std::remove_cv_t<ResultValueType>>
    simple_cast = simple_cast_impl<std::remove_cv_t<ResultUnit>,
                                   std::remove_cv_t<ResultValueType>>{};
#pragma endregion
#pragma region unit_cast
// The unit_cast function lets you cast one quantity/quantity_point to another unit
// and/or value_type. This is done by multiplying the value of the quantity/quantity_point
// with the right conversion constant. The unit_cast function uses std::pow for the con-
// version. This allows it to calculate arbitrary roots, but makes it incompatible with
// compile time evaluation. The function is still marked constexpr, to be forward com-
// patible with a constexpr std::pow implementation.
template <class ResultUnit, class ResultValueType>
struct unit_cast_impl
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType>
struct unit_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                      void>
{
    // From quantity to quantity
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ArgumentPrefix>, ArgumentValueType>& rhs)
        const noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ArgumentPrefix>, ResultValueType>& rhs) const
        noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>{rhs.value()
                                                                              * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ResultPrefix>, ArgumentValueType>& rhs) const
        noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        return quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>& rhs) const
        noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From Other to quantity
    template <class Other>
    [[nodiscard]] constexpr auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>>,
            quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>>
    {
        return quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>{rhs};
    }
};
template <class ResultDimension, class ResultPrefix, class ResultValueType>
struct unit_cast_impl<
    quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>, void>
{
    // From quantity_point to quantity_point
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto
        operator()(const quantity_point<unit<ResultDimension, ArgumentPrefix>,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ArgumentValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            static_cast<ResultValueType>(rhs.value() * factor)};
    }
    template <class ArgumentPrefix>
    [[nodiscard]] constexpr auto operator()(
        const quantity_point<unit<ResultDimension, ArgumentPrefix>, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        const auto factor = runtime_expand_prefix_list<ResultValueType>(
            type::divide_lists<ArgumentPrefix, ResultPrefix>{});
        return quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            rhs.value() * factor};
    }
    template <class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity_point<unit<ResultDimension, ResultPrefix>, ArgumentValueType>& rhs)
        const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        return quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>{
            static_cast<ResultValueType>(rhs.value())};
    }
    [[nodiscard]] constexpr auto operator()(
        const quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>& rhs)
        const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>
    {
        return rhs;
    }
    // From Other to quantity_point
    template <class Other>
    [[nodiscard]] constexpr auto operator()(const Other& rhs) const noexcept
        -> std::enable_if_t<
            type::detect_if<
                Other, is_convertible_into,
                quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>>,
            quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>>
    {
        return quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>{rhs};
    }
};
template <class ResultDimension, class ResultPrefix, class ResultValueType,
          class OtherResultValueType>
struct unit_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                      OtherResultValueType> :
    unit_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, OtherResultValueType>,
                   void>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType,
          class OtherResultValueType>
struct unit_cast_impl<OtherResultValueType,
                      quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>> :
    unit_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                   OtherResultValueType>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType,
          class OtherResultValueType>
struct unit_cast_impl<
    quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>,
    OtherResultValueType> :
    unit_cast_impl<
        quantity_point<unit<ResultDimension, ResultPrefix>, OtherResultValueType>, void>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType,
          class OtherResultValueType>
struct unit_cast_impl<
    OtherResultValueType,
    quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>> :
    unit_cast_impl<quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                   OtherResultValueType>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType>
struct unit_cast_impl<unit<ResultDimension, ResultPrefix>, ResultValueType> :
    unit_cast_impl<quantity<unit<ResultDimension, ResultPrefix>, ResultValueType>, void>,
    unit_cast_impl<quantity_point<unit<ResultDimension, ResultPrefix>, ResultValueType>,
                   void>
{
};
template <class ResultDimension, class ResultPrefix, class ResultValueType>
struct unit_cast_impl<ResultValueType, unit<ResultDimension, ResultPrefix>> :
    unit_cast_impl<unit<ResultDimension, ResultPrefix>, ResultValueType>
{
};
template <class ResultDimension, class ResultPrefix>
struct unit_cast_impl<unit<ResultDimension, ResultPrefix>, void>
{
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ResultDimension, ArgumentPrefix>, ArgumentValueType>& rhs)
        const noexcept -> quantity<unit<ResultDimension, ResultPrefix>, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity<unit<ResultDimension, ResultPrefix>, ArgumentValueType>, void>{}(
            rhs);
    }
    template <class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto
        operator()(const quantity_point<unit<ResultDimension, ArgumentPrefix>,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<unit<ResultDimension, ResultPrefix>, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<unit<ResultDimension, ResultPrefix>, ArgumentValueType>,
            void>{}(rhs);
    }
};
template <class ResultValueType>
struct unit_cast_impl<ResultValueType, void>
{
    template <class ArgumentDimension, class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto operator()(
        const quantity<unit<ArgumentDimension, ArgumentPrefix>, ArgumentValueType>& rhs)
        const noexcept
        -> quantity<unit<ArgumentDimension, ArgumentPrefix>, ResultValueType>
    {
        return unit_cast_impl<
            quantity<unit<ArgumentDimension, ArgumentPrefix>, ResultValueType>, void>{}(
            rhs);
    }
    template <class ArgumentDimension, class ArgumentPrefix, class ArgumentValueType>
    [[nodiscard]] constexpr auto
        operator()(const quantity_point<unit<ArgumentDimension, ArgumentPrefix>,
                                        ArgumentValueType>& rhs) const noexcept
        -> quantity_point<unit<ArgumentDimension, ArgumentPrefix>, ArgumentValueType>
    {
        return unit_cast_impl<
            quantity_point<unit<ArgumentDimension, ArgumentPrefix>, ArgumentValueType>,
            void>{}(rhs);
    }
};

template <class ResultUnit, class ResultValueType = void>
constexpr unit_cast_impl<std::remove_cv_t<ResultUnit>, std::remove_cv_t<ResultValueType>>
    unit_cast =
        unit_cast_impl<std::remove_cv_t<ResultUnit>, std::remove_cv_t<ResultValueType>>{};
#pragma endregion
#pragma region argument dependent lookup helper
namespace casts
{
using benri::remove_prefix;
using benri::simple_cast;
using benri::unit_cast;
using benri::value_type_cast;
} // namespace casts
#pragma endregion
} // namespace benri