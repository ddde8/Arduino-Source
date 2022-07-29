// the setup function runs once when you press reset or power the board

unsigned char A = 0b10101101;       // 0b0000000010100101
unsigned char Mask = 0b00011000;    // 0x18
// unsigned char Unmask = 0b11100111;  // 0xE7

// 처음에 한번만 호출되는 함수
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  int val = 1000;
  Serial.println(String(val));

  String str_val = "1000";
  int data = str_val.toInt();

  Serial.println(data, DEC);
  

  // // A의 3번,4번비트를 1로 변경해서 출력하세요.
  // Serial.print("A|Mask = ");
  // Serial.println(A|Mask, BIN);

  // // A의 3번,4번비트를 0로 변경해서 출력하세요.
  // Serial.print("A&(~Mask) = ");
  // Serial.println(A&(~Mask), BIN);

  // // A의 3번,4번비트를 반전해서 출력하세요.(0->1, 1->0)
  // Serial.print("A^Mask = ");
  // Serial.println(A^Mask, BIN);

  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
// 반복적으로 호출되는 함수
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}
