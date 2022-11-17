
void setPins(int row[], int column[]){
  //set pinmodes to output
  for(int i=0; i<=7; i++){
    pinMode(row[i], OUTPUT);
  }
  for(int i=0; i<=7; i++){
    pinMode(column[i], OUTPUT);
  }
}

void clearDisplay(int row[], int column[]){
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

void drawDisplay(byte *example, int row[], int column[]){
  //loop through rows and set them High
  for(int j = 0; j<8; j++){
    digitalWrite(row[j], HIGH);
    //shift through the map defined in the array example. 
    //compare the bit values of given byte and set the column to 0
    for(int i = 0; i<8; i++){
     digitalWrite(column[i], (~example[j]>>i)&0x01);
     //reset column to 1 for multiplexing
     digitalWrite(column[i], 1);
    }
    //rest row to 0 for multiplexing
    digitalWrite(row[j], 0);
  }
}

void drawX(point pos){
  //draw an / from the given pos
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
  //draw an o from the pos
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
}

static point returnPos(int i, int j){
  if(i==0 && j== 0){
    return pos1;
  }else if(i==0 && j== 1){
    return pos2;
  }
  else if(i==0 && j== 2){
    return pos3;
  }
  else if(i==1 && j== 0){
    return pos4;
  }else if(i==1 && j== 1){
    return pos5;
  }else if(i==1 && j== 2){
    return pos6;
  }else if(i==2 && j== 0){
    return pos7;
  }else if(i==2 && j== 1){
    return pos8;
  }else if(i==2 && j== 2){
    return pos9;
  }
}