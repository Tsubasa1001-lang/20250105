#include "vex.h"

using namespace vex;

// 初始化大腦，用於顯示和輸出信息
brain Brain;

// 左側馬達群組，包括左前輪和左後輪
motor LeftMotor1 = motor(PORT1, ratio18_1, false);
motor LeftMotor2 = motor(PORT2, ratio18_1, false);

// 右側馬達群組，包括右前輪和右後輪（反向）
motor RightMotor1 = motor(PORT3, ratio18_1, true);
motor RightMotor2 = motor(PORT4, ratio18_1, true);

// 馬達群組，用於簡化左右側控制
motor_group LeftMotor=motor_group(LeftMotor1,LeftMotor2);
motor_group RightMotor=motor_group(RightMotor1,RightMotor2);

// 主控制器與副控制器
controller Player1 = controller(primary);
controller Player2 = controller(partner);

// 額外功能的馬達，例如取物和傳送
motor Intake=motor(PORT5,ratio18_1,false);
motor Conveyor=motor(PORT6,ratio18_1,false);

