#include "conversion.h"

// 全域變數與常數定義
float MotorGearRatio = 600.0; // 預設馬達齒輪比
float DriveGearRatio = .8;    // 預設驅動齒輪比
float WheelDiameter = 5.3;    // 預設輪徑（單位：cm）
float volt_max = 13.0;        // 預設最大電壓（單位：volt）
float WheelBase = 31.6;       // 左右輪距

// 預計算常數
float rpm2dps = MotorGearRatio * DriveGearRatio * 6; // rpm 換算為 dps
float dps2pct = 100 / rpm2dps;                       // dps 換算為 pct
float pct2volt = volt_max / 100;                     // pct 換算為 volt

// 函數實現
float Enc2Cm(float enc)
{
    // 將編碼器角度轉換為距離（cm）
    return enc * DriveGearRatio * (1.0 / (360.0 / (WheelDiameter * M_PI)));
}

float Cm2Enc(float cm)
{
    // 將距離（cm）轉換為編碼器角度
    return (cm / DriveGearRatio) * (360.0 / (WheelDiameter * M_PI));
}

float Rpm2Dps(float rpm)
{
    // 將轉速（rpm）轉換為角速度（dps）
    return rpm * rpm2dps;
}

float Dps2Pct(float dps)
{
    // 將角速度（dps）轉換為百分比速度
    return dps * dps2pct;
}

float Pct2Volt(float pct)
{
    // 將百分比速度轉換為電壓（volt）
    return pct * pct2volt;
}
