                 // a, b, c,  d, e, f, g, dp
const int FND[8] = {13,12,11,10, 9, 8, 7, 6};
int i = 0;
int cnt = 0;
const unsigned char FND_DATA[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                                    0x7F,0x6F,0x5F,0x7C,0x58,0x5E,0x79,0x71};

void setup() {
  // put your setup code here, to run once:
  for(i=0; i<8; i++){   // (초기값,끝값,증가값)
    pinMode(FND[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  FND_OUTPUT(cnt);

  cnt++;
  if(cnt==16) cnt = 0;
  
  delay(500);
}

// 사용자 함수
void FND_OUTPUT(int num){
  for(i=0; i<8; i++){
    digitalWrite(FND[i], FND_DATA[num]&(0x01<<i));
  }
}
