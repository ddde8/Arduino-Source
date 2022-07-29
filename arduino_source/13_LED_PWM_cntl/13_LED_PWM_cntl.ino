const uint8_t LED0 = 10;
const uint8_t LED1 = 11;

void setup(){
    analogWrite(LED0, 10);  // (핀번호, 듀티비), 듀티비(0~255)
    analogWrite(LED1, 90);  // (핀번호, 듀티비)
}

void loop(){
    for(int i=0; i<255; i++){
        analogWrite(LED0, i);
        delay(10);
    }
}