#include <IRremote.h>

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

  int irPin = 22; //Pin am Arduino Nano für den IR Receiver
  int ledPin =24; //Pin am Arduino Nano für die LED als Signalbestätigung

  int led1Pin = 26; //Pin am Arduino Nano für LED 1
  int led2Pin = 28; //Pin am Arduino Nano für LED 2

  boolean led1Status = false;
  boolean led2Status = false;


  IRrecv irrecv(irPin); //Objekt initialisieren für die IR Übertragung
  decode_results results;


void setup() {
  // put your setup code here, to run once:
  set_pins();
  clearDisplay();
  pinMode(ledPin, OUTPUT);  //Den LED Pin als Ausgang deklarieren.
  pinMode(irPin, INPUT);  //Den IR Pin als Eingang deklarieren.
  irrecv.enableIRIn(); //Den IR Pin aktivieren
  Serial.begin(9600); //Serielle kommunikation mit 9600 Baud beginnen.
}

void loop() {
  // put your main code here, to run repeatedly:
  drawDisplay(field);
  remote();
}





