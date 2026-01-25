#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

/// VEXcode device constructors
motor LeftMotor = motor(PORT1, ratio6_1, true);
motor LeftMotor2 = motor(PORT17, ratio6_1, true);
motor LeftMotor3 = motor(PORT16, ratio6_1, false);
motor RightMotor = motor(PORT20, ratio6_1, false);
motor RightMotor2 = motor(PORT11, ratio6_1, false);
motor RightMotor3 = motor(PORT13, ratio6_1, true);

motor Shooter = motor(PORT10, ratio6_1, false);
motor Intake = motor(PORT7, ratio6_1, false);

inertial Inertial17 = inertial(PORT15);

controller Controller = controller();

digital_out Scraper = digital_out(Brain.ThreeWirePort.H);
digital_out Descore = digital_out(Brain.ThreeWirePort.F);
digital_out MidDescore = digital_out(Brain.ThreeWirePort.G);

competition Competition;

void vexcodeInit( void ) {
  // nothing to initialize
}
