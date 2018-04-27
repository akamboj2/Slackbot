#include <Stepper.h>
const int stepsPerRev =200;

//connect stepper on pins 8-11;
Stepper stepper(stepsPerRev, 8,9,10,11);

void setup() {
  // put your setup code here, to run once:
  //sets speed to 60 rpm
  stepper.setSpeed(60);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper.step(stepsPerRev);
  
}
