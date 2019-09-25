# Changes
**benri** uses [Semantic Versioning](https://semver.org/) to index its versions.

## v2.0.1 - Second release
This is the second full release of *benri*. The library was improved by adding `<chrono>`
support, fixing bugs and implementing more unit tests. Besides quality of life updates,
bug fixing, and more unit tests, this seems to be the final version of *benri*. No further,
compatibility breaking upgrades are planned for the future.

## v2.0.0 - `<chrono>` support
- *benri* now supports interaction with the `<chrono>` library.
- In order to be forward-compatible with the C++20 version of `<chrono>`, the month and
  year types had to be be modified:
  + `month_t` is now `calendar_month_t` with a length of 2.592×10⁶ s.
  + `year_t` is now `calendar_year_t` with a length of 3.155 760×10⁷ s
  + `month_t` maps now to the new `gregorian_month_t` with a length of 2.629 746×10⁶ s.
  + `year_t` maps now to the new `gregorian_year_t` with a length of 3.155 695 2×10⁷ s
  + Because `lightyear_t` is a function of `year_t` it slightly changes as well.

## v1.0.1 - Patch
- Fixed a long existing bug in `simple_cast` which prevented converting `quantity_point`.
- Fixed the `is_quantity_point` falsely taking into account cv-qualifiers.
- Fixed non benri types not being converted into `quantity` when using `quantity_point`
  math.

## v1.0.0 - New type conversion system
- Replaced the `is_compatible` with the new `convert` struct.
- The struct still provides a check if units should be implicitly convertible.
- It now additionally handles the actual conversion.
- This now allows us to interact with non *benri* types.

## v0.2.0 - Improved temperatures
- Added unit test for temperature conversion.
- Added unit test for affine units (via temperatures).
- Added the `absolute_zero` constant.

## v0.1.3 - Minor patch
- Improved cmake settings.

## v0.1.2 - Minor patch
- Fixed floating point conversion warning inside static_assert.

## v0.1.1 - Minor patch
- Some C++17 type_traits were used by mistake instead of the C++14 one.

## v0.1.0 - First release
First complete user experience. Among others, the following basic functions have been
implemented:
- SI units
- Astronomical units
- CGS units
- Imperial units
- Computer Science units
- temperatures
- affine types
- unit conversions
- unit math
- conversions between builtin types and the unit 1.
- user defined dimensions, units and constants/symbols
- named dimensions
- arbitrary prefix conversions
- unit compatibility helper
- examples
- unit tests
