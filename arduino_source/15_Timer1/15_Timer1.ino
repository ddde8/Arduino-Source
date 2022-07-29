#include <TimerOne.h>   // timer1, 9번, 10번핀만 사용가능

const uint8_t LED = 10;

void setup(){
    Timer1.initialize();    // 타이머1을 초기화, 디폴트 주기 1s
    Timer1.pwm(LED, 0);     // 0~1023

    Timer1.setPeriod(1000);     // 주기 변경 함수, 1us
    Timer1.setPwmDuty(LED, 511);    // 듀티비 변경
}

void loop(){

}
