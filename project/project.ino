#include <IRremote.h>

#define irPin 22

  
  IRrecv irrecv(irPin); //Objekt initialisieren für die IR Übertragung
  decode_results results;


void setup() {
  //(ledPin, OUTPUT);  //Den LED Pin als Ausgang deklarieren.
  pinMode(irPin, INPUT);  //Den IR Pin als Eingang deklarieren.
  irrecv.enableIRIn(); //Den IR Pin aktivieren
  Serial.begin(9600); //Serielle kommunikation mit 9600 Baud beginnen.
}

 
void loop()
{
  remote(results);
     
}









