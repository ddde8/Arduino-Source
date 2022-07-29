// SW0을 이용하여 LED0번을 제어하시오.
// SW0을 누르면, LED0이 꺼져있으면 50ms마다 점멸하고, 점멸하고 있으면, 끄는 프로그램
#define NUMBER  2
int SW_PIN[4] = {13,12,11,10};
int LED_PIN[4] = {9,8,7,6};
int flag_led[4] = {0,0,0,0};  // 0:OFF, 1:ON

int pre_sw[4] = {0,0,0,0}, cur_sw[4] = {0,0,0,0};

void setup(){
    for(int i=0; i<NUMBER; i++){
        pinMode(SW_PIN[i], INPUT);
        pinMode(LED_PIN[i], OUTPUT);
        if(flag_led[i] == 0)  digitalWrite(LED_PIN[i], LOW);
        else digitalWrite(LED_PIN[i], HIGH);
    }
}

void loop(){
    for(int i=0; i<NUMBER; i++){
        cur_sw[i] = digitalRead(SW_PIN[i]);     // 현재값 갱신

        if(pre_sw[i] == LOW && cur_sw[i] == HIGH)   // 상승엣지
        {
            // LED의 상태값 변경
            if (flag_led[i] == 0){
                flag_led[i] = 1;
            }
            else{
                flag_led[i] = 0;
            }
        }

        // 상태값에 따른 동작 구현
        if(flag_led[i] == 0)
        {
            digitalWrite(LED_PIN[i], LOW);
        }
        else{
            digitalWrite(LED_PIN[i], HIGH);
            delay(500);
            digitalWrite(LED_PIN[i], LOW);
            delay(500);
        }

        pre_sw[i] = cur_sw[i];          // 이전값 갱신
    }
}