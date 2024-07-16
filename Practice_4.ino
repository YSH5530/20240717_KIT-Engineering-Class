#include <filter_lib.h>
#define ts 0.001 * 0.001

lowpass_filter lowpassFilter(10);

float PulseSensorPurplePin = 0;
float Signal;
float Pre_Signal = 0;
float diff_Signal = 0;
float Filtered_diff_Signal;

unsigned long tCount = 0;
unsigned long tCountPre = 0;
float dt = 0;

void setting() {
  tCount = micros();
  Signal = analogRead(PulseSensorPurplePin);
  dt = (float)(tCount - tCountPre) * ts;
}

void saveStates() {
  Pre_Signal = Signal;
  tCountPre = tCount;
}
void firstDerivative() {
  diff_Signal = (Signal - Pre_Signal) / dt;
}

void getData() {
  setting();
  firstDerivative();
  saveStates();
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  getData();
  Filtered_diff_Signal = lowpassFilter.filter(diff_Signal);

  Serial.print(Signal);
  Serial.print(" ");
  Serial.println(Filtered_diff_Signal);
}
