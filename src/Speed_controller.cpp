#include <Romi32U4.h>
#include "Encoders.h"
#include "Speed_controller.h"

Romi32U4Motors motors;
Encoder MagneticEncoder; 

void SpeedController::Init(void)
{
    MagneticEncoder.Init();
}

void SpeedController::Run(float target_velocity_left, float target_velocity_right)
{
    if(MagneticEncoder.UpdateEncoderCounts()){
        float e_left = target_velocity_left - MagneticEncoder.ReadVelocityLeft();
        float e_right = target_velocity_right - MagneticEncoder.ReadVelocityRight();

        E_left += e_left;
        E_right += e_right;

        float u_left = Kp*e_left + Ki*E_left;
        float u_right = Kp*e_right + Ki*E_right;

        motors.setEfforts(u_left,u_right);
        //odometry.UpdatePose(target_velocity_left,target_velocity_right); //this is where your newly programmed function is/will be called
        MagneticEncoder.PrintVelocities();
    }
}

boolean SpeedController::Turn(int degree, int direction)
{
    //program a turn function
}

boolean SpeedController::Straight(int target_velocity, int time)
{
    //program a straight movement function in cm/s or mm/s
}

boolean SpeedController::Curved(int target_velocity_left, int target_velocity_right, int time)
{
    //program a curved movement function
}

void SpeedController::Stop()
{
    motors.setEfforts(0,0);
}