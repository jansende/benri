#include <iostream>
#include <benri/si/si.h>

template <class Unit>
auto operator<<(std::ostream &os, const benri::quantity<Unit> &value) -> std::ostream&
{
    os << value.value() << "?";
    return os;
}
auto operator<<(std::ostream &os, const benri::quantity<benri::si::second_t> &value) -> std::ostream&
{
    os << value.value() << "s";
    return os;
}
auto operator<<(std::ostream &os, const benri::quantity<benri::si::minute_t> &value) -> std::ostream&
{
    os << value.value() << "min";
    return os;
}
auto operator<<(std::ostream &os, const benri::quantity<benri::si::hour_t> &value) -> std::ostream&
{
    os << value.value() << "h";
    return os;
}

int main()
{
    using namespace benri::si;
    std::cout << "Long time no see!\n"
              << "(Last time: " << 357_hour << ':' << 20_minute << ':' << 11_second << ")\n"
              << std::flush;
}