#include  "Position_estimation.h"
#include "Encoders.h"

Encoder RomiEncoders;

float x = 0;
float y = 0;
float theta = 0;

void Position::Init(void)
{
    //
}

void Position::Stop(void)
{
    //
}

Position::pose_data Position::ReadPose(void)
{
    return {x,y,theta};
}

void Position::PrintPose(void)
{
    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(theta);
}

void Position::UpdatePose(float target_speed_left, float target_speed_right)
{
    //
}

