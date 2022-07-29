#include <Servo.h>

const int SERVO = 10;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO,500,2500); // us
  servo.write(0);
  delay(1000);  
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(map(analogRead(A0),0,1023,0,180));
}
