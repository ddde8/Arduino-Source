void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.write(65);
  Serial.write('A');
  Serial.write(321);
  Serial.println();

  Serial.print(65);
  Serial.print('A');
  Serial.print(321);
  Serial.println();

  Serial.println(78, BIN);
  Serial.println(78, OCT);
  Serial.println(78, DEC);
  Serial.println(78, HEX);

  Serial.println(1.23456);      // 표시할 자릿수를 생략하면 소수점 2자리까지 표시
  Serial.println(1.23456, 2);
}

void loop() {
  // put your main code here, to run repeatedly:

}
