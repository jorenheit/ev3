#include "ev3dev.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace ev3dev;

void drive(large_motor &m, int speed, int pos)
{
    m.set_speed_sp(speed);
    m.set_position_sp(pos).run_to_rel_pos();

    while (m.state().count("running"))
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
}


int main(int argc, char **argv)
{
    auto m = large_motor{OUTPUT_A};
    std::cout << m.ramp_up_sp() << '\n';
    std::cout << m.ramp_down_sp() << '\n';
    m.set_ramp_up_sp(1000);
    m.set_ramp_down_sp(1000);
    drive(m, std::stoi(argv[1]), std::stoi(argv[2]));
    std::cout << m.position() << '\n';
}
