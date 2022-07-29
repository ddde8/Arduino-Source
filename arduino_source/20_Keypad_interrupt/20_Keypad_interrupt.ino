#include "PinChangeInterrupt.h"

const uint8_t aPinRow[4] = {13,12,11,10};
const uint8_t aPinCol[4] = { 9, 8, 7, 6};
int row_val = 0;

void setup(){
    Serial.begin(115200);

    for(int i=0; i<4; i++){
        pinMode(aPinRow[i], OUTPUT);
        digitalWrite(aPinRow[i], LOW);
        pinMode(aPinCol[i], INPUT);
    }

    // 인터럽트 설정
    attachPCINT(digitalPinToPCINT(aPinCol[0]), col0_Pressed, RISING);
    attachPCINT(digitalPinToPCINT(aPinCol[1]), col1_Pressed, RISING);
    attachPCINT(digitalPinToPCINT(aPinCol[2]), col2_Pressed, RISING);
    attachPCINT(digitalPinToPCINT(aPinCol[3]), col3_Pressed, RISING);
}

void loop(){
    for(row_val=0; row_val<4; row_val++){
        digitalWrite(aPinRow[row_val], HIGH);
        delay(50);
        digitalWrite(aPinRow[row_val], LOW);
        delay(50);
    }
}

// 사용자 함수
// ISR(Interrupt Service Routine), IRQHandler
void col0_Pressed(){
    // col값 순서대로 읽기
    Serial.print((row_val*4) + 0, HEX);
    Serial.println(" KEY PUSH");
}
void col1_Pressed(){
    // col값 순서대로 읽기
    Serial.print((row_val*4) + 1, HEX);
    Serial.println(" KEY PUSH");
}
void col2_Pressed(){
    // col값 순서대로 읽기
    Serial.print((row_val*4) + 2, HEX);
    Serial.println(" KEY PUSH");
}
void col3_Pressed(){
    // col값 순서대로 읽기
    Serial.print((row_val*4) + 3, HEX);
    Serial.println(" KEY PUSH");
}