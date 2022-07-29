int LED0 = 2;

// 사용자함수
// Serial Receive ISR
void serialEvent(){
    // 데이터가 입력 됐을 때
    String userInput = Serial.readString();     // 수신된 데이터 1바이트를 읽어서 리턴
    Serial.print(userInput);

    if(userInput == "LED0_ON"){
        digitalWrite(LED0, HIGH);
    }
    else if(userInput == "LED0_OFF"){
        digitalWrite(LED0, LOW);
    }
}

void setup(){
    Serial.begin(115200);
    pinMode(LED0, OUTPUT);
}

void loop(){
    
}