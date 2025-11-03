int buzzer_pin = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzer_pin, HIGH);
  delayMicroseconds(1900);
  digitalWrite(buzzer_pin, LOW);
  delayMicroseconds(1900);
  digitalWrite(buzzer_pin, HIGH);
  delayMicroseconds(1700);
  digitalWrite(buzzer_pin, LOW);
  delayMicroseconds(1700);
}
