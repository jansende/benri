#include <benri/chrono.h>
#include <benri/si/si.h>
#include <benri/si/temperature.h>
#include <chrono>
#include <iostream>
#include <random>

using namespace benri::si;

class tnt
{
  private:
    benri::quantity<second_t>                           _fuse;
    bool                                                _ignited = false;
    benri::quantity_point<seconds_since_system_epoch_t> _start;

  public:
    tnt(const benri::quantity<second_t> fuse_time) : _fuse(fuse_time) {}

    auto ignite(benri::quantity_point<seconds_since_system_epoch_t> now) -> void
    {
        if (ignited())
            return;

        _ignited = true;
        _start   = now;
    }
    auto ignited() -> bool { return _ignited; }
    auto exploded(benri::quantity_point<seconds_since_system_epoch_t> now) -> bool
    {
        auto duration = now - _start;
        return duration > _fuse;
    }
    auto fuse_left(benri::quantity_point<seconds_since_system_epoch_t> now)
        -> benri::quantity<second_t>
    {
        if (!ignited())
            return _fuse;
        if (exploded(now))
            return 0_second;

        auto duration = now - _start;
        return _fuse - duration;
    }
};

int main()
{
    using namespace benri::si;

    auto fuse_time = double{};
    std::cout << "Enter fuse time in seconds: ";
    std::cin >> fuse_time;
    auto bomb = tnt{fuse_time * second};
    std::cout << "Bomb successfully created!\n"
              << "Ignited the fuse.\n"
              << "Starting Countdown...\n";

    auto now = benri::now<std::chrono::system_clock, seconds_since_system_epoch_t>();
    bomb.ignite(now);

    for (auto counter = static_cast<int>(bomb.fuse_left(now).value());
         !bomb.exploded(now);
         now = benri::now<std::chrono::system_clock, seconds_since_system_epoch_t>())
    {
        if (static_cast<int>(bomb.fuse_left(now).value()) < counter)
        {
            if (counter == 30 || counter == 20 || counter <= 10)
                std::cout << counter << "s\n";
            counter--;
        }
    }
    std::cout << "KABOOMM!!\n";
}