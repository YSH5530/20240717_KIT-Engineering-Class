#include <filter_lib.h>

lowpass_filter lowpassFilter(10);

float PulseSensorPurplePin = 0;
unsigned long lastBeatTime = 0;

int BPM = 0;
int Signal;
float Filtered_Signal;

int Threshold = 360;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin);
  Filtered_Signal = lowpassFilter.filter(Signal);

  if (Filtered_Signal > Threshold) {
    unsigned long currentTime = millis();
    if (currentTime - lastBeatTime > 300) {
      unsigned long beatInterval = currentTime - lastBeatTime;
      BPM = 60000 / beatInterval;
      
      lastBeatTime = currentTime;

      Serial.print("BPM: ");
      Serial.println(BPM);  
    }
  }
}
