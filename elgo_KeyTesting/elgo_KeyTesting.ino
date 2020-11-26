#include "Keyboard.h"


const int row[] = {13,18,19,20,21,22,23};
const int col[] = {2,3,4,5,6,7,8,9};


void setup() {
  // put your setup code here, to run once:
  for (int ii = 0; ii < sizeof(row) / 2; ii++)
  {
    pinMode(row[ii], OUTPUT);
    digitalWrite(row[ii], HIGH);
    //Serial.print(digitalRead(row[ii]));
    //Serial.print(" ");
  }
  //Serial.println(" ");
  //Serial.println(sizeof(col) / 2);
  for (int ii = 0; ii < sizeof(col) / 2; ii++)
  {
    pinMode(col[ii], INPUT_PULLUP);
    //Serial.print(digitalRead(col[ii]));
    //Serial.print(" ");
  }

  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
for (int ii = 0; ii < 7; ii++)
  {
    digitalWrite(row[ii], LOW);
    for (int jj = 0; jj < 8; jj++)
    {
      
      if(!digitalRead(col[jj]))
      {
        Serial.print(row[ii]);
        Serial.print(' ');
        Serial.println(col[jj]);
        digitalWrite(17,HIGH);
      }
      else
      {
        digitalWrite(17,LOW);
      }
      
    }
    digitalWrite(row[ii], HIGH);
  }
  
}
