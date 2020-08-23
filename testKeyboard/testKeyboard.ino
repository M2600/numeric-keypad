#include "Keyboard.h"


#define KEY_F13 0x68

byte lines[]={"Hello world!"};

void setup()
{
  pinMode(5,INPUT_PULLUP);  
  pinMode(17,OUTPUT);
}
void loop()
{
  if(digitalRead(5)==LOW)
  {
    digitalWrite(17,HIGH);
  }
  else
  {
    digitalWrite(17,LOW);
  }
}
