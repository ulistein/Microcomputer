#include <IRremote.h>

void remote(decode_results results, Button &button){
    if (irrecv.decode(&results)) { //Wenn etwas gelesen wurde dann...
          //Ausgabe des Wertes auf die Serielle Schnittstelle.
          int value = results.value;
          switch (value){
            case 26775 : //Taste 0
              button.But0 = true;
            break;
            case 12495 : //Taste 1  
             button.But1 = true;
            break;
            case 6375 : //Taste 2
              button.But2 = true;
            break;
            case 31365 : // Taste 3
              button.But3 = true;
            break;
            case 4335 : // Taste 4
              button.But4 = true;
            break;
            case 14535 : // Taste 5
              button.But5 = true;
            break;
            case 23205 : // Taste 6
              button.But5 = true;
            break;
            case 17085 : // Taste 7
              button.But7 = true;
            break;
            case 19125 : // Taste 8
              button.But8 = true;
            break;
            case 21165 : // Taste 9
              button.But9 = true;
            break;
            case -23971 : // Taste ON/OFF
              button.ON = true;
            break;
            case 25245 : // Taste Mode
              button.Mode = true;
            break;
            case -22441 : // Taste Minus
              button.Minus = true;
            break;
            case -28561 : // Taset Plus
              button.Plus = true;
            break;
          }
          Serial.println(value, DEC);
        
          irrecv.resume(); // auf den nächsten Wert warten
          delay(250); // kurze Pause von 250ms damit die LED aufleuchten kann.
         // digitalWrite (ledPin, LOW); //Status LED ausschalten
    }
}