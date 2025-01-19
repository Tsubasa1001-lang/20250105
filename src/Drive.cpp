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
float AvgMotorPosition() // 底盤馬達平均角度
{
    return (abs(LeftMotor.position(deg)) + abs(RightMotor.position(deg))) / 2;
}
void ResetPosition() // 重置底盤角度
{
    LeftMotor.resetPosition();
    RightMotor.resetPosition();
    wait(20, msec);
}
void move(float Distance /* 輸入位移距離(cm)*/)
{
    float enc = Cm2Enc(Distance); // 將移動距離轉換為編碼器角度
    // float currentPosition = AvgMotorPosition(); // 取得目前編碼器位置
    ResetPosition(); // 重置目前編碼器角度
    On(100, 100);
    while (AvgMotorPosition() < enc)
    {
        wait(20, msec);
    }
    Stop();
}
