#ifndef REMOTE_H
#define REMOTE_H

#include <Arduino.h>
#include <IRremote.h>

#define irPin 22


typedef struct 
{
  bool But0 = false;
  bool But1 = false;
  bool But2 = false;
  bool But3 = false;
  bool But4 = false;
  bool But5 = false;
  bool But6 = false;
  bool But7 = false;
  bool But8 = false;
  bool But9 = false;
  bool ON = false;
  bool Mode = false;
  bool Plus = false;
  bool Minus = false;
}Button;

IRrecv irrecv(irPin); //Objekt initialisieren für die IR Übertragung

class Remote
{
  public:
    Remote(){};
    
    void remote(decode_results results, Button &button);    
};


#endif /* matrix.hpp*/