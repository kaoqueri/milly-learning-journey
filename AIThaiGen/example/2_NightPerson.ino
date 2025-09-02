// If a person is in the camera frame + the light sensor has high value (dark environment), the onboard light will shine.


double node_15_data_read = 0;
boolean node_16_if = false;
boolean node_13_if = false;

void setup() {
  Serial.begin(9600);
  pinMode(14, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  node_15_data_read = analogRead(14);
  if (node_15_data_read > 900) {
    node_16_if = true;
  } else {
    node_16_if = false;
  }
  if (node_10_object_recognition == person) {
    node_13_if = true;
  } else {
    node_13_if = false;
  }
  boolean node_19_and = node_13_if && node_16_if;
  double node_9_data_write_value = constrain(node_19_and, 0, 1);
  digitalWrite(13, node_9_data_write_value);
  delay(100);
}
