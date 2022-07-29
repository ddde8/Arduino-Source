#include <TimerOne.h> // timer1, 9번 10번핀만 사용가능

const int LED = 10;

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();    // 디폴트 주기는 1s
  Timer1.pwm(LED, 0);

  Timer1.setPeriod(1000);    // 100000us = 100ms, 10Hz
  Timer1.setPwmDuty(LED, 1000);  // dutyrate = 50%, 0~1023
}

void loop() {
  // put your main code here, to run repeatedly:

}
