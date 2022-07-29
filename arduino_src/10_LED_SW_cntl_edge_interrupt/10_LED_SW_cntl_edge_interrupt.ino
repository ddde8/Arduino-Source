// 스위치를 눌러서 LED를 제어하라.
// 누르면 켜지고, 떼면 꺼지고.
const int LED1 = 10, LED2 = 9;
const int SW1 = 2, SW2 = 3;
int flag_led1 = 0, flag_led2 = 0;   // 0:OFF, 1:ON
int cnt = 0;

// 사용자 함수
void sw1_Pressed(){
  if(flag_led1 == 0){
    digitalWrite(LED1, LOW);   // LED ON
    flag_led1 = 1;
  }
  else{
    digitalWrite(LED1, HIGH);   // LED OFF
    flag_led1 = 0;
  }
}

void sw2_Pressed(){
  if(flag_led2 == 0){
    digitalWrite(LED2, LOW);   // LED ON
    flag_led2 = 1;
  }
  else{
    digitalWrite(LED2, HIGH);   // LED OFF
    flag_led2 = 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  
  digitalWrite(LED1, HIGH);    // LED 상태 초기화
  digitalWrite(LED2, HIGH);    // LED 상태 초기화

  // 인터럽트 설정
  attachInterrupt(digitalPinToInterrupt(SW1), sw1_Pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(SW2), sw2_Pressed, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

}
