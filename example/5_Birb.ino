#include <VarSpeedServo.h>

double readSonar(int trigPin, int echoPin) {  //HC-SR04 Ultrasonic sensor
  float duration, distance;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.0343 / 2;   // Calculating the distance
  return distance;
}

double node_35_data_read = 0;
double node_42_constant = 180;
boolean node_43_clock_signal = 0;
unsigned long node_43_clock_signal_previous_millis = 0; // เก็บเวลา (ms)
double node_41_if_else = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  node_35_data_read = readSonar(2, 5);
  unsigned long node_43_clock_signal_current_millis = millis(); // เวลาในขณะนี้
  if (node_43_clock_signal_current_millis - node_43_clock_signal_previous_millis >= 1000 / 1) { //T(Period) = 1000(ms) / frequency(hz)
    node_43_clock_signal_previous_millis = node_43_clock_signal_current_millis; // อัพเดตเวลาล่าสุด
    node_43_clock_signal = !node_43_clock_signal; // สลับสถานะ
  }

  if (0 <= node_35_data_read and node_35_data_read < 10) {
    node_41_if_else = 200;
  } else if (10 <= node_35_data_read and node_35_data_read < 20) {
    node_41_if_else = 100;
  } else {
    node_41_if_else = 1;
  }
  double node_44_multiply = node_43_clock_signal * node_42_constant;
  delay(100);
}
