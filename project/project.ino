#include <StivSeg.h>

//define pins for 8*8
  #define r1 2 //r=row
  #define r2 3
  #define r3 4
  #define r4 5
  #define r5 6
  #define r6 7
  #define r7 8
  #define r8 9
  #define c1 10 //c=column
  #define c2 11
  #define c3 12
  #define c4 13
  #define c5 14
  #define c6 15
  #define c7 16
  #define c8 17

  //collect rows and columns
  int row[] = {r1, r2 ,r3 ,r4 ,r5, r6, r7, r8};
  int column[] = {c1, c2, c3, c4, c5, c6, c7, c8};
  //define the playfield
  byte field[] = {0x24, 0x24, 0xff, 0x24, 0x24, 0xff, 0x24, 0x24};
  


  //define a point struct
  typedef struct {
    int row;
    int column;
  }point;

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


void setup() {
  // put your setup code here, to run once:
  set_pins();
  clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  drawDisplay(field);

}

void set_pins(){
  //set pinmodes to output
  for(int i=0; i<=7; i++){
    pinMode(row[i], OUTPUT);
  }
  for(int i=0; i<=7; i++){
    pinMode(column[i], OUTPUT);
  }
}

void clearDisplay(){
  //clears the display
  for(int i = 0; i<=7; i++){
    digitalWrite(row[i],LOW);
  }
    for(int i = 0; i<=7; i++){
    digitalWrite(column[i],HIGH);
  }
}

void drawDot(point x){
  //draws the dot at the defined point
  digitalWrite(x.row,HIGH);
  digitalWrite(x.column,LOW);
}

void drawDisplay(byte *example){
  //loop through rows and set them High
  for(int j = 0; j<8; j++){
    digitalWrite(row[j], HIGH);
    for(int i = 0; i<8; i++){
     digitalWrite(column[i], (~example[j]>>i)&0x01);
     digitalWrite(column[i], 1);
    }
    digitalWrite(row[j], 0);
  }
}

void drawX(point pos){
  digitalWrite(pos.row,HIGH);
  digitalWrite(pos.column,LOW);

  digitalWrite(pos.row,LOW);
  digitalWrite(pos.column,HIGH);

  digitalWrite(pos.row+1,HIGH);
  digitalWrite(pos.column+1,LOW);

  digitalWrite(pos.row+1,LOW);
  digitalWrite(pos.column+1,HIGH);
}

void drawO(point pos){
  digitalWrite(pos.row,HIGH);
  digitalWrite(pos.column,LOW);

  digitalWrite(pos.row,LOW);
  digitalWrite(pos.column,HIGH);

  digitalWrite(pos.row,HIGH);
  digitalWrite(pos.column+1,LOW);

  digitalWrite(pos.row,LOW);
  digitalWrite(pos.column+1,HIGH);

   digitalWrite(pos.row+1,HIGH);
  digitalWrite(pos.column,LOW);

  digitalWrite(pos.row+1,LOW);
  digitalWrite(pos.column,HIGH);

  digitalWrite(pos.row+1,HIGH);
  digitalWrite(pos.column+1,LOW);

  digitalWrite(pos.row+1,LOW);
  digitalWrite(pos.column+1,HIGH);


}



