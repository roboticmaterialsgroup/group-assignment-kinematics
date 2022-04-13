# Group assignment: kinematics
This is your fourth group assignment. Please follow the exact instructions
below to receive full points. It is important that you create > 10
commits for each demonstration. **If you copy and paste code, and push it with a single commit, you risk earning a low grade.**
Individual and group grades may vary.

## Overview
To complete the term project, you will need methods to control the path of your robot. You have explored velocity control, wall-following, and image processing; here you will explore forward and inverse kinematics so that you can command your robot to *move to a specified point*.

By *forward* kinematics, we mean calculating the motion of the vehicle from sensor readings, in this case, encoder readings.

*Inverse* kinematics, on the other hand, is what you use to determine the inputs needed to produce a desired motion.

To move to a point, you will have to combine the two into a control loop: motion estimates are used to update the *pose* of the robot, and the updated pose is used to calculate *new motor commands*.

In this exercise, you will start by seeing how well you can track the motion of your Romi using the encoders as motion sensors. You will finish with a challenge, where your robot will drive to a specific point on command.

## Step 1: each team member: clone this repository to your computer
Clone this repository to your local machine.
```
git clone <PASTE THE REPO ADDRESS HERE>
```

## Step 2: each team member: open the cloned project in VS Code
Open the repository that you just cloned in MS Visual Studio Code. Your Platform IO plugin should be working at this stage.

## Step 3: each team member: upload the program to your Romi
Once uploaded, your Romi should drive at a constant speed of 50 mm/s and output the 
velocity to the terminal. Here, you are provided with Encoders., Speed_controller., and Position_estimation. source
and header files, which you *can* use for your individual and group assignment. Try to understand the implemenation 
of the files and their inter-dependency, before procedding to the next step. If you cannot get the terminal to output
the velicities as described above, please ask for help from your group members or SAs in one of their lab sessions
or office hours.

## Step 4: each team member: 

 "Robot idle" in your terminal. After you press button A 
on your Romi board, this message should change to "Distance measurement". Essentially, you are provided
with an example of a simple state machine, which you can use for your individual
and group assignments. Try to understand the implementation of the state machine, before
proceeding to the next step. If you cannot get the terminal to output the messages as 
described above, please ask for help from your group members or SAs in one of their lab 
sessions or office hours.

