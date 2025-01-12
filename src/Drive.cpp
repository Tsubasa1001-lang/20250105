#include "robot.h"
using namespace vex;

float WheelDiameter = 5.3;  // 輪胎直徑
float WheelBase = 31.6;     // 左右輪距
float MotorGearRatio = 600; // 馬達齒輪箱(轉速rpm)
float DriveGearRatio = .8;  // 底盤齒輪箱
float volt_max = 13.0;      // 最大電壓
// 單位換算
float rpm2dps = MotorGearRatio * DriveGearRatio * 6; // rpm換算為dps
float dps2pct = 100 / rpm2dps;                       // dps換算為pct
float pct2volt = volt_max / 100;                     // pct換算為volt
float Enc2Cm(float enc)                              // 角度換cm
{
    return (enc * DriveGearRatio * (1.0 / (360.0 / (WheelDiameter * M_PI))));
}
float Cm2Enc(float cm) // cm換角度
{
    return ((cm / DriveGearRatio) * (360.0 / (WheelDiameter * M_PI)));
}
float Rpm2Dps(float Rpm)
{
    return Rpm * rpm2dps;
}
float Dps2Pct(float Dps)
{
    return Dps * dps2pct;
}
float Pct2Volt(float Pct)
{ // 將百分比轉換為電壓
    return Pct * pct2volt;
}
void On(float lv, float rv)
{
    LeftMotor.spin(fwd, Pct2Volt(lv), volt);
    RightMotor.spin(fwd, Pct2Volt(rv), volt);
}
void Stop(brakeType type = vex::brakeType::brake)//使底盤停止

{
    LeftMotor.stop(type);
    RightMotor.stop(type);
}
