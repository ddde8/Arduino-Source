const int LED = 10;
int i = 0;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0; i<=255; i++){
    analogWrite(LED, i);
    delay(10);
  }
  
}
