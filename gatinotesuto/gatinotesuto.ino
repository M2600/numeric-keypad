#include <HID-Project.h>
#include <HID-Settings.h>
#include "Adafruit_NeoPixel.h"
#include "EEPROM.h"

#define KEY_ENT  0xB0 //Enter
#define KEY_EXLM 0x21 // Exclamationmark !

//#define KEY_A  4 //Enter


String keymap = "KEY_LEFT_SHIFT";

void setup() {
  BootKeyboard.begin();
  Serial.begin(9600);
  delay(1000);
  
  Serial.println(KEY_LEFT_SHIFT);
  BootKeyboard.press(KEY_TILDE);
  //BootKeyboard.press(KEY_A);
  //BootKeyboard.release(KEY_A);
  BootKeyboard.release(KEY_TILDE);
}
 
void loop() {
  Serial.println(KEY_LEFT_SHIFT);
  Serial.println(keymap);
}
