#include "Keyboard.h"


//===============================
//===================================
//  Keyboard

#define NONE 0x00



const int rowNum = 8;
const int colNum = 6;

const int rowPin[rowNum] = {3,4,5,6,7,8,9,10};
const int colPin[colNum] = {13,14,15,16,17,18};

bool currentState[rowNum][colNum];
bool beforeState[rowNum][colNum];



const byte keyMap[rowNum][colNum] = {
  
  {KEY_ESC, NONE, KEY_F1, KEY_F2, KEY_F3, KEY_F4}
  
  
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
