#include "Keyboard.h"

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  
}
void loop()
{
  if(digitalRead(2) == LOW && digitalRead(5) == LOW)
  {
    digitalWrite(17,LOW);
  }
  else if(digitalRead(2) == HIGH && digitalRead(5) == HIGH)
  {
    digitalWrite(17,HIGH);
  }
  
}
