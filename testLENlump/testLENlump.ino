#include "Keyboard.h"

void setup() {
  // put your setup code here, to run once:

  pinMode(17,OUTPUT);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Keyboard.getLedStatus(LED_CAPS_LOCK))
  {
    digitalWrite(17,HIGH);
  }
  else
  {
    digitalWrite(17,LOW);
  }
}
