#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop() {
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

}
void displayInfo()
{
  Serial.print(gps.location.lng(), 6);
  Serial.print(';');
  Serial.print(gps.location.lat(), 6);
  Serial.print(';');
  Serial.print(gps.altitude.meters(), 2);
  Serial.print(';');
  Serial.print(gps.speed.mps(), 2);
  Serial.print(';');
  Serial.print(gps.satellites.value());
  Serial.print(';');
  Serial.print(gps.location.age());
  
}
