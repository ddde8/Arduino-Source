
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button_a = digitalRead(8);
  int button_b = digitalRead(9);

  Serial.print("a = ");
  Serial.print(button_a);
  Serial.print(", b = ");
  Serial.println(button_b);
  
  if(button_a == 1){
    digitalWrite(4, button_a);
    if(button_a == 0){ // led가 켜져있는 상태에서 버튼을 누르면 끈다.
      digitalWrite(4, button_a);
    }
  }

  digitalWrite(5, button_b);
  delay(50);


}
