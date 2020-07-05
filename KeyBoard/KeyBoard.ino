#include "Keyboard.h"


const int rowNum = 8;
const int colNum = 6;

const int rowPin[rowNum] = {3,4,5,6,7,8,9,10};
const int colPin[colNum] = {13,14,15,16,17,18};

bool currentState[rowNum][colNum];
bool beforeState[rowNum][colNum];


#define NONE    0x00
  #define _______ 0x00
        
  #define KC_ENT  0x28
  #define KC_ESC  0x29
  #define KC_BSPC 0x2A
  #define KC_DEL  0x4C
  #define KC_TAB  0x2B
  #define KC_CAPS 0x39
  #define KC_LCTL 0xE0
  #define KC_LSFT 0xE1
  #define KC_LALT 0xE2
  #define KC_LGUI 0xE3
  #define KC_RCTL 0xE4
  #define KC_RSFT 0xE5
  #define KC_RALT 0xE6
  #define KC_RGUI 0xE7

  #define KC_PGUP 0x4B
  #define KC_PGDN 0x4E
  #define KC_HOME 0x4A
  #define KC_END  0x4D
  #define KC_LEFT 0x50
  #define KC_RGHT 0x4F
  #define KC_UP   0x52
  #define KC_DOWN 0x51

  #define KC_0 0x27
  #define KC_1 0x1E
  #define KC_2 0x1F
  #define KC_3 0x20
  #define KC_4 0x21
  #define KC_5 0x22
  #define KC_6 0x23
  #define KC_7 0x24
  #define KC_8 0x25
  #define KC_9 0x26

  #define KC_F1 0x3A
  #define KC_F2 0x3B
  #define KC_F3 0x3C
  #define KC_F4 0x3D
  #define KC_F5 0x3E
  #define KC_F6 0x3F
  #define KC_F7 0x40
  #define KC_F8 0x41
  #define KC_F9 0x42
  #define KC_F10 0x43
  #define KC_F11 0x44
  #define KC_F12 0x45

  #define KC_MINS 0x2D
  #define KC_EQL 0x2E
  #define KC_LSBC 0x2F
  #define KC_RSBC 0x30
  #define KC_BSLS 0x38
  #define KC_SCLN 0x33
  #define KC_APS 0x34
  #define KC_CMM  0x36
  #define KC_DOT 0x37
  #define KC_SLS 0x38
  #define KC_LGUI 0xE3
  #define KC_RGUI 0xE7
  #define KC_GAT 0x35

  #define KC_A 0x04
  #define KC_B 0x05
  #define KC_C 0x06
  #define KC_D 0x07
  #define KC_E 0x08
  #define KC_F 0x09
  #define KC_G 0x0A
  #define KC_H 0x0B
  #define KC_I 0x0C
  #define KC_J 0x0D
  #define KC_K 0x0E
  #define KC_L 0x0F
  #define KC_M 0x10
  #define KC_N 0x11
  #define KC_O 0x12
  #define KC_P 0x13
  #define KC_Q 0x14
  #define KC_R 0x15
  #define KC_S 0x16
  #define KC_T 0x17
  #define KC_U 0x18
  #define KC_V 0x19
  #define KC_W 0x1A
  #define KC_X 0x1B
  #define KC_Y 0x1C
  #define KC_Z 0x1D

const byte keyMap[rowNum][colNum] = {
  
  {KC_ESC, NONE, KC_F1, KC_F2, KC_F3, KC_F4}
  
  
}


void setup() 
{
  for(int i=0;i<rowNum;i++)
  {
    pinMode(rowPin[rowNum],OUTPUT);
  }
  
  for(int i=0;i<colNum;i++)
  {
    pinMode(colPin[colNum],INPUT_PULLUP);
  }

  for( int i = 0; i < rowNum; i++){
    for( int j = 0; j < colNum; j++){
      currentState[i][j] = HIGH;
      beforeState[i][j] = HIGH;
    }
  }

  Keyboard.begin();
}

void loop() 
{
  for(int i=0;i<rowNum;i++)
  {
    digitalWrite(rowPin[i],LOW);
    
    for(int j=0;j<colNum;j++)
    {
      currentState[i][j] = digitalRead(colPin[j]);

      if(currentState[i][j] != beforeState[i][j])
      {
        if(currentState[i][j] == LOW)
        {
          Serial.println("Pushed");
          Keyboard.press('A');
        }
        else
        {
          
        }
      }
      
    }
  }
  
}
