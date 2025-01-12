#include "Drive.h"

    int drive_controller()
    {
        int Turn, Forward;
        while (1)
        {
            int Lv, Rv;
            Turn = Player1.Axis1.position();
            Forward = Player1.Axis3.position();
            Lv = Forward + Turn;
            Rv = Forward - Turn;
            if (abs(Rv) + abs(Lv) > 5)
            {
                On(Pct2Volt(Lv), Pct2Volt(Rv));
            }
            else
            {
                On(0, 0);
            }
            wait(20, msec);
        }

        return 0;
    }

    int Intake_controller()
    {
        while (1)
        {
            if (Player1.ButtonL1.pressing())
            {
                Intake.spin(fwd, 13, volt);
                Conveyor.spin(fwd, 13, volt);
            }
            else if (Player1.ButtonL2.pressing())
            {
                Intake.spin(fwd, -13, volt);
                Conveyor.spin(fwd, -13, volt);
            }
            else
            {
                Intake.stop(brakeType::coast);
                Conveyor.stop(brakeType::coast);
            }
            wait(20, msec);
        }
        return 0;
    }
