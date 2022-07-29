#include <Servo.h>

const int SERVO = 10;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO,500,2500); // us
  servo.write(0);
  delay(1000);

  for(int angle=0; angle<=180; angle++){
    servo.write(angle);
    delay(30);
  }
  servo.detach();
}

void loop() {
  // put your main code here, to run repeatedly:

}
