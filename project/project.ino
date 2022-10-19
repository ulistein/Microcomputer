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
  if (irrecv.decode(&results)) { //Wenn etwas gelesen wurde dann...
      //Ausgabe des Wertes auf die Serielle Schnittstelle.
      int value = results.value;
      switch (value){
        case 16738455 : //Taste 0
        case 16724175 : //Taste 1
            led1Status = !led1Status; //umkehren des Status für die LED 1
            if(led1Status == true){
              digitalWrite (led1Pin, HIGH); //LED anschalten
            } else {
              digitalWrite (led1Pin, LOW); //LED ausschalten
            }
        break;
        case 16718055 : //Taste 2
            led2Status = !led2Status; //umkehren des Status für die LED 2
            if(led2Status == true){
              digitalWrite (led2Pin, HIGH); //LED anschalten
            } else {
              digitalWrite (led2Pin, LOW); //LED ausschalten
            }
            case 16743045 : // Taste 3

            case 16716015 : // Taste 4

            case 16726215 : // Taste 5

            case 16734885 : // Taste 6

            case 16728765 : // Taste 7

            case 16730805 : // Taste 8

            case 16732845 : // Taste 9

            case 16753245 : // Taste ON/OFF

            case 16736925 : // Taste Mode

            case 16754775 : // Taste Minus

            case 16748655 : // Taset Plus
        break;
      }
      Serial.println(value, DEC);
      digitalWrite (ledPin, HIGH); //Status LED anschalten
      irrecv.resume(); // auf den nächsten Wert warten
      delay(250); // kurze Pause von 250ms damit die LED aufleuchten kann.
      digitalWrite (ledPin, LOW); //Status LED ausschalten
 }
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




