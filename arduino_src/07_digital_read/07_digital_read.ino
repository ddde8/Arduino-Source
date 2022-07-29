const int digitalPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(digitalPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int digitalValue = digitalRead(digitalPin);
  Serial.println(digitalValue);
}
