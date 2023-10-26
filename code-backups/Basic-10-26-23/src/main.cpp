#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor1               motor         1               
// Motor10              motor         10              
// Motor11              motor         11              
// Motor20              motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
using namespace vex;
competition Competition;

void pre_auton(void) {
  vexcodeInit();
} 
//  610
void autonomous(void) {
  FR_Drive.spinFor(610, deg, 100, velocityUnits::pct, false);
  FL_Drive.spinFor(610, deg, 100, velocityUnits::pct, false);
  RR_Drive.spinFor(610, deg, 100, velocityUnits::pct, false);
  RL_Drive.spinFor(610, deg, 100, velocityUnits::pct);
  wait(100, msec);
  FR_Drive.spinFor(-100, deg, 100, velocityUnits::pct, false);
  FL_Drive.spinFor(-100, deg, 100, velocityUnits::pct, false);
  RR_Drive.spinFor(-100, deg, 100, velocityUnits::pct, false);
  RL_Drive.spinFor(-100, deg, 100, velocityUnits::pct);
}

void usercontrol(void) {
  while (1) {
    FR_Drive.spin(fwd, Controller1.Axis2.value()/.635,pct);
    FL_Drive.spin(fwd, Controller1.Axis3.value()/.635,pct);
    RR_Drive.spin(fwd, Controller1.Axis2.value()/.635,pct);
    RL_Drive.spin(fwd, Controller1.Axis3.value()/.635,pct);
  }
}


int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
