int PulseSensorPurplePin = 0;
int Signal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin);
  Serial.println(Signal);
}
