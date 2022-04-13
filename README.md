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
Once uploaded, your Romi should drive at a constant speed of 50 mm/s after button A was pressed. Here, you are provided with Encoders., Speed_controller., and Position_estimation. source
and header files, which you *can* use for your individual and group assignment. Try to understand the implemenation 
of the files and their inter-dependency, before proceeding to the next step. If you cannot get the terminal to output
the velocities as described above, please ask for help from your group members or SAs in one of their lab sessions
or office hours.

## Step 4: each team member: create personal file in user folder
Each group member has to create a txt file and the **name** of the file must contain
the student's name and student id. Either create the file manually, or do it via the 
terminal all together:

```
git pull
cd users
touch user-id_last-name.txt
git add --all 
git commit -m "I added my user id and name file"
git push
```

## Step 5: each team member: create a branch and program demo 1
Each group member will have to program their own demo 1. Therefore you need to
create your own branch from the remote group repository. As a branch name, use your 
first dash last name "FIRST-LAST" (e.g., MARKUS-NEMITZ). Steps 5-8 cover demo 1.

```
git checkout -b "your-branch-name"
git branch
```

The terminal will confirm that you are in your own personal branch. Once you see this 
confirmation, add a line to the main.cpp file:

```
//this is my version of the group assignment
```

Now add, commit, and push the code to your group repository:

```
git add -A
git commit -m "this is my own version of the git repository; I am safe to make 
changes here"
git push -u origin "your-branch-name"
```

Check your group repository in the browser. You should be able to see the repo
and a branch with your name (You may need to refresh the page).

## Step 6: each team member: forward kinematics
You will program the ``void Position::UpdatePose(float target_speed_left, float target_speed_right)`` function that performs the forward kinematics calculation. This function keeps track of the pose (x,y, theta) of your robot using encoder counts. There are three different cases that you need to cover: (i) straight movement, (ii) rotation, and (iii) curved movement; and for each case the equations differ. Have a look at the lecture slides if you do not remember the governing equations in detail.

## Step 7: each team member: moving straight - demo 1
In the laboratory, you will find an arena with graph paper; each grid square is 1 cm in length. For the sign off, put your Romi into the arena and let it move straight at an arbitary speed and for an arbitrary duration (of course, you do not want your Romi to collide with the arena wall). Check your terminal whether the calculated pose of your robot aligns with the actual pose in the arena (the grid paper will be helpful to determine the pose of your robot). Repeat this experiment one more time. If your estimated and actual poses are sufficiently close to one another (i.e., 1 cm), you will receive your sign-off.

[SIGN-OFF: 1]

Create a release of your code in GitHub and call it: ``demo 1 YOUR-NAME``. As tag, enter 1.0.X.

You can improve your pose estimation for straight movement by optimizing your value for the wheel radius. Any imprecision in your wheel radius will lead to imprecisions in your position estimations. 

## Step 8: each team member: turning - demo 2
Repeat step 7, but instead of moving straight, your robot turns at an arbitrary speed and arbitrary rotation. For the sign off, put your Romi into the arena and show that your robot can rotate < 360 degrees and > 360 degrees. When your robot exceeds 360 degrees, it should reset its orientation to 0 degrees. If your estimated and actual poses are sufficiently close to one another (i.e., 5 degrees), you will receive your sign-off.

[SIGN-OFF: 2]

Create a release of your code in GitHub and call it: ``demo 2 YOUR-NAME``. As tag, enter 2.0.X.

You can improve your pose estimation for rotating movements by optimizing your value for the wheel track. Any imprecision in your wheel track will lead to imprecisions in your position estimations.

## Step 9: each team member: curved movement - demo 3
Combine steps 8 and 9, and make your robot move in an arbitrary arch. For the sign off, put your Romi into the arena, and print the pose estimation to the terminal. If your estimated and actual poses are sufficiently close to one another (i.e., 1 cm in Euclidean distance, and 5 degrees in orientation), you will receive your sign-off.

[SIGN-OFF: 3]

Create a release of your code in GitHub and call it: ``demo 3 YOUR-NAME``. As tag, enter 3.0.X.

## Step 10: group discussion
Discuss with your group, who developed the strongest pose estimation.
That student then creates a pull request in the browser (see exemplarily image below).
    
<img width="726" alt="Screen Shot 2022-03-20 at 8 52 10 PM" src="https://user-images.githubusercontent.com/68814774/159193554-723d103d-df89-4e7d-8852-266da1f0243a.png">

Each group member has to go in detail through the changes, and make comments
or suggestions to the pull request. Once everyone agrees, accept the pull request
and work as a group from your master branch.

```
git checkout master
```

## Step 11: inverse kinematics - demo 4
Here, you will apply inverse kinematics to command your Romi to move to one of several positions. The specific position will be commanded using the buttons
of the Romi. We will discuss control algorithms in class.

Edit your code so that pressing a button will command the Romi to drive to a point:

* Button A sets the destination to x=30cm; y=30cm
* Button B sets the destination to x=60cm; y=0cm
* Button C sets the destination to x=30cm; y=-30cm

You will need to extend your state machine and define a state ``DRIVE_TO_POINT``, for when your Romi is moving to a destination.

You will want to call ``Position::UpdatePose(float target_speed_left, float target_speed_right)`` during movement.

You will need to add a function that checks whether you have reached the destination. Add a buffer around each point (e.g., 2 - 5 cm) that is "good enough". Otherwise your Romi will try to perfectly reach the target position, which it never will ...

Demonstrate this demo to a SA; if not all team members can be present for the sign-off, explain your circumstances to the SA. They will be in touch with me.

[SIGN-OFF: 4]

Create a release of your code in GitHub and call it: `demo 4 YOUR-GROUP-NAME`. As tag, enter 4.0.0.