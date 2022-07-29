/*
 *  Timer1 library example
 *  June 2008 | jesse dot tane at gmail dot com
 */
 
#include "TimerOne.h"

const int LED1 = 8;
const int LED2 = 9;

unsigned long us_count = 0;

unsigned long t1_prev = 0;
const unsigned long t1_delay = 300000;  // 300ms

unsigned long t2_prev = 0;
const unsigned long t2_delay = 500000;  // 500ms

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  Timer1.initialize(1);              // initialize timer1, and set a 1/2 second period
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
  Serial.begin(115200);
}
 
void callback()
{
  us_count++;
}
 
void loop()
{
  // your program here...
  unsigned long t1_now = us_count;
  if(t1_now-t1_prev >= t1_delay){
    t1_prev = t1_now;
    digitalWrite(LED1, digitalRead(LED1)^1);
  }

  unsigned long t2_now = us_count;
  if(t2_now-t2_prev >= t2_delay){
    t2_prev = t2_now;
    digitalWrite(LED2, digitalRead(LED2)^1); 
  }
}
 
