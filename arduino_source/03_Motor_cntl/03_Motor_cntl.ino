int DC_P = 5;
int DC_N = 4;
int DC_PWM = 3;

void MOTOR_init(int P, int N, int PWM){
  pinMode(P, OUTPUT);
  pinMode(N, OUTPUT);
  pinMode(PWM, OUTPUT);
}

void MOTOR_mode(int mode, int P, int N, int PWM){  // 0:CW, 1:STOP, 2:CCW, 3:BREAK
  if (mode == 0)
  {
    // CW
    digitalWrite(P, LOW);    digitalWrite(N, HIGH);    digitalWrite(PWM, HIGH);
  }
  else if ( mode == 1)
  {
    // STOP
    digitalWrite(P, LOW);    digitalWrite(N, LOW);    digitalWrite(PWM, LOW);
  }
  else if ( mode == 12)
  {
    // CCW
    digitalWrite(P, HIGH);    digitalWrite(N, LOW);    digitalWrite(PWM, HIGH);
  }
  else if ( mode == 3)
  {
    // BREAK
    digitalWrite(P, HIGH);    digitalWrite(N, HIGH);    digitalWrite(PWM, HIGH);
  }
}    

void setup() {
  // put your setup code here, to run once:
  MOTOR_init(DC_P, DC_N, DC_PWM);

  // STOP
  MOTOR_mode(1, DC_P, DC_N, DC_PWM);
}

void loop() {
  // put your main code here, to run repeatedly:
  // CW
  MOTOR_mode(0, DC_P, DC_N, DC_PWM);  delay(1000);

  // STOP
  MOTOR_mode(1, DC_P, DC_N, DC_PWM);  delay(1000);

  // CCW
  MOTOR_mode(2, DC_P, DC_N, DC_PWM);  delay(1000);

  // BREAK
  MOTOR_mode(3, DC_P, DC_N, DC_PWM);  delay(1000);
  
}
