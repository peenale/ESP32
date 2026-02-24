#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Hello World!");
}

void loop() {
  Serial.println("ESP32-S3 funzionante!");
  delay(1000);
}