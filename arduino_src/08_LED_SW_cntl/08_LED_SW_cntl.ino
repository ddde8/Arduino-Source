// 스위치를 눌러서 LED를 제어하라.
// 누르면 켜지고, 떼면 꺼지고.
const int LED1 = 2, LED2 = 3;
const int SW1 = 10, SW2 = 9;
int flag_led1 = 0, flag_led2 = 0;   // 0:OFF, 1:ON
int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  
  digitalWrite(LED1, HIGH);    // LED 상태 초기화
  digitalWrite(LED2, HIGH);    // LED 상태 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(SW1) == HIGH){  // 버튼을 눌렀을 때(레벨체크)
    if(flag_led1 == 0){
      digitalWrite(LED1, LOW);   // LED ON
      flag_led1 = 1;
    }
    else{
      digitalWrite(LED1, HIGH);   // LED OFF
      flag_led1 = 0;
    }
    //delay(300);
    for(int i=0; i<400000000; i++);
  }

  if(digitalRead(SW2) == HIGH){  // 버튼을 눌렀을 때(레벨체크)
    if(flag_led2 == 0){
      digitalWrite(LED2, LOW);   // LED ON
      flag_led2 = 1;
    }
    else{
      digitalWrite(LED2, HIGH);   // LED OFF
      flag_led2 = 0;
    }
    //delay(300);
    for(int i=0; i<400000000; i++);
  }
}
