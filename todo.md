# TODO
- [x] Implement affine types.
- [ ] Implement units.
- [x] Use backsubstitution on dimensions?
- [x] Allow normal math for dimensionless quantities.
- [ ] Write unit tests.
- [x] Write cmath functions.
- [x] Write log<Unit>(Unit) functions.
- [ ] Write c++17 cmath functions.
- [ ] Write the sinc function.
- ~~[ ] Support dimensionless to radian/steradian conversions.~~
- [ ] Implement compile time special math, like log and exp?
- ~~[ ] Implement to_string for dimensions.~~
- ~~[ ] Implement to_string for units.~~
- ~~[ ] Implement a binary representation of the units.~~
- ~~[ ] Implement operator overloading for unit composition.~~
- [ ] std::chrono support
- [ ] std::common_type support
- [ ] write a warning about using integral types
- [ ] write an explanation for affine types
- [ ] document the is_compatible trickery
- [ ] do some cleaning up
- [ ] get the right value for the solar luminosity

## Quantities using Integral Types


## Table of units

 | Base quantity                                                        | Categories      | Dimension        | Unit                                | Symbol    | Conversion                                     |
 |:---------------------------------------------------------------------|:----------------|:-----------------|:------------------------------------|:----------|:-----------------------------------------------|
i| length                                                               | SI, base        | L                | metre                               | m         | (base unit)                                    |
i|                                                                      | extra           |                  | astronomical unit                   | AU        | 1 AU = 149 597 870 700 m                       |
i|                                                                      | extra           |                  | parsec                              | pc        | 1 pc = (648 000/π) au = 3.085 678...×10¹⁶ m    |
i|                                                                      | extra           |                  | lightyear                           | lyr       | 1 lyr = c × 365.25 d = 9 460 730 472 580 800 m |
i|                                                                      | extra           |                  | atomic unit of length, bohr         | a₀        | 1 a₀ = 0.529 177 2108(18)×10⁻¹⁰ m              |
i|                                                                      | extra           |                  | ångström                            | Å         | 1 Å = 10⁻¹⁰ m                                  |
i|                                                                      | imperial        |                  | nautical mile                       | M         | 1 M = 1852 m                                   |
i|                                                                      | imperial        |                  | international mile                  | mi        | 1 mi = 5280 ft = 1609.344 m                    |
i|                                                                      | imperial        |                  | yard                                | yd        | 1 yd = 0.9144 m                                |
i|                                                                      | imperial        |                  | international foot                  | ', ft     | 1 ft = 0.3048 m                                |
i|                                                                      | imperial        |                  | inch                                | ", in     | 39.37 in = 1 m                                 |
i| mass                                                                 | SI, base        | M                | kilogram                            | kg        | (base unit)                                    |
i|                                                                      | SI              |                  | tonne, metric ton                   | t         | 1 t = 10³ kg                                   |
i|                                                                      | extra           |                  | dalton                              | Da        | 1 Da = 1.660 538 86(28)×10⁻²⁷ kg               |
i|                                                                      | extra           |                  | unified atomic mass unit            | u         | 1 u = 1 Da                                     |
i|                                                                      | extra           |                  | natural unit of mass                | m_e       | 1 m_e = 9.109 3826(16)×10⁻³¹ kg                |
i|                                                                      | extra           |                  | earth mass                          | M_Earth   | 1 M_Earth (see table)                          |
i|                                                                      | extra           |                  | jupiter mass                        | M_Jupiter | 1 M_Jupiter (see table)                        |
i|                                                                      | extra           |                  | solar mass                          | M_Sun     | 1 M_Sun (see table)                            |
i|                                                                      | imperial        |                  | photometric carat                   | carat     | 1 carat = 2×10⁻⁴ kg                            |
i|                                                                      | imperial        |                  | pound                               | lb        | 1 lb = 4.535 923 7×10⁻¹ kg                     |
i|                                                                      | imperial        |                  | ounce                               | oz        | 1 oz = 2.834 952×10⁻² kg                       |
i| time, duration                                                       | SI, base        | T                | second                              | s         | (base unit)                                    |
i|                                                                      | SI              |                  | minute                              | min       | 1 min = 60 s                                   |
i|                                                                      | SI              |                  | hour                                | h         | 1 h = 60 min = 3 600 s                         |
i|                                                                      | SI              |                  | day                                 | d         | 1 d = 24 h = 86 400 s                          |
i|                                                                      | SI              |                  | week                                | w         | 1 w = 7 d = 604 800 s                          |
i|                                                                      | SI              |                  | month                               |           | 1 month = 30 d = 2 592 000 s                   |
i|                                                                      | SI              |                  | year                                | yr        | 1 yr = 365.25 d = 3.155 760×10⁷ s              |
i|                                                                      | extra           |                  | sidereal year                       |           | 1 sidereal year = 3.155 815×10⁷ s              |
i|                                                                      | extra           |                  | tropical year                       |           | 1 tropical year = 3.155 693×10⁷ s              |
i|                                                                      | extra           |                  | natural unit of time                | ħ/(m_e c²)| 1 ħ/(m_e c²) = 1.288 088 6677(86)×10⁻²¹ s      |
i|                                                                      | extra           |                  | atomic unit of time                 | ħ/Eh      | 1 ħ/Eh = 2.418 884 326 505(16)×10⁻¹⁷ s         |
i| electric current                                                     | SI, base        | I                | ampere                              | A         | (base unit)                                    |
i| thermodynamic temperature                                            | SI, base        | Θ                | kelvin                              | K         | (base unit)                                    |
i|                                                                      | SI              |                  | degree Celsius                      | °C        | T/K = t/°C + 273.15                            |
i|                                                                      | imperial        |                  | degree Fahrenheit                   | °F        | T/K = (t/°F - 459.67)/1.8                      |
i|                                                                      | imperial        |                  | degree Rankine                      | °R        | T/K = (t/°R)/1.8, T/°F = t/°R + 459.67         |
i| amount of substance                                                  | SI, base        | N                | mole                                | mol       | (base unit)                                    |
i| luminous intensity                                                   | SI, base        | J                | candela                             | cd        | (base unit)                                    |
i| area                                                                 | SI              | L²               | square metre                        |           | 1 m²                                           |
i|                                                                      | SI              |                  | hectare                             | ha        | 1 ha = 10⁴ m²                                  |
i|                                                                      | imperial        |                  | barn                                | b         | 1 b = 10⁻²⁸ m²                                 |
i| volume                                                               | SI              | L³               | cubic metre                         |           | 1 m³                                           |
i|                                                                      | SI              |                  | litre                               | l         | 1 l = 10⁻³ m³                                  |
i| speed, velocity                                                      | SI              | L T⁻¹            | metre per second                    |           | 1 m/s                                          |
i|                                                                      | SI              |                  | kilometre per hour                  |           | 1 km/h = (1000/3600) m/s                       |
i|                                                                      | extra           |                  | natural unit of speed               | c         | 1 c = 299 792 458 m/s (exact)                  |
i|                                                                      | imperial        |                  | knot (nautical mile per hour)       | kn        | 1 M/h = 1852/3600 m/s                          |
i| acceleration                                                         | SI              | L T⁻²            | metre per second squared            |           | 1 m/s²                                         |
i|                                                                      | CGS             |                  | gal                                 | Gal       | 1 Gal = 10⁻² m s⁻²                             |
i| wavenumber                                                           | SI              | L⁻¹              | reciprocal metre                    |           | 1 m⁻¹                                          |
i| density, mass density, mass concentration                            | SI              | L⁻³ M            | kilogram per cubic metre            |           | 1 kg/m³                                        |
i| surface density, area density                                        | SI              | L⁻² M            | kilogram per square metre           |           | 1 kg/m²                                        |
i| specific volume                                                      | SI              | L³ M⁻¹           | cubic metre per kilogram            |           | 1 m³/kg                                        |
i| current density                                                      | SI              | L⁻² I            | ampere per square metre             |           | 1 A/m²                                         |
i| magnetic field strength, magnetization                               | SI              | L⁻¹ I            | ampere per metre                    |           | 1 A/m                                          |
i|                                                                      | CGS             |                  | œrsted                              | Oe        | 1 Oe = (10³/4π) A m⁻¹                          |
i| amount concentration, concentration, molar concentration             | SI              | L⁻³ N            | mole per cubic metre                |           | 1 mol/m³                                       |
i| luminance                                                            | SI              | L⁻² J            | candela per square metre            |           | 1 cd/m²                                        |
i|                                                                      | CGS             |                  | stilb                               | sb        | 1 sb = 10⁴ cd m⁻²                              |
i| refractive index                                                     | removed         | 1                | one                                 |           | 1                                              |
i| relative permeability                                                | removed         | 1                | one                                 |           | 1                                              |
i| angle, plane angle                                                   | SI, base        | A                | radian                              | rad       | 1 rad = 1 m/m (base unit)                      |
i|                                                                      | SI              |                  | degree                              | °         | 1 ° = (π/    180) rad                          |
i|                                                                      | SI              |                  | minute, arcminute                   | ', amin   | 1 ' = (π/ 10 800) rad                          |
i|                                                                      | SI              |                  | second, arcsecond                   | ", as     | 1 " = (π/648 000) rad                          |
i|                                                                      | extra           |                  | gon, grad                           | gon       | 1 gon = (π/    200) rad                        |
i|                                                                      | imperial        |                  | revolution                          | r         | 1 r = 2π rad                                   |
i| solid angle                                                          | SI              | A²               | steradian                           | sr        | 1 sr = 1 rad² = 1 m²/m²                        |
i| frequency                                                            | SI              | T⁻¹              | hertz                               | Hz        | 1 Hz = 1 s⁻¹                                   |
i| force                                                                | SI              | L M T⁻²          | newton                              | N         | 1 N = 1 m kg s⁻²                               |
i|                                                                      | CGS             |                  | dyne                                | dyn       | 1 dyn = 10⁻⁵ N                                 |
 |                                                                      | imperial        |                  | kilogram-force                      | kgf       | 1 kgf = 9.806 65 N                             |
i| pressure, stress                                                     | SI              | L⁻¹ M T⁻²        | pascal                              | Pa        | 1 Pa = 1 N/m² = 1 m⁻¹ kg s⁻²                   |
i|                                                                      | extra           |                  | bar                                 | bar       | 1 bar = 10⁵ Pa                                 |
i|                                                                      | extra           |                  | millimetre of mercury               | mmHg      | 1 mmHg = 133.322 Pa                            |
i|                                                                      | imperial        |                  | standard atmosphere                 | atm       | 1 atm = 101 325 Pa                             |
i|                                                                      | imperial        |                  | torr                                | Torr      | 1 Torr = (101 325/760) Pa                      |
i| energy, work, amount of heat                                         | SI              | L² M T⁻²         | joule                               | J         | 1 J = 1 N m = 1 m² kg s⁻²                      |
i|                                                                      | SI              |                  | watt hour                           |           | 1 W h = 3 600 J                                |
i|                                                                      | extra           |                  | electronvolt                        | eV        | 1 eV = 1.602 176 53(14)×10⁻¹⁹ J                |
 |                                                                      | imperial        |                  | calorie                             | cal       | 1 cal = 4.184 J                                |
i|                                                                      | extra           |                  | atomic unit of energy, hartree      | Eh        | 1 Eh = 4.359 744 17(75)×10⁻¹⁸ J                |
i|                                                                      | CGS             |                  | erg                                 | erg       | 1 erg = 10⁻⁷ J                                 |
i| power, radiant flux                                                  | SI              | L² M T⁻³         | watt                                | W         | 1 W = 1 J/s = 1 m² kg s⁻³                      |
i| electric charge, amount of electricty                                | SI              | T I              | coulomb                             | C         | 1 C = 1 s A                                    |
i|                                                                      | SI              |                  | ampere hour                         |           | 1 A h = 3 600 A s                              |
i|                                                                      | extra           |                  | atomic unit of charge               | e         | 1 e = 1.602 176 53(14)×10⁻¹⁹ C                 |
i| electric potential difference, electromotive force                   | SI              | L² M T⁻³ I⁻¹     | volt                                | V         | 1 V = 1 W/A = 1 m² kg s⁻³ A⁻¹                  |
i| capacitance                                                          | SI              | L⁻² M⁻¹ T⁴ I²    | farad                               | F         | 1 F = 1C/V = 1 m⁻² kg⁻¹ s⁴ A²                  |
i| electric resitance, impedance                                        | SI              | L² M T⁻³ I⁻²     | ohm                                 | Ω         | 1 Ω = 1V/A = 1 m² kg s⁻³ A⁻²                   |
i| electric conductance                                                 | SI              | L⁻² M⁻¹ T³ I²    | siemens                             | S         | 1 S = 1A/V = 1 m⁻² kg⁻¹ s³ A²                  |
i| magnetic flux                                                        | SI              | L² M T⁻² I⁻¹     | weber                               | Wb        | 1 Wb = 1V s = 1 m² kg s⁻² A⁻¹                  |
i|                                                                      | CGS             |                  | maxwell                             | Mx        | 1 Mx = 10⁻⁸ Wb                                 |
i| magnetic flux density                                                | SI              | M T⁻² I⁻¹        | tesla                               | T         | 1 T = 1 Wb/m² = 1 kg s⁻² A⁻¹                   |
i|                                                                      | CGS             |                  | gauss                               | G         | 1 G = 10⁻⁴ T                                   |
i| inductance                                                           | SI              | L² M T⁻² I⁻²     | henry                               | H         | 1 H = 1 Wb/A = 1 m² kg s⁻² A⁻²                 |
i| luminous flux                                                        | SI              | J A²             | lumen                               | lm        | 1 lm = 1 cd sr                                 |
i| illuminance                                                          | SI              | L⁻² J A²         | lux                                 | lx        | 1 lx = 1 lm/m² = 1 m⁻² cd sr                   |
 |                                                                      | CGS             |                  | phot                                | ph        | 1 ph = 10⁴ lx                                  |
i| luminosity, radiant intensity                                        | SI              | L² M T⁻³ A⁻²     | watt per steradian                  | W/sr      | 1 W/sr = 1 m² kg s⁻³                           |
 |                                                                      | extra           |                  | solar luminosity                    | L_Sun     | 1 L_sun (see table)                            |
i| number of radioactive events, counts                                 | SI, base        | C                | count                               | Count     | 1 (base unit)                                  |
i| activity referred to a radionuclide                                  | SI              | T⁻¹ C            | becquerel                           | Bq        | 1 Bq = 1 Count s⁻¹                             |
 |                                                                      | imperial        |                  | curie                               | Ci        | 1 Ci = 3.7×10¹⁰ Bq                             |
i| absorbed does, specific energy (imparted), kerma                     | SI              | L² T⁻²           | gray                                | Gy        | 1 Gy = 1 J/kg = 1 m² s⁻²                       |
 |                                                                      | imperial        |                  | rad                                 | rd        | 1 rd = 10⁻² Gy                                 |
i| dose equivalent, ambient does equivalent, personal dose equivalent   | SI              | S L² T⁻²         | sievert                             | Sv        | 1 Sv = 1 J/kg = 1 m² s⁻²                       |
 |                                                                      | imperial        |                  | roentgen equivalent man (rem)       | rem       | 1 rem = 10⁻² Sv                                |
i| radiation weighting factor                                           | SI, base        | S                | sievert per gray                    |           | 1 Sv/Gy (base unit)                            |
i| tissue weighting factor                                              | removed         | 1                | one                                 |           | 1                                              |
i| catalytic activity                                                   | SI              | T⁻¹ N            | katal                               | kat       | 1 kat = 1 s⁻¹ mol                              |
i| dynamic viscosity                                                    | SI              | L⁻¹ M T⁻¹        | pascal second                       |           | 1 Pa s = 1 m⁻¹ kg s⁻¹                          |
i|                                                                      | CGS             |                  | poise                               | P         | 1 P = 0.1 Pa s = 0.1 m⁻¹ kg s⁻¹                |
i| moment of force, torque                                              | SI              | L² M T⁻² A⁻¹     | joule per radian                    |           | 1 J/rad = 1 m² kg s⁻²                          |
 | surface tension                                                      | SI              | M T⁻²            | newton per metre                    |           | 1 N/m = 1 kg s⁻²                               |
i| angular velocity                                                     | SI              | T⁻¹ A            | radian per second                   |           | 1 rad/s = 1 m m⁻¹ s⁻¹                          |
 |                                                                      | imperial        |                  | revolution per minute               | rpm       | 1 rpm = (2π/60) rad/s                          |
i| angular acceleration                                                 | SI              | T⁻² A            | radian per second squared           |           | 1 rad/s² = 1 m m⁻¹ s⁻²                         |
i| heat flux density, irradiance, intensity                             | SI              | M T⁻³            | watt per square metre               |           | 1 W/m² = 1 kg s⁻³                              |
i| spectral heat flux density, spectral irradiance                      | SI              | M T⁻²            | watt per square metre hertz         |           | 1 W/m²Hz = 1 kg s⁻²                            |
i| (implemented in terms of surface tension)                            | SI              |                  | Jansky                              | Jy        | 1 Jy = 10⁻²⁶ W/m²Hz = 1 kg s⁻²                 |
i| heat capacity, entropy                                               | SI              | L² M T⁻² Θ⁻¹     | joule per kelvin                    |           | 1 J/K = 1 m² kg s⁻² K⁻¹                        |
i| specific heat capacity, specific entropy                             | SI              | L² T⁻² Θ⁻¹       | joule per kilogram kelvin           |           | 1 J/(kg K) = 1 m² s⁻² K⁻¹                      |
i| specific energy (implemented in terms of absorbed dose)              | SI              | L² T⁻²           | joule per kilogram                  |           | 1 J/kg = 1 m² s⁻²                              |
i| thermal conductivity                                                 | SI              | L M T⁻³ Θ⁻¹      | watt per metre kelvin               |           | 1 W/(m K) = 1 m kg s⁻³ K⁻¹                     |
i| energy density (implemented in terms of pressure)                    | SI              | L⁻¹ M T⁻²        | joule per cubic metre               |           | 1 J/m³ = 1 m⁻¹ kg s⁻²                          |
i| electric field strength                                              | SI              | L M T⁻³ I⁻¹      | volt per metre                      |           | 1 V/m = 1 m kg s⁻³ A⁻¹                         |
i| electric charge density                                              | SI              | L⁻³ T I          | coulomb per cubic metre             |           | 1 C/m³ = 1 m⁻³ s A                             |
i| surface charge density, electric flux density, electric displacement | SI              | L⁻² T I          | coulomb per square metre            |           | 1 C/m² = 1 m⁻² s A                             |
i| permittivity                                                         | SI              | L⁻³ M⁻¹ T⁴ I²    | farad per metre                     |           | 1 F/m  = 1 m⁻³ kg⁻¹ s⁴ A²                      |
i| permeability                                                         | SI              | L M T⁻² I⁻²      | henry per metre                     |           | 1 H/m = 1 m kg s⁻² A⁻²                         |
i| molar energy, chemical potential                                     | SI              | L² M T⁻² N⁻¹     | joule per mole                      |           | 1 J/mol = 1 m² kg s⁻² mol⁻¹                    |
i| molar entropy, molar heat capacity                                   | SI              | L² M T⁻² Θ⁻¹ N⁻¹ | joule per mole kelvin               |           | 1 J/(mol K) = 1 m² kg s⁻² K⁻¹ mol⁻¹            |
i| exposure (x- and γ-rays)                                             | SI              | M⁻¹ T I          | coulomb per kilogram                |           | 1 C/kg = 1 kg⁻¹ s A                            |
 |                                                                      | imperial        |                  | roentgen                            | R         | 1 R = 2.58×10⁻⁴ C/kg                           |
i| absorbed dose rate                                                   | SI              | L² T⁻³           | gray per second                     |           | 1 Gy/s = 1 m² s⁻³                              |
i| radiance                                                             | SI              | M T⁻³ A²         | watt per square metre steradian     |           | 1 W/(m² sr) = 1 kg s⁻³                         |
i| catalytic activity concentration, reaction rate                      | SI              | L⁻³ T⁻¹ N        | katal per cubic metre               |           | 1 kat/m³ = 1 m⁻³ s⁻¹ mol                       |
i| action                                                               | SI              | L² M T⁻¹         | joule second                        |           | 1 J s = 1 m² kg s⁻¹                            |
 |                                                                      | extra           |                  | natural unit of action              | ħ         | 1 ħ = 1.054 571 68(18)×10⁻³⁴ J s               |
 | kinematic viscosity                                                  | SI              | L² T⁻¹           | square metre per second             |           | 1 m²/s                                         |
 |                                                                      | CGS             |                  | stokes                              | St        | 1 St = 10⁻⁴ m² s⁻¹                             |
i| dimensionless quantities                                             | SI, base        | 1                | one                                 |           | 1                                              |
i|                                                                      | SI, base        |                  | percent                             | %         | 1 % = 10⁻²                                     |
i|                                                                      | SI, base        |                  | permille                            | ‰         | 1 ‰ = 10⁻³                                     |
i|                                                                      | extra           |                  | parts per million                   | ppm       | 1 ppm = 10⁻⁶                                   |
i| amount of data, disk space                                           | SI, data        | B                | bit                                 | bit       | (base unit)                                    |
i|                                                                      | SI, data        |                  | byte                                | B         | 1 B = 8 bit                                    |
i| speed of data transfer, bandwidth                                    | SI, data        | T⁻¹ B            | bit per second                      |           | 1 bit/s                                        |
i|                                                                      | SI, data        |                  | byte per second                     |           | 1 byte/s = 8 bit/s                             |
i| screen position                                                      | data            | X                | pixel                               | px        | (base unit)                                    |
i| screen area                                                          | data            | X²               | pixel                               | pixel     | 1 pixel = 1 px²                                |
i| line density                                                         | extra           | L⁻¹ M            | kilogram per metre                  |           | 1 kg/m                                         |
i| absement                                                             | extra           | L T              | metre second                        |           | 1 m s                                          |
i| jerk                                                                 | not implemented | L T⁻³            | metre per cubic second              |           | 1 m s⁻³                                        |
i| snap                                                                 | not implemented | L T⁻⁴            | metre per quartic second            |           | 1 m s⁻⁴                                        |
i| crackle                                                              | not implemented | L T⁻⁵            | metre per second to the 5th         |           | 1 m s⁻⁵                                        |
i| pop                                                                  | not implemented | L T⁻⁶            | metre per second to the 6th         |           | 1 m s⁻⁶                                        |
i| electric conductivity                                                | extra           | L⁻³ M⁻¹ T³ I²    | siemens per metre                   | S/m       | 1 S/m = 1A/V m = 1 m⁻³ kg⁻¹ s³ A²              |
i| electric resitivity                                                  | extra           | L³ M T⁻³ I⁻²     | ohm metre                           | Ω m       | 1 Ω m = 1V m/A = 1 m kg s⁻³ A⁻²                |
i| momentum, impulse                                                    | SI              | L M T⁻¹          | newton second                       | N s       | 1 N s = 1 m kg s⁻¹                             |
i| angular momentum                                                     | SI              | L² M T⁻¹ A⁻¹     | newton metre second per radian      | N m s/rad | 1 N m s/rad = 1 m² kg s⁻¹ rad⁻¹                |
i| moment of inertia                                                    | SI              | L² M A⁻²         | square metre kilogram per steradian | m² kg/sr  | 1 m² kg rad⁻²                                  |

## Unit generator

```
quantity   = value unit .
unit       = system (one|prefix|user defined prefix) dimension .
dimension  = {(base|user defined base) power} .
base       = L | M | T | I | Θ | N | J | A | C | S | B | X . //See table of dimensions
prefix     = (yocto | zepto | ... | yotta) //See table of prefixes
```

## Table of physical constants

 | Name                            | Symbol                   | Value                             | Base Unit                                |
 |:--------------------------------|:-------------------------|:----------------------------------|:-----------------------------------------|
i| speed of light                  | c                        | 299 792 458 m/s (exact)           |                    1 m s⁻¹               |
i| magnetic constant               | μ₀                       | 4π×10⁻⁷ H/m (exact)               |            1 H/m = 1 m kg s⁻² A⁻²        |
i| electric constant               | ε₀ = 1/μ₀c²              | 8.854 178 817...×10⁻¹² F/m        |            1 F/m = 1 m⁻³ kg⁻¹ s⁴ A²      |
i| gravitational constant          | G                        | 6.674 08(31)×10⁻¹¹ m³ kg⁻¹ s⁻²    |                    1 m³ kg⁻¹ s⁻²         |
i| Planck constant                 | h                        | 6.626 070 040(81)×10⁻³⁴ J s       |            1 J s = 1 m² kg s⁻¹           |
i| reduced Planck constant         | ħ = h/2π                 | 1.054 571 800(13)×10⁻³⁴ J s       |            1 J s = 1 m² kg s⁻¹           |
i| elementary charge               | e                        | 1.602 176 6208(98)×10⁻¹⁹ C        |              1 C = 1 s A                 |
i| fine-structure constant         | α = e²/4πε₀ħc = e²μ₀c/2h | 7.297 352 5664(17)×10⁻³           |                    1                     |
i| inverse fine-structure constant | α⁻¹                      | 137.035 999 139(31)               |                    1                     |
i| electron mass                   | m_e                      | 9.109 383 56(11)×10⁻³¹ kg         |                    1 kg                  |
i| proton mass                     | m_p                      | 1.672 621 898(21)×10⁻²⁷ kg        |                    1 kg                  |
i| muon mass                       | m_μ                      | 1.883 531 594(48)×10⁻²⁸ kg        |                    1 kg                  |
i| tau mass                        | m_τ                      | 3.167 47(29)×10⁻²⁷ kg             |                    1 kg                  |
i| neutron mass                    | m_n                      | 1.674 927 471(21)×10⁻²⁷ kg        |                    1 kg                  |
i| deuteron mass                   | m_d                      | 3.343 583 719(41)×10⁻²⁷ kg        |                    1 kg                  |
i| triton mass                     | m_t                      | 5.007 356 665(62)×10⁻²⁷ kg        |                    1 kg                  |
i| helion mass                     | m_h                      | 5.006 412 700(62)×10⁻²⁷ kg        |                    1 kg                  |
i| α particle mass                 | m_α                      | 6.644 657 230(82)×10⁻²⁷ kg        |                    1 kg                  |
i| Rydberg constant                | R_∞ = α²m_e c/2h         | 10 973 731.568 508(65) m⁻¹        |                    1 m⁻¹                 |
i| Bohr radius                     | a₀ = α/4πR_∞             | 0.529 177 210 67(12)×10⁻¹⁰ m      |                    1 m                   |
i| Bohr magneton                   | μ_B = eħ/2m_e            | 927.400 9994(57)×10⁻²⁶ J/T        |            1 J/T = 1 m² A                |
i| Avogadro constant               | N_A                      | 6.022 140 857(74)×10²³ mol⁻¹      |                    1 mol⁻¹               |
i| Faraday constant                | F = N_A e                | 96 485.332 89(59) C/mol           |          1 C/mol = 1 s A mol⁻¹           |
i| molar gas constant              | R                        | 8.314 4598(48) J/(mol K)          |      1 J/(mol K) = 1 m² kg s⁻² mol⁻¹ K⁻¹ |
i| Boltzmann constant              | k = R/N_A                | 1.380 648 52(79)×10⁻²³ J/K        |            1 J/K = 1 m² kg s⁻² K⁻¹       |
i| Stefan-Boltzmann constant       | σ = π²k⁴/60 ħ³c²         | 5.670 367(13)×10⁻⁸ W m⁻² K⁻⁴ sr⁻¹ | 1 W m⁻² K⁻⁴ sr⁻¹ = 1 kg s⁻³ K⁻⁴ sr⁻¹     |
i| magnetic flux quantum           | φ₀ = h/2e                | 2.067 833 831(13)×10⁻¹⁵ Wb        |             1 Wb = 1 m² kg s⁻² A⁻¹       |
i| Josephson constant              | K_J = 2e/h               | 483 597.8525(30)×10⁹ Hz/V         |           1 Hz/V = 1 m⁻² kg⁻¹ s² A       |
i| von Klitzing constant           | R_K = h/e²               | 25 812.807 4555(59) Ω             |              1 Ω = 1 m² kg s⁻³ A⁻²       |
i| atomic mass unit                | u                        | 1.660 538 86(28)×10⁻²⁷ kg         |                    1 kg                  |
i| Hartree energy                  | E_h = e²/4πε₀a₀          | 4.359 744 650(54)×10⁻¹⁸ J         |              1 J = 1 m² kg s⁻²           |
i| conductance quantum             | G₀ = 2e²/h               | 7.748 091 7310(18)×10⁻⁵ S         |              1 S = 1 m⁻² kg⁻¹ s³ A²      |
i| inverse conductance quantum     | G₀⁻¹                     | 12 906.403 7278(29) Ω             |              1 Ω = 1 m² kg s⁻³ A⁻²       |
i| vacuum impedance                | Z₀ = μ₀c                 | 376.730 313 461... Ω              |              1 Ω = 1 m² kg s⁻³ A⁻²       |
i| Nuclear magneton                | μ_N = eħ/2m_p            | 5.050 783 699(31)×10⁻²⁷ J/T       |            1 J/T = 1 m² A                |

## Table of mathematical constants

 | Name                      | Symbol  | Value             |
 |:--------------------------|:--------|:------------------|
i| Pi (Archimedes constant)  | π       | 3.141592653589... |
i| 2 Pi                      | 2π      | 6.283185307179... |
i| Euler constant            | e       | 2.718281828459... |
i| golden ratio              | φ       | 1.618033988749... |
i| Euler Mascheroni constant | γ       | 0.577215664901... |
i| square root two           | sqrt(2) | 1.414213562373... |

## Table of astronomical constants

These values are not really citable in any way...

 | Name                   | Symbol                     | Value                    |
 |:-----------------------|:---------------------------|:-------------------------|
 | Solar mass parameter   | GM_S                       | 1.327 124 40×10²⁰ m³ s⁻² |
 | Solar luminosity       | L_S                        | 3.939×10²⁶ W/sr          |
 | Sun-Jupiter mass ratio | M_S/M_J                    | 1.047 348 644×10³        |
 | Sun-Earth mass ratio   | M_S/M_E                    | 322 946.0487             |
i| Solar mass             | M_S = (GM_S)G⁻¹            | 1.988 474 491×10³⁰ kg    |
i| Jupiter mass           | M_J = (GM_S)(M_S/M_J)⁻¹G⁻¹ | 1.898 579 334×10²⁷ kg    |
i| Earth mass             | M_E = (GM_S)(M_S/M_E)⁻¹G⁻¹ | 6.157 296 241×10²⁴ kg    |

## Table of base dimensions

 | Base dimension                       | Symbol | benri |
 |:-------------------------------------|:-------|:------|
i| length                               | L      | L     |
i| mass                                 | M      | M     |
i| time, duration                       | T      | T     |
i| electric current                     | I      | I     |
i| thermodynamic temperature            | Θ      | H     |
i| amount of substance                  | N      | N     |
i| luminous intensity                   | J      | J     |
i| angle, plane angle                   | A      | A     |
i| number of radioactive events, counts | C      | C     |
i| helper for sievert units             | S      | S     |
i| amount of data, bits, bytes          | B      | B     |
i| screen position                      | X      | X     |

## Table of SI prefixes

 | Prefix | Symbol | Factor |
 |:-------|:-------|:-------|
i| yocto  | y      | 10⁻²⁴  |
i| zepto  | z      | 10⁻²¹  |
i| atto   | a      | 10⁻¹⁸  |
i| femto  | f      | 10⁻¹⁵  |
i| pico   | p      | 10⁻¹²  |
i| nano   | n      | 10⁻⁹   |
i| micro  | μ      | 10⁻⁶   |
i| milli  | m      | 10⁻³   |
i| centi  | c      | 10⁻²   |
i| deci   | d      | 10⁻¹   |
i| one    |        | 10⁰    |
i| deca   | da     | 10¹    |
i| hecto  | h      | 10²    |
i| kilo   | k      | 10³    |
i| mega   | M      | 10⁶    |
i| giga   | G      | 10⁹    |
i| tera   | T      | 10¹²   |
i| peta   | P      | 10¹⁵   |
i| exa    | E      | 10¹⁸   |
i| zetta  | Z      | 10²¹   |
i| yotta  | Y      | 10²⁴   |

## Table of data prefixes

 | Prefix | Symbol | Factor |
 |:-------|:-------|:-------|
i| kibi   | ki     | 2¹⁰    |
i| mebi   | Mi     | 2²⁰    |
i| gibi   | Gi     | 2³⁰    |
i| tebi   | Ti     | 2⁴⁰    |
i| pebi   | Pi     | 2⁵⁰    |
i| exbi   | Ei     | 2⁶⁰    |
i| zebi   | Zi     | 2⁷⁰    |
i| yobi   | Yi     | 2⁸⁰    |
