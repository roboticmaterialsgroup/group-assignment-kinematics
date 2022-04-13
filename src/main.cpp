#include <Arduino.h>
#include <Speed_controller.h>

SpeedController robot;
Romi32U4ButtonA buttonA;

enum ROBOT_STATE {IDLE, MOVE, TURN};
ROBOT_STATE robot_state = IDLE;

void setup() {
  robot.Init();
}
        
void loop() {

  switch (robot_state)
    {
    case IDLE:
        if(buttonA.getSingleDebouncedRelease()){ 
            robot_state = MOVE; 
            robot.Stop();             
        } 
        else { 
            robot_state = IDLE;
            robot.Stop(); 
        }   
        break;
    
    case MOVE:
        robot.Move(50,50);
        break;
  }
}