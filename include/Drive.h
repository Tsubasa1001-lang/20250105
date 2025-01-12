#ifndef DRIVE_H
#define DRIVE_H

#include "robot.h" // 引入 robot.h 以便使用馬達相關的宣告

// 啟動底盤
void On(float lv, float rv);

// 將百分比轉換為電壓的輔助函數
float Pct2Volt(float pct);
// 停止底盤
void Stop(vex::brakeType type = vex::brakeType::brake);
#endif
