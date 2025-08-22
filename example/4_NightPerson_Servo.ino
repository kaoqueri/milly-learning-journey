#include <VarSpeedServo.h>

double node_15_data_read = 0;
double node_24_constant = 180;
double node_26_constant = 100;
boolean node_28_clock_signal = 0;
unsigned long node_28_clock_signal_previous_millis = 0; // เก็บเวลา (ms)
boolean node_16_if = false;
boolean node_13_if = false;
double node_32_gate;

void setup() {
  Serial.begin(9600);
  pinMode(14, INPUT);
}

void loop() {
  node_15_data_read = analogRead(14);
  unsigned long node_28_clock_signal_current_millis = millis(); // เวลาในขณะนี้
  if (node_28_clock_signal_current_millis - node_28_clock_signal_previous_millis >= 1000 / 1) { //T(Period) = 1000(ms) / frequency(hz)
    node_28_clock_signal_previous_millis = node_28_clock_signal_current_millis; // อัพเดตเวลาล่าสุด
    node_28_clock_signal = !node_28_clock_signal; // สลับสถานะ
  }

  if (node_15_data_read < 900) {
    node_16_if = true;
  } else {
    node_16_if = false;
  }
  double node_29_multiply = node_24_constant * node_28_clock_signal;
  if (node_10_object_recognition == person) {
    node_13_if = true;
  } else {
    node_13_if = false;
  }
  boolean node_19_and = node_13_if && node_16_if;
  if (node_19_and) {
    node_32_gate = node_29_multiply;
  }
  Serial.print("node_32_gate: ");
  Serial.println(node_32_gate);
  delay(100);
}
