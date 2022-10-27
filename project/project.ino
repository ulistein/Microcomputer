//#include <IRremote.h>
#include "Remote.h"



Remote myremote;
void setup() {
  
  pinMode(irPin, INPUT);  //Den IR Pin als Eingang deklarieren.
  irrecv.enableIRIn(); //Den IR Pin aktivieren
  Serial.begin(9600); //Serielle kommunikation mit 9600 Baud beginnen.
  
  decode_results results;
}
Button button;
 
void loop()
{
  myremote.remote(results, button);
     
}









