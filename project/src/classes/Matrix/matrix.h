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

class Matrix{
  public:

  //constructor
  Matrix(){};
  
  void setPins(int row[], int column[]);
  void clearDisplay(int row[], int column[]);
  void drawDot(point x);
  void drawDisplay(byte *example, int row[], int column[]);
  void drawX(point pos,int row[], int column[]);
  void drawO(point pos,int row[], int column[]);


  private:
  //collect rows and columns
  //int row[8];
  //int column[8];
  
 

};

#endif /* matrix.hpp*/