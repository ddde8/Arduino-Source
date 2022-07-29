// SW0을 이용하여 LED0번을 제어하시오.
// SW0을 누르면, LED0 ON, 평상시 LED0 OFF

int SW_PIN[4] = {13,12,11,10};
int LED_PIN[4] = {9,8,7,6};

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);   // 시리얼 통신을 사용하도록하는 함수

    for(int i=0; i<4; i++){
        pinMode(SW_PIN[i], INPUT);
        pinMode(LED_PIN[i], OUTPUT);
    }
}

void loop() {
    // put your main code here, to run repeatedly:
    for(int i=0; i<4; i++){
        if(digitalRead(SW_PIN[i])){
            // 입력이 1일때
            digitalWrite(LED_PIN[i], HIGH);
        }
        else{
            // 입력이 0일때
            digitalWrite(LED_PIN[i], LOW);
        }
    }
}