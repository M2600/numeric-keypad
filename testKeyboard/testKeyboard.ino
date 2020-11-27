#include "Keyboard.h"


#define KEY_F13 0x68
#define KEY_MUTE        0x7F
  #define KEY_VOLUMEUP    0x80
  #define KEY_VOLUMEDOWN  0x81

byte lines[]={"Hello world!"};

void setup()
{
  pinMode(5,INPUT_PULLUP);  
  pinMode(17,OUTPUT);

  Serial.begin(9600);
  Keyboard.begin();
  

  Keyboard.press(KEY_MUTE);
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
