const int SW1 = 2, SW2 = 3;
const int LED1 = 10, LED2 = 11;
int flag_led1 = 0, flag_led2 = 0;   // 0:OFF, 1:ON

unsigned long t1_prev = 0;
const unsigned long t1_delay = 300;

unsigned long t2_prev = 0;
const unsigned long t2_delay = 500;

// 사용자 함수
void sw1_Pressed(){
  // LED에 상태값 변경
  if(flag_led1 == 0){
    // 점멸
    flag_led1 = 1;
  }
  else{
    // OFF
    flag_led1 = 0;
  }
}

void sw2_Pressed(){
  // LED에 상태값 변경
  if(flag_led2 == 0){
    // 점멸
    flag_led2 = 1;
  }
  else{
    // OFF
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

  digitalWrite(LED1, LOW);    // LED 상태 초기화
  digitalWrite(LED2, LOW);    // LED 상태 초기화

  // 인터럽트 설정
  attachInterrupt(digitalPinToInterrupt(SW1), sw1_Pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(SW2), sw2_Pressed, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  // LED의 상태값에 따른 동작 구현
  unsigned long t1_now = millis();
  if(t1_now-t1_prev >= t1_delay){
    t1_prev = t1_now;
    
    if(flag_led1 == 1){   // 점멸
      digitalWrite(LED1, !digitalRead(LED1));
    }else{
      digitalWrite(LED1, LOW);
    }  
  }
  
  unsigned long t2_now = millis();
  if(t2_now-t2_prev >= t2_delay){
    t2_prev = t2_now;
    
    if(flag_led2 == 1){   // 점멸
      digitalWrite(LED2, !digitalRead(LED2));
    }else{
      digitalWrite(LED2, LOW);
    }  
  }
  
}
