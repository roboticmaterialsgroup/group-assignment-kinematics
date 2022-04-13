#include <Arduino.h>
#include <Encoders.h>
#include <Speed_controller.h>

SpeedController robot;
Romi32U4ButtonA buttonA;

enum ROBOT_STATE {IDLE, TURN};
ROBOT_STATE robot_state = IDLE; //initial state: IDLE

void setup() {
  robot.Init();
}
        
void loop() {
  //mySpeedController.Move(50,50);

  switch (robot_state)
    {
    case IDLE:
        if(buttonA.getSingleDebouncedRelease()){ 
            robot_state = TURN; 
            robot.Stop();             
        } 
        else { 
            robot_state = IDLE;
            robot.Stop(); 
        }   
        break;
    
    case TURN:
        if(robot.Turn(90,-1)) robot_state = IDLE;
        break;
  }
}