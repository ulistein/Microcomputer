#ifndef MATRIX_H
#define MATRIX_H

#include "Arduino.h"

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

  //define a point struct
  typedef struct {
    int row;
    int column;
  }point;

  point pos1 = {r1, c1};
  point pos2 = {r1, c4};
  point pos3 = {r1, c7};
  point pos4 = {r4, c1};
  point pos5 = {r4, c4};
  point pos6 = {r4, c7};
  point pos7 = {r7, c1};
  point pos8 = {r7, c4};
  point pos9 = {r7, c7};

class Matrix{
  public:

  //constructor
  Matrix(){};
  
  void setPins(int row[], int column[]);
  void clearDisplay(int row[], int column[]);
  void drawDot(point x);
  void drawDisplay(byte *example, int row[], int column[]);
  void drawX(point pos);
  void drawO(point pos);
  point returnPos(int i, int j);


  private:
  //collect rows and columns
  //int row[8];
  //int column[8];
  
 

};

#endif /* matrix.hpp*/