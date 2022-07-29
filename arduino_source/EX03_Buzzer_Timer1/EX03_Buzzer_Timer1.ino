// 타이머1을 이용하여 음계를 출력하세요.
// Buzzer : 10 또는 9번에 연결
// SW0 : 음계를 올리는거 5옥타브도에서 6옥타브도까지 증가
// SW1 : 음계를 내리는거 5옥타브도에서 6옥타브도까지 증가
// SW2 : 시작, 정지
#include <TimerOne.h>   // timer1, 9번, 10번핀만 사용가능
#include "PinChangeInterrupt.h"

const uint8_t BUZZER = 10;
const uint8_t SW0 = 13;
const uint8_t SW1 = 12;
const uint8_t SW2 = 11;

int flag_buzzer = 0;
int cnt = 0;
int aPitchData[8] = {523,587,659,698,784,880,988,1046};

void setup(){
    Serial.begin(115200);
    pinMode(SW0, INPUT);
    attachPCINT(digitalPinToPCINT(SW0), sw0_Pressed, RISING);
    pinMode(SW1, INPUT);
    attachPCINT(digitalPinToPCINT(SW1), sw1_Pressed, RISING);
    pinMode(SW2, INPUT);
    attachPCINT(digitalPinToPCINT(SW2), sw2_Pressed, RISING);

    Timer1.initialize();    // 타이머1을 초기화, 디폴트 주기 1s
}

void loop(){

}

void sw0_Pressed(){
    Serial.println("SW0 pushed..!!");
    Timer1.pwm(BUZZER, 1000, 1000000/aPitchData[cnt]);
    if(cnt >= 7)
        cnt = 7;
    else
        cnt++;
    flag_buzzer = 1;
}

void sw1_Pressed(){
    Serial.println("SW1 pushed..!!");
    Timer1.pwm(BUZZER, 1000, 1000000/aPitchData[cnt]);
    if(cnt <= 0)
        cnt = 0;
    else
        cnt--;  
    flag_buzzer = 1; 
}

void sw2_Pressed(){
    Serial.println("SW2 pushed..!!");
    cnt = 0;
    if(flag_buzzer == 0){
        Timer1.start();
        flag_buzzer = 1;
    }
    else{
        Timer1.stop();
        flag_buzzer = 0;
    }
}

