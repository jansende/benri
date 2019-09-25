# Changes
**benri** uses [Semantic Versioning](https://semver.org/) to index its versions.

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
