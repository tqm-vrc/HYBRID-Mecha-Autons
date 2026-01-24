#include "vex.h"

using namespace vex;


/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(LeftMotor, LeftMotor2, LeftMotor3),

//Right Motors:
motor_group(RightMotor, RightMotor2, RightMotor3),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT15,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
PORT2,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
6,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
PORT2,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

int current_auton_selection = 0;
bool auto_started = false;


bool R1_last_active = false;
bool L1_last_active = false;
bool B_last_active = false;
bool L2_last_active = false;



void onL1(){
wait(10, msec);
  R1_last_active = false;
  L2_last_active = false;
  B_last_active = false;
if (!L1_last_active){
  Intake.spin(forward, 600, rpm);
  Shooter.spin(forward, 600, rpm);
  L1_last_active = true;
} else{
  wait(5, msec);
  Shooter.setStopping(brake);
  Shooter.stop();
  Intake.setStopping(hold);
  Intake.stop();
  L1_last_active = false;
}
}

void onL2(){ // middle goal - reverse shooting, forward intake
  wait(10, msec);
  R1_last_active = false;
  L1_last_active = false;
B_last_active = false;
if (!L2_last_active){
  Intake.spin(reverse, 420, rpm);
  wait(150, msec);
  Shooter.spin(reverse, 420, rpm);
  Intake.spin(forward, 420, rpm);
  L2_last_active = true;
} else{
  wait(5, msec);
  Shooter.setStopping(brake);
  Shooter.stop();
  Intake.setStopping(hold);
  Intake.stop();
  L2_last_active = false;
}
}

void onR1(){ // intake forward only
wait(10, msec);
L1_last_active = false;
B_last_active = false;
L2_last_active = false;

if (!R1_last_active){
  Intake.spin(forward, 540, rpm);
  Shooter.setStopping(brake);
  Shooter.stop();
  R1_last_active = true;
} else{
  wait(5, msec);
  Shooter.setStopping(brake);
  Shooter.stop();
  Intake.setStopping(coast);
  Intake.stop();
  R1_last_active = false;
}
}

void onB(){ // bottom goal (less important)
wait(10, msec);
  R1_last_active = false;
  L1_last_active = false;
  L2_last_active = false;
if (!B_last_active){
  Intake.spin(reverse, 600, rpm);
  wait(100, msec);
  Shooter.spin(reverse, 600, rpm);
  B_last_active = true;
} else{
  wait(5, msec);
  Shooter.setStopping(brake);
  Shooter.stop();
  Intake.setStopping(hold);
  Intake.stop();
  B_last_active = false;
}
}

bool DescoreFlag = false;
void onR2(){
if (DescoreFlag){
    Descore.set(false);
    DescoreFlag = false;
    wait(100, msec);
  }
  else {
    Descore.set(true);
    DescoreFlag = true;
    wait(100, msec);
  }
}


bool ScraperFlag = false;
void onY(){
  if (ScraperFlag){
    Scraper.set(false);
    ScraperFlag = false;
    wait(100, msec);
  }
  else {
    Scraper.set(true);
    ScraperFlag = true;
    wait(100, msec);
  }
}

bool MidFlag = false;
void onDown(){
    if (MidFlag){
    MidDescore.set(false);
    MidFlag = false;
    wait(100, msec);
  }
  else {
    MidDescore.set(true);
    MidFlag = true;
    wait(100, msec);
  }
}





/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  Inertial17.calibrate();

  while(Inertial17.isCalibrating()){
    wait(10, msec);
  }
  while(!auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "Auton 1");
        break;
      case 1:
        Brain.Screen.printAt(5, 140, "Auton 2");
        break;
      case 2:
        Brain.Screen.printAt(5, 140, "Auton 3");
        break;
      case 3:
        Brain.Screen.printAt(5, 140, "Auton 4");
        break;
      case 4:
        Brain.Screen.printAt(5, 140, "Auton 5");
        break;
      case 5:
        Brain.Screen.printAt(5, 140, "Auton 6");
        break;
      case 6:
        Brain.Screen.printAt(5, 140, "Auton 7");
        break;
      case 7:
        Brain.Screen.printAt(5, 140, "Auton 8");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      drive_test();
      break;
    case 1:         
      drive_test();
      break;
    case 2:
      turn_test();
      break;
    case 3:
      swing_test();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
 }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
    LeftMotor.setStopping(coast);
  LeftMotor2.setStopping(coast);
  LeftMotor3.setStopping(coast);
  RightMotor.setStopping(coast);
  RightMotor2.setStopping(coast);
  RightMotor3.setStopping(coast);
  Controller.ButtonR1.pressed(onR1);
  Controller.ButtonR2.pressed(onR2);
  Controller.ButtonL1.pressed(onL1);
  Controller.ButtonL2.pressed(onL2);
  Controller.ButtonB.pressed(onB);
  Controller.ButtonY.pressed(onY);
  Controller.ButtonDown.pressed(onDown);
  float a1 = 0;
  float a3 = 0;
  while (1) {
    a1 = Controller.Axis1.position();
    a3 = Controller.Axis3.position();
    if (a3<5 && a3>-5){
      a3 = 0;
    }
    if (a1<5 && a1>-5){
      a1 = 0;
    }

    LeftMotor.setVelocity(a3+a1, percent);
  LeftMotor2.setVelocity(a3+a1, percent);
  LeftMotor3.setVelocity(a3+a1, percent);
  RightMotor.setVelocity(a3-a1, percent);
  RightMotor2.setVelocity(a3-a1, percent);
  RightMotor3.setVelocity(a3-a1, percent);
    LeftMotor.spin(forward);
    LeftMotor2.spin(forward);
    LeftMotor3.spin(forward);
    RightMotor.spin(forward);
    RightMotor2.spin(forward);
    RightMotor3.spin(forward);
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}



