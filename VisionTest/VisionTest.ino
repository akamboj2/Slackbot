#include <Pixy.h>
#include <SPI.h>

Pixy cam;

void setup() {
  //Serial.begin(9600); // initialize serial
  test_camera();      // executing testing for the servo
  cam.init();        // initing the pixy cam
}

void test_camera(){ 
  //myservo.write(0);
  delay(1000);
  //myservo.write(90);
  delay(1000);
  //myservo.write(180);
  delay(1000);
  //myservo.write(90); // get the camera centered
}
 
void loop() {
  //variables
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  int32_t xpos;
  
  // grabing the blocks
  blocks = cam.getBlocks();
  
  // If there are detect blocks
  if (blocks){
    i++;
 
    if (i%50==0){
      sprintf(buf, "Detected %d:\n", blocks);
      for (j=0; j<blocks; j++){
        sprintf(buf, "  block %d: ", j);
        
        //Serial.println((((pixy.blocks[j].x)/2)+10)-60); //print out to what position will the servo go
 
        // this is used so the servo can't get stuck at minimum and maximum values
        if(((((cam.blocks[j].x)/2)+10)-60) > 180 || ((((cam.blocks[j].x)/2)+10)-60) < 0 ){
          //myservo.write(90);  // if at min or max go to the middle
        } else {
          // if there is no problem with min and max
          //myservo.write((((pixy.blocks[j].x)/2)+10)-60);
        }
      }
    }
  }
}
