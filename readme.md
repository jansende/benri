# Readme
**benri** is a header-only c++ library for compile time checking of physical quantities. **benri** supports dimensional analysis and conversions of physical units at compile time.

# TODO
- [ ] Implement a point type.
- [ ] Implement units.
- [ ] Use backsubstitution on dimensions?
- [ ] Allow normal math for dimensionless quantities.
- [ ] Write unit tests.
- [ ] Write cmath functions.
- [ ] Support dimensionless to radian/steradian conversions.

## Table of units

| Base quantity                                                        | Categories    | Dimension        | Unit                            | Symbol    | Conversion                                     |
|:---------------------------------------------------------------------|:--------------|:-----------------|:--------------------------------|:----------|:-----------------------------------------------|
| length                                                               | SI, base      | L                | metre                           | m         | (base unit)                                    |
|                                                                      | extra         |                  | astronomical unit               | AU        | 1 AU = 1.495 978 706 91(6)×10¹¹ m              |
|                                                                      | extra         |                  | parsec                          | pc        | 1 pc = 3.085 678×10¹⁶ m                        |
|                                                                      | extra         |                  | lightyear                       | lyr       | 1 lyr = c × 365.25 d = 9 460 730 472 580 800 m |
|                                                                      | extra         |                  | atomic unit of length, bohr     | a₀        | 1 a₀ = 0.529 177 2108(18)×10⁻¹⁰ m              |
|                                                                      | extra         |                  | ångström                        | Å         | 1 Å = 10⁻¹⁰ m                                  |
|                                                                      | imperial      |                  | nautical mile                   | M         | 1 M = 1852 m                                   |
|                                                                      | imperial      |                  | international mile              | mi        | 1 mi = 5280 ft = 1609.344 m                    |
|                                                                      | imperial      |                  | yard                            | yd        | 1 yd = 0.9144 m                                |
|                                                                      | imperial      |                  | international foot              | ', ft     | 1 ft = 0.3048 m                                |
|                                                                      | imperial      |                  | inch                            | ", in     | 39.37 in = 1 m                                 |
| mass                                                                 | SI, base      | M                | kilogram                        | kg        | (base unit)                                    |
|                                                                      | SI            |                  | tonne, metric ton               | t         | 1 t = 10³ kg                                   |
|                                                                      | extra         |                  | dalton                          | Da        | 1 Da = 1.660 538 86(28)×10⁻²⁷ kg               |
|                                                                      | extra         |                  | unified atomic mass unit        | u         | 1 u = 1 Da                                     |
|                                                                      | extra         |                  | natural unit of mass            | m_e       | 1 m_e = 9.109 3826(16)×10⁻³¹ kg                |
|                                                                      | extra         |                  | earth mass                      | M_Earth   | 1 M_Earth =  kg                                |x
|                                                                      | extra         |                  | jupiter mass                    | M_Jupiter | 1 M_Jupiter =  kg                              |x
|                                                                      | extra         |                  | solar mass                      | M_Sun     | 1 M_Sun =  kg                                  |x
|                                                                      | imperial      |                  | photometric carat               | carat     | 1 carat = 2×10⁻⁴ kg                            |
|                                                                      | imperial      |                  | pound                           | lb        | 1 lb = 4.535 923 7×10⁻¹ kg                     |
|                                                                      | imperial      |                  | ounce                           | oz        | 1 oz = 2.834 952×10⁻² kg                       |
| time, duration                                                       | SI, base      | T                | second                          | s         | (base unit)                                    |
|                                                                      | SI            |                  | minute                          | min       | 1 min = 60 s                                   |
|                                                                      | SI            |                  | hour                            | h         | 1 h = 60 min = 3 600 s                         |
|                                                                      | SI            |                  | day                             | d         | 1 d = 24 h = 86 400 s                          |
|                                                                      | SI            |                  | week                            | w         | 1 w = 7 d = 604 800 s                          |
|                                                                      | SI            |                  | month                           |           | 1 month = 30 d = 2 592 000 s                   |
|                                                                      | SI            |                  | year                            | yr        | 1 yr = 365.25 d = 3.155 760×10⁷ s              |
|                                                                      | extra         |                  | sidereal year                   |           | 1 sidereal year = 3.155 815×10⁷ s              |
|                                                                      | extra         |                  | tropical year                   |           | 1 tropical year = 3.155 693×10⁷ s              |
|                                                                      | extra         |                  | natural unit of time            | ħ/(me c²) | 1 ħ/(me c²) = 1.288 088 6677(86)×10⁻²¹ s       |
|                                                                      | extra         |                  | atomic unit of time             | ħ/Eh      | 1 ħ/Eh = 2.418 884 326 505(16)×10⁻¹⁷ s         |
| electric current                                                     | SI, base      | I                | ampere                          | A         | (base unit)                                    |
| thermodynamic temperature                                            | SI, base      | Θ                | kelvin                          | K         | (base unit)                                    |
|                                                                      | SI            |                  | degree Celsius                  | °C        | T/K = t/°C + 273.15                            |
|                                                                      | imperial      |                  | degree Fahrenheit               | °F        | T/K = (t/°F - 459.67)/1.8                      |
|                                                                      | imperial      |                  | degree Rankine                  | °R        | T/K = (t/°R)/1.8                               |
| amount of substance                                                  | SI, base      | N                | mole                            | mol       | (base unit)                                    |
| luminous intensity                                                   | SI, base      | J                | candela                         | cd        | (base unit)                                    |
| area                                                                 | SI            | L²               | square metre                    |           | 1 m²                                           |
|                                                                      | SI            |                  | hectare                         | ha        | 1 ha = 10⁴ m²                                  |
|                                                                      | imperial      |                  | barn                            | b         | 1 b = 10⁻²⁸ m²                                 |
| volume                                                               | SI            | L³               | cubic metre                     |           | 1 m³                                           |
|                                                                      | SI            |                  | litre                           | l         | 1 l = 10⁻³ m³                                  |
| speed, velocity                                                      | SI            | L T⁻¹            | metre per second                |           | 1 m/s                                          |
|                                                                      | SI            |                  | kilometre per hour              |           | 1 km/h = (1000/3600) m/s                       |
|                                                                      | extra         |                  | natural unit of speed           | c         | 1 c = 299 792 458 m/s (exact)                  |
|                                                                      | imperial      |                  | knot (nautical mile per hour)   | kn        | 1 M/h = 1852/3600 m/s                          |
| acceleration                                                         | SI            | L T⁻²            | metre per second squared        |           | 1 m/s²                                         |
|                                                                      | CGS           |                  | gal                             | Gal       | 1 Gal = 10⁻² m s⁻²                             |
| wavenumber                                                           | SI            | L⁻¹              | reciprocal metre                |           | 1 m⁻¹                                          |
| density, mass density, mass concentration                            | SI            | L⁻³ M            | kilogram per cubic metre        |           | 1 kg/m³                                        |
| surface density, area density                                        | SI            | L⁻² M            | kilogram per square metre       |           | 1 kg/m²                                        |
| specific volume                                                      | SI            | L³ M⁻¹           | cubic metre per kilogram        |           | 1 m³/kg                                        |
| current density                                                      | SI            | L⁻² I            | ampere per square metre         |           | 1 A/m²                                         |
| magnetic field strength, magnetization                               | SI            | L⁻¹ I            | ampere per metre                |           | 1 A/m                                          |
|                                                                      | CGS           |                  | œrsted                          | Oe        | 1 Oe = (10³/4π) A m⁻¹                          |
| amount concentration, concentration, molar concentration             | SI            | L⁻³ N            | mole per cubic metre            |           | 1 mol/m³                                       |
| luminance                                                            | SI            | L⁻² J            | candela per square metre        |           | 1 cd/m²                                        |
|                                                                      | CGS           |                  | stilb                           | sb        | 1 sb = 10⁴ cd m⁻²                              |
| refractive index                                                     | removed       | 1                | one                             |           | 1                                              |
| relative permeability                                                | removed       | 1                | one                             |           | 1                                              |
| angle, plane angle                                                   | SI, base      | A                | radian                          | rad       | 1 rad = 1 m/m (base unit)                      |
|                                                                      | SI            |                  | degree                          | °         | 1 ° = (π/    180) rad                          |
|                                                                      | SI            |                  | minute                          | '         | 1 ' = (π/ 10 800) rad                          |
|                                                                      | SI            |                  | second, arcsecond               | ", as     | 1 " = (π/648 000) rad                          |
|                                                                      | extra         |                  | gon, grad                       | gon       | 1 gon = (π/    200) rad                        |
|                                                                      | imperial      |                  | revolution                      | r         | 1 r = 2π rad                                   |
| solid angle                                                          | SI            | A²               | steradian                       | sr        | 1 sr = 1 rad² = 1 m²/m²                        |
| frequency                                                            | SI            | T⁻¹              | hertz                           | Hz        | 1 Hz = 1 s⁻¹                                   |
| force                                                                | SI            | L M T⁻²          | newton                          | N         | 1 N = 1 m kg s⁻²                               |
|                                                                      | CGS           |                  | dyne                            | dyn       | 1 dyn = 10⁻⁵ N                                 |
|                                                                      | imperial      |                  | kilogram-force                  | kgf       | 1 kgf = 9.806 65 N                             |
| pressure, stress                                                     | SI            | L⁻¹ M T⁻²        | pascal                          | Pa        | 1 Pa = 1 N/m² = 1 m⁻¹ kg s⁻²                   |
|                                                                      | extra         |                  | bar                             | bar       | 1 bar = 10⁵ Pa                                 |
|                                                                      | extra         |                  | millimetre of mercury           | mmHg      | 1 mmHg = 133.322 Pa                            |
|                                                                      | imperial      |                  | standard atmosphere             | atm       | 1 atm = 101 325 Pa                             |
|                                                                      | imperial      |                  | torr                            | Torr      | 1 Torr = (101 325/760) Pa                      |
| energy, work, amount of heat                                         | SI            | L² M T⁻²         | joule                           | J         | 1 J = 1 N m = 1 m² kg s⁻²                      |
|                                                                      | SI            |                  | watt hour                       |           | 1 W h = 3 600 J                                |
|                                                                      | extra         |                  | electronvolt                    | eV        | 1 eV = 1.602 176 53(14)×10⁻¹⁹ J                |
|                                                                      | imperial      |                  | calorie                         | cal       | 1 cal = 4.184 J                                |
|                                                                      | extra         |                  | atomic unit of energy, hartree  | Eh        | 1 Eh = 4.359 744 17(75)×10⁻¹⁸ J                |
|                                                                      | CGS           |                  | erg                             | erg       | 1 erg = 10⁻⁷ J                                 |
| power, radiant flux                                                  | SI            | L² M T⁻³         | watt                            | W         | 1 W = 1 J/s = 1 m² kg s⁻³                      |
| electric charge, amount of electricty                                | SI            | T I              | coulomb                         | C         | 1 C = 1 s A                                    |
|                                                                      | SI            |                  | ampere hour                     |           | 1 A h = 3 600 A s                              |
|                                                                      | extra         |                  | atomic unit of charge           | e         | 1 e = 1.602 176 53(14)×10⁻¹⁹ C                 |
| electric potential difference, electromotive force                   | SI            | L² M T⁻³ I⁻¹     | volt                            | V         | 1 V = 1 W/A = 1 m² kg s⁻³ A⁻¹                  |
| capacitance                                                          | SI            | L⁻² M⁻¹ T⁴ I²    | farad                           | F         | 1 F = 1C/V = 1 m⁻² kg⁻¹ s⁴ A²                  |
| electric resitance, impedance                                        | SI            | L² M T⁻³ I⁻²     | ohm                             | Ω         | 1 Ω = 1V/A = 1 m² kg s⁻³ A⁻²                   |
| electric conductance                                                 | SI            | L⁻² M⁻¹ T³ I²    | siemens                         | S         | 1 S = 1A/V = 1 m⁻² kg⁻¹ s³ A²                  |
| magnetic flux                                                        | SI            | L² M T⁻² I⁻¹     | weber                           | Wb        | 1 Wb = 1V s = 1 m² kg s⁻² A⁻¹                  |
|                                                                      | CGS           |                  | maxwell                         | Mx        | 1 Mx = 10⁻⁸ Wb                                 |
| magnetic flux density                                                | SI            | M T⁻² I⁻¹        | tesla                           | T         | 1 T = 1 Wb/m² = 1 kg s⁻² A⁻¹                   |
|                                                                      | CGS           |                  | gauss                           | G         | 1 G = 10⁻⁴ T                                   |
| inductance                                                           | SI            | L² M T⁻² I⁻²     | henry                           | H         | 1 H = 1 Wb/A = 1 m² kg s⁻² A⁻²                 |
| luminous flux                                                        | SI            | J A²             | lumen                           | lm        | 1 lm = 1 cd sr                                 |
| illuminance                                                          | SI            | L⁻² J A²         | lux                             | lx        | 1 lx = 1 lm/m² = 1 m⁻² cd sr                   |
|                                                                      | CGS           |                  | phot                            | ph        | 1 ph = 10⁴ lx                                  |
| luminosity, radiant intensity                                        | SI            | L² M T⁻³ A⁻²     | watt per steradian              | W/sr      | 1 W/sr = 1 m² kg s⁻³                           |
|                                                                      | extra         |                  | solar luminosity                | L_Sun     | 1 L_sun = W/sr                                 |
| number of radioactive events, counts                                 | SI, base      | C                | count                           | Count     | 1 (base unit)                                  |
| activity referred to a radionuclide                                  | SI            | T⁻¹ C            | becquerel                       | Bq        | 1 Bq = 1 Count s⁻¹                             |
|                                                                      | imperial      |                  | curie                           | Ci        | 1 Ci = 3.7×10¹⁰ Bq                             |
| absorbed does, specific energy (imparted), kerma                     | SI            | L² T⁻²           | gray                            | Gy        | 1 Gy = 1 J/kg = 1 m² s⁻²                       |
|                                                                      | imperial      |                  | rad                             | rd        | 1 rd = 10⁻² Gy                                 |
| dose equivalent, ambient does equivalent, personal dose equivalent   | SI            | S L² T⁻²         | sievert                         | Sv        | 1 Sv = 1 J/kg = 1 m² s⁻²                       |
|                                                                      | imperial      |                  | roentgen equivalent man (rem)   | rem       | 1 rem = 10⁻² Sv                                |
| radiation weighting factor                                           | SI, base      | S                | sievert per gray                |           | 1 Sv/Gy (base unit)                            |
| tissue weighting factor                                              | removed       | 1                | one                             |           | 1                                              |
| catalytic activity                                                   | SI            | T⁻¹ N            | katal                           | kat       | 1 kat = 1 s⁻¹ mol                              |
| dynamic viscosity                                                    | SI            | L⁻¹ M T⁻¹        | pascal second                   |           | 1 Pa s = 1 m⁻¹ kg s⁻¹                          |
|                                                                      | CGS           |                  | poise                           | P         | 1 P = 0.1 Pa s = 0.1 m⁻¹ kg s⁻¹                |
| moment of force, torque                                              | SI            | L M T⁻² A⁻¹      | newton metre                    |           | 1 N m = 1 J/rad = 1 m² kg s⁻²                  |
| surface tension                                                      | SI            | M T⁻²            | newton per metre                |           | 1 N/m = 1 kg s⁻²                               |
| angular velocity                                                     | SI            | T⁻¹ A            | radian per second               |           | 1 rad/s = 1 m m⁻¹ s⁻¹                          |
|                                                                      | imperial      |                  | revolution per minute           | rpm       | 1 rpm = (2π/60) rad/s                          |
| angular acceleration                                                 | SI            | T⁻² A            | radian per second squared       |           | 1 rad/s² = 1 m m⁻¹ s⁻²                         |
| heat flux density, irradiance, intensity                             | SI            | M T⁻³            | watt per square metre           |           | 1 W/m² = 1 kg s⁻³                              |
| heat capacity, entropy                                               | SI            | L² M T⁻² Θ⁻¹     | joule per kelvin                |           | 1 J/K = 1 m² kg s⁻² K⁻¹                        |
| specific heat capacity, specific entropy                             | SI            | L² T⁻² Θ⁻¹       | joule per kilogram kelvin       |           | 1 J/(kg K) = 1 m² s⁻² K⁻¹                      |
| specific energy                                                      | removed       | L² T⁻²           | joule per kilogram              |           | 1 J/kg = 1 m² s⁻²                              |
| thermal conductivity                                                 | SI            | L M T⁻³ Θ⁻¹      | watt per metre kelvin           |           | 1 W/(m K) = 1 m kg s⁻³ K⁻¹                     |
| energy density                                                       | removed       | L⁻¹ M T⁻²        | joule per cubic metre           |           | 1 J/m³ = 1 m⁻¹ kg s⁻²                          |
| electric field strength                                              | SI            | L M T⁻³ I⁻¹      | volt per metre                  |           | 1 V/m = 1 m kg s⁻³ A⁻¹                         |
| electric charge density                                              | SI            | L⁻³ T I          | coulomb per cubic metre         |           | 1 C/m³ = 1 m⁻³ s A                             |
| surface charge density, electric flux density, electric displacement | SI            | L⁻² T I          | coulomb per square metre        |           | 1 C/m² = 1 m⁻² s A                             |
| permittivity                                                         | SI            | L⁻³ M⁻¹ T⁴ I²    | farad per metre                 |           | 1 F/m  = 1 m⁻³ kg⁻¹ s⁴ A²                      |
| permeability                                                         | SI            | L M T⁻² I⁻²      | henry per metre                 |           | 1 H/m = 1 m kg s⁻² A⁻²                         |
| molar energy, chemical potential                                     | SI            | L² M T⁻² N⁻¹     | joule per mole                  |           | 1 J/mol = 1 m² kg s⁻² mol⁻¹                    |
| molar entropy, molar heat capacity                                   | SI            | L² M T⁻² Θ⁻¹ N⁻¹ | joule per mole kelvin           |           | 1 J/(mol K) = 1 m² kg s⁻² K⁻¹ mol⁻¹            |
| exposure (x- and γ-rays)                                             | SI            | M⁻¹ T I          | coulomb per kilogram            |           | 1 C/kg = 1 kg⁻¹ s A                            |
|                                                                      | imperial      |                  | roentgen                        | R         | 1 R = 2.58×10⁻⁴ C/kg                           |
| absorbed dose rate                                                   | SI            | L² T⁻³           | gray per second                 |           | 1 Gy/s = 1 m² s⁻³                              |
| radiance                                                             | SI            | M T⁻³ A²         | watt per square metre steradian |           | 1 W/(m² sr) = 1 kg s⁻³                         |
| catalytic activity concentration                                     | SI            | L⁻³ T⁻¹ N        | katal per cubic metre           |           | 1 kat/m³ = 1 m⁻³ s⁻¹ mol                       |
| action                                                               | SI            | L² M T⁻¹         | joule second                    |           | 1 J s = 1 m² kg s⁻¹                            |
|                                                                      | extra         |                  | natural unit of action          | ħ         | 1 ħ = 1.054 571 68(18)×10⁻³⁴ J s               |
| kinematic viscosity                                                  | SI            | L² T⁻¹           | square metre per second         |           | 1 m²/s                                         |
|                                                                      | CGS           |                  | stokes                          | St        | 1 St = 10⁻⁴ m² s⁻¹                             |
| dimensionless quantities                                             | SI            | 1                | one                             |           | 1                                              |
|                                                                      | SI            |                  | percent                         | %         | 1 % = 10⁻²                                     |
|                                                                      | extra         |                  | permille                        | ‰         | 1 ‰ = 10⁻³                                     |
|                                                                      | extra         |                  | parts per million               | ppm       | 1 ppm = 10⁻⁶                                   |
| amount of data, disk space                                           | SI, data      | B                | bit                             | bit       | (base unit)                                    |
|                                                                      | SI, data      |                  | byte                            | B         | 1 B = 8 bit                                    |
| speed of data transfer, bandwidth                                    | SI, data      | T⁻¹ B            | bit per second                  |           | 1 bit/s                                        |
|                                                                      | SI, data      |                  | byte per second                 |           | 1 byte/s = 8 bit/s                             |
| screen position                                                      | data          | X                | pixel                           | px        | (base unit)                                    |
| screen area                                                          | data          | X²               | pixel                           | pixel     | 1 pixel = 1 px²                                |
| line density                                                         | extra         | L⁻¹ M            | kilogram per metre              |           | 1 kg/m                                         |
| absement                                                             | extra         | L T              | metre second                    |           | 1 m s                                          |
| jerk                                                                 | extra         | L T⁻³            | metre per cubic second          |           | 1 m s⁻³                                        |
| snap                                                                 | extra         | L T⁻⁴            | metre per second to the 4th     |           | 1 m s⁻⁴                                        |
| crackle                                                              | extra         | L T⁻⁵            | metre per second to the 5th     |           | 1 m s⁻⁵                                        |
| pop                                                                  | extra         | L T⁻⁶            | metre per second to the 6th     |           | 1 m s⁻⁶                                        |
| reaction rate                                                        | SI            | L⁻³ T⁻¹ N        | mole per cubic metre second     |           | 1 m⁻³ s⁻¹ mol                                  |
| electric conductivity                                                | extra         | L⁻³ M⁻¹ T³ I²    | siemens per metre               | S/m       | 1 S/m = 1A/V m = 1 m⁻³ kg⁻¹ s³ A²              |
| electric resitivity                                                  | extra         | L³ M T⁻³ I⁻²     | ohm metre                       | Ω m       | 1 Ω m = 1V m/A = 1 m kg s⁻³ A⁻²                |
| momentum, impulse                                                    | SI            | L M T⁻¹          | newton second                   | N s       | 1 N s = 1 m kg s⁻¹                             |
| angular momentum                                                     | SI            | L² M             | kilogram square metre           | N s       | 1 N s = 1 m kg s⁻¹                             |
| moment of inertia                                                    | SI            | L² M T⁻¹ A       | newton second radian            | N s rad   | 1 N s rad = 1 m kg s⁻¹                         |

## Unit generator
```
quantity   = value unit .
unit       = system (one|prefix|user defined prefix) dimension .
dimension  = {(base|user defined base) power} .
base       = L | M | T | I | Θ | N | J | A | C | S | B . //See table of dimensions
prefix     = (yocto | zepto | ... | yotta) //See table of prefixes
```

## Table of constants

| Name                      | Symbol | Value |
|:--------------------------|:-------|:------|
| speed of light            | c      |       |
| Stefan-Boltzmann constant | k_B    |       |
| gravitational constant    | G      |       |
| Planck constant           | h      |       |
| reduced Planck constant   | ħ      |       |
| Pi                        | π      |       |
| Euler's number            | e      |       |
| magnetic constant         | μ₀     |       |
| electric constant         | ε₀     |       |
| elementary charge         | e      |       |
| Bohr radius               | a₀     |       |
| electron mass             | m_e    |       |
| proton mass               | m_p    |       |
| atomic mass               | m_u    |       |
| Avogadro constant         | N_A    |       |
| Hartree energy            | Eh     |       |
## Table of base dimensions

| Base dimension                       | Symbol | benri |
|:-------------------------------------|:-------|:------|
| length                               | L      | L     |
| mass                                 | M      | M     |
| time, duration                       | T      | T     |
| electric current                     | I      | I     |
| thermodynamic temperature            | Θ      | H     |
| amount of substance                  | N      |       |
| luminous intensity                   | J      |       |
| angle, plane angle                   | A      |       |
| number of radioactive events, counts | C      |       |
| helper for sievert units             | S      |       |
| amount of data, bits, bytes          | B      |       |

## Table of SI prefixes

| Prefix | Symbol | Factor |
|:-------|:-------|:-------|
| yocto  | y      | 10⁻²⁴  |
| zepto  | z      | 10⁻²¹  |
| atto   | a      | 10⁻¹⁸  |
| femto  | f      | 10⁻¹⁵  |
| pico   | p      | 10⁻¹²  |
| nano   | n      | 10⁻⁹   |
| micro  | μ      | 10⁻⁶   |
| milli  | m      | 10⁻³   |
| centi  | c      | 10⁻²   |
| deci   | d      | 10⁻¹   |
| one    |        | 10⁰    |
| deca   | da     | 10¹    |
| hecto  | h      | 10²    |
| kilo   | k      | 10³    |
| mega   | M      | 10⁶    |
| giga   | G      | 10⁹    |
| tera   | T      | 10¹²   |
| peta   | P      | 10¹⁵   |
| exa    | E      | 10¹⁸   |
| zetta  | Z      | 10²¹   |
| yotta  | Y      | 10²⁴   |

## Table of data prefixes

| Prefix | Symbol | Factor |
|:-------|:-------|:-------|
| kibi   | ki     | 2¹⁰    |
| mebi   | Mi     | 2²⁰    |
| gibi   | Gi     | 2³⁰    |
| tebi   | Ti     | 2⁴⁰    |
| pebi   | Pi     | 2⁵⁰    |
| exbi   | Ei     | 2⁶⁰    |
| zebi   | Zi     | 2⁷⁰    |
| yobi   | Yi     | 2⁸⁰    |

## Table of custom prefixes

| Prefix | Symbol | Factor |
|:-------|:-------|:-------|
| dozen  |        | 12     |
| gross  |        | 144    |
