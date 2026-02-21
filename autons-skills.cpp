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
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1, 450, 1500);
  chassis.set_turn_exit_conditions(0.7, 50, 1000);
  chassis.set_swing_exit_conditions(0.7, 300, 1000);

  //slowing down to 2/3rds of the original speed
  chassis.drive_max_voltage = 8;
  chassis.turn_max_voltage = 8;
  chassis.swing_max_voltage = 8;
  chassis.heading_max_voltage = 4;
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 4;
}

void shooterLongDelay(){ // thread function
  wait(400, msec);
  Descore.set(true);
  Shooter.spin(fwd, 600, rpm);
  wait(900, msec);
  Shooter.stop();
  Descore.set(false);
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
  RightMotor3.setStopping(hold); */

void drive_test(){
  chassis.drive_distance(19.8); // to disp
  Intake.spin(fwd, 600, rpm);
  chassis.turn_to_angle(-90); // turn to disp
  Scraper.set(true);
  wait(500, msec);
  chassis.drive_min_voltage = 6;
  chassis.set_drive_exit_conditions(0.5, 0, 2000);
  chassis.drive_distance(10);
  chassis.drive_min_voltage = 4;
  wait(1000, msec);
  chassis.drive_distance(3);
  wait(1000, msec);
  odom_constants();
  chassis.drive_distance(-8); // back from disp
  Scraper.set(false);
  chassis.turn_to_angle(0); // 
  chassis.set_drive_exit_conditions(0.2, 30, 4000);
  chassis.drive_distance(-46.5);
  chassis.turn_to_angle(-90);
  chassis.set_drive_exit_conditions(0.5, 50, 2000);
  chassis.drive_distance(-9); // into the right long goal
  Shooter.spin(fwd, 600, rpm); // shoot into the right long
  wait(3500, msec);
  Shooter.stop();
  Intake.spin(fwd, 600, rpm);
  Scraper.set(true);
  wait(500, msec);
  chassis.set_drive_exit_conditions(0.3, 50, 2000);
  chassis.drive_distance(16); // to right dispenser
  wait(1000, msec);
  chassis.drive_distance(-5);
  chassis.drive_distance(6);
  wait(1000, msec);
  chassis.turn_to_angle(-86);
  chassis.drive_distance(-15); // back to long
  Scraper.set(false);
  Shooter.spin(fwd, 600, rpm);
  wait(3500, msec);
  Shooter.stop();
  chassis.drive_distance(6); // detach from long
  chassis.turn_to_angle(120);
  chassis.drive_distance(-16); // slam into wall
  chassis.turn_to_angle(172);
  chassis.drive_distance(6); // away from the parked zone into dispenser ready to RAM
  chassis.drive_min_voltage = 11.5;
  chassis.drive_max_voltage = 12;
  chassis.set_drive_exit_conditions(0.5, 0, 2000);
  chassis.drive_distance(-29);




  /*chassis.drive_distance(6); // detach from long
  chassis.turn_to_angle(0);
  chassis.drive_distance(21); // to near parked zone
  chassis.turn_to_angle(-90);
  chassis.drive_min_voltage = 11.5;
  chassis.drive_max_voltage = 12;
  chassis.set_drive_exit_conditions(0.5, 0, 2000);
  chassis.drive_distance(14); // into the parked zone*/
  // Shooter.spin(fwd, 600, rpm);
  //chassis.drive_distance(6);
  //chassis.turn_to_angle(135);
  //chassis.drive_distance(-7);
  //Descore.set(true);
  //chassis.turn_to_angle(90);
  // chassis.drive_distance(6);
  // LeftMotor.stop(hold);
  // LeftMotor2.stop(hold);
  // LeftMotor3.stop(hold);
  //RightMotor.stop(hold);
  // RightMotor2.stop(hold);
  // RightMotor3.stop(hold);

  

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
