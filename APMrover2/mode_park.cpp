#include "mode.h"
#include "Rover.h"

void ModePark::update()
{
    float throttle = 0.0f;

    // if vehicle is balance bot, calculate actual throttle required for balancing
    if (rover.is_balancebot()) {
        rover.balancebot_pitch_control(throttle);
    }
    // in park mode, fall backwards only
    // prevent any negative throttle action
    if (throttle < 0.0f) { throttle = 0.0f; }

    // relax mainsail
    g2.motors.set_mainsail(100.0f);

    // hold position - stop motors and center steering
    g2.motors.set_throttle(throttle);
    g2.motors.set_steering(0.0f);
}
