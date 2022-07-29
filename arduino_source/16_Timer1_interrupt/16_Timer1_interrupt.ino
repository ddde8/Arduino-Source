#include "TimerOne.h"

void setup(){
    Serial.begin(115200);

    Timer1.initialize();
    Timer1.attachInterrupt(callback);   // 
}

void loop(){
    
}

// 사용자 함수
// Timer1 ISR
void callback(){
    Serial.println("test..!!");
}