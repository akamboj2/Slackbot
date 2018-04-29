/*
 *  explaining the (((pixy.blocks[j].x)/2)+10)-60
 *  with pixy.blocks[j].x we get the x position of the object detected
 *  we divide it because the max value it can read is 320
 *  I did the + 10 for small adjustments 
 *  the -60 is used for rotating away from the object
 */
 
#include <Servo.h>
#include <SPI.h>
#include <Pixy.h>
 
Servo myservo;  // create servo object to control a servo
Pixy pixy;    // create pixy object for controlling the pixy camera
 
// function for testing the servo
void test_camera(){ 
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90); // get the camera centered
}
 
void setup() {
  //Serial.begin(9600); // initialize serial
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  test_camera();      // executing testing for the servo
  pixy.init();        // initing the pixy camera
}
 
void loop() {
  //variables
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  int32_t xpos;
  
  // grabing the blocks
  blocks = pixy.getBlocks();
  
  // If there are detect blocks
  if (blocks)
  {
  i++;
 
  // we are using 50FPS 
  if (i%50==0)
  {
    sprintf(buf, "Detected %d:\n", blocks);
    for (j=0; j<blocks; j++)
    {
      sprintf(buf, "  block %d: ", j);
        
      //Serial.println((((pixy.blocks[j].x)/2)+10)-60); //print out to what position will the servo go
 
      // this is used so the servo can't get stuck at minimum and maximum values
      if(((((pixy.blocks[j].x)/2)+10)-60) > 180 || ((((pixy.blocks[j].x)/2)+10)-60) < 0 ) 
      {
        myservo.write(90);  // if at min or max go to the middle
      }
      else{
 
      // if there is no problem with min and max
      myservo.write((((pixy.blocks[j].x)/2)+10)-60);
      }
    }
  }
  }
}
