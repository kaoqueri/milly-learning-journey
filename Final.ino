
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

double node_29_constant = 5;
double node_36_data_read = 0;
boolean node_21_if = false;
double node_39_accumulate = 0;
double node_39_accumulate_last_value = 0;
boolean node_39_accumulate_prev_reset = false;
double node_20_accumulate = 0;
double node_20_accumulate_last_value = 0;
boolean node_20_accumulate_prev_reset = false;
boolean node_22_if = false;
double node_35_random = random(0, 255);
boolean node_22_if_previous = false; //ใช้ควบคุมการสุ่มเลข
double node_34_random = random(0, 255);
boolean node_22_if_previous = false; //ใช้ควบคุมการสุ่มเลข
double node_33_random = random(0, 255);
boolean node_22_if_previous = false; //ใช้ควบคุมการสุ่มเลข

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  node_36_data_read = readSonar(2, 5);
  if (node_36_data_read < 20) {
    node_21_if = true;
  } else {
    node_21_if = false;
  }
  boolean node_39_accumulate_trigger = false;
  if (node_39_accumulate_trigger && !node_39_accumulate_prev_reset) {
    node_39_accumulate = 0;
  }
  node_39_accumulate_prev_reset = node_39_accumulate_trigger;
  if (node_21_if != node_39_accumulate_last_value) {
    node_39_accumulate += node_21_if;
    node_39_accumulate_last_value = node_21_if;
  }
  boolean node_20_accumulate_trigger = false;
  if (node_20_accumulate_trigger && !node_20_accumulate_prev_reset) {
    node_20_accumulate = 0;
  }
  node_20_accumulate_prev_reset = node_20_accumulate_trigger;
  if (node_18_mouth_open != node_20_accumulate_last_value) {
    node_20_accumulate += node_18_mouth_open;
    node_20_accumulate_last_value = node_18_mouth_open;
  }
  double node_40_plus = node_20_accumulate + node_39_accumulate;
  double node_30_modulo = node_40_plus % node_29_constant;
  if (node_30_modulo == 0) {
    node_22_if = true;
  } else {
    node_22_if = false;
  }
  if(node_22_if_previous == 0 && node_22_if == 1){
    node_35_random = random(0, 255);
    node_22_if_previous = node_22_if; //ใช้ควบคุมการสุ่มเลข
  } else if (node_22_if_previous == 1 && node_22_if == 0){ 
    node_22_if_previous = node_22_if; //ใช้ควบคุมการสุ่มเลข
  }
  if(node_22_if_previous == 0 && node_22_if == 1){
    node_34_random = random(0, 255);
    node_22_if_previous = node_22_if; //ใช้ควบคุมการสุ่มเลข
  } else if (node_22_if_previous == 1 && node_22_if == 0){ 
    node_22_if_previous = node_22_if; //ใช้ควบคุมการสุ่มเลข
  }
  if(node_22_if_previous == 0 && node_22_if == 1){
    node_33_random = random(0, 255);
    node_22_if_previous = node_22_if; //ใช้ควบคุมการสุ่มเลข
  } else if (node_22_if_previous == 1 && node_22_if == 0){ 
    node_22_if_previous = node_22_if; //ใช้ควบคุมการสุ่มเลข
  }
  double node_41_data_write_value = constrain(node_22_if, 0, 1);
  digitalWrite(8, node_41_data_write_value);
  delay(100);
}
