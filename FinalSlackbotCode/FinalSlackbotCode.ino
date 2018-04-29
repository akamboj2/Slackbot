#include <SPI.h>
#include <Pixy.h>
#include <Stepper.h>

const int stepsPerRev =400;
static int dir;//-1 is left, 0 is forward, 1 is right

Pixy pixy;
Stepper stepperR(stepsPerRev, 8,9,10,11);
Stepper stepperL(stepsPerRev, 4,5,6,7);

void forward();
void turnLeft();
void turnRight();

void setup() {
  // put your setup code here, to run once:
  dir=0;
  pixy.init();
  stepperR.setSpeed(60);
  stepperL.setSpeed(60);
  Serial.begin(9600);
}

void loop() {
  static int i=0;
  static int x=0;
  static int y=0;
  uint16_t blocks;
  // put your main code here, to run repeatedly:
  blocks = pixy.getBlocks();
  if (blocks){
    i++;
    if (i%10==0){
      x=pixy.blocks[1].x;
      Serial.print("X Coordinate: ");
      Serial.println(x);
      if (x<140){
        Serial.println("Moving Left:");
        dir=-1;
        //delay(500);
      }else if (x>180){
        Serial.println("Move Right:");
        dir=1;
       // delay(500);
      }
    }
  } 
  switch (dir){
    case 0:
      forward();
      break;
    case 1:
      turnRight();
      break;
    case -1:
      turnLeft();
      break;
  }
}

void forward(){
   for (int x=0;x<stepsPerRev;x++){
    stepperR.step(1);
    stepperL.step(-1);
  }
}
void turnRight(){
  for (int x=0;x<stepsPerRev;x++){
    if (x%2==0){
      stepperR.step(1);
    }
   stepperL.step(-1);
  }
}

void turnLeft(){
  for (int x=0;x<stepsPerRev;x++){
    if (x%2==0){
    stepperL.step(-1);
    }
    stepperR.step(1);
  }
}


