const int LED1 = 13;
const int LED2 = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);     // 핀모드 설정(핀번호, 입출력설정)
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int t_high=0; t_high<=1000; t_high++){
    digitalWrite(LED2, HIGH);  // 핀 출력값 설정(핀번호, 출력값)
    delayMicroseconds(t_high);
    digitalWrite(LED2, LOW);  // 핀 출력값 설정(핀번호, 출력값)
    delayMicroseconds(1000-t_high);
  }
 
}
