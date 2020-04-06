//
//  Dump u-blox message emulator
//

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("0.0;1.0;2.0;3.0;4.");
  delay(100);
}
