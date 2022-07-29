const int LED = 13;
int flag_led = 0;     // OFF

// 사용자 함수
void serialEvent(){
  char userInput = Serial.read();
  Serial.print(userInput);

//  // LED ctrl
//  if(userInput == 'l'){
//    if(flag_led == 0){
//      digitalWrite(LED, HIGH);
//      flag_led = 1;
//    }else{
//      digitalWrite(LED, LOW);
//      flag_led = 0;
//    }
//  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);   // LED 초기화
}

void loop() {
  // put your main code here, to run repeatedly:

}
