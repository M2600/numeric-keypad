/*//#include "Keyboard.h"
#include "Mouse.h"
#include "ConsumerControl.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        10
#define NUMPIXELS 4

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  }
}*/
int inByte = 0;
int SA = 0;
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  SA = Serial.available();  // シリアルポートにデータがあるかを確認
  if(SA > 0){
    Serial.println("received");
    inByte = Serial.read(); // データを読み込む
    if(inByte==65){
      Serial.print("Done.");  // ASCIIコードで"A"だった場合に"Done."を送信
      delay(1000);  // 通信用の待機時間
      Serial.println("send");
    }
  }
}
