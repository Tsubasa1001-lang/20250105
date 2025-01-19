#ifndef UNIT_CONVERSION_H
#define UNIT_CONVERSION_H

#include <cmath> // 為了使用 M_PI 定義

// 全域變數與常數聲明
extern float MotorGearRatio; // 馬達齒輪比
extern float DriveGearRatio; // 驅動齒輪比
extern float WheelDiameter;  // 輪徑（單位：cm）
extern float volt_max;       // 最大電壓（單位：volt）

// 函數聲明
float Enc2Cm(float enc);     // 將編碼器角度轉換為距離（cm）
float Cm2Enc(float cm);      // 將距離（cm）轉換為編碼器角度
float Rpm2Dps(float rpm);    // 將轉速（rpm）轉換為角速度（dps）
float Dps2Pct(float dps);    // 將角速度（dps）轉換為百分比速度
float Pct2Volt(float pct);   // 將百分比速度轉換為電壓（volt）

#endif
