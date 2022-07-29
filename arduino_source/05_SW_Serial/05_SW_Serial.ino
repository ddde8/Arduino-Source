int SW_PIN[4] = {13,12,11,10};

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);   // 시리얼 통신을 사용하도록하는 함수

    for(int i=0; i<4; i++){
        pinMode(SW_PIN[i], INPUT);
    }
}

void loop() {
    // put your main code here, to run repeatedly:
    for(int i=0; i<4; i++){
        if(digitalRead(SW_PIN[i])){
            // 입력이 1일때
            Serial.print(SW_PIN[i]);
            Serial.print("#");
            Serial.println("Switch Pushed");
            delay(500);
        }
    }
}