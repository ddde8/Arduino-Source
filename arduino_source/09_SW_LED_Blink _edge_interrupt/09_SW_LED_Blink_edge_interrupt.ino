int SW0 = 2, SW1 = 3;
int LED0 = 9, LED1 = 8;
int flag_led0 = 0, flag_led1 = 0;

// 사용자 함수
// ISR(Interrupt Service Routine), IRQHandler
void sw0_Pressed(){
    Serial.println("SW0번이 눌렸습니다.");
    if(flag_led0 == 0){
        flag_led0 = 1;
    }
    else{
        flag_led0 = 0;
    }
}
// 
void sw1_Pressed(){
    Serial.println("SW1번이 눌렸습니다.");
    if(flag_led1 == 0){
        flag_led1 = 1;
    }
    else{
        flag_led1 = 0;
    }
}

void setup(){
    Serial.begin(115200);

    pinMode(SW0, INPUT);
    pinMode(SW1, INPUT);
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);

    // 인터럽트 설정
    attachInterrupt(digitalPinToInterrupt(SW0), sw0_Pressed, RISING);
    attachInterrupt(digitalPinToInterrupt(SW1), sw1_Pressed, RISING);
}

void loop(){
    // 상태값에 따른 동작 구현
    if(flag_led0 == 0)
    {
        digitalWrite(LED0, LOW);
    }
    else{
        digitalWrite(LED0, HIGH);
        delay(500);
        digitalWrite(LED0, LOW);
        delay(500);
    }

    if(flag_led1 == 0)
    {
        digitalWrite(LED1, LOW);
    }
    else{
        digitalWrite(LED1, HIGH);
        delay(500);
        digitalWrite(LED1, LOW);
        delay(500);
    }
}

