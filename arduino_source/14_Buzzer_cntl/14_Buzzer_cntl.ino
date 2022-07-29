const uint8_t pinGnd = 5;
const uint8_t pinBuzzer = 3;

int aPitchData[8] = {523,587,659,698,784,880,988,1046};

void setup(){
    pinMode(pinGnd, OUTPUT);
    pinMode(pinBuzzer, OUTPUT);
    digitalWrite(pinGnd, LOW);
}

void loop(){
    for(int i=0; i<8; i++){
        tone(pinBuzzer, aPitchData[i]);
        delay(1000);
        noTone(pinBuzzer);
    }
}