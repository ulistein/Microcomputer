#include <IRremote.h>
#define irPin 22


struct Button
{
  boolean But0 = false;
  boolean But1 = false;
  boolean But2 = false;
  boolean But3 = false;
  boolean But4 = false;
  boolean But5 = false;
  boolean But6 = false;
  boolean But7 = false;
  boolean But8 = false;
  boolean But9 = false;
  boolean ON = false;
  boolean Mode = false;
  boolean Plus = false;
  boolean Minus = false;
};

  

void setup() 
{
 pinMode(irPin, INPUT);  //Den IR Pin als Eingang deklarieren.
  irrecv.enableIRIn(); //Den IR Pin aktivieren
  Serial.begin(9600); //Serielle kommunikation mit 9600 Baud beginnen.
 // IRrecv irrecv(irPin); //Objekt initialisieren für die IR Übertragung
  IRrecv irrecv(irPin); //Objekt initialisieren für die IR Übertragung
decode_results results;

}

  Button button;
void loop()
{
  
  remote(results, button);

}