#include "vex.h"
#include <thread> // important - lets us do 2 things at once
// this is right long plus middle only
/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(12, 1.5, 0, 10, 0); // 1.5 kp, 10 kd
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, 0, 3, 15); // .4 kp, 3 kd
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(0.3, 100, 800);
  chassis.set_turn_exit_conditions(0.3, 10, 800);
  chassis.set_swing_exit_conditions(0.3, 10, 1100);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 0.2;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 10;
}

void shooterLongDelay(){ // thread function
  wait(650, msec);
  Shooter.spin(fwd, 600, rpm);
  wait(1100, msec);
  Shooter.stop();

}

void shooterLongDelay2(){ // thread function
  wait(650, msec);
  Shooter.spin(fwd, 600, rpm);


}
/**
 * The expected behavior is to return to the start position.
 */

 // slot 4 code here
   /*chassis.drive_distance(19.5); // to disp
  Intake.spin(fwd, 600, rpm);
  chassis.turn_to_angle(89); // turn to disp
  Scraper.set(true);
    chassis.set_drive_exit_conditions(0.5, 0, 660);
  chassis.drive_distance(6);
odom_constants();
  thread shoot1 = thread(shooterLongDelay);
  chassis.drive_distance(-13.8);
  while (Shooter.isSpinning()){
    wait(5, msec);
  }
  Scraper.set(false);
  chassis.drive_distance(1); //detach from long
  chassis.left_swing_to_angle(218); //swing to first 3 
  chassis.drive_distance(12);
  chassis.turn_to_angle(180);
  chassis.drive_distance(21); // 2nd 3 here
  Scraper.set(true);//trap ball
  wait(100, msec);//intake delay
  chassis.turn_to_angle(135);//
  chassis.drive_distance(-10);
  Shooter.spin(fwd, 600, rpm);
  LeftMotor.setStopping(hold);
  LeftMotor2.setStopping(hold);
  LeftMotor3.setStopping(hold);
  RightMotor.setStopping(hold);
  RightMotor2.setStopping(hold);
  RightMotor3.setStopping(hold); 
  
   chassis.drive_distance(19.8); // to disp
  Descore.set(true);
  Intake.spin(fwd, 600, rpm);
  chassis.turn_to_angle(-90);
  Descore.set(false); 
  Scraper.set(true);
  chassis.set_drive_exit_conditions(0.5, 0, 900);
  chassis.drive_distance(6);
  odom_constants();
  chassis.drive_distance(-13.8);
  Shooter.spin(fwd, 600, rpm);
  wait(1400, msec);
  chassis.drive_distance(6);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-6);
  chassis.turn_to_angle(-70);
  chassis.drive_distance(-12);
  LeftMotor.stop(hold);
  LeftMotor2.stop(hold);
  LeftMotor3.stop(hold);
  RightMotor.stop(hold);
  RightMotor2.stop(hold);
  RightMotor3.stop(hold);

  */
void scraperDelay1(){
  wait(600, msec);
  Scraper.set(true);
  wait(350, msec);
  Scraper.set(false);
  wait(1700, msec);
  Scraper.set(true);
  wait(300, msec);
  Scraper.set(false);
}

void middleScoring(){
  wait(100, msec);
  Shooter.spin(reverse, 480, rpm);
  Intake.spin(fwd, 480, rpm); 
  wait(400, msec);
  Shooter.stop();
}

/*
chassis.drive_distance(13);
  Scraper.set(true);
  Intake.spin(fwd, 600, rpm);
  chassis.turn_to_angle(90);
  chassis.drive_distance(8);
  wait(280, msec);
  thread s1 = thread(shooterLongDelay);
  chassis.drive_min_voltage = 11.8;
  chassis.set_drive_exit_conditions(0.2, 100, 1200);
  chassis.drive_distance(-14);
  chassis.drive_min_voltage = 10;
  Scraper.set(false);
  wait(1000, msec);
  chassis.left_swing_to_angle(230); // tuning needed
  thread scr1 = thread(scraperDelay1);
  chassis.set_drive_exit_conditions(0.2, 0, 1000);
  chassis.drive_distance(12.25);
  chassis.turn_to_angle(180);
   chassis.set_drive_exit_conditions(0.2, 0, 2000); // 
  chassis.drive_distance(20.9);
   chassis.set_drive_exit_conditions(0.2, 0, 800);
  wait(300, msec);
  chassis.turn_to_angle(135);
  chassis.set_drive_exit_conditions(0.3, 100, 100); 
  thread mid1 = thread(middleScoring);
  chassis.drive_distance(-4.5); // not realistic just ramming with pace
  wait(300, msec);
  chassis.set_drive_exit_conditions(0.3, 100, 800);
  chassis.set_drive_exit_conditions(0.2, 100, 2000);
  chassis.turn_to_angle(140);
  chassis.drive_distance(22);
  chassis.turn_to_angle(90);
  Scraper.set(true);
  chassis.set_drive_exit_conditions(0.2, 100, 800);
  chassis.drive_distance(14);
  wait(300, msec);
  thread s2 = thread(shooterLongDelay2);
  chassis.drive_min_voltage = 11.8;
  chassis.set_drive_exit_conditions(0.2, 100, 1200);
  chassis.drive_distance(-24);
  chassis.drive_min_voltage = 10;
  Scraper.set(false);
  wait(1200, msec);

*/

void drive_test(){
  odom_constants();
 // distances in units of 2 inches for gear ratio reasons
 chassis.drive_distance(13);
  Scraper.set(true);
  Intake.spin(fwd, 600, rpm);
  chassis.turn_to_angle(90);
  chassis.drive_distance(8);
  wait(280, msec);
  thread s1 = thread(shooterLongDelay);
  chassis.drive_min_voltage = 11.8;
  chassis.set_drive_exit_conditions(0.2, 100, 1200);
  chassis.drive_distance(-14);
  chassis.drive_min_voltage = 10;
  Scraper.set(false);
  wait(1000, msec);
  Descore.set(true);
  chassis.drive_min_voltage = 10;
  chassis.drive_distance(5);
  chassis.turn_to_angle(-45); // needs to change angle relative to proper starts
  chassis.drive_distance(-8);
   Descore.set(false);
  chassis.turn_to_angle(90); // need to change
  chassis.drive_distance(-9);
  LeftMotor.stop(hold);
  LeftMotor2.stop(hold);
  LeftMotor3.stop(hold);
  RightMotor.stop(hold);
  RightMotor2.stop(hold);
  RightMotor3.stop(hold);
  

  
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}
