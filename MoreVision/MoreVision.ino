#include <SPI.h>
#include <Pixy.h>
Pixy pixy;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pixy.init();
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
      //Serial.print("X Coordinate: ");
      //Serial.println(pixy.blocks[1].x);
      pixy.blocks[1].print();
      x=pixy.blocks[1].x;
      y=pixy.blocks[1].y;
    }
  }
  
}
