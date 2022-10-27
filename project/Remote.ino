void remote(decode_results results){
    if (irrecv.decode(&results)) { //Wenn etwas gelesen wurde dann...
          //Ausgabe des Wertes auf die Serielle Schnittstelle.
          int value = results.value;
          switch (value){
            case 26775 : //Taste 0
            case 12495 : //Taste 1
               
            break;
            case 6375 : //Taste 2
                
                case 31365 : // Taste 3

                case 4335 : // Taste 4

                case 14535 : // Taste 5

                case 23205 : // Taste 6

                case 17085 : // Taste 7

                case 19125 : // Taste 8

                case 21165 : // Taste 9

                case -23971 : // Taste ON/OFF

                case 25245 : // Taste Mode

                case -22441 : // Taste Minus

                case -28561 : // Taset Plus
            break;
          }
          Serial.println(value, DEC);
        //  digitalWrite (ledPin, HIGH); //Status LED anschalten
          irrecv.resume(); // auf den nächsten Wert warten
          delay(250); // kurze Pause von 250ms damit die LED aufleuchten kann.
         // digitalWrite (ledPin, LOW); //Status LED ausschalten
    }
}