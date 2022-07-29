#include <LiquidCrystal.h>
                //rs,rw, e,      D0~D7
LiquidCrystal lcd(13,12,11,10,9,8,7,6,5,4,3);

// 사용자함수
// Serial Receive ISR
void serialEvent(){
    // 데이터가 입력 됐을 때
    char userInput = Serial.read();     // 수신된 데이터 1바이트를 읽어서 리턴
    Serial.print(userInput);
    
    if(userInput != '\n' || userInput != '\r')
        lcd.print(userInput);
}

void setup(){
    Serial.begin(115200);

    lcd.begin(16,2);
    lcd.print(" - Serial Test -");
    lcd.setCursor(0,1);
}

void loop(){

}