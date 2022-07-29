// SW0을 이용하여 LED0번을 제어하시오.
// SW0을 누르면, LED0이 켜져있으면 끄고, 꺼져있으면 켜고
int SW_PIN[4] = {13,12,11,10};
int LED_PIN[4] = {9,8,7,6};
int flag_led[4] = {0,0,0,0};  // 0:OFF, 1:ON

int pre_sw[4] = {0,0,0,0}, cur_sw[4] = {0,0,0,0};

void setup(){
    for(int i=0; i<4; i++){
        pinMode(SW_PIN[i], INPUT);
        pinMode(LED_PIN[i], OUTPUT);
        if(flag_led[i] == 0)  digitalWrite(LED_PIN[i], LOW);
        else digitalWrite(LED_PIN[i], HIGH);
    }
}

void loop(){
    for(int i=0; i<4; i++){
        cur_sw[i] = digitalRead(SW_PIN[i]);     // 현재값 갱신

        if(pre_sw[i] == LOW && cur_sw[i] == HIGH)   // 상승엣지
        {
            // 눌렸을때
            if (flag_led[i] == 0){
                digitalWrite(LED_PIN[i], HIGH);
                flag_led[i] = 1;
            }
            else{
                digitalWrite(LED_PIN[i], LOW);
                flag_led[i] = 0;
            }
        }

        pre_sw[i] = cur_sw[i];          // 이전값 갱신
    }
}