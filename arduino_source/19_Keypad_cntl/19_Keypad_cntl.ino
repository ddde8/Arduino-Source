const uint8_t aPinRow[4] = {13,12,11,10};
const uint8_t aPinCol[4] = { 9, 8, 7, 6};

void setup(){
    Serial.begin(115200);

    for(int i=0; i<4; i++){
        pinMode(aPinRow[i], OUTPUT);
        digitalWrite(aPinRow[i], LOW);
        pinMode(aPinCol[i], INPUT);
    }
}

void loop(){
    for(int i=0; i<4; i++){
        digitalWrite(aPinRow[i], HIGH);
        // col값 순서대로 읽기
        for(int j=0; j<4; j++){
            if(digitalRead(aPinCol[j])){
                Serial.print((i*4) + j, HEX);
                Serial.println(" KEY PUSH");
            }         
        }
        digitalWrite(aPinRow[i], LOW);
        delay(100);
    }
}