
int remote(decode_results results)
{
  if (irrecv.decode(&results)) { //Wenn etwas gelesen wurde dann...
      //Ausgabe des Wertes auf die Serielle Schnittstelle.
      int value = results.value;
      
      switch (value)
      {
          case 26775: //Taste 0
              return 0;
              break;
          case 12495: //Taste 1  
              return 1;
              break;
          case 6375: //Taste 2
              return 2;
              break;
          case 31365: // Taste 3
              return 3;
              break;
          case 4335: // Taste 4
              return 4;
              break;
          case 14535: // Taste 5
              return 5;
              break;
          case 23205 : // Taste 6
              return 6;
              break;
          case 17085 : // Taste 7
              return 7;
              break;
          case 19125 : // Taste 8
              return 8;
              break;
          case 21165 : // Taste 9
              return 9;
              break;
          case -23971 : // Taste ON/OFF
              return 10;
              break;
          case 25245 : // Taste Mode
              return 11;
              break;
          case -22441 : // Taste Minus
              return 12;
              break;
          case -28561 : // Taset Plus
              return 13;
          break;
        
      }
      Serial.println(value, DEC);
     
      irrecv.resume(); // auf den nächsten Wert warten
      delay(250); // kurze Pause von 250ms damit die LED aufleuchten kann.
      
 }
}