const uint8_t pinGnd = A0;
const uint8_t pinVcc = A1;
const uint8_t pinX = A2;
const uint8_t pinY = A3;
const uint8_t pinSwitch = A4;

void setup(){
    Serial.begin(115200);

    pinMode(pinGnd, OUTPUT);
    pinMode(pinVcc, OUTPUT);
    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);
    pinMode(pinSwitch, INPUT_PULLUP);   // 내부 풀업저항을 사용

    digitalWrite(pinGnd, LOW);
    digitalWrite(pinVcc, HIGH);
}

void loop(){
    int x_val = analogRead(pinX);
    int y_val = analogRead(pinY);
    int x = map(x_val, 505-510, 505+510, -5, 5);  // -5:좌, 5:우측
    int y = map(y_val, 496-510, 496+510, 5, -5);  // -5:위, 5:아래

    Serial.print("x_val : ");
    Serial.print(x_val);
    Serial.print("\tX : ");
    Serial.print(x);
    Serial.print(" \ty_val : ");
    Serial.print(y_val);
    Serial.print("\tY : ");
    Serial.print(y);
    Serial.print("\tSW : ");

    if(digitalRead(pinSwitch) == LOW){
        // 버튼이 눌렸을 때
        Serial.println("ON");
    }
    else{
        Serial.println("OFF");
    }

    delay(1000);
}