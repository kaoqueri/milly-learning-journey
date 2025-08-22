// Just a normal LED Blinking
double node_2_constant = 1;
boolean node_6_clock_signal = 0;
unsigned long node_6_clock_signal_previous_millis = 0; // เก็บเวลา (ms)

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  unsigned long node_6_clock_signal_current_millis = millis(); // เวลาในขณะนี้
  if (node_6_clock_signal_current_millis - node_6_clock_signal_previous_millis >= 1000 / 1) { //T(Period) = 1000(ms) / frequency(hz)
    node_6_clock_signal_previous_millis = node_6_clock_signal_current_millis; // อัพเดตเวลาล่าสุด
    node_6_clock_signal = !node_6_clock_signal; // สลับสถานะ
  }

  double node_7_multiply = node_2_constant * node_6_clock_signal;
  double node_5_data_write_value = constrain(node_7_multiply, 0, 1);
  digitalWrite(13, node_5_data_write_value);
  delay(100);
}
