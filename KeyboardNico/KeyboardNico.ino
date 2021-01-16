#include <HID-Project.h>
#include <HID-Settings.h>
//#include "Keyboard.h"
//#include "Mouse.h"
//#include "HID.h"
#include "Adafruit_NeoPixel.h"
#include "EEPROM.h"
//#include "ConsumerControl.h"
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
#define KEY_FN   0x01
#define KEY_CPFL 0x02
#define KEY_RAIS 0x03
#define KEY_LOWE 0x04


// missing sound control keys
//
#define KEY_MUTE        0x05
#define KEY_VOLUMEUP    0x06
#define KEY_VOLUMEDOWN  0x07

#define KEY_FOR  0x08
#define KEY_CLPF 0x09    
#define KEY_MAIL 0x0a
#define KEY_IF   0x0b  

#define KEY_MUP  0x0c
#define KEY_MDWN 0x0d
#define KEY_MRIT 0x0e
#define KEY_MLFT 0x0f
#define KEY_MRCL 0x10
#define KEY_MLCL 0x11
#define KEY_MHUP 0x12
#define KEY_MHDW 0x13

#define KEY_KLCK 0x14

#define KEY_ENT  0xB0 //Enter
#define KEY_ESCP 0xB1 //Escape 
#define KEY_BSPC 0xB2 //Backspace
#define KEY_DEL  0xD4 //Delete
#define KEY_TB   0xB3 //Tab
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
#define KEY_HOM 0xD2 //Home
#define KEY_EN  0xD5 //End
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

#define KEY_FU1        0xC2
#define KEY_FU2        0xC3
#define KEY_FU3        0xC4
#define KEY_FU4        0xC5
#define KEY_FU5        0xC6
#define KEY_FU6        0xC7
#define KEY_FU7        0xC8
#define KEY_FU8        0xC9
#define KEY_FU9        0xCA
#define KEY_FU10       0xCB
#define KEY_FU11       0xCC
#define KEY_FU12       0xCD
#define KEY_FU13       0x7C
#define KEY_FUl4       0x7D
#define KEY_FU15       0x7E
#define KEY_FU16       0x7F
#define KEY_FU17       0x80
#define KEY_FU18       0x81
#define KEY_FU19       0x82
#define KEY_FU20       0x83
#define KEY_FU21       0x84
#define KEY_FU22       0x85
#define KEY_FU23       0x86
#define KEY_FU24       0x87



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
  {KEY_ESCP, KEY_FU1,  KEY_FU2,  KEY_FU3,  KEY_FU4,  KEY_FU5,  KEY_FU6,  NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TB,   KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_LPRN, NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_LCBR, NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_FOR,  NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_RSFT, KEY_DEL,  ____     },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },

  //leftFn
  {KEY_ESCP, KEY_FU1,  KEY_FU2,  KEY_FU3,  KEY_MUTE, KEY_VOLUMEDOWN, KEY_VOLUMEUP, NONE     },
  {KEY_CPFL, KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,          KEY_6,        NONE     },
  {KEY_CLPF, KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,          KEY_LPRN,     NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,          KEY_LCBR,     NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,          KEY_FOR,      NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_RSFT,       KEY_DEL,      ____     },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,           KEY_KLCK,     NONE     },

  //leftRais
  {KEY_ESCP, KEY_FU1,  KEY_FU2,   KEY_FU3,  KEY_FU4,  KEY_FU5,  KEY_FU6,  NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TB,   KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_LPRN, NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_LCBR, NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_FOR,  NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_RSFT, KEY_DEL,  ____     },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },

  //leftLower
  {KEY_ESCP, KEY_FU1,  KEY_FU2,  KEY_FU3,  KEY_FU4,  KEY_FU5,  KEY_FU6,  NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TB,   KEY_Q,    KEY_W,    KEY_MUP,  KEY_R,    KEY_T,    KEY_LPRN, NONE     },
  {KEY_CAPS, KEY_A,    KEY_MLFT, KEY_MDWN, KEY_MRIT, KEY_G,    KEY_LCBR, NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_FOR,  NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_RAIS, KEY_MLCL, KEY_DEL,  ____     },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_MRCL,  NONE     },



  //leftGame
  {KEY_ESCP, KEY_FU1,  KEY_FU2,  KEY_FU3,  KEY_FU4,  KEY_FU5,  KEY_FU6,  NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TB,   KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_F1,   NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_F2,   NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_F3,   NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_C,    KEY_F4,   KEY_F5,   KEY_F6   },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },

  //leftGameFn
  {KEY_ESCP, KEY_FU1,  KEY_FU2,  KEY_FU3,  KEY_MUTE, KEY_VOLUMEDOWN, KEY_VOLUMEUP, NONE     },
  {KEY_CPFL, KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,          KEY_6,        NONE     },
  {KEY_CLPF, KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,          KEY_F1,       NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,          KEY_F2,       NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,          KEY_F3,       NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_C,    KEY_F4,         KEY_F5,       KEY_F6   },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,           KEY_KLCK,     NONE     },

  //leftGameRAIS
  {KEY_ESCP, KEY_FU1,  KEY_FU2,  KEY_FU3,  KEY_FU4,  KEY_FU5,  KEY_FU6,  NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TB,   KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_F1,   NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_F2,   NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_F3,   NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_C,    KEY_F4,   KEY_F5,   KEY_F6   },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },

  //leftGameLower
  {KEY_ESCP, KEY_FU1,  KEY_FU2,  KEY_FU3,  KEY_FU4,  KEY_FU5,  KEY_FU6,  NONE     },
  {KEY_GRV,  KEY_1,    KEY_2,    KEY_3,    KEY_4,    KEY_5,    KEY_6,    NONE     },
  {KEY_TB,   KEY_Q,    KEY_W,    KEY_E,    KEY_R,    KEY_T,    KEY_F1,   NONE     },
  {KEY_CAPS, KEY_A,    KEY_S,    KEY_D,    KEY_F,    KEY_G,    KEY_F2,   NONE     },
  {KEY_LSFT, KEY_Z,    KEY_X,    KEY_C,    KEY_V,    KEY_B,    KEY_F3,   NONE     },
  {KEY_LCTL, KEY_LGUI, KEY_LALT, KEY_FN,   KEY_C,    KEY_F4,   KEY_F5,   KEY_F6   },
  {NONE,     NONE,     NONE,     NONE,     NONE,     NONE,     KEY_SPC,  NONE     },


  //right
  {KEY_FU7,  KEY_FU8,  KEY_FU9,  KEY_FU10, KEY_FU11, KEY_FU12, KEY_KLCK, KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,    KEY_9,    KEY_0,    KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_RPRN, KEY_Y,    KEY_U,    KEY_I,    KEY_O,    KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_RCBR, KEY_H,    KEY_J,    KEY_K,    KEY_L,    KEY_SCLN, KEY_QUOT, KEY_ENT},
  {KEY_IF,   KEY_N,    KEY_M,    KEY_COMM, KEY_DOT,  KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_BSPC, KEY_LSFT, KEY_LOWE, KEY_FN,   KEY_RALT, KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE, NONE,     NONE,     NONE,     NONE,     NONE,    },

  //rightFn
  {KEY_FU7,  KEY_FU8,  KEY_FU9,      KEY_MUTE,       KEY_VOLUMEDOWN, KEY_VOLUMEUP,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,        KEY_9,          KEY_0,          KEY_MINS,      KEY_EQL,  KEY_HOM  },
  {KEY_RPRN, KEY_Y,    KEY_U,        KEY_I,          KEY_O,          KEY_P,         KEY_LCBR, KEY_PGUP },
  {KEY_RCBR, KEY_H,    KEY_J,        KEY_K,          KEY_L,          KEY_SCLN,      KEY_QUOT, KEY_PGDN },
  {KEY_IF,   KEY_N,    KEY_MAIL,     KEY_COMM,       KEY_DOT,        KEY_SLSH,      KEY_UP,   KEY_EN   }, 
  {KEY_BSPC, KEY_LSFT, KEY_LOWE,     KEY_FN,         KEY_RALT,       KEY_LEFT,      KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE,     NONE,           NONE,           NONE,          NONE,     NONE,    },

  //rightRais
  {KEY_FU7,  KEY_FU8,  KEY_FU9,  KEY_FU10, KEY_FU11, KEY_FU12, KEY_KLCK, KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,    KEY_9,    KEY_0,    KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_RPRN, KEY_Y,    KEY_U,    KEY_UP,    KEY_O,   KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_RCBR, KEY_H,    KEY_LEFT, KEY_DOWN, KEY_RGHT, KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_IF,   KEY_N,    KEY_M,    KEY_COMM, KEY_DOT,  KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_BSPC, KEY_LSFT, KEY_LOWE, KEY_FN,   KEY_RALT, KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE, NONE,     NONE,     NONE,     NONE,     NONE,    },

  //rightLower
  {KEY_FU7,  KEY_FU8,      KEY_FU9,      KEY_FU10,     KEY_FU11,     KEY_FU12, NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,        KEY_8,        KEY_9,        KEY_0,        KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_RPRN, KEY_Y,        KEY_KEYPAD_7, KEY_KEYPAD_8, KEY_KEYPAD_9, KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_RCBR, KEY_H,        KEY_KEYPAD_4, KEY_KEYPAD_5, KEY_KEYPAD_6, KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_IF,   KEY_KEYPAD_0, KEY_KEYPAD_1, KEY_KEYPAD_2, KEY_KEYPAD_3, KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_BSPC, KEY_LSFT,     KEY_LOWE,     KEY_FN,       KEY_RALT,     KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE,         NONE,         NONE,         NONE,     NONE,     NONE,    },

  //rightGame
  {KEY_FU7,  KEY_FU8,  KEY_FU9,  KEY_FU10, KEY_FU11, KEY_FU12, KEY_KLCK, KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,    KEY_9,    KEY_0,    KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_F7,   KEY_Y,    KEY_U,    KEY_I,    KEY_O,    KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_F8,   KEY_H,    KEY_J,    KEY_K,    KEY_L,    KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_F9,   KEY_N,    KEY_M,    KEY_COMM, KEY_DOT,  KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_BSPC, KEY_LSFT, KEY_LOWE, KEY_FN,   KEY_RALT, KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE, NONE,     NONE,     NONE,     NONE,     NONE,    },

  //rightGameFn
  {KEY_FU7,  KEY_FU8,  KEY_FU9,      KEY_MUTE,       KEY_VOLUMEDOWN, KEY_VOLUMEUP,  NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,        KEY_9,          KEY_0,          KEY_MINS,      KEY_EQL,  KEY_HOM  },
  {KEY_F7,   KEY_Y,    KEY_U,        KEY_I,          KEY_O,          KEY_P,         KEY_LCBR, KEY_PGUP },
  {KEY_F8,   KEY_H,    KEY_J,        KEY_K,          KEY_L,          KEY_SCLN,      KEY_QUOT, KEY_PGDN },
  {KEY_F9,   KEY_N,    KEY_MAIL,     KEY_COMM,       KEY_DOT,        KEY_SLSH,      KEY_UP,   KEY_EN   },
  {KEY_BSPC,  KEY_LSFT,KEY_LOWE,     KEY_FN,         KEY_RALT,       KEY_LEFT,      KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE,     NONE,           NONE,           NONE,          NONE,     NONE,    },

  //rightGameRais
  {KEY_FU7,  KEY_FU8,  KEY_FU9,  KEY_FU10, KEY_FU11, KEY_FU12, NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,    KEY_8,    KEY_9,    KEY_0,    KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_F7,   KEY_Y,    KEY_U,    KEY_I,    KEY_O,    KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_F8,   KEY_H,    KEY_J,    KEY_K,    KEY_L,    KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_F9,   KEY_N,    KEY_M,    KEY_COMM, KEY_DOT,  KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_BSPC, KEY_LSFT, KEY_LOWE, KEY_FN,   KEY_RALT, KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER, NONE, NONE, NONE,     NONE,     NONE,     NONE,     NONE,    },

  //rightGameLower
  {KEY_FU7,  KEY_FU8,      KEY_FU9,      KEY_FU10,     KEY_FU11,     KEY_FU12, NONE,     KEY_CPFL },
  {KEY_BSLS, KEY_7,        KEY_8,        KEY_9,        KEY_0,        KEY_MINS, KEY_EQL,  KEY_BSPC },
  {KEY_F7,   KEY_Y,        KEY_KEYPAD_7, KEY_KEYPAD_8, KEY_KEYPAD_9, KEY_P,    KEY_LBRC, KEY_RBRC },
  {KEY_F8,   KEY_H,        KEY_KEYPAD_4, KEY_KEYPAD_5, KEY_KEYPAD_6, KEY_SCLN, KEY_QUOT, KEY_ENT  },
  {KEY_F9,   KEY_KEYPAD_0, KEY_KEYPAD_1, KEY_KEYPAD_2, KEY_KEYPAD_3, KEY_SLSH, KEY_UP,   KEY_RSFT },
  {KEY_BSPC, KEY_LSFT,     KEY_LOWE,     KEY_FN,       KEY_RALT,     KEY_LEFT, KEY_DOWN, KEY_RGHT },
  {KEY_KEYPAD_ENTER,   NONE,     NONE,   NONE,         NONE,         NONE,     NONE,     NONE,    }
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
  {150,150,200}
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
bool capsLocked = false;
bool chengeIMERaisEnabled = false;
bool chengeIMELowerEnabled = false;

bool mouseMovex = false;
bool mouseMove_x = false;
bool mouseMovey = false;
bool mouseMove_y = false;

bool keyboardEnabled = true;

float MouseConstant = 3.0;
const int AS_RAW_SCANCODE = 136;



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
    Serial.print(F(" "));
  }
  Serial.println(F(" "));
  Serial.println(sizeof(col) / 2);
  for (int ii = 0; ii < sizeof(col) / 2; ii++)
  {
    pinMode(col[ii], INPUT_PULLUP);
    Serial.print(digitalRead(col[ii]));
    Serial.print(F(" "));
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
  //Keyboard.begin();
  BootKeyboard.begin();
  BootMouse.begin();
  Consumer.begin();
  FlashLED( led, 4);
  Serial.begin(9600);
  Serial1.begin(9600);
  backLED.begin();
  statusLED.begin();
  delay(600);
  Serial.println(F("Serial available!!"));

  


  LEDProfile = EEPROM[0x000]; 
  gameModeEnabled = EEPROM[0x001];
  backLEDOn = EEPROM[0x002];
    

  for (int i = 0; i < 3; i++)
  {
    statusLED.clear();
    for (int i = 0; i < numpixels; i++)
    {
      statusLED.setPixelColor(i, statusLED.Color(5, 0, 0));
    }
  
    statusLED.show();
    delay(100);
    statusLED.clear();
    for (int i = 0; i < numpixels; i++)
    {
      statusLED.setPixelColor(i, statusLED.Color(0, 0, 0));
    }
    statusLED.show();
    delay(100);
  }
  if(!backLEDOn)
  {
    backLED.clear();
    for (int i = 0; i < numpixels; i++)
    {
      backLED.setPixelColor(i, backLED.Color(
        backLightLEDNormal[LEDProfile][0], backLightLEDNormal[LEDProfile][1], backLightLEDNormal[LEDProfile  ][2]));
    }
    backLED.show();
    backLEDOn = true;
  }
  else
  {
    backLEDOn = false;
  }
  
  if(gameModeEnabled)
  {
    gameModeEnabled = false;
  }
  else
  {
    gameModeEnabled = true;
  }
  changeProfile();


  Serial.print(F("EEPROM[0x000] "));
  Serial.println(EEPROM[0x000]);
  Serial.print(F("EEPROM[0x001] "));
  Serial.println(EEPROM[0x001]);


  //起動時にNumLock On
  /*if (!Keyboard.getLedStatus(LED_NUM_LOCK))
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

  
  //capsLockチェック
  
  if (Keyboard.getLedStatus(LED_CAPS_LOCK))
  {
    capsLockLedOn();
    sendData = 0b10000001;
    Serial1.write(sendData);
    Serial.flush();
    Serial.print(F("senddate"));
    Serial.print(F(" "));
    Serial.println(sendData);
    capsLocked = true;
  }*/
  BootKeyboard.releaseAll();
}


//============================loop==================================
void loop() {
  //AntiChattering
  int delayTime = 8;
  int gameDelayTime = 5;
  if(gameModeEnabled) 
  { 
    delay(gameDelayTime);
  }
  else
  {
    delay(delayTime);
  }
  

  if(Serial.available())
  {
    readPcSerial();
  }


  //capslockSetting
  if (BootKeyboard.getLeds() & LED_CAPS_LOCK && !capsLocked)
  {
    capsLockLedOn();
    sendData = 0b10000001;
    Serial1.write(sendData);
    Serial.flush();
    Serial.print(F("senddate"));
    Serial.print(F(" "));
    Serial.println(sendData);
    capsLocked = true;
  }
  else
  {
    if(capsLocked)
    {
    capsLockLedOff();
    sendData = 0b10000010;
    Serial1.write(sendData);
    Serial.print(F("senddate"));
    Serial.print(F(" "));
    Serial.println(sendData);
    Serial.flush();
    capsLocked = false;
    }
  }

  if(mouseMovey && keyboardEnabled)
  {
    
    BootMouse.move(0,MouseConstant);
  }
  if(mouseMove_y && keyboardEnabled)
  {
    BootMouse.move(0,-MouseConstant);
  }if(mouseMovex && keyboardEnabled)
  {
    BootMouse.move(MouseConstant,0);
  }if(mouseMove_x && keyboardEnabled)
  {
    BootMouse.move(-MouseConstant,0);
  }


  if(leftShiftPushed && keyboardEnabled)
  {
    BootKeyboard.press(KEY_LEFT_SHIFT);
  }
  if(rightShiftPushed && keyboardEnabled)
  {
    BootKeyboard.press(KEY_RIGHT_SHIFT);
  }
  if(leftControlPushed && keyboardEnabled)
  {
    BootKeyboard.press(KEY_LEFT_CTRL);
  }
  if(rightControlPushed && keyboardEnabled)
  {
    BootKeyboard.press(KEY_RIGHT_CTRL);
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
        int optionIME = 0;
        bool sendchar = true;
        if (!leftSide)
        {
          option += 56;
          optionIME = 56;
        }
        if (fnKeyPushed && !raisKeyPushed && !loweKeyPushed)
        {
          option += 7;
          Serial.println(F("FNKeylayer"));
        }
        if (raisKeyPushed && !fnKeyPushed && !loweKeyPushed)
        {
          option += 14;
          Serial.println(F("reisKeylayer"));
        }
        if (loweKeyPushed && !fnKeyPushed && !raisKeyPushed)
        {
          option += 21;
          Serial.println(F("lowerKeylayer"));
        }
        if (gameModeEnabled)
        {
          option += 28;
          Serial.println(F("gameKeylayer"));
        }

        if ( !currentState[ii][jj] )
        {


          if (keyMap[ii + optionIME][jj] == KEY_RAIS)
          {
            if(chengeIMELowerEnabled)
            {
              if(keyboardEnabled)
              {
                BootKeyboard.press( KEY_LEFT_ALT );
                BootKeyboard.press( KEY_TILDE );
                BootKeyboard.release( KEY_TILDE );
                BootKeyboard.release( KEY_LEFT_ALT );
              }
              sendchar = false;
            }
            chengeIMERaisEnabled = true;
            pressed = 1;
          }
          else if (keyMap[ii + optionIME][jj] == KEY_LOWE)
          {
            if(chengeIMERaisEnabled)
            {
              if(keyboardEnabled)
              {
                BootKeyboard.press( KEY_LEFT_ALT );
                BootKeyboard.press( KEY_TILDE );
                BootKeyboard.release( KEY_TILDE );
                BootKeyboard.release( KEY_LEFT_ALT );
              }
              sendchar = false;
            }
            chengeIMELowerEnabled = true;
            pressed = 1;
          }
          
          
          if(keyMap[ii + option][jj] == KEY_LSFT)
          {
            pressed = 1;
            leftShiftPushed = true;
            sendKey( keyMap[ii + option][jj],pressed);
          }
          else if(keyMap[ii + option][jj] == KEY_RSFT)
          {
            pressed = 1;
            rightShiftPushed = true;
            sendKey( keyMap[ii + option][jj],pressed);
          }
          else if(keyMap[ii + option][jj] == KEY_LCTL)
          {
            pressed = 1;
            leftControlPushed = true;
            sendKey( keyMap[ii + option][jj],pressed);
          }
          else if(keyMap[ii + option][jj] == KEY_RCTL)
          {
            pressed = 1;
            rightControlPushed = true;
            sendKey( keyMap[ii + option][jj],pressed);
          }
          else if (keyMap[ii + option][jj] == KEY_FN)
          {
            //Keyboard.releaseAll();
            fnKeyPushed = true;
            pressed = 1;
            Serial.println(F("FNKeyPushed!"));
          }
          else if (keyMap[ii + option][jj] == KEY_RAIS)
          {
              BootKeyboard.releaseAll();
              raisKeyPushed = true;
              pressed = 1; }
          else if (keyMap[ii + option][jj] == KEY_LOWE)
          {
              BootKeyboard.releaseAll();
              loweKeyPushed = true;
              pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_CPFL)
          {
            changeProfile();
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_CLPF)
          {
            changeLightProfile();
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_MUTE)
          {
            Consumer.press(MEDIA_VOLUME_MUTE);
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_VOLUMEUP)
          {
            Consumer.press(MEDIA_VOLUME_UP);
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_VOLUMEDOWN)
          {
            Consumer.press(MEDIA_VOLUME_DOWN);
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_MAIL)
          {
            if(keyboardEnabled)
            {
              BootKeyboard.print(F("shota.M.020626.S.K.F@gmail.com"));
            }
            pressed = 1;
          } 
          else if (keyMap[ii + option][jj] == KEY_FOR)
          {
            if(keyboardEnabled)
            {
              BootKeyboard.print(F("for() \n"));
              BootKeyboard.print(F("{ \n"));
              BootKeyboard.write(KEY_UP);
              BootKeyboard.write(KEY_UP);
              BootKeyboard.write(KEY_RGHT);
              BootKeyboard.write(KEY_RGHT);
            }
            //Keyboard.print("}");
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_IF)
          {
            if(keyboardEnabled)
            {
              BootKeyboard.print(F("if() \n"));
              BootKeyboard.print(F("{ \n"));
              BootKeyboard.write(KEY_UP);
              BootKeyboard.write(KEY_UP);
              BootKeyboard.write(KEY_RGHT);
            }
            
            //Keyboard.print("}");
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_MUP)
          {
            startMouseMove(KEY_MUP);
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_MDWN)
          {
            startMouseMove(KEY_MDWN);
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_MRIT)
          {
            startMouseMove(KEY_MRIT);
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_MLFT)
          {
            startMouseMove(KEY_MLFT);
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_MLCL)
          {
            if(keyboardEnabled)
            {
              //Mouse.press(MOUSE_LEFT);
            }
            pressed = 1;
          }
          else if (keyMap[ii + option][jj] == KEY_MRCL)
          {
            if(keyboardEnabled)
            {
              //Mouse.press(MOUSE_RIGHT);
            }
            pressed = 1;
          }

          if (keyMap[ii + option][jj] == KEY_MUTE)
          {
            pressed = 1;
            Consumer.press(MEDIA_VOLUME_MUTE);
          }
          if (keyMap[ii + option][jj] == KEY_VOLUMEUP)
          {
            pressed = 1;
            Consumer.press(MEDIA_VOLUME_UP);
          }
          if (keyMap[ii + option][jj] == KEY_VOLUMEDOWN)
          {
            pressed = 1;
            Consumer.press(MEDIA_VOLUME_DOWN);
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

          else if(keyMap[ii + option][jj] == KEY_ESCP && fnKeyPushed)
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
          else if(keyMap[ii + option][jj] == KEY_KLCK)
          {
            chengeKeyboardEnabled();
          }
          
          else
          {
            if(sendchar && keyboardEnabled)
            {
              pressed = 1;
              sendKey( keyMap[ii + option][jj],pressed);
              Serial.print(F("pressed keycode "));
              Serial.println(keyMap[ii + option][jj]);
            }
            
          }
        }
        else
        {

          if (keyMap[ii + optionIME][jj] == KEY_RAIS)
          {
              chengeIMERaisEnabled = false;
              pressed = 0;
          }
          if (keyMap[ii + optionIME][jj] == KEY_LOWE)
          {
            chengeIMELowerEnabled = false;
            pressed = 0;
          }

          

          if(keyMap[ii + option][jj] == KEY_LSFT)
          {
            pressed = 0;
            leftShiftPushed = false;
            sendKey( keyMap[ii + option][jj],pressed);
          }
          if(keyMap[ii + option][jj] == KEY_RSFT)
          {
            pressed = 0;
            rightShiftPushed = false;
            sendKey( keyMap[ii + option][jj],pressed);
          }
          if(keyMap[ii + option][jj] == KEY_LCTL)
          {
            pressed = 0;
            leftControlPushed = false;
            sendKey( keyMap[ii + option][jj],pressed);
          }
          if(keyMap[ii + option][jj] == KEY_RCTL)
          {
            pressed = 0;
            rightControlPushed = false;
            sendKey( keyMap[ii + option][jj],pressed);
          }
          
          if (keyMap[ii + option][jj] == KEY_FN)
          {
            fnKeyPushed = false;
            pressed = 0;
            BootKeyboard.releaseAll();
            //ConsumerControl.release();
            Serial.println(F("FNKeyreleased!"));
          }
          if (keyMap[ii + option][jj] == KEY_RAIS)
          {
            raisKeyPushed = false;
            pressed = 0;
            BootKeyboard.releaseAll();
          }
          if (keyMap[ii + option][jj] == KEY_LOWE)
          {
            loweKeyPushed = false;
            pressed = 0;
            stopMouseMove(0);
            BootKeyboard.releaseAll();
          }
          if (keyMap[ii + option][jj] == KEY_CPFL)
          {
            pressed = 0;
          }
          if (keyMap[ii + option][jj] == KEY_CLPF)
          {
            pressed = 0;
          }

          if (keyMap[ii + option][jj] == KEY_MUP)
          {
            stopMouseMove(KEY_MUP);
            pressed = 0;
          }
          if (keyMap[ii + option][jj] == KEY_MDWN)
          {
            stopMouseMove(KEY_MDWN);
            pressed = 0;
          }
          if (keyMap[ii + option][jj] == KEY_MRIT)
          {
            stopMouseMove(KEY_MRIT);
            pressed = 0;
          }
          if (keyMap[ii + option][jj] == KEY_MLFT)
          {
            stopMouseMove(KEY_MLFT);
            pressed = 0;
          }
          if (keyMap[ii + option][jj] == KEY_MLCL)
          {
            BootMouse.release(MOUSE_LEFT);
            pressed = 0;
          }
          if (keyMap[ii + option][jj] == KEY_MRCL)
          {
            BootMouse.release(MOUSE_RIGHT);
            pressed = 0;
          }


          
          if (keyMap[ii + option][jj] == KEY_MUTE)
          {
            pressed = 0;
            Consumer.release(MEDIA_VOLUME_MUTE);
          }
          if (keyMap[ii + option][jj] == KEY_VOLUMEUP)
          {
            pressed = 0;
            Consumer.release(MEDIA_VOLUME_UP);
          }
          if (keyMap[ii + option][jj] == KEY_VOLUMEDOWN)
          {
            pressed = 0;
            Consumer.release(MEDIA_VOLUME_DOWN);
          }
          else
          {
            pressed = 0;
            sendKey( keyMap[ii + option][jj],pressed);
          }
        }
        digitalWrite(led, !currentState[ii][jj]);
        beforeState[ii][jj] = currentState[ii][jj];
        sendData = pressed << 6 | ii  << 3 | jj;
        Serial1.write(sendData);
        Serial.flush();

        Serial.print(F("senddate"));
        Serial.print(F(" "));
        Serial.print(sendData);
        Serial.print(F(" "));
        Serial.print(pressed);
        Serial.print(F(" "));
        Serial.print(ii);
        Serial.print(F(" "));
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
    Serial.print(F("readdate"));
    Serial.print(F(" "));
    Serial.println(receiveData);
  }
  else if (receiveData == 0b10000010)
  {
    capsLockLedOff();
    Serial.print(F("readdate"));
    Serial.print(F(" "));
    Serial.println(receiveData);
  }
  else if (receiveData == 0b10000011)
  {
    gameModeEnabled = false;
    changeProfile();
  }
  else if (receiveData == 0b10000100)
  {
    gameModeEnabled = true;
    changeProfile();
    Serial.print(F("keyboardEnabled :"));
    Serial.print(keyboardEnabled);
  }
  else if (receiveData == 0b10000101)
  {
    keyboardEnabled = false;
    statusLED.setPixelColor(3,statusLED.Color(5, 0, 0));
    statusLED.show();
    Serial.print(F("keyboardEnabled :"));
    Serial.println(keyboardEnabled);
  }
  else if (receiveData == 0b10000110)
  {
    
    keyboardEnabled = true;
    statusLED.setPixelColor(3,statusLED.Color(0, 5, 0));
    statusLED.show();
    Serial.print(F("keyboardEnabled :"));
    Serial.println(keyboardEnabled);
  }
  if (receiveData & 0b10000000)
  {

  }

  else
  {
    int pressed1 = receiveData >> 6;
    int row1 = receiveData  >> 3 & 0b00000111;
    int col1 = receiveData & 0b00000111;

    Serial.print(F("readdate"));
    Serial.print(F(" "));
    Serial.print(receiveData);
    Serial.print(F(" "));
    Serial.print(pressed1);
    Serial.print(F(" "));
    Serial.print(row1);
    Serial.print(F(" "));
    Serial.println(col1);

    int option1 = 0;
    int optionIME1 = 0;
    bool sendChar1 = true;
    if (leftSide)
    {
      option1 = 56;
      optionIME1 = 56;
    }
    if (fnKeyPushed && !raisKeyPushed && !loweKeyPushed)
    {
      option1 += 7;
      Serial.println(F("FNKeylayer"));
    }
    if (raisKeyPushed && !fnKeyPushed && !loweKeyPushed)
    {
      option1 += 14;
      Serial.println(F("raisKeylayer"));
    }
    if (loweKeyPushed && !fnKeyPushed && !raisKeyPushed)
    {
      option1 += 21;
      Serial.println(F("lowerKeylayer"));
    }
    if (gameModeEnabled)
    {
      option1 += 28;
      Serial.println(F("gameKeylayer"));
    }
    if (pressed1)
    {

      if (keyMap[row1 + optionIME1][col1] == KEY_RAIS)
      {
        if(chengeIMELowerEnabled)
          {
            if(keyboardEnabled)
          {
            BootKeyboard.press( KEY_LEFT_ALT );
            BootKeyboard.press( KEY_TILDE );
            BootKeyboard.release( KEY_TILDE );
            BootKeyboard.release( KEY_LEFT_ALT );
          }
            sendChar1 = false;
          }
          chengeIMERaisEnabled = true;
          pressed = 1;
      }
      else if (keyMap[row1 + optionIME1][col1] == KEY_LOWE)
      {
        if(chengeIMERaisEnabled)
        {
          if(keyboardEnabled)
          {
            BootKeyboard.press( KEY_LEFT_ALT );
            BootKeyboard.press( KEY_TILDE );
            BootKeyboard.release( KEY_TILDE );
            BootKeyboard.release( KEY_LEFT_ALT );
          }
          
          sendChar1 = false;
        }
        chengeIMELowerEnabled = true;
        pressed = 1;
      }
        

      if(keyMap[row1 + option1][col1] == KEY_LSFT)
      {
        pressed = 1;
        leftShiftPushed = true;
        sendKey( keyMap[row1 + option1][col1],pressed);
      }
      else if(keyMap[row1 + option1][col1] == KEY_RSFT)
      {
        pressed = 1;
        rightShiftPushed = true;
        sendKey( keyMap[row1 + option1][col1],pressed);
      }
      else if(keyMap[row1 + option1][col1] == KEY_LCTL)
      {
        pressed = 1;
        leftControlPushed = true;
        sendKey( keyMap[row1 + option1][col1],pressed);
      }
      else if(keyMap[row1 + option1][col1] == KEY_RCTL)
      {
        pressed = 1;
        rightControlPushed = true;
        sendKey( keyMap[row1 + option1][col1],pressed);
      }
      else if (keyMap[row1 + option1][col1] == KEY_FN)
      {
        BootKeyboard.releaseAll();
        fnKeyPushed = true;
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_RAIS)
      {
        BootKeyboard.releaseAll();
        raisKeyPushed = true;
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_LOWE)
      {
        BootKeyboard.releaseAll();
        loweKeyPushed = true; 
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_CPFL)
      {
        changeProfile();
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_CLPF)
      {
        changeLightProfile();
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_MUTE)
      {
        //ConsumerControl.press(VOLUME_MUTE);
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_VOLUMEUP)
      {
        //Keyboard.print(128+AS_RAW_SCANCODE);
        //ConsumerControl.press(VOLUME_UP);
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_VOLUMEDOWN)
      {
        //Keyboard.print(129+AS_RAW_SCANCODE);
        //ConsumerControl.press(VOLUME_DOWN);
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_MAIL)
      {
        if(keyboardEnabled)
        {
          BootKeyboard.print(F("shota.M.020626.S.K.F@gmail.com"));
        }
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_FOR)
      {
        if(keyboardEnabled)
        {
          BootKeyboard.print(F("for() \n"));
          BootKeyboard.print(F("{ \n"));
          BootKeyboard.write(KEY_UP);
          BootKeyboard.write(KEY_UP);
          BootKeyboard.write(KEY_RGHT);
          BootKeyboard.write(KEY_RGHT);
        }
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_IF)
      {
        if(keyboardEnabled)
        {
          BootKeyboard.print(F("if() \n"));
          BootKeyboard.print(F("{ \n"));
          BootKeyboard.write(KEY_UP);
          BootKeyboard.write(KEY_UP);
          BootKeyboard.write(KEY_RGHT);
        }
        //Keyboard.print("}");
        pressed = 1;
      }

      else if (keyMap[row1 + option1][col1] == KEY_MUP)
      {
        startMouseMove(KEY_MUP);
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_MDWN)
      {
        startMouseMove(KEY_MDWN);
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_MRIT)
      {
        startMouseMove(KEY_MRIT);
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_MLFT)
      {
        startMouseMove(KEY_MLFT);
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_MLCL)
      {
        if(keyboardEnabled)
        {
          BootMouse.press(MOUSE_LEFT);
        }
        pressed = 1;
      }
      else if (keyMap[row1 + option1][col1] == KEY_MRCL)
      {
        if(keyboardEnabled)
        {
          BootMouse.press(MOUSE_RIGHT);
        }
        pressed = 1;
      }

      if (keyMap[row1 + option1][col1] == KEY_MUTE)
      {
        pressed = 1;
        Consumer.press(MEDIA_VOLUME_MUTE);
      }
      if (keyMap[row1 + option1][col1] == KEY_VOLUMEUP)
      {
        pressed = 1;
        Consumer.press(MEDIA_VOLUME_UP);
      }
      if (keyMap[row1 + option1][col1] == KEY_VOLUMEDOWN)
      {
        pressed = 1;
        Consumer.press(MEDIA_VOLUME_DOWN);
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

      else if(keyMap[row1 + option1][col1] == KEY_ESCP && fnKeyPushed)
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
        Serial.print(F("sendChar1 :"));
        Serial.print(sendChar1);
        Serial.print(F("keyboardEnabled :"));
        Serial.print(keyboardEnabled);
        if(sendChar1 && keyboardEnabled)
        {
          pressed = 1;
          sendKey( keyMap[row1 + option1][col1],pressed);
          Serial.println(keyMap[row1 + option1][col1]);
          Serial.print(F("pressed keycode "));
          Serial.println(keyMap[row1 + option1][col1]);
        }
      }
    }
    else
    {

      if (keyMap[row1 + optionIME1][col1] == KEY_RAIS)
      {
        chengeIMERaisEnabled = false;
        pressed = 0;
      }
      if (keyMap[row1 + optionIME1][col1] == KEY_LOWE)
      {
        chengeIMELowerEnabled = false;
        pressed = 0;
      }

      
      if (keyMap[row1 + option1][col1] == KEY_FN)
      {
        fnKeyPushed = false;
        BootKeyboard.releaseAll();
        //ConsumerControl.release();
      }

      if(keyMap[row1 + option1][col1] == KEY_LSFT)
      {
        pressed = 0;
        leftShiftPushed = false;
        sendKey( keyMap[row1 + option1][col1],pressed);
      }
      if(keyMap[row1 + option1][col1] == KEY_RSFT)
      {
        pressed = 0;
        rightShiftPushed = false;
        sendKey( keyMap[row1 + option1][col1],pressed);
      }
      if(keyMap[row1 + option1][col1] == KEY_LCTL)
      {
        pressed = 0;
        leftControlPushed = false;
        sendKey( keyMap[row1 + option1][col1],pressed);
      }
      if(keyMap[row1 + option1][col1] == KEY_RCTL)
      {
        pressed = 0;
        rightControlPushed = false;
        sendKey( keyMap[row1 + option1][col1],pressed);
      }

      
      if (keyMap[row1 + option1][col1] == KEY_RAIS)
      {
        BootKeyboard.releaseAll();
        raisKeyPushed = false;
      }
      if (keyMap[row1 + option1][col1] == KEY_LOWE)
      {
        BootKeyboard.releaseAll();
        stopMouseMove(0);
        loweKeyPushed = false;
      }
      if (keyMap[row1 + option1][col1] == KEY_CPFL)
      {
        pressed = 0;
      }
      if (keyMap[row1 + option1][col1] == KEY_CLPF)
      {
        pressed = 0;
      }

      if (keyMap[row1 + option1][col1] == KEY_MUP)
      {
        stopMouseMove(KEY_MUP);
        pressed = 0;
      }
      if (keyMap[row1 + option1][col1] == KEY_MDWN)
      {
        stopMouseMove(KEY_MDWN);
        pressed = 0;
      }
      if (keyMap[row1 + option1][col1] == KEY_MRIT)
      {
        stopMouseMove(KEY_MRIT);
        pressed = 0;
      }
      if (keyMap[row1 + option1][col1] == KEY_MLFT)
      {
        stopMouseMove(KEY_MLFT);
        pressed = 0;
      }
      if (keyMap[row1 + option1][col1] == KEY_MLCL)
      {
        if(keyboardEnabled)
        {
          BootMouse.release(MOUSE_LEFT);
        }
        pressed = 0;
      }
      if (keyMap[row1 + option1][col1] == KEY_MRCL)
      {
        if(keyboardEnabled)
        {
          BootMouse.release(MOUSE_RIGHT);
        }
        pressed = 0;
      }


      
      if (keyMap[row1 + option1][col1] == KEY_MUTE)
      {
        pressed = 0;
        Consumer.release(MEDIA_VOLUME_MUTE);
      }
      if (keyMap[row1 + option1][col1] == KEY_VOLUMEUP)
      {
        pressed = 0;
        Consumer.release(MEDIA_VOLUME_UP);
      }
      if (keyMap[row1 + option1][col1] == KEY_VOLUMEDOWN)
      {
        pressed = 0;
        Consumer.release(MEDIA_VOLUME_DOWN);
      }
      else
      {
        pressed = 0;
        sendKey( keyMap[row1 + option1][col1],pressed);
      }
    }
  }
}

void readPcSerial()
{
  byte receivedata = Serial.read();

  if(receivedata == 'G')
  {
    gameModeEnabled = false;
    Serial1.write(0b10000011);
    changeProfile();
  }
  else if(receivedata == 'D')
  {
    gameModeEnabled = true;
    Serial1.write(0b10000100);
    changeProfile();
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
  EEPROM[0x002] = backLEDOn;
}
void onBackLED()
{
  backLED.clear();
  for (int i = 0; i < numpixels; i++)
  {
    backLED.setPixelColor(i, backLED.Color(
      backLightLEDNormal[LEDProfile][0], backLightLEDNormal[LEDProfile][1], backLightLEDNormal[LEDProfile  ][2]));
  }
  backLED.show();
  EEPROM[0x002] = backLEDOn;
}

void capsLockLedOn()
{
  /*uint32_t color0 = statusLED.getPixelColor(0);
  uint8_t color0_0 = color0 >> 16 & 0b0000000011111111;
  uint8_t color0_1 = color0 >> 8 & 0b0000000011111111;
  uint8_t color0_2 = color0   & 0b0000000011111111;
  Serial.print("color1 ");
  Serial.print(color0);
  Serial.print(" ");
  Serial.print(color0_0);
  Serial.print(" ");
  Serial.print(color0_1);
  Serial.print(" ");
  Serial.println(color0_2);
  uint32_t color1 = statusLED.getPixelColor(1);
  uint8_t color1_0 = color1 >> 16 & 0b0000000011111111;
  uint8_t color1_1 = color1 >> 8 & 0b0000000011111111;
  uint8_t color1_2 = color1   & 0b0000000011111111;
  Serial.print("color1");
  Serial.print(color1);
  Serial.print(" ");
  Serial.print(color1_0);
  Serial.print(" ");
  Serial.print(color1_1);
  Serial.print(" ");
  Serial.println(color1_2);
  uint32_t color3 = statusLED.getPixelColor(3);
  uint8_t color3_0 = color3 >> 16 & 0b0000000011111111;
  uint8_t color3_1 = color3 >> 8 & 0b0000000011111111;
  uint8_t color3_2 = color3   & 0b0000000011111111;
  Serial.print("color3 ");
  Serial.print(color3);
  Serial.print(" ");
  Serial.print(color3_0);
  Serial.print(" ");
  Serial.print(color3_1);
  Serial.print(" ");
  Serial.println(color3_2);*/
    
    
  //statusLED.clear();
  statusLED.setPixelColor(2,statusLED.Color(0, 5, 0)); 
  //statusLED.setPixelColor(0,statusLED.Color(color0_0,color0_1,color0_2));
  //statusLED.setPixelColor(1,statusLED.Color(color1_0,color1_1,color1_2));
  //statusLED.setPixelColor(3,statusLED.Color(color3_0,color3_1,color3_2));
  statusLED.show();
    
}
void capsLockLedOff()
{
  /*uint32_t color0 = statusLED.getPixelColor(0);
  uint8_t color0_0 = color0 >> 16 & 0b0000000011111111;
  uint8_t color0_1 = color0 >> 8 & 0b0000000011111111;
  uint8_t color0_2 = color0   & 0b0000000011111111;
  Serial.print("color1 ");
  Serial.print(color0);
  Serial.print(" ");
  Serial.print(color0_0);
  Serial.print(" ");
  Serial.print(color0_1);
  Serial.print(" ");
  Serial.println(color0_2);
  uint32_t color1 = statusLED.getPixelColor(1);
  uint8_t color1_0 = color1 >> 16 & 0b0000000011111111;
  uint8_t color1_1 = color1 >> 8 & 0b0000000011111111;
  uint8_t color1_2 = color1   & 0b0000000011111111;
  Serial.print("color1");
  Serial.print(color1);
  Serial.print(" ");
  Serial.print(color1_0);
  Serial.print(" ");
  Serial.print(color1_1);
  Serial.print(" ");
  Serial.println(color1_2);
  uint32_t color3 = statusLED.getPixelColor(3);
  uint8_t color3_0 = color3 >> 16 & 0b0000000011111111;
  uint8_t color3_1 = color3 >> 8 & 0b0000000011111111;
  uint8_t color3_2 = color3   & 0b0000000011111111;
  Serial.print("color3 ");
  Serial.print(color3);
  Serial.print(" ");
  Serial.print(color3_0);
  Serial.print(" ");
  Serial.print(color3_1);
  Serial.print(" ");
  Serial.println(color3_2);*/
    
    
  //statusLED.clear();
  statusLED.setPixelColor(2,statusLED.Color(0, 0, 0)); 
  //statusLED.setPixelColor(0,statusLED.Color(color0_0,color0_1,color0_2));
  //statusLED.setPixelColor(1,statusLED.Color(color1_0,color1_1,color1_2));
  //statusLED.setPixelColor(3,statusLED.Color(color3_0,color3_1,color3_2));
  statusLED.show();

  
}

void changeProfile()
{
  if(!gameModeEnabled)
  {
    gameModeEnabled = true;
    Serial.println(F("gameMode Enabled"));
    /*uint32_t color1 = statusLED.getPixelColor(1);
    uint8_t color1_0 = color1 >> 16 & 0b0000000011111111;
    uint8_t color1_1 = color1 >> 8 & 0b0000000011111111;
    uint8_t color1_2 = color1   & 0b0000000011111111;
    Serial.print("color1 ");
    Serial.print(color1);
    Serial.print(" ");
    Serial.print(color1_0);
    Serial.print(" ");
    Serial.print(color1_1);
    Serial.print(" ");
    Serial.println(color1_2);
    uint32_t color2 = statusLED.getPixelColor(2);
    uint8_t color2_0 = color2 >> 16 & 0b0000000011111111;
    uint8_t color2_1 = color2 >> 8 & 0b0000000011111111;
    uint8_t color2_2 = color2   & 0b0000000011111111;
    Serial.print("color2 ");
    Serial.print(color2);
    Serial.print(" ");
    Serial.print(color2_0);
    Serial.print(" ");
    Serial.print(color2_1);
    Serial.print(" ");
    Serial.println(color2_2);
    uint32_t color3 = statusLED.getPixelColor(3);
    uint8_t color3_0 = color3 >> 16 & 0b0000000011111111;
    uint8_t color3_1 = color3 >> 8 & 0b0000000011111111;
    uint8_t color3_2 = color3   & 0b0000000011111111;
    Serial.print("color3 ");
    Serial.print(color3);
    Serial.print(" ");
    Serial.print(color3_0);
    Serial.print(" ");
    Serial.print(color3_1);
    Serial.print(" ");
    Serial.println(color3_2);*/
    
    
    //statusLED.clear();
    statusLED.setPixelColor(0,statusLED.Color(5, 0, 0)); 
    //statusLED.setPixelColor(1,statusLED.Color(color1_0,color1_1,color1_2));
    //statusLED.setPixelColor(2,statusLED.Color(color2_0,color2_1,color2_2));
    //statusLED.setPixelColor(3,statusLED.Color(color3_0,color3_1,color3_2));
    statusLED.show();
  }
  else
  {
    gameModeEnabled = false;
    Serial.println(F("gameMode Disenabled"));
    /*uint32_t color1 = statusLED.getPixelColor(1);
    uint8_t color1_0 = color1 >> 16 & 0b0000000011111111;
    uint8_t color1_1 = color1 >> 8 & 0b0000000011111111;
    uint8_t color1_2 = color1   & 0b0000000011111111;
    Serial.print("color1 ");
    Serial.print(color1);
    Serial.print(" ");
    Serial.print(color1_0);
    Serial.print(" ");
    Serial.print(color1_1);
    Serial.print(" ");
    Serial.println(color1_2);
    uint32_t color2 = statusLED.getPixelColor(2);
    uint8_t color2_0 = color2 >> 16 & 0b0000000011111111;
    uint8_t color2_1 = color2 >> 8 & 0b0000000011111111;
    uint8_t color2_2 = color2   & 0b0000000011111111;
    Serial.print("color2 ");
    Serial.print(color2);
    Serial.print(" ");
    Serial.print(color2_0);
    Serial.print(" ");
    Serial.print(color2_1);
    Serial.print(" ");
    Serial.println(color2_2);
    uint32_t color3 = statusLED.getPixelColor(3);
    uint8_t color3_0 = color3 >> 16 & 0b0000000011111111;
    uint8_t color3_1 = color3 >> 8 & 0b0000000011111111;
    uint8_t color3_2 = color3   & 0b0000000011111111;
    Serial.print("color3 ");
    Serial.print(color3);
    Serial.print(" ");
    Serial.print(color3_0);
    Serial.print(" ");
    Serial.print(color3_1);
    Serial.print(" ");
    Serial.println(color3_2);*/
    
    
    //statusLED.clear();
    statusLED.setPixelColor(0,statusLED.Color(0, 0, 0)); 
    //statusLED.setPixelColor(1,statusLED.Color(color1_0,color1_1,color1_2));
    //statusLED.setPixelColor(2,statusLED.Color(color2_0,color2_1,color2_2));
    //statusLED.setPixelColor(3,statusLED.Color(color3_0,color3_1,color3_2));
    statusLED.show();
  }
  EEPROM[0x001] = gameModeEnabled;
  Serial.print(F("EEPROM[0x001] "));
  Serial.println(EEPROM[0x001]);
}
void changeLightProfile()
{
  if (LEDProfile == 6)
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
  Serial.print(F("LEDProfile "));
  Serial.println( LEDProfile);

  EEPROM[0x000] = LEDProfile;
  Serial.print(F("EEPROM[0x000] "));
  Serial.println(EEPROM[0x000]);
}
void startMouseMove(uint8_t directions)
{
  if(directions == KEY_MUP)
  {
    mouseMove_y = true;
  }
  if(directions == KEY_MDWN)
  {
    mouseMovey = true;
  }
  if(directions == KEY_MRIT)
  {
    mouseMovex = true;
  }
  if(directions == KEY_MLFT)
  {
    mouseMove_x = true;
  }
}
void stopMouseMove(uint8_t directions)
{
  if(directions == 0)
  {
     mouseMove_y = false;
     mouseMovey = false;
     mouseMovex = false;
     mouseMove_x = false;
     Mouse.release();
  }
  else
  {
    if(directions == KEY_MUP)
    {
      mouseMove_y = false;
    }
    if(directions == KEY_MDWN)
    {
      mouseMovey = false;
    }
    if(directions == KEY_MRIT)
    {
      mouseMovex = false;
    }
    if(directions == KEY_MLFT)
    {
      mouseMove_x = false;
    }
  }
  
}
void chengeKeyboardEnabled()
{
  if(!keyboardEnabled)
  {
    keyboardEnabled = true;
    Serial1.write(0b10000101);
    statusLED.setPixelColor(3,statusLED.Color(0, 5, 0));
    statusLED.show();
    Serial.print(F("keyboardEnabled :"));
    Serial.println(keyboardEnabled);
  }
  else
  {
    keyboardEnabled = false;
    Serial1.write(0b10000110);
    statusLED.setPixelColor(3,statusLED.Color(5, 0, 0)); 
    statusLED.show();
    Serial.print(F("keyboardEnabled :"));
    Serial.println(keyboardEnabled);
  }
  
}

void sendKey(byte keycode,bool pressed)
{
  if(pressed)
  {
    if(keycode == KEY_A)      BootKeyboard.press(KEY_A);
    else if(keycode == KEY_B) BootKeyboard.press(KEY_B);
    else if(keycode == KEY_C) BootKeyboard.press(KEY_C);
    else if(keycode == KEY_D) BootKeyboard.press(KEY_D);
    else if(keycode == KEY_E) BootKeyboard.press(KEY_E);
    else if(keycode == KEY_F) BootKeyboard.press(KEY_F);
    else if(keycode == KEY_G) BootKeyboard.press(KEY_G);
    else if(keycode == KEY_H) BootKeyboard.press(KEY_H);
    else if(keycode == KEY_I) BootKeyboard.press(KEY_I);
    else if(keycode == KEY_J) BootKeyboard.press(KEY_J);
    else if(keycode == KEY_K) BootKeyboard.press(KEY_K);
    else if(keycode == KEY_L) BootKeyboard.press(KEY_L);
    else if(keycode == KEY_M) BootKeyboard.press(KEY_M);
    else if(keycode == KEY_N) BootKeyboard.press(KEY_N);
    else if(keycode == KEY_O) BootKeyboard.press(KEY_O);
    else if(keycode == KEY_P) BootKeyboard.press(KEY_P);
    else if(keycode == KEY_Q) BootKeyboard.press(KEY_Q);
    else if(keycode == KEY_R) BootKeyboard.press(KEY_R);
    else if(keycode == KEY_S) BootKeyboard.press(KEY_S);
    else if(keycode == KEY_T) BootKeyboard.press(KEY_T);
    else if(keycode == KEY_U) BootKeyboard.press(KEY_U);
    else if(keycode == KEY_V) BootKeyboard.press(KEY_V);
    else if(keycode == KEY_W) BootKeyboard.press(KEY_W);
    else if(keycode == KEY_X) BootKeyboard.press(KEY_X);
    else if(keycode == KEY_Y) BootKeyboard.press(KEY_Y);
    else if(keycode == KEY_Z) BootKeyboard.press(KEY_Z);

    else if(keycode == KEY_KEYPAD_0) BootKeyboard.press(KEYPAD_0);
    else if(keycode == KEY_KEYPAD_1) BootKeyboard.press(KEYPAD_1);
    else if(keycode == KEY_KEYPAD_2) BootKeyboard.press(KEYPAD_2);
    else if(keycode == KEY_KEYPAD_3) BootKeyboard.press(KEYPAD_3);
    else if(keycode == KEY_KEYPAD_4) BootKeyboard.press(KEYPAD_4);
    else if(keycode == KEY_KEYPAD_5) BootKeyboard.press(KEYPAD_5);
    else if(keycode == KEY_KEYPAD_6) BootKeyboard.press(KEYPAD_6);
    else if(keycode == KEY_KEYPAD_7) BootKeyboard.press(KEYPAD_7);
    else if(keycode == KEY_KEYPAD_8) BootKeyboard.press(KEYPAD_8);
    else if(keycode == KEY_KEYPAD_9) BootKeyboard.press(KEYPAD_9);
    else if(keycode == KEY_KEYPAD_DECIMAL)  BootKeyboard.press(KEYPAD_DOT);
    else if(keycode == KEY_KEYPAD_ENTER)    BootKeyboard.press(KEYPAD_ENTER);
    else if(keycode == KEY_KEYPAD_PLUS)     BootKeyboard.press(KEYPAD_ADD);
    else if(keycode == KEY_KEYPAD_MINUS)    BootKeyboard.press(KEYPAD_SUBTRACT);
    else if(keycode == KEY_KEYPAD_MULTIPLY) BootKeyboard.press(KEYPAD_MULTIPLY);
    else if(keycode == KEY_KEYPAD_DIVIDE)   BootKeyboard.press(KEYPAD_DIVIDE);
    else if(keycode == KEY_KEYPAD_NUMLOCK)  BootKeyboard.press(KEY_NUM_LOCK);

    
    else if(keycode == KEY_ENT)  BootKeyboard.press(KEY_ENTER);
    else if(keycode == KEY_ESCP)  BootKeyboard.press(KEY_ESC);
    else if(keycode == KEY_BSPC) BootKeyboard.press(KEY_BACKSPACE);
    else if(keycode == KEY_DEL)  BootKeyboard.press(KEY_DELETE);
    else if(keycode == KEY_TB)  BootKeyboard.press(KEY_TAB);
    else if(keycode == KEY_CAPS) BootKeyboard.press(KEY_CAPS_LOCK);
    else if(keycode == KEY_LCTL) BootKeyboard.press(KEY_LEFT_CTRL);
    else if(keycode == KEY_LSFT) BootKeyboard.press(KEY_LEFT_SHIFT);
    else if(keycode == KEY_LALT) BootKeyboard.press(KEY_LEFT_ALT);
    else if(keycode == KEY_LGUI) BootKeyboard.press(KEY_LEFT_GUI);
    else if(keycode == KEY_RCTL) BootKeyboard.press(KEY_RIGHT_CTRL);
    else if(keycode == KEY_RSFT) BootKeyboard.press(KEY_RIGHT_SHIFT);
    else if(keycode == KEY_RALT) BootKeyboard.press(KEY_RIGHT_ALT);
    else if(keycode == KEY_RGUI) BootKeyboard.press(KEY_RIGHT_GUI);

    
    else if(keycode == KEY_PGUP) BootKeyboard.press(KEY_PAGE_UP);
    else if(keycode == KEY_PGDN) BootKeyboard.press(KEY_PAGE_DOWN);
    else if(keycode == KEY_HOM) BootKeyboard.press(KEY_HOME);
    else if(keycode == KEY_EN)  BootKeyboard.press(KEY_END);
    else if(keycode == KEY_LEFT) BootKeyboard.press(KEY_LEFT_ARROW);
    else if(keycode == KEY_RGHT) BootKeyboard.press(KEY_RIGHT_ARROW);
    else if(keycode == KEY_UP)   BootKeyboard.press(KEY_UP_ARROW);
    else if(keycode == KEY_DOWN) BootKeyboard.press(KEY_DOWN_ARROW);
    
    else if(keycode == KEY_0) BootKeyboard.press(KEY_0);
    else if(keycode == KEY_1) BootKeyboard.press(KEY_1);
    else if(keycode == KEY_2) BootKeyboard.press(KEY_2);
    else if(keycode == KEY_3) BootKeyboard.press(KEY_3);
    else if(keycode == KEY_4) BootKeyboard.press(KEY_4);
    else if(keycode == KEY_5) BootKeyboard.press(KEY_5);
    else if(keycode == KEY_6) BootKeyboard.press(KEY_6);
    else if(keycode == KEY_7) BootKeyboard.press(KEY_7);
    else if(keycode == KEY_8) BootKeyboard.press(KEY_8);
    else if(keycode == KEY_9) BootKeyboard.press(KEY_9);
    
    else if(keycode == KEY_EXLM) BootKeyboard.press(KEY_EXLM);
    else if(keycode == KEY_AT)   BootKeyboard.press(KEY_AT);
    else if(keycode == KEY_HASH) BootKeyboard.press(KEY_HASH);
    else if(keycode == KEY_DLR)  BootKeyboard.press(KEY_DLR);
    else if(keycode == KEY_PERC) BootKeyboard.press(KEY_PERC);
    else if(keycode == KEY_CIRC) BootKeyboard.press(KEY_CIRC);
    else if(keycode == KEY_AMPR) BootKeyboard.press(KEY_AMPR);
    else if(keycode == KEY_ASTR) BootKeyboard.press(KEY_ASTR);
    else if(keycode == KEY_LPRN) BootKeyboard.press(KEY_LPRN);
    else if(keycode == KEY_RPRN) BootKeyboard.press(KEY_RPRN);
    
    else if(keycode == KEY_MINS) BootKeyboard.press(KEY_MINUS);
    else if(keycode == KEY_EQL)  BootKeyboard.press(KEY_EQUAL);
    else if(keycode == KEY_SPC)  BootKeyboard.press(KEY_SPACE);
    else if(keycode == KEY_LBRC) BootKeyboard.press(KEY_LEFT_BRACE);
    else if(keycode == KEY_RBRC) BootKeyboard.press(KEY_RIGHT_BRACE);
    else if(keycode == KEY_LCBR) BootKeyboard.press(KEY_LCBR);
    else if(keycode == KEY_RCBR) BootKeyboard.press(KEY_RCBR);
    else if(keycode == KEY_BSLS) BootKeyboard.press(KEY_BACKSLASH);
    else if(keycode == KEY_SCLN) BootKeyboard.press(KEY_SEMICOLON);
    else if(keycode == KEY_QUOT) BootKeyboard.press(KEY_QUOTE);
    else if(keycode == KEY_GRV)  BootKeyboard.press(KEY_TILDE);
    else if(keycode == KEY_COMM) BootKeyboard.press(KEY_COMMA);
    else if(keycode == KEY_DOT)  BootKeyboard.press(KEY_PERIOD);
    else if(keycode == KEY_SLSH) BootKeyboard.press(KEY_SLASH);

    
    else if(keycode == KEY_FU1)  BootKeyboard.press(KEY_F1);
    else if(keycode == KEY_FU2)  BootKeyboard.press(KEY_F2);
    else if(keycode == KEY_FU3)  BootKeyboard.press(KEY_F3);
    else if(keycode == KEY_FU4)  BootKeyboard.press(KEY_F4);
    else if(keycode == KEY_FU5)  BootKeyboard.press(KEY_F5);
    else if(keycode == KEY_FU6)  BootKeyboard.press(KEY_F6);
    else if(keycode == KEY_FU7)  BootKeyboard.press(KEY_F7);
    else if(keycode == KEY_FU8)  BootKeyboard.press(KEY_F8);
    else if(keycode == KEY_FU9)  BootKeyboard.press(KEY_F9);
    else if(keycode == KEY_FU10) BootKeyboard.press(KEY_F10);
    else if(keycode == KEY_FU11) BootKeyboard.press(KEY_F11);
    else if(keycode == KEY_FU12) BootKeyboard.press(KEY_F12);
  }
  else
  {
    if(keycode == KEY_A)      BootKeyboard.release(KEY_A);
    else if(keycode == KEY_B) BootKeyboard.release(KEY_B);
    else if(keycode == KEY_C) BootKeyboard.release(KEY_C);
    else if(keycode == KEY_D) BootKeyboard.release(KEY_D);
    else if(keycode == KEY_E) BootKeyboard.release(KEY_E);
    else if(keycode == KEY_F) BootKeyboard.release(KEY_F);
    else if(keycode == KEY_G) BootKeyboard.release(KEY_G);
    else if(keycode == KEY_H) BootKeyboard.release(KEY_H);
    else if(keycode == KEY_I) BootKeyboard.release(KEY_I);
    else if(keycode == KEY_J) BootKeyboard.release(KEY_J);
    else if(keycode == KEY_K) BootKeyboard.release(KEY_K);
    else if(keycode == KEY_L) BootKeyboard.release(KEY_L);
    else if(keycode == KEY_M) BootKeyboard.release(KEY_M);
    else if(keycode == KEY_N) BootKeyboard.release(KEY_N);
    else if(keycode == KEY_O) BootKeyboard.release(KEY_O);
    else if(keycode == KEY_P) BootKeyboard.release(KEY_P);
    else if(keycode == KEY_Q) BootKeyboard.release(KEY_Q);
    else if(keycode == KEY_R) BootKeyboard.release(KEY_R);
    else if(keycode == KEY_S) BootKeyboard.release(KEY_S);
    else if(keycode == KEY_T) BootKeyboard.release(KEY_T);
    else if(keycode == KEY_U) BootKeyboard.release(KEY_U);
    else if(keycode == KEY_V) BootKeyboard.release(KEY_V);
    else if(keycode == KEY_W) BootKeyboard.release(KEY_W);
    else if(keycode == KEY_X) BootKeyboard.release(KEY_X);
    else if(keycode == KEY_Y) BootKeyboard.release(KEY_Y);
    else if(keycode == KEY_Z) BootKeyboard.release(KEY_Z);

    else if(keycode == KEY_KEYPAD_0) BootKeyboard.release(KEYPAD_0);
    else if(keycode == KEY_KEYPAD_1) BootKeyboard.release(KEYPAD_1);
    else if(keycode == KEY_KEYPAD_2) BootKeyboard.release(KEYPAD_2);
    else if(keycode == KEY_KEYPAD_3) BootKeyboard.release(KEYPAD_3);
    else if(keycode == KEY_KEYPAD_4) BootKeyboard.release(KEYPAD_4);
    else if(keycode == KEY_KEYPAD_5) BootKeyboard.release(KEYPAD_5);
    else if(keycode == KEY_KEYPAD_6) BootKeyboard.release(KEYPAD_6);
    else if(keycode == KEY_KEYPAD_7) BootKeyboard.release(KEYPAD_7);
    else if(keycode == KEY_KEYPAD_8) BootKeyboard.release(KEYPAD_8);
    else if(keycode == KEY_KEYPAD_9) BootKeyboard.release(KEYPAD_9);
    else if(keycode == KEY_KEYPAD_DECIMAL)  BootKeyboard.release(KEYPAD_DOT);
    else if(keycode == KEY_KEYPAD_ENTER)    BootKeyboard.release(KEYPAD_ENTER);
    else if(keycode == KEY_KEYPAD_PLUS)     BootKeyboard.release(KEYPAD_ADD);
    else if(keycode == KEY_KEYPAD_MINUS)    BootKeyboard.release(KEYPAD_SUBTRACT);
    else if(keycode == KEY_KEYPAD_MULTIPLY) BootKeyboard.release(KEYPAD_MULTIPLY);
    else if(keycode == KEY_KEYPAD_DIVIDE)   BootKeyboard.release(KEYPAD_DIVIDE);
    else if(keycode == KEY_KEYPAD_NUMLOCK)  BootKeyboard.release(KEY_NUM_LOCK);

    
    else if(keycode == KEY_ENT)  BootKeyboard.release(KEY_ENTER);
    else if(keycode == KEY_ESCP)  BootKeyboard.release(KEY_ESC);
    else if(keycode == KEY_BSPC) BootKeyboard.release(KEY_BACKSPACE);
    else if(keycode == KEY_DEL)  BootKeyboard.release(KEY_DELETE);
    else if(keycode == KEY_TB)  BootKeyboard.release(KEY_TAB);
    else if(keycode == KEY_CAPS) BootKeyboard.release(KEY_CAPS_LOCK);
    else if(keycode == KEY_LCTL) BootKeyboard.release(KEY_LEFT_CTRL);
    else if(keycode == KEY_LSFT) BootKeyboard.release(KEY_LEFT_SHIFT);
    else if(keycode == KEY_LALT) BootKeyboard.release(KEY_LEFT_ALT);
    else if(keycode == KEY_LGUI) BootKeyboard.release(KEY_LEFT_GUI);
    else if(keycode == KEY_RCTL) BootKeyboard.release(KEY_RIGHT_CTRL);
    else if(keycode == KEY_RSFT) BootKeyboard.release(KEY_RIGHT_SHIFT);
    else if(keycode == KEY_RALT) BootKeyboard.release(KEY_RIGHT_ALT);
    else if(keycode == KEY_RGUI) BootKeyboard.release(KEY_RIGHT_GUI);

    
    else if(keycode == KEY_PGUP) BootKeyboard.release(KEY_PAGE_UP);
    else if(keycode == KEY_PGDN) BootKeyboard.release(KEY_PAGE_DOWN);
    else if(keycode == KEY_HOM) BootKeyboard.release(KEY_HOME);
    else if(keycode == KEY_EN)  BootKeyboard.release(KEY_END);
    else if(keycode == KEY_LEFT) BootKeyboard.release(KEY_LEFT_ARROW);
    else if(keycode == KEY_RGHT) BootKeyboard.release(KEY_RIGHT_ARROW);
    else if(keycode == KEY_UP)   BootKeyboard.release(KEY_UP_ARROW);
    else if(keycode == KEY_DOWN) BootKeyboard.release(KEY_DOWN_ARROW);
    
    else if(keycode == KEY_0) BootKeyboard.release(KEY_0);
    else if(keycode == KEY_1) BootKeyboard.release(KEY_1);
    else if(keycode == KEY_2) BootKeyboard.release(KEY_2);
    else if(keycode == KEY_3) BootKeyboard.release(KEY_3);
    else if(keycode == KEY_4) BootKeyboard.release(KEY_4);
    else if(keycode == KEY_5) BootKeyboard.release(KEY_5);
    else if(keycode == KEY_6) BootKeyboard.release(KEY_6);
    else if(keycode == KEY_7) BootKeyboard.release(KEY_7);
    else if(keycode == KEY_8) BootKeyboard.release(KEY_8);
    else if(keycode == KEY_9) BootKeyboard.release(KEY_9);
    
    else if(keycode == KEY_EXLM) BootKeyboard.release(KEY_EXLM);
    else if(keycode == KEY_AT)   BootKeyboard.release(KEY_AT);
    else if(keycode == KEY_HASH) BootKeyboard.release(KEY_HASH);
    else if(keycode == KEY_DLR)  BootKeyboard.release(KEY_DLR);
    else if(keycode == KEY_PERC) BootKeyboard.release(KEY_PERC);
    else if(keycode == KEY_CIRC) BootKeyboard.release(KEY_CIRC);
    else if(keycode == KEY_AMPR) BootKeyboard.release(KEY_AMPR);
    else if(keycode == KEY_ASTR) BootKeyboard.release(KEY_ASTR);
    else if(keycode == KEY_LPRN) BootKeyboard.release(KEY_LPRN);
    else if(keycode == KEY_RPRN) BootKeyboard.release(KEY_RPRN);
    
    else if(keycode == KEY_MINS) BootKeyboard.release(KEY_MINUS);
    else if(keycode == KEY_EQL)  BootKeyboard.release(KEY_EQUAL);
    else if(keycode == KEY_SPC)  BootKeyboard.release(KEY_SPACE);
    else if(keycode == KEY_LBRC) BootKeyboard.release(KEY_LEFT_BRACE);
    else if(keycode == KEY_RBRC) BootKeyboard.release(KEY_RIGHT_BRACE);
    else if(keycode == KEY_LCBR) BootKeyboard.release(KEY_LCBR);
    else if(keycode == KEY_RCBR) BootKeyboard.release(KEY_RCBR);
    else if(keycode == KEY_BSLS) BootKeyboard.release(KEY_BACKSLASH);
    else if(keycode == KEY_SCLN) BootKeyboard.release(KEY_SEMICOLON);
    else if(keycode == KEY_QUOT) BootKeyboard.release(KEY_QUOTE);
    else if(keycode == KEY_GRV)  BootKeyboard.release(KEY_TILDE);
    else if(keycode == KEY_COMM) BootKeyboard.release(KEY_COMMA);
    else if(keycode == KEY_DOT)  BootKeyboard.release(KEY_PERIOD);
    else if(keycode == KEY_SLSH) BootKeyboard.release(KEY_SLASH);

    
    else if(keycode == KEY_FU1)  BootKeyboard.release(KEY_F1);
    else if(keycode == KEY_FU2)  BootKeyboard.release(KEY_F2);
    else if(keycode == KEY_FU3)  BootKeyboard.release(KEY_F3);
    else if(keycode == KEY_FU4)  BootKeyboard.release(KEY_F4);
    else if(keycode == KEY_FU5)  BootKeyboard.release(KEY_F5);
    else if(keycode == KEY_FU6)  BootKeyboard.release(KEY_F6);
    else if(keycode == KEY_FU7)  BootKeyboard.release(KEY_F7);
    else if(keycode == KEY_FU8)  BootKeyboard.release(KEY_F8);
    else if(keycode == KEY_FU9)  BootKeyboard.release(KEY_F9);
    else if(keycode == KEY_FU10) BootKeyboard.release(KEY_F10);
    else if(keycode == KEY_FU11) BootKeyboard.release(KEY_F11);
    else if(keycode == KEY_FU12) BootKeyboard.release(KEY_F12);
  }
}
