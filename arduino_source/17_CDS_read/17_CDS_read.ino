#include <LiquidCrystal.h>

const uint8_t pinGnd = A2;
const uint8_t pinVcc = A1;
const uint8_t pinCds = A0;

                //rs,rw, e,      D0~D7
LiquidCrystal lcd(13,12,11,10,9,8,7,6,5,4,3);

void setup(){
    Serial.begin(115200);

    lcd.begin(16,2);

    pinMode(pinGnd, OUTPUT);
    pinMode(pinVcc, OUTPUT);
    pinMode(pinCds, INPUT);
    digitalWrite(pinGnd, LOW);
    digitalWrite(pinVcc, HIGH);
}

void loop(){
    int adcData = analogRead(pinCds);
    float volt = (5.0/1024.0) * adcData;
    Serial.print("CDS : ");
    Serial.print(adcData);
    Serial.print(", volt : ");
    Serial.print(volt, 5);
    Serial.println(" V");

    lcd.setCursor(0,0);
    lcd.print("CDS : ");
    lcd.print(adcData);
    lcd.setCursor(0,1);
    lcd.print("volt : ");
    lcd.print(volt);
    lcd.print(" V");
    delay(500);
}