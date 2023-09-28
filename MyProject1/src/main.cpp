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

void autonomous(void) {
}



void usercontrol(void) {
  while (1) {
    while(Controller1.Axis4.value() < -43) {
      FR_Drive.spin(directionType::rev, Controller1.Axis4.value(), velocityUnits::pct);
      FL_Drive.spin(directionType::fwd, Controller1.Axis4.value(), velocityUnits::pct);
      RR_Drive.spin(directionType::fwd, Controller1.Axis4.value(), velocityUnits::pct);
      RL_Drive.spin(directionType::rev, Controller1.Axis4.value(), velocityUnits::pct);
    } while(Controller1.Axis1.value() > 43) {
      FR_Drive.spin(directionType::rev, Controller1.Axis1.value(), velocityUnits::pct);
      FL_Drive.spin(directionType::fwd, Controller1.Axis1.value(), velocityUnits::pct);
      RR_Drive.spin(directionType::fwd, Controller1.Axis1.value(), velocityUnits::pct);
      RL_Drive.spin(directionType::rev, Controller1.Axis1.value(), velocityUnits::pct);
    }
    FR_Drive.spin(directionType::fwd, Controller1.Axis2.value()/0.635, velocityUnits::pct);
    FL_Drive.spin(directionType::fwd, Controller1.Axis3.value()/0.635, velocityUnits::pct);
    RR_Drive.spin(directionType::fwd, Controller1.Axis2.value()/0.635, velocityUnits::pct);
    RL_Drive.spin(directionType::fwd, Controller1.Axis3.value()/0.635, velocityUnits::pct);
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
