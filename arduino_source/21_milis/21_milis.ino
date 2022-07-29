const uint8_t LED0 = 2;
const uint8_t LED1 = 3;

unsigned long t1_prev = 0;
const unsigned long t1_delay = 300;

unsigned long t2_prev = 0;
const unsigned long t2_delay = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long t1_now = millis();
  if(t1_now-t1_prev >= t1_delay){
    t1_prev = t1_now;
    digitalWrite(LED0, !digitalRead(LED0));   // 
  }

  unsigned long t2_now = millis();
  if(t2_now-t2_prev >= t2_delay){
    t2_prev = t2_now;
    digitalWrite(LED1, !digitalRead(LED1)); 
  }
  
}
