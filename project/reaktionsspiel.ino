// Array zur Ablage der Zahlencoierung für die LED-Beschaltung

int num_array[11][8] = {  { 1,1,1,1,1,1,0,0 },  // 0
                          { 0,1,1,0,0,0,0,0 },  // 1
                          { 1,1,0,1,1,0,1,0 },  // 2
                          { 1,1,1,1,0,0,1,0 },  // 3
                          { 0,1,1,0,0,1,1,0 },  // 4
                          { 1,0,1,1,0,1,1,0 },  // 5
                          { 1,0,1,1,1,1,1,0 },  // 6
                          { 1,1,1,0,0,0,0,0 },  // 7
                          { 1,1,1,1,1,1,1,0 },  // 8
                          { 1,1,1,0,0,1,1,0 },  // 9
                          { 0,0,0,0,0,0,0,1}};  // Punkt
                   
                                       
void Num_Write(int);

void set_pins(){

  pinMode(28, OUTPUT);   // PIns 7 segment anzeige setzen
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(42, OUTPUT);

  pinMode(24, INPUT); // Button 1 Pin als Input
  pinMode(26, INPUT);

}
void countdown(){

    for (int counter = 10; counter > 0; --counter) // Die Darstellung des Punktes counter auf 10 setzen 
  {
   delay(1000);
   Num_Write(counter-1); //Zahl um 1 Verringern
  }
  delay(3000);
}
}

void game(){

  while(true){

    if(digitalread(24) == 1){ //wenn button 1 gedrückt, dann 1 Anzeigen

      Num_Write(1);
      break;

    }
    else if(digitalread(26 == 1){ //wenn button 2 gedrückt, dann 2 Anzeigen

      Num_Write(2);
      break;

    }

  }





}

// Diese Funktion steuert die jeweis für die Nummer benötigten Pins an 
void Num_Write(int number) 
{
  int pin= 28; //Anfangs Pin  28
  for (int j=0; j < 8; j++) { 
   digitalWrite(pin, num_array[number][j]); // Number ist die Zahl, die ich anzeigen will. J ist die Spalte. Greift 
                                                                                                  // Num_array zu
    pin = pin+2;            // Um 2 hochzählen, da pin 28,30,32  ... insgesamt 7 mal um 2 erhöhen
  }
}

