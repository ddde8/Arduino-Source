int Analog_pin = A5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float val = analogRead(Analog_pin);
  float res = (5.0/1024.0)*val;
  Serial.print(res);
  Serial.println(" V");
  delay(500);
}
