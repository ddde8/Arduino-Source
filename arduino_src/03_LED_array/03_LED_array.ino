int i = 0, j = 0;
int cnt = 0;
const int LED[4] = {13,12,11,10};

void setup() {
  // put your setup code here, to run once:
  for(i=0; i<4; i++){   // (초기값,끝값,증가값)
    pinMode(LED[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0; i<8; i++){
    digitalWrite(LED[i], (~cnt)&(0x01<<i));
  }
  cnt++;
  delay(1000);
}
