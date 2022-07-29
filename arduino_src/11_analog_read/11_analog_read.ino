const int analogPin = A0;
const int LED = 10;
const int SW1 = 2, SW2 = 3;
int analogValue = 0;
int analogMin = 0, analogMAX = 0;

// 사용자 함수
void sw1_Pressed(){
  analogMin=255;
  for(int i=0; i<1000; i++){
    int tempValue = analogRead(analogPin);
    if(analogMin>tempValue){
      analogMin = tempValue;
    }
  }
}

void sw2_Pressed(){
  analogMAX=0;
  for(int i=0; i<1000; i++){
    int tempValue = analogRead(analogPin);
    if(analogMAX<tempValue){
      analogMAX = tempValue;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  
  // 인터럽트 설정
  attachInterrupt(digitalPinToInterrupt(SW1), sw1_Pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(SW2), sw2_Pressed, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(analogPin);
  analogWrite(LED, map(analogValue, analogMin, analogMAX, 0, 255));
  float volt = (5.0/1024.0) * analogValue;

  // ADC: 680, VOLT: 3.32 V
  Serial.println(analogValue);
  Serial.println(volt);
  delay(100);
}
