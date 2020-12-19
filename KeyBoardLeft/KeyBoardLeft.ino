#include "Keyboard.h"
#include "Adafruit_NeoPixel.h"
#include "EEPROM.h"
#include "ConsumerControl.h"
//===================================
//Keyboard
  /*########################################################################
  ###                                                                    ###
  ###    Before writing the program, make the left and right settings.   ###
  ###     - It has been updated to work without this setting.            ###
  ###                                                                    ###
  ########################################################################*/

                       //#//
                       //#//
                       //#//
                       //#//
                       //#//
                   //////#//////
                    /////#/////
                     ////#////
                      ///#///
                       //#//
                        ///

bool leftSide;

//KeycodeDeclare

#define NONE     0x00
#define ____     0x00
#define KEY_FN   0xff
#define KEY_CPFL 0xfe
#define KEY_RAIS 0xfd
#define KEY_LOWE 0xfc


// missing sound control keys
//
#define KEY_MUTE        0xFb
#define KEY_VOLUMEUP    0xFa
#define KEY_VOLUMEDOWN  0xf9

#define KEY_FOR  0xf8
#define KEY_CLPF 0xf7

#define KEY_ENT  0xB0 //Enter
#define KEY_ESC  0xB1 //Escape 
#define KEY_BSPC 0xB2 //Backspace
#define KEY_DEL  0xD4 //Delete
#define KEY_TAB  0xB3 //Tab
#define KEY_CAPS 0xC1 //Capslock
#define KEY_LCTL 0x80 //Leftcontrol
#define KEY_LSFT 0x81 //Leftshift
#define KEY_LALT 0x82 //Leftalt
#define KEY_LGUI 0x83 //Leftgui
#define KEY_RCTL 0x84 //Rightcontrol
#define KEY_RSFT 0x85 //Rightshift
#define KEY_RALT 0x86 //Rightalt
#define KEY_RGUI 0x87 //Rightgui

#define KEY_PGUP 0xD3 //Pageup
#define KEY_PGDN 0xD6 //Pagedown
#define KEY_HOME 0xD2 //Home
#define KEY_END  0xD5 //End
#define KEY_LEFT 0xD8
#define KEY_RGHT 0xD7
#define KEY_UP   0xDA
#define KEY_DOWN 0xD9

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

#define KEY_EXLM 0x21 // Exclamationmark !
#define KEY_AT   0x40 // Commercialat @
#define KEY_HASH 0x23 // Hashkey #
#define KEY_DLR  0x24 // Dollarsign $
#define KEY_PERC 0x25 // Percent %
#define KEY_CIRC 0x5E // Circumflex ^
#define KEY_AMPR 0x26 // Ampersand &
#define KEY_ASTR 0x2A // Asterisk *
#define KEY_LPRN 0x28 // (
#define KEY_RPRN 0x29 // )

#define KEY_MINS 0x2D // Minus -
#define KEY_EQL  0x3D // Equal =
#define KEY_SPC  0x20 // Space
#define KEY_LBRC 0x5B // [
#define KEY_RBRC 0x5D // ]
#define KEY_LCBR 0x7B // {
#define KEY_RCBR 0x7D // }
#define KEY_BSLS 0x5C // Backslash
#define KEY_SCLN 0x3B // Semicolon ;
#define KEY_QUOT 0x27 // Apostrophe '
#define KEY_GRV  0x60 // Graveaccent `
#define KEY_COMM 0x2C // ,
#define KEY_DOT  0x2E // Period .
#define KEY_SLSH 0x2F // Slash

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

#define KEY_F13       0x68
#define KEY_F14       0x69
#define KEY_F15       0x6A
#define KEY_F16       0x6B
#define KEY_F17       0x6C
#define KEY_F18       0x6D
#define KEY_F19       0x6E
#define KEY_F20       0x6F
#define KEY_F21       0x70
#define KEY_F22       0x71
#define KEY_F23       0x72
#define KEY_F24       0x73
#define KEY_F24       0x73



//keyPad
#define KEY_KEYPAD_0 0xEA
#define KEY_KEYPAD_1 0xE1
#define KEY_KEYPAD_2 0xE2
#define KEY_KEYPAD_3 0xE3
#define KEY_KEYPAD_4 0xE4
#define KEY_KEYPAD_5 0xE5
#define KEY_KEYPAD_6 0xE6
#define KEY_KEYPAD_7 0xE7
#define KEY_KEYPAD_8 0xE8
#define KEY_KEYPAD_9 0xE9

#define KEY_KEYPAD_DECIMAL  0xEB  // dot
#define KEY_KEYPAD_ENTER    0xE0  // keypadEnter
#define KEY_KEYPAD_PLUS     0xDF  // +
#define KEY_KEYPAD_MINUS    0xDE  // -
#define KEY_KEYPAD_MULTIPLY 0xDD  // *
#define KEY_KEYPAD_DIVIDE   0xDC  // /
#define KEY_KEYPAD_NUMLOCK  0xDB


//======================================

const int row[] = {13, 18, 19, 20, 21, 22, 23};
const int col[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int capslockLedNum = 12;


byte sendData, receiveData;
int pressed;

//LEDTapeSettings
#ifdef __AVR__
#include <avr/power.h>
#endif
int backLEDPin = 11;
int statusLEDPin = 10;
int numpixels = 10;
int numpixels1 = 4;


Adafruit_NeoPixel backLED(numpixels, backLEDPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel statusLED(numpixels1, statusLEDPin, NEO_GRB + NEO_KHZ800);




// keyMap ～ as you like!! ～
const byte keyMap[sizeof(row) / 2 * 16][sizeof(col) / 2] = {
  //left
  {KEY_ESC,  KEY_F1,   KEY_F2,   KEY_F3,   KEY_F4,   KEY_F5,   KEY_F6,   NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TAB,  KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_LPRN, NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_LCBR, NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_LEFT, NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_RSFT, KEY_DEL,  ____     },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },

  //leftFn
  {KEY_ESC,  KEY_F1,   KEY_F2,   KEY_F3,   KEY_MUTE, KEY_VOLUMEDOWN,   KEY_VOLUMEUP, NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,        NONE     },
  {KEY_CLPF, KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_LPRN,     NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_LCBR,     NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_LEFT,     NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_RSFT, KEY_DEL,      ____     },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,      NONE     },

  //leftRais
  {KEY_ESC,  KEY_F1,   KEY_F2,   KEY_F3,   KEY_F4,   KEY_F5,   KEY_F6,   NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TAB,  KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_LPRN, NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_LCBR, NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_LEFT, NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_RSFT, KEY_DEL,  ____     },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },

  //leftLower
  {KEY_ESC,  KEY_F1,   KEY_F2,   KEY_F3,   KEY_F4,   KEY_F5,   KEY_F6,   NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TAB,  KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_LPRN, NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_LCBR, NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_LEFT, NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_RSFT, KEY_DEL,  ____     },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },



  //leftGame
  {KEY_ESC,  KEY_F1,   KEY_F2,   KEY_F3,   KEY_F4,   KEY_F5,   KEY_F6,   NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TAB,  KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_F13,  NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_F14,  NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_F15,  NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_F16,  KEY_F17,  KEY_F18  },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },

  //leftGameFn
  {KEY_ESC,  KEY_F1,   KEY_F2,   KEY_F3,   KEY_F4,   KEY_F5,   KEY_F6,   NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_CLPF, KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_F13,  NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_F14,  NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_F15,  NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_F16,  KEY_F17,  KEY_F18  },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },

  //leftGameRAIS
  {KEY_ESC,  KEY_F1,   KEY_F2,   KEY_F3,   KEY_F4,   KEY_F5,   KEY_F6,   NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TAB,  KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_F13,  NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_F14,  NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_F15,  NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_F16,  KEY_F17,  KEY_F18  },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },

  //leftGameLower
  {KEY_ESC,  KEY_F1,   KEY_F2,   KEY_F3,   KEY_F4,   KEY_F5,   KEY_F6,   NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TAB,  KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_F13,  NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_F14,  NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_F15,  NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_F16,  KEY_F17,  KEY_F18  },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },


  //right
  {KEY_F7,   KEY_F8,   KEY_F9,   KEY_F10,  KEY_F11,  KEY_F12,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,    KEY_9,    KEY_0,    KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_RPRN, KEY_Y,    KEY_U,    KEY_I,    KEY_O,    KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_RCBR, KEY_H,    KEY_J,    KEY_K,    KEY_L,    KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_RGHT, KEY_N,    KEY_M,    KEY_COMM, KEY_DOT,  KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_BSPC, KEY_LSFT, KEY_LOWE, KEY_FN,   KEY_RALT, KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE, NONE,     NONE,     NONE,     NONE,     NONE,    },

  //rightFn
  {KEY_F7,   KEY_F8,   KEY_F9,       KEY_MUTE,       KEY_VOLUMEDOWN, KEY_VOLUMEUP,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,        KEY_9,          KEY_0,          KEY_MINS,      KEY_EQL,  KEY_HOME },
  {KEY_RPRN, KEY_Y,    KEY_U,        KEY_I,          KEY_O,          KEY_P,         KEY_LCBR, KEY_PGUP },
  {KEY_RCBR, KEY_H,    KEY_J,        KEY_K,          KEY_L,          KEY_SCLN,      KEY_QUOT, KEY_PGDN  },
  {KEY_RGHT, KEY_N,    KEY_M,        KEY_COMM,       KEY_DOT,        KEY_SLSH,      KEY_UP,   KEY_END  },
  {KEY_BSPC, KEY_LSFT, KEY_LOWE,     KEY_FN,         KEY_RALT,       KEY_LEFT,      KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE,     NONE,           NONE,           NONE,          NONE,     NONE,    },

  //rightRais
  {KEY_F7,   KEY_F8,   KEY_F9,   KEY_F10,  KEY_F11,  KEY_F12,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,    KEY_9,    KEY_0,    KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_RPRN, KEY_Y,    KEY_U,    KEY_UP,    KEY_O,   KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_RCBR, KEY_H,    KEY_LEFT, KEY_DOWN, KEY_RGHT, KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_RGHT, KEY_N,    KEY_M,    KEY_COMM, KEY_DOT,  KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_BSPC, KEY_LSFT, KEY_LOWE, KEY_FN,   KEY_RALT, KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE, NONE,     NONE,     NONE,     NONE,     NONE,    },

  //rightLower
  {KEY_F7,   KEY_F8,       KEY_F9,       KEY_F10,      KEY_F11,      KEY_F12,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,        KEY_8,        KEY_9,        KEY_0,        KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_RPRN, KEY_Y,        KEY_KEYPAD_7, KEY_KEYPAD_8, KEY_KEYPAD_9, KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_RCBR, KEY_H,        KEY_KEYPAD_4, KEY_KEYPAD_5, KEY_KEYPAD_6, KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_RGHT, KEY_KEYPAD_0, KEY_KEYPAD_1, KEY_KEYPAD_2, KEY_KEYPAD_3, KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_BSPC, KEY_LSFT,     KEY_LOWE,     KEY_FN,       KEY_RALT,     KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE,         NONE,         NONE,         NONE,     NONE,     NONE,    },

  //rightGame
  {KEY_F7,   KEY_F8,   KEY_F9,   KEY_F10,  KEY_F11,  KEY_F12,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,    KEY_9,    KEY_0,    KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_F19,  KEY_Y,    KEY_U,    KEY_I,    KEY_O,    KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_F20,  KEY_H,    KEY_J,    KEY_K,    KEY_L,    KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_F21,  KEY_N,    KEY_M,    KEY_COMM, KEY_DOT,  KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_F23,  KEY_F22,  KEY_LOWE, KEY_FN,   KEY_RALT, KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_F24,  NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     NONE,    },

  //rightGameFn
  {KEY_F7,   KEY_F8,   KEY_F9,       KEY_MUTE,       KEY_VOLUMEDOWN, KEY_VOLUMEUP,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,        KEY_9,          KEY_0,          KEY_MINS,      KEY_EQL,  KEY_HOME },
  {KEY_F19,  KEY_Y,    KEY_U,        KEY_I,          KEY_O,          KEY_P,         KEY_LCBR, KEY_PGUP },
  {KEY_F20,  KEY_H,    KEY_J,        KEY_K,          KEY_L,          KEY_SCLN,      KEY_QUOT, KEY_PGDN },
  {KEY_F21,  KEY_N,    KEY_M,        KEY_COMM,       KEY_DOT,        KEY_SLSH,      KEY_UP,   KEY_END  },
  {KEY_F23,  KEY_F22,  KEY_LOWE,     KEY_FN,         KEY_RALT,       KEY_LEFT,      KEY_DOWN, KEY_RGHT },
  {KEY_F24,  NONE,     NONE,         NONE,           NONE,           NONE,          NONE,     NONE,    },

  //rightGameRais
  {KEY_F7,   KEY_F8,   KEY_F9,   KEY_F10,  KEY_F11,  KEY_F12,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,    KEY_9,    KEY_0,    KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_F19,  KEY_Y,    KEY_U,    KEY_I,    KEY_O,    KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_F20,  KEY_H,    KEY_J,    KEY_K,    KEY_L,    KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_F21,  KEY_N,    KEY_M,    KEY_COMM, KEY_DOT,  KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_F23,  KEY_F22,  KEY_LOWE, KEY_FN,   KEY_RALT, KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_F24,  NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     NONE,    },

  //rightGameLower
  {KEY_F7,   KEY_F8,   KEY_F9,   KEY_F10,  KEY_F11,  KEY_F12,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,    KEY_9,    KEY_0,    KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_F19,  KEY_Y,    KEY_U,    KEY_I,    KEY_O,    KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_F20,  KEY_H,    KEY_J,    KEY_K,    KEY_L,    KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_F21,  KEY_N,    KEY_M,    KEY_COMM, KEY_DOT,  KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_F23,  KEY_F22,  KEY_LOWE, KEY_FN,   KEY_RALT, KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_F24,  NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     NONE,    }
};

//backLed============================================================

int backLightLEDNormal[][3]={
  //red
  {150,0,0},
  //purple
  {150,0,150},
  //blue
  {0,0,150},
  //aquablue
  {0,150,150},
  //green
  {0,150,0},
  //yellow
  {150,150,0},
  //white
  {150,150,150}
  };

//checkLED
int led = 13 ;

//eachKeysStatus
bool currentState[sizeof(row) / 2][sizeof(col) / 2];
bool beforeState[sizeof(row) / 2][sizeof(col) / 2];
//FNkeyStatus
bool fnKeyPushed = 0;
bool raisKeyPushed = 0;
bool loweKeyPushed = 0;
bool gameModeEnabled = 0;
bool leftShiftPushed = 0;
bool rightShiftPushed = 0;
bool leftControlPushed = 0;
bool rightControlPushed = 0;
bool forKeyPushed = 0;
bool backLEDOn = 0;


int LEDProfile = 0;

//LEDFlashSubroutine
void FlashLED( int pin, int num )
{
  for ( int ii = 0; ii < num; ii++ )
  {
    static bool sta = true;
    digitalWrite(pin, sta);
    delay(100);
    sta = !sta;
  }


}



//=========================setup========================
void setup() {

  //check left or right
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
  if(!digitalRead(12))
  {
    leftSide=true;
  }
  else
  {
    leftSide=false;
  }
  digitalWrite(12,LOW);

  
  pinMode(led, OUTPUT); //setLEDPin
  FlashLED( led, 4 );   //flashStatusLED

  pinMode( 13, OUTPUT); //NumlockStatusLED
  pinMode( capslockLedNum, OUTPUT);//capslockStatusLED


  //キースイッチのマトリックスなんやら用の設定
  Serial.println(sizeof(row) / 2);
  for (int ii = 0; ii < sizeof(row) / 2; ii++)
  {
    pinMode(row[ii], OUTPUT);
    digitalWrite(row[ii], HIGH);
    Serial.print(digitalRead(row[ii]));
    Serial.print(" ");
  }
  Serial.println(" ");
  Serial.println(sizeof(col) / 2);
  for (int ii = 0; ii < sizeof(col) / 2; ii++)
  {
    pinMode(col[ii], INPUT_PULLUP);
    Serial.print(digitalRead(col[ii]));
    Serial.print(" ");
  }

  //setKeysStatus
  for (int ii = 0; ii < sizeof(row) / 2; ii++)
  {
    for (int jj = 0; jj < sizeof(col) / 2; jj++)
    {
      currentState[ii][jj] = HIGH;
      beforeState[ii][jj] = HIGH;
      //HIGH=false LOW=true
    }
  }

  //LEDTapeSettings
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif



  //launchKeyboard
  Keyboard.begin();
  FlashLED( led, 4);
  Serial.begin(9600);
  Serial1.begin(9600);
  backLED.begin();
  statusLED.begin();
  delay(600);
  Serial.println("Serial available!!");


  //LEDProfile = EEPROM[0x000]; 
    

  for (int i = 0; i < 3; i++)
  {
    statusLED.clear();
    backLED.clear();
    for (int i = 0; i < numpixels; i++)
    {
      statusLED.setPixelColor(i, statusLED.Color(5, 0, 0));
      backLED.setPixelColor(i, backLED.Color(
        backLightLEDNormal[LEDProfile][0], backLightLEDNormal[LEDProfile][1], backLightLEDNormal[LEDProfile  ][2]));
    }
  
    statusLED.show();
    backLEDOn=true;
    backLED.show();
    delay(100);
    statusLED.clear();
    for (int i = 0; i < numpixels; i++)
    {
      statusLED.setPixelColor(i, statusLED.Color(0, 0, 0));
    }
    statusLED.show();
    delay(100);
  }


  Serial.print("EEPROM[0x000] ");
  Serial.println(EEPROM[0x000]);


  //起動時にNumLock On
  if (!Keyboard.getLedStatus(LED_NUM_LOCK))
  {
    Keyboard.press(KEY_KEYPAD_NUMLOCK);
    Keyboard.release(KEY_KEYPAD_NUMLOCK);
  }
  else
  {
    Keyboard.press(KEY_KEYPAD_NUMLOCK);
    Keyboard.release(KEY_KEYPAD_NUMLOCK);
    Keyboard.press(KEY_KEYPAD_NUMLOCK);
    Keyboard.release(KEY_KEYPAD_NUMLOCK);
  }
  digitalWrite(capslockLedNum, LOW);
}

bool capsLocked = false;

//============================loop==================================
void loop() {
  //AntiChattering
  int delayTime = 5;
  delay(delayTime);




  //capslockSetting
  if (Keyboard.getLedStatus(LED_CAPS_LOCK) && !capsLocked)
  {
    capsLockLedOn();
    sendData = 0b10000001;
    Serial1.write(sendData);
    Serial.flush();
    Serial.print("senddate");
    Serial.print(" ");
    Serial.println(sendData);
    capsLocked = true;
  }
  else if (!Keyboard.getLedStatus(LED_CAPS_LOCK) && capsLocked)
  {
    capsLockLedOff();
    sendData = 0b10000010;
    Serial1.write(sendData);
    Serial.print("senddate");
    Serial.print(" ");
    Serial.println(sendData);
    Serial.flush();
    capsLocked = false;
  }

  //profile



  if(leftShiftPushed)
  {
    Keyboard.press(KEY_LSFT);
  }
  if(rightShiftPushed)
  {
    Keyboard.press(KEY_RSFT);
  }
  if(leftControlPushed)
  {
    Keyboard.press(KEY_LCTL);
  }
  if(rightControlPushed)
  {
    Keyboard.press(KEY_RCTL);
  }


  for (int ii = 0; ii < sizeof(row) / 2; ii++)
  {
    digitalWrite(row[ii], LOW);
    for (int jj = 0; jj < sizeof(col) / 2; jj++)
    {
      currentState[ii][jj] = digitalRead(col[jj]);
      if (currentState[ii][jj] != beforeState[ii][jj])
      {
        int option = 0;
        if (!leftSide)
        {
          option += 56;
        }
        if (fnKeyPushed && !raisKeyPushed && !loweKeyPushed)
        {
          option += 7;
          Serial.println("FNKey+Keypushed");
        }
        if (raisKeyPushed && !fnKeyPushed && !loweKeyPushed)
        {
          option += 14;
        }
        if (loweKeyPushed && !fnKeyPushed && !raisKeyPushed)
        {
          option += 21;
        }
        if (gameModeEnabled)
        {
          option += 28;
        }

        if ( !currentState[ii][jj] )
        {
          
          if(keyMap[ii + option][jj] == KEY_LSFT)
          {
            leftShiftPushed = true;
            Keyboard.press( keyMap[ii + option][jj]);
            pressed = 1;
          }
          if(keyMap[ii + option][jj] == KEY_RSFT)
          {
            rightShiftPushed = true;
            Keyboard.press( keyMap[ii + option][jj]);
            pressed = 1;
          }
          if(keyMap[ii + option][jj] == KEY_LCTL)
          {
            leftControlPushed = true;
            Keyboard.press( keyMap[ii + option][jj]);
            pressed = 1;
          }
          if(keyMap[ii + option][jj] == KEY_RCTL)
          {
            rightControlPushed = true;
            Keyboard.press( keyMap[ii + option][jj]);
            pressed = 1;
          }
          if (keyMap[ii + option][jj] == KEY_FN)
          {
            Keyboard.releaseAll();
            fnKeyPushed = true;
            pressed = 1;
            Serial.println("FNKeyPushed!");
          }
          if (keyMap[ii + option][jj] == KEY_RAIS)
          {
            if(loweKeyPushed)
            {
              Keyboard.press( KEY_LALT );
              Keyboard.press( KEY_GRV );
              Keyboard.release( KEY_GRV );
              Keyboard.release( KEY_LALT );
              pressed = 1;
            }
            else
            {
              Keyboard.releaseAll();
              raisKeyPushed = true;
              pressed = 1;
            }
            
          }
          if (keyMap[ii + option][jj] == KEY_LOWE)
          {
            if(raisKeyPushed)
            {
              Keyboard.press( KEY_LALT );
              Keyboard.press( KEY_GRV );
              Keyboard.release( KEY_GRV );
              Keyboard.release( KEY_LALT );
              pressed = 1;
            }
            else
            {
              Keyboard.releaseAll();
              loweKeyPushed = true;
              pressed = 1;
            }
          }
          if (keyMap[ii + option][jj] == KEY_CPFL)
          {
            changeProfile();
            pressed = 1;
          }
          if (keyMap[ii + option][jj] == KEY_CLPF)
          {
            changeLightProfile();
            pressed = 1;
          }
          if (keyMap[ii + option][jj] == KEY_MUTE)
          {
            ConsumerControl.press(VOLUME_MUTE);
            pressed = 1;
          }
          if (keyMap[ii + option][jj] == KEY_VOLUMEUP)
          {
            ConsumerControl.press(VOLUME_UP);
            pressed = 1;
          }
          if (keyMap[ii + option][jj] == KEY_VOLUMEDOWN)
          {
            ConsumerControl.press(VOLUME_DOWN);
            pressed = 1;
          }


          
          /*if(keyMap[ii + option][jj] == KEY_SPC && leftControlPushed)
          {
            Keyboard.release( KEY_LCTL );
            Keyboard.press( KEY_LALT );
            Keyboard.press( KEY_GRV );
            Keyboard.release( KEY_GRV );
            Keyboard.release( KEY_LALT );
            Keyboard.press( KEY_LCTL );
            pressed = 1;
          }
          else if(keyMap[ii + option][jj] == KEY_SPC && rightControlPushed)
          {
            Keyboard.release( KEY_RCTL );
            Keyboard.press( KEY_LALT );
            Keyboard.press( KEY_GRV );
            Keyboard.release( KEY_GRV );
            Keyboard.release( KEY_LALT );
            Keyboard.press( KEY_RCTL );
            pressed = 1;
          }*/

          if(keyMap[ii + option][jj] == KEY_ESC && fnKeyPushed)
          {
            if(backLEDOn)
            {
              offBackLED();
              backLEDOn=false;
            }
            else
            {
              onBackLED();
              backLEDOn=true;
            }
            pressed = 1;
          }
          
          else
          {
            Keyboard.press( keyMap[ii + option][jj]);
            pressed = 1;
            Serial.println(keyMap[ii + option][jj]);
          }
        }
        else
        {

          if(keyMap[ii + option][jj] == KEY_LSFT)
          {
            leftShiftPushed = false;
            Keyboard.release( keyMap[ii + option][jj]);
            pressed = 0;
          }
          if(keyMap[ii + option][jj] == KEY_RSFT)
          {
            rightShiftPushed = false;
            Keyboard.release( keyMap[ii + option][jj]);
            pressed = 0;
          }
          if(keyMap[ii + option][jj] == KEY_LCTL)
          {
            leftControlPushed = false;
            Keyboard.release( keyMap[ii + option][jj]);
            pressed = 0;
          }
          if(keyMap[ii + option][jj] == KEY_RCTL)
          {
            rightControlPushed = false;
            Keyboard.release( keyMap[ii + option][jj]);
            pressed = 0;
          }
          
          if (keyMap[ii + option][jj] == KEY_FN)
          {
            fnKeyPushed = false;
            pressed = 0;
            Keyboard.releaseAll();
            ConsumerControl.release();
            Serial.println("FNKeyreleased!");
          }
          if (keyMap[ii + option][jj] == KEY_RAIS)
          {
            raisKeyPushed = false;
            pressed = 0;
            Keyboard.releaseAll();
          }
          if (keyMap[ii + option][jj] == KEY_LOWE)
          {
            loweKeyPushed = false;
            pressed = 0;
            Keyboard.releaseAll();
          }
          if (keyMap[ii + option][jj] == KEY_CPFL)
          {
            pressed = 0;
            Keyboard.releaseAll();
          }
          if (keyMap[ii + option][jj] == KEY_CPFL)
          {
            pressed = 0;
          }
          if (keyMap[ii + option][jj] == KEY_MUTE)
          {
            pressed = 0;
            ConsumerControl.release();
          }
          if (keyMap[ii + option][jj] == KEY_VOLUMEUP)
          {
            pressed = 0;
            ConsumerControl.release();
          }
          if (keyMap[ii + option][jj] == KEY_VOLUMEDOWN)
          {
            pressed = 0;
            ConsumerControl.release();
          }
          else
          {
            Keyboard.release( keyMap[ii + option][jj]);
            pressed = 0;
          }
        }
        digitalWrite(led, !currentState[ii][jj]);
        beforeState[ii][jj] = currentState[ii][jj];
        sendData = pressed << 6 | ii  << 3 | jj;
        Serial1.write(sendData);
        Serial.flush();

        Serial.print("senddate");
        Serial.print(" ");
        Serial.print(sendData);
        Serial.print(" ");
        Serial.print(pressed);
        Serial.print(" ");
        Serial.print(ii);
        Serial.print(" ");
        Serial.println(jj);
      }
    }
    digitalWrite(row[ii], HIGH);
  }
  if (Serial1.available())
  {
    readSerial();
  }
}

//================other===========================

void readSerial()
{
  int row, col;

  receiveData = Serial1.read();
  Serial.println(receiveData);
  if (receiveData == 0b10000001)
  {
    capsLockLedOn();
    Serial.print("readdate");
    Serial.print(" ");
    Serial.println(receiveData);
  }
  else if (receiveData == 0b10000010)
  {
    capsLockLedOff();
    Serial.print("readdate");
    Serial.print(" ");
    Serial.println(receiveData);
  }
  else if (receiveData & 0b10000000)
  {

  }

  else
  {
    int pressed1 = receiveData >> 6;
    int row1 = receiveData  >> 3 & 0b00000111;
    int col1 = receiveData & 0b00000111;

    Serial.print("readdate");
    Serial.print(" ");
    Serial.print(receiveData);
    Serial.print(" ");
    Serial.print(pressed1);
    Serial.print(" ");
    Serial.print(row1);
    Serial.print(" ");
    Serial.println(col1);

    int option1 = 0;
    if (leftSide)
    {
      option1 = 56;
    }
    if (fnKeyPushed && !raisKeyPushed && !loweKeyPushed)
    {
      option1 += 7;
    }
    if (raisKeyPushed && !fnKeyPushed && !loweKeyPushed)
    {
      option1 += 14;
    }
    if (loweKeyPushed && !fnKeyPushed && !raisKeyPushed)
    {
      option1 += 21;
    }
    if (gameModeEnabled)
    {
      option1 += 28;
    }
    if (pressed1)
    {
      

      if(keyMap[row1 + option1][col1] == KEY_LSFT)
      {
        leftShiftPushed = true;
        Keyboard.press( keyMap[row1 + option1][col1]);
        pressed = 1;
      }
      if(keyMap[row1 + option1][col1] == KEY_RSFT)
      {
        rightShiftPushed = true;
        Keyboard.press( keyMap[row1 + option1][col1]);
        pressed = 1;
      }
      if(keyMap[row1 + option1][col1] == KEY_LCTL)
      {
        leftControlPushed = true;
        Keyboard.press( keyMap[row1 + option1][col1]);
        pressed = 1;
      }
      if(keyMap[row1 + option1][col1] == KEY_RCTL)
      {
        rightControlPushed = true;
        Keyboard.press( keyMap[row1 + option1][col1]);
        pressed = 1;
      }
      if (keyMap[row1 + option1][col1] == KEY_FN)
      {
        Keyboard.releaseAll();
        fnKeyPushed = true;
      }
      if (keyMap[row1 + option1][col1] == KEY_RAIS)
      {
        if(loweKeyPushed)
          {
            Keyboard.press( KEY_LALT );
            Keyboard.press( KEY_GRV );
            Keyboard.release( KEY_GRV );
            Keyboard.release( KEY_LALT );
            pressed = 1;
          }
          else
          {
            Keyboard.releaseAll();
            raisKeyPushed = true;
          }
      }
      if (keyMap[row1 + option1][col1] == KEY_LOWE)
      {
        if(raisKeyPushed)
        {
          Keyboard.press( KEY_LALT );
          Keyboard.press( KEY_GRV );
          Keyboard.release( KEY_GRV );
          Keyboard.release( KEY_LALT );
          pressed = 1;
        }
        else
        {
          Keyboard.releaseAll();
          loweKeyPushed = true;
        }
      }
      if (keyMap[row1 + option1][col1] == KEY_CPFL)
      {
          changeProfile();
          pressed = 1;
      }
      if (keyMap[row1 + option1][col1] == KEY_CLPF)
          {
            changeLightProfile();
            pressed = 1;
          }
      if (keyMap[row1 + option1][col1] == KEY_MUTE)
      {
        ConsumerControl.press(VOLUME_MUTE);
        pressed = 1;
      }
      if (keyMap[row1 + option1][col1] == KEY_VOLUMEUP)
      {
        ConsumerControl.press(VOLUME_UP);
        pressed = 1;
      }
      if (keyMap[row1 + option1][col1] == KEY_VOLUMEDOWN)
      {
        ConsumerControl.press(VOLUME_DOWN);
        pressed = 1;
      }

      /*if(keyMap[row1 + option1][col1] == KEY_SPC && leftControlPushed)
      {
        Keyboard.release( KEY_LCTL );
        Keyboard.press( KEY_LALT );
        Keyboard.press( KEY_GRV );
        Keyboard.release( KEY_GRV );
        Keyboard.release( KEY_LALT );
        Keyboard.press( KEY_LCTL );
        pressed = 1;
      }
      else if(keyMap[row1 + option1][col1] == KEY_SPC && rightControlPushed)
      {
        Keyboard.release( KEY_RCTL );
        Keyboard.press( KEY_LALT );
        Keyboard.press( KEY_GRV );
        Keyboard.release( KEY_GRV );
        Keyboard.release( KEY_LALT );
        Keyboard.press( KEY_RCTL );
        pressed = 1;
      }*/

      if(keyMap[row1 + option1][col1] == KEY_ESC && fnKeyPushed)
      {
        if(backLEDOn)
        {
          offBackLED();
          backLEDOn=false;
        }
        else
        {
          onBackLED();
          backLEDOn=true;
        }
        pressed = 1;
      }
      
      else
      {
        Keyboard.press( keyMap[row1 + option1][col1]);
        Serial.println(keyMap[row1 + option1][col1]);
      }
    }
    else
    {
      if (keyMap[row1 + option1][col1] == KEY_FN)
      {
        fnKeyPushed = false;
        Keyboard.releaseAll();
        ConsumerControl.release();
      }

      if(keyMap[row1 + option1][col1] == KEY_LSFT)
      {
        leftShiftPushed = false;
        Keyboard.press( keyMap[row1 + option1][col1]);
        pressed = 0;
      }
      if(keyMap[row1 + option1][col1] == KEY_RSFT)
      {
        rightShiftPushed = false;
        Keyboard.press( keyMap[row1 + option1][col1]);
        pressed = 0;
      }
      if(keyMap[row1 + option1][col1] == KEY_LCTL)
      {
        leftControlPushed = false;
        Keyboard.press( keyMap[row1 + option1][col1]);
        pressed = 0;
      }
      if(keyMap[row1 + option1][col1] == KEY_RCTL)
      {
        rightControlPushed = false;
        Keyboard.press( keyMap[row1 + option1][col1]);
        pressed = 0;
      }

      
      if (keyMap[row1 + option1][col1] == KEY_RAIS)
      {
        Keyboard.releaseAll();
        raisKeyPushed = false;
      }
      if (keyMap[row1 + option1][col1] == KEY_LOWE)
      {
        Keyboard.releaseAll();
        loweKeyPushed = false;
      }
      if (keyMap[row1 + option1][col1] == KEY_CPFL)
      {
        pressed = 0;
        Keyboard.releaseAll();
      }
      if (keyMap[row1 + option1][col1] == KEY_CLPF)
      {
        pressed = 0;
      }
      if (keyMap[row1 + option1][col1] == KEY_MUTE)
      {
        pressed = 0;
        ConsumerControl.release();
      }
      if (keyMap[row1 + option1][col1] == KEY_VOLUMEUP)
      {
        pressed = 0;
        ConsumerControl.release();
      }
      if (keyMap[row1 + option1][col1] == KEY_VOLUMEDOWN)
      {
        pressed = 0;
        ConsumerControl.release();
      }
      else
      {
        Keyboard.release( keyMap[row1 + option1][col1]);
      }
    }
  }
}
void LEDTape()
{
  backLED.clear();
  statusLED.clear();
  for (int i = 0; i < numpixels; i++)
  {
    statusLED.setPixelColor(i, statusLED.Color(5, 0, 0));
    backLED.setPixelColor(i, backLED.Color(10, 0, 0));
  }
  backLED.show();
  statusLED.show();
}

void offLEDTape()
{
  statusLED.clear();
  for (int i = 0; i < numpixels; i++)
  {
    statusLED.setPixelColor(i, statusLED.Color(0, 0, 0));
  }
  statusLED.show();
}

void offBackLED()
{
  backLED.clear();
  for (int i = 0; i < numpixels; i++)
  {
    backLED.setPixelColor(i, backLED.Color(0, 0, 0));
  }
  backLED.show();
}
void onBackLED()
{
  backLED.clear();
  for (int i = 0; i < numpixels; i++)
  {
    backLED.setPixelColor(i, backLED.Color(150, 0, 0));
  }
  backLED.show();
}

void capsLockLedOn()
{
  statusLED.clear();
  statusLED.setPixelColor(2, statusLED.Color(0, 5, 0));
  statusLED.show();
}
void capsLockLedOff()
{
  statusLED.clear();
  statusLED.setPixelColor(2, statusLED.Color(0, 0, 0));
  statusLED.show();
}

void changeProfile()
{
  if(!gameModeEnabled)
  {
    gameModeEnabled = true;
  }
  else
  {
    gameModeEnabled = false;
  }
  
}
void changeLightProfile()
{
  if (LEDProfile ==6)
  {
    LEDProfile = 0; 
  }
  else
  {
    LEDProfile++;
  }

  backLED.clear();
  for (int i = 0; i < numpixels; i++)
  {
    backLED.setPixelColor(i, backLED.Color(
      backLightLEDNormal[LEDProfile][0], backLightLEDNormal[LEDProfile][1], backLightLEDNormal[LEDProfile  ][2]));
  }
  backLED.show();
  Serial.print("LEDProfile ");
  Serial.println( LEDProfile);

  EEPROM[0x000] = LEDProfile;
  Serial.print("EEPROM[0x000] ");
  Serial.println(EEPROM[0x000]);
}
