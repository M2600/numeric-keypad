#include "Keyboard.h"

////Numeric keypad
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
#define KEY_KEYPAD_DECIMAL 0xEB   //小数点
#define KEY_KEYPAD_ENTER 0xE0     //エンター
#define KEY_KEYPAD_PLUS 0xDF      //＋
#define KEY_KEYPAD_MINUS 0xDE     //ー
#define KEY_KEYPAD_MULTIPLY 0xDD  //✕
#define KEY_KEYPAD_DIVIDE 0xDC    //÷
#define KEY_KEYPAD_NUMLOCK 0xDB
#define NONE 0x00


// KEY_F2 // 編集モード
// KEY_F4 // 1つ前のコマンドを実行
// KEY_F8 // 半角/全角変換

const int myCOPY  = 1; // コピー
const int myPASTE = 2; // 貼り付け
const int myCUT   = 3; // カット
const int myRe    = 4; // １つ戻る
const int myPrint = 5; // 印刷


//キーボードの縦横のスイッチ数
int row[] = {6, 5, 4, 3, 2};
int col[] = {8, 9, 10, 11};

/* キーマップ ～ as you like!! ～ */
const byte keyMap[2][sizeof(row) / 2][sizeof(col) / 2] = {
  { /* 通常時 */
    {  KEY_KEYPAD_NUMLOCK,  KEY_F2,             KEY_F4,               KEY_F8         },
    {  KEY_KEYPAD_7,        KEY_KEYPAD_8,       KEY_KEYPAD_9,         KEY_BACKSPACE  },
    {  KEY_KEYPAD_4,        KEY_KEYPAD_5,       KEY_KEYPAD_6,         KEY_TAB        },
    {  KEY_KEYPAD_1,        KEY_KEYPAD_2,       KEY_KEYPAD_3,         KEY_RETURN     },
    {  KEY_KEYPAD_0,        NONE,               KEY_KEYPAD_DECIMAL,   NONE           }
  },
  /*-
    { // NumLock時
    {  KEY_KEYPAD_NUMLOCK,  KEY_F2,             KEY_F4,               KEY_F8        },
    {  KEY_HOME,            KEY_UP_ARROW,       KEY_END,              KEY_BACKSPACE },
    {  KEY_LEFT_ARROW,      NONE,               KEY_RIGHT_ARROW,      KEY_TAB       },
    {  KEY_PAGE_UP,         KEY_DOWN_ARROW,     KEY_PAGE_DOWN,        KEY_RETURN    },
    {  NONE,                NONE,               KEY_KEYPAD_DECIMAL,   NONE          }
    }*/
  { /* NumLock時            Ctrl+C              Ctrl+V                Ctrl+X        */
    {  KEY_KEYPAD_NUMLOCK,  myCOPY,             myPASTE,              myRe          },
    {  KEY_HOME,            KEY_UP_ARROW,       KEY_END,              KEY_BACKSPACE },
    {  KEY_LEFT_ARROW,      NONE,               KEY_RIGHT_ARROW,      KEY_TAB       },
    {  KEY_PAGE_UP,         KEY_DOWN_ARROW,     KEY_PAGE_DOWN,        KEY_RETURN    },
    {  NONE,                NONE,               NONE,                 NONE          }
  }
};

/* ショートカット用 */
void ShortCut( int sts, int key1, char key2 ) {
  if ( sts == 1 ) {
    Keyboard.press( key1 );
    Keyboard.press( key2 );
  }
  else {
    //Keyboard.release( key1 );
    //Keyboard.release( key2 );
    Keyboard.releaseAll();
  }
}

//起動状態表示用のLED
int led = 17 ;

//キーボード状態保存用
bool currentState[sizeof(row) / 2][sizeof(col) / 2];
bool beforeState[sizeof(row) / 2][sizeof(col) / 2];

//LED点滅サブルーチン
void FlashLED( int pin, int num ) {
  for ( int ii = 0; ii < num; ii++ ) {
    static bool sta = true;
    digitalWrite(pin, sta);
    delay(100);
    sta = !sta;
  }
}

void setup() {
  pinMode(led, OUTPUT); //起動状態表示用LED
  FlashLED( led, 4 );   //適当に点滅

  pinMode( 13, OUTPUT); //Numlock状態表示用LED

  //キースイッチのマトリックスなんやら用の設定
  Serial.println(sizeof(row) / 2);
  for (int ii = 0; ii < sizeof(row) / 2; ii++)  {
    pinMode(row[ii], OUTPUT);
    digitalWrite(row[ii], HIGH);
    Serial.print(digitalRead(row[ii]));
    Serial.print(" ");
  }
  Serial.println(" ");
  Serial.println(sizeof(col) / 2);
  for (int ii = 0; ii < sizeof(col) / 2; ii++)  {
    pinMode(col[ii], INPUT_PULLUP);
    Serial.print(digitalRead(col[ii]));
    Serial.print(" ");
  }

  //キースイッチ状態保存の初期化
  for (int ii = 0; ii < sizeof(row) / 2; ii++)  {
    for (int jj= 0; jj < sizeof(col) / 2; jj++)    {
      currentState[ii][jj] = HIGH;
      beforeState[ii][jj] = HIGH;
      //HIGH=false LOW=true
    }
  }

  //キーボード起動
  Keyboard.begin();
  FlashLED( led, 4);
  Serial.begin(9600);
  delay(200);

  //起動時にNumLock On
  if (!Keyboard.getLedStatus(LED_NUM_LOCK)) {
    Keyboard.press(KEY_KEYPAD_NUMLOCK);
    Keyboard.release(KEY_KEYPAD_NUMLOCK);
  }
}


void loop() {

  int delayTime = 3;
  delay(delayTime);
  
  //NUmLockの状態確認
  int flag_NL;
  if (Keyboard.getLedStatus(LED_NUM_LOCK)) flag_NL = 0;
  else                                     flag_NL = 1;
  digitalWrite(13, 1 - flag_NL ); //NumLock状態表示LEDに反映

  for (int ii = 0; ii < sizeof(row) / 2; ii++) {
    digitalWrite(row[ii], LOW);
    for (int jj = 0; jj < sizeof(col) / 2; jj++)  {
      currentState[ii][jj] = digitalRead(col[jj]);
      if (currentState[ii][jj] != beforeState[ii][jj]) {
          switch ( keyMap[flag_NL][ii][jj] ) {
            case 1  : ShortCut( !currentState[ii][jj], KEY_LEFT_CTRL, 'c' ); break;
            case 2  : ShortCut( !currentState[ii][jj], KEY_LEFT_CTRL, 'v' ); break;
            case 3  : ShortCut( !currentState[ii][jj], KEY_LEFT_CTRL, 'x' ); break;
            case 4  : ShortCut( !currentState[ii][jj], KEY_LEFT_CTRL, 'z' ); break;
            case 5  : ShortCut( !currentState[ii][jj], KEY_LEFT_CTRL, 'p' ); break;
            default :
              if( !currentState[ii][jj] ) Keyboard.press( keyMap[flag_NL][ii][jj]);
              else                      Keyboard.release( keyMap[flag_NL][ii][jj]);
              break;
          }
          //Keyboard.release( keyMap[flag_NL][ii][jj]); //キーマップの実行
          digitalWrite(led, !currentState[ii][jj]);
          
        if (currentState[ii][jj] == LOW) { 
//        /*
          Serial.print("pressed");//以下デバッグ用
          Serial.print("keyMap");
          Serial.print(ii);
          Serial.print(" ");
          Serial.println(jj);
//        */
        }
        else {
          digitalWrite(led, HIGH);
//        /*
          Serial.print("released"); //以下デバッグ用
          Serial.print("keyMap");
          Serial.print(ii);
          Serial.print(" ");
          Serial.println(jj);
//        */
        }
        beforeState[ii][jj] = currentState[ii][jj];
      }
    }
    digitalWrite(row[ii], HIGH);
  }
}
