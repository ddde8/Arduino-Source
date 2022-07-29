// 스위치를 눌러서 LED를 제어하라.
// 누르면 켜지고, 떼면 꺼지고.
const int LED1 = 2, LED2 = 3;
const int SW1 = 10, SW2 = 9;
int flag_led1 = 0, flag_led2 = 0;   // 0:OFF, 1:ON
int cnt = 0;
int pre_sw1=0, cur_sw1=0;
int pre_sw2=0, cur_sw2=0;

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
  cur_sw1 = digitalRead(SW1);
  cur_sw2 = digitalRead(SW2);
  
  if(pre_sw1==LOW && cur_sw1==HIGH){  // 버튼을 눌렀을 때(상승엣지 체크)
    if(flag_led1 == 0){
      digitalWrite(LED1, LOW);   // LED ON
      flag_led1 = 1;
    }
    else{
      digitalWrite(LED1, HIGH);   // LED OFF
      flag_led1 = 0;
    }
  }

  if(pre_sw2==HIGH && cur_sw2==LOW){  // 버튼을 눌렀을 때(하강엣지체크)
    if(flag_led2 == 0){
      digitalWrite(LED2, LOW);   // LED ON
      flag_led2 = 1;
    }
    else{
      digitalWrite(LED2, HIGH);   // LED OFF
      flag_led2 = 0;
    }
  }

  pre_sw1 = cur_sw1;    // 현재값을 이전값에 대입
  pre_sw2 = cur_sw2;    // 현재값을 이전값에 대입
}
