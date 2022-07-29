// 처음에 한번만 호출되는 함수
void setup() {
  //pinMode(13, OUTPUT);      // 13번을 OUTPUT로 설정
  DDRB |= 0b00111111;           // PORTB의 데이터 방향 설정
  DDRD |= 0b11000000;
  DDRC |= 0b00111111;
}

// the loop function runs over and over again forever
// 반복적으로 호출되는 함수
void loop() {
  //digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  PORTB |= 0b00111111;
  PORTD |= 0b11000000;
  PORTC &= ~0b00111111;
  delay(100);                       // wait for a second
  //digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  PORTB &= ~0b00111111;
  PORTD &= ~0b11000000;
  PORTC |= 0b00111111;
  delay(100);                        // wait for a second
}
