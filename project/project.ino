#include <IRremote.h>

int irPin = 10; //Pin am Arduino Nano für den IR Receiver
int ledPin = 5; //Pin am Arduino Nano für die LED als Signalbestätigung

int led1Pin = 4; //Pin am Arduino Nano für LED 1
int led2Pin = 3; //Pin am Arduino Nano für LED 2

boolean led1Status = false;
boolean led2Status = false;


IRrecv irrecv(irPin); //Objekt initialisieren für die IR Übertragung
decode_results results;

void setup() {
  pinMode(ledPin, OUTPUT);  //Den LED Pin als Ausgang deklarieren.
  pinMode(irPin, INPUT);  //Den IR Pin als Eingang deklarieren.
  irrecv.enableIRIn(); //Den IR Pin aktivieren
  Serial.begin(9600); //Serielle kommunikation mit 9600 Baud beginnen.
}
 
void loop(){
   if (irrecv.decode(&results)) { //Wenn etwas gelesen wurde dann...
      //Ausgabe des Wertes auf die Serielle Schnittstelle.
      int value = results.value;
      switch (value){
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
        break;
      }
      Serial.println(value, DEC);
      digitalWrite (ledPin, HIGH); //Status LED anschalten
      irrecv.resume(); // auf den nächsten Wert warten
      delay(250); // kurze Pause von 250ms damit die LED aufleuchten kann.
      digitalWrite (ledPin, LOW); //Status LED ausschalten
 }
}