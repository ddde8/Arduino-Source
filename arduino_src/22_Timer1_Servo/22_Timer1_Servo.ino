#include <TimerOne.h>

const int SERVO = 9;
const int VR = A0;

const int SERVO_PERIOD = 20000;
const float SERVO_MINDUTY = (1024.0/20.0) * 0.5;  // 0.5ms, 0도
const float SERVO_MAXDUTY = (1024.0/20.0) * 2.5;  // 2.5ms, 180도

float angle = SERVO_MINDUTY;

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(SERVO_PERIOD);  // 20s
  Timer1.pwm(SERVO, 0);

  Timer1.setPwmDuty(SERVO, angle);
  delay(1000);

  //Timer1.disablePwm(SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(VR);
  angle = map(value,0,1023,SERVO_MINDUTY,SERVO_MAXDUTY);
  Timer1.setPwmDuty(SERVO, angle);
}
