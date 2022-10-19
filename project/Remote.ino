void remote(){
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