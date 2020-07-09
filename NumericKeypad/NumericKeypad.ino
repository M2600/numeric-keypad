#include "Keyboard.h"

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);

  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);

  //digitalWrite(5,LOW);
  //digitalWrite(6,LOW);

  
  
  
  digitalWrite(17,LOW);
  delay(1000);
  digitalWrite(17,HIGH);
  delay(1000);
  digitalWrite(17,LOW);
  delay(1000);
  digitalWrite(17,HIGH);
  delay(1000);
  digitalWrite(17,LOW);
  delay(1000);
  digitalWrite(17,HIGH);
  delay(1000);
  
}
void loop()
{
  
  
  if(digitalRead(5) == LOW && digitalRead(2) == HIGH)
  {
    digitalWrite(17,LOW);
  }
  if(digitalRead(5) == LOW && digitalRead(3) == HIGH)
  {
    digitalWrite(30,LOW);
  }
  else
  {
    digitalWrite(17,HIGH);
    digitalWrite(30,HIGH);
  }
  /*if(digitalRead(5) == LOW && digitalRead(3) == LOW)
  {
    digitalWrite(30,LOW);
  }
  else if(digitalRead(5) == HIGH && digitalRead(3) == HIGH)
  {
    digitalWrite(30,HIGH);
    digitalWrite(17,HIGH);
  }*/
}
