
#include "src/classes/Matrix/matrix.h"

  //create object to us matrix functions
  Matrix myMatrix;

  //collect rows and columns
  int row[] = {r1, r2 ,r3 ,r4 ,r5, r6, r7, r8};
  int column[] = {c1, c2, c3, c4, c5, c6, c7, c8};
  //define the playfield
  byte field[] = {0x24, 0x24, 0xff, 0x24, 0x24, 0xff, 0x24, 0x24};

  

  //define positions
  point pos1 = {r1, c1};
  point pos2 = {r1, c4};
  point pos3 = {r1, c7};
  point pos4 = {r4, c1};
  point pos5 = {r4, c4};
  point pos6 = {r4, c7};
  point pos7 = {r7, c1};
  point pos8 = {r7, c4};
  point pos9 = {r7, c7};

  int irPin = 22; //Pin am Arduino Nano für den IR Receiver
  int ledPin =24; //Pin am Arduino Nano für die LED als Signalbestätigung

  int led1Pin = 26; //Pin am Arduino Nano für LED 1
  int led2Pin = 28; //Pin am Arduino Nano für LED 2

  boolean led1Status = false;
  boolean led2Status = false;


 


void setup() {
  // put your setup code here, to run once:
  myMatrix.setPins(row, column);
  //myMatrix.clearDisplay(row, column);
  pinMode(ledPin, OUTPUT);  //Den LED Pin als Ausgang deklarieren.
  pinMode(irPin, INPUT);  //Den IR Pin als Eingang deklarieren.
 
}

void loop() {
  // put your main code here, to run repeatedly:
  myMatrix.drawDisplay(field, row, column);
  
}





