#include <LiquidCrystal.h>
#include "PinChangeInterrupt.h"

int SW0 = A0;
int SW1 = A1;
                //rs,rw, e,      D0~D7
LiquidCrystal lcd(13,12,11,10,9,8,7,6,5,4,3);

// 사용자 함수
// ISR(Interrupt Service Routine), IRQHandler
void sw0_Pressed(){
  lcd.setCursor(0,1);
  lcd.print("SW0 Pushed..!!");
}

void sw1_Pressed(){
  lcd.setCursor(0,1);
  lcd.print("SW1 Pushed..!!");
}

void setup(){
    lcd.begin(16,2);
    lcd.print(" - Switch Test -");

    pinMode(SW0, INPUT);
    pinMode(SW1, INPUT);
    // 인터럽트 설정
    attachPCINT(digitalPinToPCINT(SW0), sw0_Pressed, RISING);
    attachPCINT(digitalPinToPCINT(SW1), sw1_Pressed, RISING);
}

void loop(){

}