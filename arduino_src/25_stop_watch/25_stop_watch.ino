#define time_val  1

#include "PinChangeInterrupt.h"
#include "TimerOne.h"

const int SW1 = A0, SW2 = A1;
                          // a, b, c, d, e, f, g, dp
const int FND_DATA_PIN[8] = {2, 3, 4, 5, 6, 7, 8, 9};
                           // D1, D2, D3, D4
const int FND_DIGIT_PIN[4] = {10, 11, 12, 13};
const unsigned char FND_DATA[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                                    0x7F,0x6F,0x5F,0x7C,0x58,0x5E,0x79,0x71};
const unsigned char FND_DIGIT[4] = {0xE, 0xD, 0xB, 0x7}; 
int i = 0, j = 0, k = 0;
static unsigned int time_S = 0; 
int flag_stopwatch = 0;   // 0:stop, 1:start                              

void setup() {
  // put your setup code here, to run once:
  display_init();
  
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);

  // 인터럽트 설정
  attachPCINT(digitalPinToPCINT(SW1), sw1_Pressed, RISING);
  attachPCINT(digitalPinToPCINT(SW2), sw2_Pressed, RISING);

  Timer1.initialize(10000); // 주기가 1초인 타이머 설정
  Timer1.attachInterrupt(timer1_callback);
}

void loop() {
  // put your main code here, to run repeatedly:
  display_numbers(time_S);
}

// 사용자 함수
void sw1_Pressed(){
  flag_stopwatch = (flag_stopwatch==1)? 0 : 1;
}

void sw2_Pressed(){
  time_S = 0;
  flag_stopwatch = 0;
}

void timer1_callback()    // 1초마다 호출
{
  if(flag_stopwatch==1){
    time_S++;
  }
}

void display_init(){
  for(int x=0; x<8; x++){   
    pinMode(FND_DATA_PIN[x], OUTPUT);
  }
  for(int y=0; y<4; y++){  
    pinMode(FND_DIGIT_PIN[y], OUTPUT);
  }
}

void display_clear(){
  for(int x=0; x<8; x++){   
    digitalWrite(FND_DATA_PIN[x], LOW);
  }
  for(int y=0; y<4; y++){  
    digitalWrite(FND_DIGIT_PIN[y], HIGH);
  }
}

void display_numbers(int num){   // 8475
  int num_tbl[4] = {};

  num_tbl[0] = num/1000;        // 천의 자리
  num_tbl[1] = (num%1000)/100;  // 백의 자리
  num_tbl[2] = (num%100)/10;    // 십의 자리
  num_tbl[3] = num%10;          // 일의 자리
  
  for(i=0; i<4; i++){
    display_clear();
    for(k=0; k<8; k++){
      digitalWrite(FND_DATA_PIN[k], FND_DATA[num_tbl[i]]&(0x01<<k));
    }
    for(j=0; j<4; j++){
      digitalWrite(FND_DIGIT_PIN[j], FND_DIGIT[i]&(0x01<<j));
    }
    delay(time_val);
  }
}
