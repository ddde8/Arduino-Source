#include <TimerOne.h> // timer1, 9번 10번핀만 사용가능

const int LED = 10;
const int VR = A0;
int pre_value = 0, cur_value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Timer1.initialize(1000);    // 주기는 1ms
  Timer1.pwm(LED, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  cur_value = analogRead(VR);
  
  if(pre_value != cur_value){ // 값이 바뀌면 수정
    Timer1.setPwmDuty(LED, cur_value);
    pre_value = cur_value;
    Serial.println(cur_value);
  }
}
