#include "matrix.h"

void Matrix::setPins(int row[], int column[]){
  //set pinmodes to output
  for(int i=0; i<=7; i++){
    pinMode(row[i], OUTPUT);
  }
  for(int i=0; i<=7; i++){
    pinMode(column[i], OUTPUT);
  }
}

void Matrix::clearDisplay(int row[], int column[]){
  //clears the display
  for(int i = 0; i<=7; i++){
    digitalWrite(row[i],LOW);
  }
    for(int i = 0; i<=7; i++){
    digitalWrite(column[i],HIGH);
  }
}

void Matrix::drawDot(point x){
  //draws the dot at the defined point
  digitalWrite(x.row,HIGH);
  digitalWrite(x.column,LOW);
}

void Matrix::drawDisplay(byte *example, int row[], int column[]){
  //loop through rows and set them High
  for(int j = 0; j<8; j++){
    digitalWrite(row[j], HIGH);
    //shift through the map defined in the array example. 
    //compare the bit values of given byte and set the column to 0
    for(int i = 0; i<8; i++){
     digitalWrite(column[i], (~example[j]>>i)&0x01);
     //reset column to 1 for multiplexing
     digitalWrite(column[i], 1);
    }
    //rest row to 0 for multiplexing
    digitalWrite(row[j], 0);
  }
}

void Matrix::drawX(point pos, int row[], int column[]){
  //draw an / from the given pos
  digitalWrite(pos.row,HIGH);
  digitalWrite(pos.column,LOW);

  digitalWrite(pos.row,LOW);
  digitalWrite(pos.column,HIGH);

  digitalWrite(pos.row+1,HIGH);
  digitalWrite(pos.column+1,LOW);

  digitalWrite(pos.row+1,LOW);
  digitalWrite(pos.column+1,HIGH);
}

void Matrix::drawO(point pos, int row[], int column[]){
  //draw an o from the pos
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