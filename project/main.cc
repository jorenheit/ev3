#include "ev3dev.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace ev3dev;

void drive(large_motor &m1, large_motor &m2, int speed, int pos)
{
    m1.set_speed_sp(speed);
    m1.set_position_sp(pos).run_to_rel_pos();

    m2.set_speed_sp(speed);
    m2.set_position_sp(pos).run_to_rel_pos();

    while (m1.state().count("running") || m2.state().count("running"))
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
}


int main(int argc, char **argv)
{
    auto m1 = large_motor{OUTPUT_B};
    auto m2 = large_motor{OUTPUT_C};
    drive(m1, m2, std::stoi(argv[1]), std::stoi(argv[2]));
}
