#include "SoftwareSerial.h"
#include "PinChangeInterrupt.h"
#include "TimerOne.h"

const uint8_t pinGnd = A0;
const uint8_t pinVcc = A1;
const uint8_t pinX = A2;
const uint8_t pinY = A3;
const uint8_t pinSwitch = A4;
int cnt = 0;

SoftwareSerial mySerial = SoftwareSerial(2,3);    // (Rx, Tx)

void setup(){
    Serial.begin(9600);
    mySerial.begin(9600);

    Serial.println("--- test ---");

    pinMode(pinGnd, OUTPUT);
    pinMode(pinVcc, OUTPUT);
    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);
    pinMode(pinSwitch, INPUT_PULLUP);
    digitalWrite(pinGnd, LOW);
    digitalWrite(pinVcc, HIGH);
}

void loop(){
    int x = map(analogRead(pinX), 505-510, 505+510, -5, 5);  // -5:좌, 5:우측
    // int y = map(analogRead(pinY), 496-510, 496+510, 5, -5);  // -5:위, 5:아래

    if(x >= 4){         // 우측이면
        if(cnt >= 99) cnt = 99;
        else cnt++;
        delay(100);
    }
    else if(x <= -4){    // 좌측이면
        if(cnt <= 0) cnt = 0;
        else cnt--;
        delay(100);
    }

    mySerial.println(cnt);
    Serial.println(cnt);
    delay(1000);
}