                //  a, b, c, d, e, f, g, dp
int FND_DATA[8] = {13,12,11,10, 9, 8, 7, 6};
int FND_DIGIT[6] = {A0,A1,A2,A3,A4,A5};
int SW0 = 2;
unsigned char FND_VALUE[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                               0x7F,0x6F,0x5F,0x7C,0x58,0x5E,0x79,0x71};
unsigned char FND_DIGIT_VAL[6] = {0x3E,0x3D,0x3B,0x37,0x2F,0x1F};
                                //  0b00111110
                                //  0b00111101
                                //  0b00111011
                                //  0b00110111
                                //  0b00101111
                                //  0b00011111

int cnt = 0;

// 사용자 함수
// ISR(Interrupt Service Routine), IRQHandler
void sw0_Pressed(){
  static int isr_cnt = 0;
  isr_cnt++;
  Serial.println(isr_cnt);
  cnt++;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for(int i=0; i<8; i++)  pinMode(FND_DATA[i], OUTPUT);
  for(int i=0; i<6; i++)  pinMode(FND_DIGIT[i], OUTPUT);
  pinMode(SW0, INPUT);
  // 인터럽트 설정
  attachInterrupt(digitalPinToInterrupt(SW0), sw0_Pressed, RISING);

}

void loop() {
  // put your main code here, to run repeatedly:
  FND6_OUTPUT(cnt);
}

// ---------------------------- 사용자 함수 ----------------------------------
void FND_OUTPUT(int num)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(FND_DATA[i], FND_VALUE[num] & (0x01<<i));
  }
}

void FND_SEL_OUTPUT(int sel, int num)   // (출력할 위치, 출력할 숫자값)
{
  FND_OUTPUT(num);
  for(int i=0; i<6; i++)  
    digitalWrite(FND_DIGIT[i], FND_DIGIT_VAL[sel-1] & (0x01<<i));
  delay(1);
}

void FND6_OUTPUT(uint32_t num)
{
  uint32_t num_tbl[6] = {};

  num_tbl[0] = num / 100000;
  num_tbl[1] = (num%100000) / 10000;
  num_tbl[2] = (num%10000) / 1000;
  num_tbl[3] = (num%1000) / 100;
  num_tbl[4] = (num%100) / 10;
  num_tbl[5] = num%10;

  for(int i=0; i<6; i++)
  {
    FND_SEL_OUTPUT(i+1, num_tbl[i]);
  }
}
