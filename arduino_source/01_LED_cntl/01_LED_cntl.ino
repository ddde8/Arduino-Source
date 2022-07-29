int LED0 = 13;
int LED1 = 12;
int LED2 = 11;
int LED3 = 10;
int LED4 = 9;
int LED5 = 8;
int LED6 = 7;
int LED7 = 6;
int LED[] = {LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7};
int len_LED = sizeof(LED) / sizeof(int);
int delay_val = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);   // 시리얼 통신을 사용하도록하는 함수 
  Serial.println(len_LED);

  for(int i=0; i<len_LED; i++)    // for(초기값;조건식;증감값)
  {
    pinMode(LED[i], OUTPUT);    // 원하는 핀을 입력으로 사용할지 출력으로 사용할지를 설정하는 함수
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<len_LED; i++) 
  {
    digitalWrite(LED[i], HIGH);
    delay(delay_val);
    digitalWrite(LED[i], LOW);
  }
  

  // for(int i=0; i<len_LED; i++)    // for(초기값;조건식;증감값)
  // {
  //   digitalWrite(LED[i], HIGH);
  // }
  // delay(1000);  // 1000ms
  // for(int i=0; i<len_LED; i++)    // for(초기값;조건식;증감값)
  // {
  //   digitalWrite(LED[i], LOW);
  // }
  // delay(1000);  // 1000ms
}
