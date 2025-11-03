int led_pin[4] = {4, 5, 6, 7};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<4; i++){
    pinMode(led_pin[i], OUTPUT);
  }
}

void loop() {
  for(int i =0; i<4; i++){
    digitalWrite(led_pin[i], HIGH);
    delay(1000);
  }
  for(int i =0; i<4; i++){
    digitalWrite(led_pin[i], LOW);
    delay(1000);
  }
}
