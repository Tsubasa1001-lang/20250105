#include "robot.h"
#include "conversion.h"

void On(float lv, float rv)
{
    LeftMotor.spin(fwd, Pct2Volt(lv), volt);
    RightMotor.spin(fwd, Pct2Volt(rv), volt);
}
void Stop(brakeType type = brakeType::brake) // 使底盤停止

{
    LeftMotor.stop(type);
    RightMotor.stop(type);
}
float AvgMotorPosition()
{
    return (abs(LeftMotor.position(deg)) + abs(RightMotor.position(deg))) / 2;
}
void ResetPosition()
{
    LeftMotor.resetPosition();
    RightMotor.resetPosition();
}
void move()
{

    On(100, 100);
    while (true)
    {
        wait(20, msec);
    }
}
