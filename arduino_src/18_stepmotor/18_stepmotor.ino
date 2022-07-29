#define time_val  10

const int IN[4] = {8,9,10,11};  // A,nA,B,nb
const int step_val_1[4] = {0x01,0x02,0x04,0x08};
//const int step_val_1_2[8] = {0x01,0x03,0x02,0x06,0x04,0x0C,0x08,0x09};
const int step_val_2[4] = {0x05, 0x06, 0x0A, 0x09};
int i = 0, j = 0;
int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for(i=0; i<4; i++){
    pinMode(IN[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while(cnt<2048){
    for(i=0; i<4; i++){
      for(j=0; j<4; j++){
        digitalWrite(IN[j], step_val_2[i] & 0x01<<j);
      }
      cnt++;
      delay(time_val);
    }
  }
  Serial.println(cnt);
}
