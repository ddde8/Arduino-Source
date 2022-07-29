int LED0 = 2;

void setup(){
    Serial.begin(115200);
    pinMode(LED0, OUTPUT);
}

int rev_num = 0;
void loop(){
    rev_num = Serial.available();
    if(rev_num != 0){ // 수신된 데이터의 갯수
        // 데이터가 입력 됐을 때
        char userInput = Serial.read();     // 수신된 데이터 1바이트를 읽어서 리턴
        Serial.print(userInput);

        if(userInput == 'n'){
            digitalWrite(LED0, HIGH);
        }
        else if(userInput == 'f'){
            digitalWrite(LED0, LOW);
        }
    }
}