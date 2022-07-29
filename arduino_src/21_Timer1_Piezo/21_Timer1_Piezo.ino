#include <TimerOne.h>

const int BUZZER = 9;
const int VR = A0;
const int melody[] = {0,262,294,330,349,393,440,494,523,};

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  Timer1.pwm(BUZZER, 0);

  Timer1.setPwmDuty(BUZZER, 512);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(VR);
  int i = map(value,0,1023,0,8);
  Timer1.setPeriod(1000000/melody[i]);
}
