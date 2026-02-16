from vex import *
import urandom
import math

# Brain should be defined by default
brain=Brain()

# Robot configuration code


# wait for rotation sensor to fully initialize
wait(30, MSEC)


# Make random actually random
def initializeRandomSeed():
    wait(100, MSEC)
    random = brain.battery.voltage(MV) + brain.battery.current(CurrentUnits.AMP) * 100 + brain.timer.system_high_res()
    urandom.seed(int(random))
      
# Set random seed 
initializeRandomSeed()


def play_vexcode_sound(sound_name):
    # Helper to make playing sounds from the V5 in VEXcode easier and
    # keeps the code cleaner by making it clear what is happening.
    print("VEXPlaySound:" + sound_name)
    wait(5, MSEC)

# add a small delay to make sure we don't print in the middle of the REPL header
wait(200, MSEC)
# clear the console to make sure we don't have the REPL in the console
print("\033[2J")

#endregion VEXcode Generated Robot Configuration

# ------------------------------------------
# 
# 	Project:
#	Author:
#	Created:
#	Configuration:
# 
# ------------------------------------------







controller_1 = Controller(PRIMARY)
L1 = Motor(Ports.PORT16, GearSetting.RATIO_6_1, True)
L2 = Motor(Ports.PORT1, GearSetting.RATIO_6_1, False)
L3 = Motor(Ports.PORT17, GearSetting.RATIO_6_1, False)
R1 = Motor(Ports.PORT13, GearSetting.RATIO_6_1, True)
R2 = Motor(Ports.PORT20, GearSetting.RATIO_6_1, False)
R3 = Motor(Ports.PORT11, GearSetting.RATIO_6_1, False)
Intake1 = Motor(Ports.PORT7, GearSetting.RATIO_6_1, False)
Intake2 = Motor(Ports.PORT10, GearSetting.RATIO_18_1, False)
Descore = DigitalOut(brain.three_wire_port.f)
LilWill = DigitalOut(brain.three_wire_port.h)
Indexer1 = DigitalOut(brain.three_wire_port.a)
Indexer2 = DigitalOut(brain.three_wire_port.b)





B_count = 0
Y_count = 0
L1_count = 0
L2_count = 0
R1_count = 0
R2_count = 0
left_group = MotorGroup(L1, L2, L3)
right_group =  MotorGroup(R1, R2, R3)
Intake_group = MotorGroup(Intake1, Intake2)

def drive():
    while True:
        L1.set_velocity((controller_1.axis1.position() + controller_1.axis3.position()), PERCENT)
        L2.set_velocity((controller_1.axis1.position() + controller_1.axis3.position()), PERCENT)
        L3.set_velocity((controller_1.axis1.position() + controller_1.axis3.position()), PERCENT)
        R1.set_velocity((controller_1.axis1.position() - controller_1.axis3.position()), PERCENT)
        R2.set_velocity((controller_1.axis1.position() - controller_1.axis3.position()), PERCENT)
        R3.set_velocity((controller_1.axis1.position() - controller_1.axis3.position()), PERCENT)
        L1.spin(REVERSE)
        L2.spin(REVERSE)
        L3.spin(REVERSE)
        R1.spin(REVERSE)
        R2.spin(REVERSE)
        R3.spin(REVERSE)
        wait(5, MSEC)

def ButtonY():
    global Y_count
    if Y_count % 2 == 0:
        LilWill.set(True)
    else:
        LilWill.set(False)
    Y_count = A_count + 1

def ButtonR2():
    global R2_count
    if R2_count % 2 == 0:
        Descore.set(True)
    else:
        Descore.set(False)
    R2_count = R2_count + 1

def ButtonR1():
    global R1_count
    global L1_count
    global B_count
    global L2_count
    L1_count = L1_count * 2
    L2_count = L2_count * 2
    B_count = B_count * 2
    if R1_count % 2 == 0:
        Indexer1.set(False)
        Indexer2.set(True)
        Intake_group.spin(FORWARD)
    else:
        Indexer1.set(False)
        Indexer2.set(True)
        Intake_group.stop()
    R1_count = R1_count + 1

def ButtonL1():
    global R1_count
    global L1_count
    global B_count
    global L2_count
    B_count = B_count * 2
    L2_count = L2_count * 2
    R1_count = R1_count * 2
    if L1_count % 2 == 0:
        Indexer1.set(False)
        Indexer2.set(False)
        wait(60, MSEC)
        Intake_group.spin(FORWARD)
    else:
        Indexer1.set(False)
        Indexer2.set(True)
        Intake_group.stop()
    L1_count = L1_count + 1

def ButtonL2():
    global R1_count
    global L1_count
    global B_count
    global L2_count
    B_count = B_count * 2
    L1_count = L1_count * 2
    R1_count = R1_count * 2
    if L2_count % 2 == 0:
        Indexer1.set(True)
        Indexer2.set(True)
        wait(60, MSEC)
        Intake_group.FORWARD()                                                                                                                                                                                                                  
    else:
        Indexer1.set(False)
        Indexer2.set(True)
        Intake_group.stop()
    L2_count = L2_count + 1

def ButtonB():
    global R1_count
    global L1_count
    global B_count
    global L2_count
    L1_count = L1_count * 2
    L2_count = L2_count * 2
    R1_count = R1_count * 2
    if B_count % 2 == 0:
        Indexer1.set(False)
        Indexer2.set(True)
        Intake_group.spin(REVERSE)
    else:
        Indexer1.set(False)
        Indexer2.set(True)
        Intake_group.stop()
    B_count = B_count + 1        





def drive_forwards(f, p):
    global left_group
    global right_group
    left_group.set_velocity(p,PERCENT)
    right_group.set_velocity(p,PERCENT)
    left_group.spin_for(FORWARD, f,TURNS, wait=False)
    right_group.spin_for(FORWARD, f, TURNS,wait=True)

def drive_reverse(r,p):
    global left_group
    global right_group
    left_group.set_velocity(p,PERCENT)
    right_group.set_velocity(p,PERCENT)
    left_group.spin_for(REVERSE, r,TURNS, wait=False)
    right_group.spin_for(REVERSE, r, TURNS,wait=True)

def turn_left(l, p):
    global left_group
    global right_group
    left_group.set_velocity(p,PERCENT)
    right_group.set_velocity(p,PERCENT)
    left_group.spin_for(REVERSE, l,TURNS, wait=False)
    right_group.spin_for(FORWARD, l, TURNS,wait=True)

def turn_right(r, p):
    global left_group
    global right_group
    left_group.set_velocity(p,PERCENT)
    right_group.set_velocity(p,PERCENT)
    left_group.spin_for(FORWARD, r,TURNS, wait=False)
    right_group.spin_for(REVERSE, r, TURNS,wait=True)
    




def pre_autonomous():
    # actions to do when the program starts
    pass

def autonomous():
    brain.screen.clear_screen()
    brain.screen.print("autonomous code")
    # place automonous code here
    Intake.set_velocity(100, PERCENT)
    Intake.spin(FREVERSE)
    drive_forwards(5, 100)
    wait(5, SECONDS)
    Intake.stop()


def driver_control():
    brain.screen.clear_screen()
    # place driver control in this while loop
    Intake.set_velocity(90, PERCENT)
    Intake.spin(FORWARD)
    while True:
        wait(20, MSEC)
        controller_1.buttonB.pressed(ButtonB)
        controller_1.buttonY.pressed(ButtonY)
        controller_1.buttonR1.pressed(ButtonR1)
        controller_1.buttonL1.pressed(ButtonL1)
        controller_1.buttonR2.pressed(ButtonR2)
        controller_1.buttonL2.pressed(ButtonL2)
        drive()   

# create competition instance
comp = Competition(user_control, autonomous)
pre_autonomous()




        
