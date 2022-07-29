#include "PinChangeInterrupt.h"
#include "TimerOne.h"

const uint8_t pinGnd = A0;
const uint8_t pinVcc = A1;
const uint8_t pinX = A2;
const uint8_t pinY = A3;
const uint8_t pinSwitch = A4;
                //  a, b, c, d, e, f, g, dp
const uint8_t FND_DATA[8] = {13,12,11,10, 9, 8, 7, 6};
const uint8_t FND_DIGIT[2] = {5,4};
unsigned char FND_VALUE[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                               0x7F,0x6F,0x5F,0x7C,0x58,0x5E,0x79,0x71};
unsigned char FND_DIGIT_VAL[2] = {0x02,0x01};
                                //  0b00000010
                                //  0b00000001
int cnt = 0;

// 사용자 함수
// ISR(Interrupt Service Routine), IRQHandler
void pinSwitch_Pressed(){
  cnt = 0;
}

// Timer1 ISR
void timer1_isr(){
    FND6_OUTPUT(cnt);
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("--- test ---");
    for(int i=0; i<8; i++)  pinMode(FND_DATA[i], OUTPUT);
    for(int i=0; i<2; i++)  pinMode(FND_DIGIT[i], OUTPUT);
    
    pinMode(pinGnd, OUTPUT);
    pinMode(pinVcc, OUTPUT);
    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);
    pinMode(pinSwitch, INPUT_PULLUP);
    digitalWrite(pinGnd, LOW);
    digitalWrite(pinVcc, HIGH);

    // 인터럽트 설정
    attachPCINT(digitalPinToPCINT(pinSwitch), pinSwitch_Pressed, RISING);

    Timer1.initialize(5000);
    Timer1.attachInterrupt(timer1_isr);
}

void loop() {
    // put your main code here, to run repeatedly:
    int x = map(analogRead(pinX), 505-510, 505+510, -5, 5);  // -5:좌, 5:우측
    // int y = map(analogRead(pinY), 496-510, 496+510, 5, -5);  // -5:위, 5:아래

    if(x >= 4){         // 우측이면
        if(cnt >= 99) cnt = 99;
        else cnt++;
        delay(100);
    }
    else if(x <= -4){    // 좌측이면
        if(cnt <= 0) cnt = 0;
        else cnt--;
        delay(100);
    }
    //FND6_OUTPUT(cnt);
}

// ---------------------------- 사용자 함수 ----------------------------------
void FND_OUTPUT(int num)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(FND_DATA[i], FND_VALUE[num] & (0x01<<i));
  }
}

void FND_SEL_OUTPUT(int sel, int num)   // (출력할 위치, 출력할 숫자값)
{
  FND_OUTPUT(num);
  for(int i=0; i<2; i++)  
    digitalWrite(FND_DIGIT[i], FND_DIGIT_VAL[sel-1] & (0x01<<i));
  delay(1);
}

void FND6_OUTPUT(uint32_t num)
{
  uint32_t num_tbl[2] = {};

  num_tbl[0] = (num%100) / 10;
  num_tbl[1] = num%10;

  for(int i=0; i<2; i++)
  {
    FND_SEL_OUTPUT(i+1, num_tbl[i]);
  }
}
