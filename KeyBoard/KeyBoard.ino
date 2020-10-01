#include "Keyboard.h"


//===============================
//===================================
//  Keyboard

  #define NONE 0x00
//#define KEY_ENT  0xB0 //Enter
//#define KEY_ESC  0xB1 //Escape
//#define KEY_BSPC 0xB2 //Backspace
//#define KEY_DEL  0xD4 //Delete
//#define KEY_TAB  0xB3 //Tab
//#define KEY_CAPS 0xC1 //Capslock
//#define KEY_LCTL 0x80 //Leftcontrol
//#define KEY_LSFT 0x81 //Leftshift
//#define KEY_LALT 0x82 //Leftalt
//#define KEY_LGUI 0x83 //Leftgui
//#define KEY_RCTL 0x84 //Rightcontrol
//#define KEY_RSFT 0x85 //Rightshift
//#define KEY_RALT 0x86 //Rightalt
//#define KEY_RGUI 0x87 //Rightgui

//#define KEY_PGUP 0xD3 //Pageup 
//#define KEY_PGDN 0xD6 //Pagedown
//#define KEY_HOME 0xD2 //Home
//#define KEY_END  0xD5 //End
//#define KEY_LEFT 0xD8 
//#define KEY_RGHT 0xD7
//#define KEY_UP   0xDA
//#define KEY_DOWN 0xD9

  #define KEY_0 0x30
  #define KEY_1 0x31
  #define KEY_2 0x32
  #define KEY_3 0x33
  #define KEY_4 0x34
  #define KEY_5 0x35
  #define KEY_6 0x36
  #define KEY_7 0x37
  #define KEY_8 0x38
  #define KEY_9 0x39

  #define KEY_EXLM 0x21 //Exclamationmark !
  #define KEY_AT   0x40 //Commercialat @
  #define KEY_HASH 0x23 //Hashkey #
  #define KEY_DLR  0x24 //Dollarsign $
  #define KEY_PERC 0x25 //Percent %
  #define KEY_CIRC 0x5E //Circumflex ^
  #define KEY_AMPR 0x26 //Ampersand &
  #define KEY_ASTR 0x2A //Asterisk *
  #define KEY_LPRN 0x28 // (
  #define KEY_RPRN 0x29 // )

  #define KEY_MINS 0x2D //Minus -
  #define KEY_EQL  0x3D //Equal =
  #define KEY_SPC  0x20 //Space
  #define KEY_LBRC 0x5B // [
  #define KEY_RBRC 0x5D // ]
  #define KEY_LCBR 0x7B // {
  #define KEY_RCBR 0x7D // }
  #define KEY_BSLS 0x5C //Backslash
  #define KEY_SCLN 0x3B //Semicolon ;
  #define KEY_QUOT 0x27 //Apostrophe '
  #define KEY_GRV  0x60 //Graveaccent `
  #define KEY_COMM 0x2C // ,
  #define KEY_DOT  0x2E //Period .
  #define KEY_SLSH 0x2F //Slash

  #define KEY_A 0x61
  #define KEY_B 0x62
  #define KEY_C 0x63
  #define KEY_D 0x64
  #define KEY_E 0x65
  #define KEY_F 0x66
  #define KEY_G 0x67
  #define KEY_H 0x68
  #define KEY_I 0x69
  #define KEY_J 0x6A
  #define KEY_K 0x6B
  #define KEY_L 0x6C
  #define KEY_M 0x6D
  #define KEY_N 0x6E
  #define KEY_O 0x6F
  #define KEY_P 0x70
  #define KEY_Q 0x71
  #define KEY_R 0x72
  #define KEY_S 0x73
  #define KEY_T 0x74
  #define KEY_U 0x75
  #define KEY_V 0x76
  #define KEY_W 0x77
  #define KEY_X 0x78
  #define KEY_Y 0x79
  #define KEY_Z 0x7A


const int rowNum = 6;
const int colNum = 8;

const int rowPin[rowNum] = {13,14,15,16,17,18};
const int colPin[colNum] = {2,3,4,5,6,7,8,9};

bool currentState[rowNum][colNum];
bool beforeState[rowNum][colNum];



const byte keyMap[rowNum*4][colNum] = {
  //left
  {KEY_ESC, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, NONE},
  {KEY_}

  //right
  {}
  
  
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

  Keyboard.press('v');

  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_F1);
  Keyboard.release(KEY_RIGHT_SHIFT);

  
}

bool FnKeyPushed = false;

void loop() 
{
  if("fn osareta")
  {
    FnKeyPushed = true;
  }
  
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
          if(uraki-no umu aru && FnKeyPushed)
          {
            Keyboard.press(KEY_VOLUMEUP);
          }
          else{
          Serial.println("Pushed");
          Keyboard.press("KEY_F9");
          }
        }
        else
        {
          
        }
      }
      
    }
  }
  
}
