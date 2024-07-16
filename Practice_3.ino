#include <filter_lib.h>

lowpass_filter lowpassFilter(10);

float PulseSensorPurplePin = 0;
float Signal;
float Filtered_Signal;

int LED = 13;
int Threshold = 360;
int LED_H = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin);
  
  Filtered_Signal = lowpassFilter.filter(Signal);

  Serial.print(Filtered_Signal);
  Serial.print(" ");

  if(Filtered_Signal > Threshold) {
    digitalWrite(LED,HIGH);
    LED_H = 400;
  } else {
    digitalWrite(LED,LOW);
    LED_H = 320;
  }
  Serial.println(LED_H);
}
