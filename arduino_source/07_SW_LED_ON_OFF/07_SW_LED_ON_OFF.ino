// SW0을 이용하여 LED0번을 제어하시오.
// SW0을 누르면, LED0이 켜져있으면 끄고, 꺼져있으면 켜고
int SW0_PIN = 13;
int LED0_PIN = 9;
int flag_led0 = 0;  // 0:OFF, 1:ON

void setup(){
    pinMode(SW0_PIN, INPUT);
    pinMode(LED0_PIN, OUTPUT);
    if(flag_led0 == 0)  digitalWrite(LED0_PIN, LOW);
    else digitalWrite(LED0_PIN, HIGH);
}

void loop(){
    if(digitalRead(SW0_PIN) == HIGH)
    {
        // 눌렸을때
        if (flag_led0 == 0){
            digitalWrite(LED0_PIN, HIGH);
            flag_led0 = 1;
        }
        else{
            digitalWrite(LED0_PIN, LOW);
            flag_led0 = 0;
        }
        delay(500);
    }
}