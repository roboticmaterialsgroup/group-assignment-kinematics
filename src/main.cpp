#include <Arduino.h>
#include <Encoders.h>
#include <Speed_controller.h>

SpeedController mySpeedController;

void setup() {
  // put your setup code here, to run once:
  mySpeedController.Init();

}

void loop() {
  // put your main code here, to run repeatedly:
  mySpeedController.Run(50,50);
}