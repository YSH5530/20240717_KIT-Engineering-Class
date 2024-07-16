#include <filter_lib.h>

lowpass_filter lowpassFilter(10);

float PulseSensorPurplePin = 0;
float Signal;
float Filtered_Signal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin);
  
  Filtered_Signal = lowpassFilter.filter(Signal);
  
  Serial.print(Signal);
  Serial.print(" ");
  Serial.println(Filtered_Signal);
}
