#include "SoftwareSerial.h"

SoftwareSerial mySerial = SoftwareSerial(A2,A3);    // (Rx, Tx)

void setup(){
    Serial.begin(115200);
    mySerial.begin(9600);
}

void loop(){
    if(Serial.available()){
        char userInput = Serial.read();     // 수신된 데이터 1바이트를 읽어서 리턴
        mySerial.print(userInput);
    }
    if(mySerial.available()){
        char userInput = mySerial.read();     // 수신된 데이터 1바이트를 읽어서 리턴
        Serial.print(userInput);
    }

}