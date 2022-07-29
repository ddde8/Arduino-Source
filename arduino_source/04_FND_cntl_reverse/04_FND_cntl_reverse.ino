                //  a, b, c, d, e, f, g, dp
int FND_DATA[8] = {13,12,11,10, 9, 8, 7, 6};
int FND_DIGIT[6] = {A0,A1,A2,A3,A4,A5};
unsigned char FND_VALUE[16] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,
                               0xFE,0xF6,0xFA,0x3E,0x9C,0x7A,0x9E,0x8E};
void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<8; i++)  pinMode(FND_DATA[i], OUTPUT);
  for(int i=0; i<6; i++)  pinMode(FND_DIGIT[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 0~F
  for(int val=0; val<16; val++)
  {
    for(int i=0; i<8; i++)
    {
      digitalWrite(FND_DATA[i], FND_VALUE[val] & (0x80>>i));
    }
    delay(1000);
  }
}
