#include "Keyboard.h"



// Numeric keypad
//
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
#define KEY_KEYPAD_DECIMAL 0xEB
#define KEY_KEYPAD_ENTER 0xE0
#define KEY_KEYPAD_PLUS 0xDF
#define KEY_KEYPAD_MINUS 0xDE
#define KEY_KEYPAD_MULTIPLY 0xDD
#define KEY_KEYPAD_DIVIDE 0xDC
#define KEY_KEYPAD_NUMLOCK 0xDB
#define NONE 0x00


int row[] = {6,5,4,3,2};
int col[] = {8,9,10,11};

const byte keyMap[sizeof(row)/2][sizeof(col)/2]={
  {  KEY_KEYPAD_NUMLOCK,  KEY_KEYPAD_DIVIDE,  KEY_KEYPAD_MULTIPLY,  KEY_KEYPAD_MINUS   },
  {  KEY_KEYPAD_7,        KEY_KEYPAD_8,       KEY_KEYPAD_9,         KEY_KEYPAD_PLUS    },
  {  KEY_KEYPAD_4,        KEY_KEYPAD_5,       KEY_KEYPAD_6,         KEY_TAB            },
  {  KEY_KEYPAD_1,        KEY_KEYPAD_2,       KEY_KEYPAD_3,         KEY_KEYPAD_ENTER   },
  {  KEY_KEYPAD_0,        NONE,               KEY_KEYPAD_DECIMAL,   NONE               }
};


//
int led=17;

bool currentState[sizeof(row)/2][sizeof(col)/2];
bool beforeState[sizeof(row)/2][sizeof(col)/2];

void setup()
{

  
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);

  Serial.println(sizeof(row)/2);
  for(int i=0;i<sizeof(row)/2;i++)
  {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], HIGH);
    Serial.print(digitalRead(row[i]));
    Serial.print(" ");
  }
  Serial.println(" ");
  Serial.println(sizeof(col)/2);
  for(int i=0;i<sizeof(col)/2;i++)
  {
    pinMode(col[i], INPUT_PULLUP);
    Serial.print(digitalRead(col[i]));
    Serial.print(" ");
  }
  for(int i=0;i<sizeof(row)/2;i++)
  {
    for(int j=0;j<sizeof(col)/2;j++)
    {
      currentState[i][j]=HIGH;
      beforeState[i][j]=HIGH;
      //HIGH=false LOW=true
    }
  }
  
  
  Keyboard.begin();
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  Serial.begin(9600);
  delay(1000);
}
void loop()
{
  
  for(int i=0;i<sizeof(row)/2;i++)
  {
    digitalWrite(row[i],LOW);
    for(int j=0;j<sizeof(col)/2;j++)
    {
      currentState[i][j]=digitalRead(col[j]);
      if(currentState[i][j]!=beforeState[i][j])
      {
        if(currentState[i][j]==LOW)
        {
          Keyboard.press(keyMap[i][j]);
          digitalWrite(led,HIGH);
          Serial.print("pressed");
          Serial.print("keyMap");
          Serial.print(i);
          Serial.print(" ");
          Serial.println(j);
        }
        else
        {
          Keyboard.release(keyMap[i][j]);
          digitalWrite(led,LOW);
          digitalWrite(led,HIGH);
          Serial.print("released");
          Serial.print("keyMap");
          Serial.print(i);
          Serial.print(" ");
          Serial.println(j);
        }
      beforeState[i][j]=currentState[i][j];
      }
    }
    digitalWrite(row[i],HIGH);
  }

  
  
}
