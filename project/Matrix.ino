/*void set_pins(){
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
}*/
