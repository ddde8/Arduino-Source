// 스위치 세개를 이용해서 모터를 제어하시오.
// SW0 - mode 설정(CW, CCW), 듀티비는 50%로 시작
// SW1 - 모터의 속도 증가, 10%씩 증가
// SW2 - 모터의 속도 감소, 10%씩 감소
// SW3 - 모터 정지

#include "PinChangeInterrupt.h"

const uint8_t DC_P = 5;
const uint8_t DC_N = 4;
const uint8_t DC_PWM = 3;
const uint8_t SW0 = 13;
const uint8_t SW1 = 12;
const uint8_t SW2 = 11;
const uint8_t SW3 = 10;

uint8_t motor_state = 1;    // 0:CW, 1:STOP, 2:CCW, 3:BREAK
uint8_t dyty_rate = 0;

// 사용자 함수
void MOTOR_init(int P, int N, int PWM){
  pinMode(P, OUTPUT);
  pinMode(N, OUTPUT);

  MOTOR_mode(motor_state, 0);
}

void MOTOR_mode(int mode, int duty_rate){  // 0:CW, 1:STOP, 2:CCW, 3:BREAK
  if (mode == 0)
  {
    // CW
    digitalWrite(DC_P, LOW);    digitalWrite(DC_N, HIGH);    analogWrite(DC_PWM, duty_rate);
  }
  else if ( mode == 1)
  {
    // STOP
    digitalWrite(DC_P, LOW);    digitalWrite(DC_N, LOW);    analogWrite(DC_PWM, 0);
  }
  else if ( mode == 2)
  {
    // CCW
    digitalWrite(DC_P, HIGH);    digitalWrite(DC_N, LOW);    analogWrite(DC_PWM, duty_rate);
  }
  else if ( mode == 3)
  {
    // BREAK
    digitalWrite(DC_P, HIGH);    digitalWrite(DC_N, HIGH);    analogWrite(DC_PWM, duty_rate);
  }
}    

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  MOTOR_init(DC_P, DC_N, DC_PWM);
  
  pinMode(SW0, INPUT);
  attachPCINT(digitalPinToPCINT(SW0), sw0_Pressed, RISING);
  pinMode(SW1, INPUT);
  attachPCINT(digitalPinToPCINT(SW1), sw1_Pressed, RISING);
  pinMode(SW2, INPUT);
  attachPCINT(digitalPinToPCINT(SW2), sw2_Pressed, RISING);
  pinMode(SW3, INPUT);
  attachPCINT(digitalPinToPCINT(SW3), sw3_Pressed, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

// ISR(Interrupt Service Routine), IRQHandler
void sw0_Pressed(){
    Serial.println(motor_state);
    if(motor_state == 0)    // 0:CW, 1:STOP, 2:CCW, 3:BREAK
        motor_state = 2;
    else if(motor_state == 1)
        motor_state = 0;
    else if(motor_state == 2)
        motor_state = 0;

    dyty_rate = (255/10) * 5;
    MOTOR_mode(motor_state, dyty_rate);
}

void sw1_Pressed(){
    Serial.println(motor_state);
    dyty_rate += (255/10) * 1;
    MOTOR_mode(motor_state, dyty_rate);
}

void sw2_Pressed(){
    Serial.println(motor_state);
    dyty_rate -= (255/10) * 1;
    MOTOR_mode(motor_state, dyty_rate);
}

void sw3_Pressed(){
    Serial.println(motor_state);
    motor_state = 1;
    dyty_rate = 0;
    MOTOR_mode(motor_state, dyty_rate);
}
