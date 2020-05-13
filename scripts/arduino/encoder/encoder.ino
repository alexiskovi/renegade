volatile int tick_count = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, addtick, FALLING);
}

void loop() {
  delay(200);
  Serial.println(tick_count);
  tick_count = 0;
}

void addtick() {
  tick_count += 1;
}
