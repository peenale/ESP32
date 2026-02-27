#include <Arduino.h>
#include <Wire.h>
#include <SSD1306.h>
#include <Fragments.h>

#define POWER_PIN 13   // We will send power OUT of this pin
#define LISTEN_PIN 15 // We will listen for power ON this pin

void setup() {
  Serial.begin(115200);
  
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, HIGH); // Turn the power pin ON
  
  // Set the listen pin to pull-down so it defaults to LOW (0) when nothing is connected
  pinMode(LISTEN_PIN, INPUT_PULLDOWN); 
}

void loop() {
  int wireStatus = digitalRead(LISTEN_PIN);
  
  if (wireStatus == HIGH) {
    Serial.println("WIRE IS GOOD! (Connection detected)");
  } else {
    Serial.println("BROKEN OR DISCONNECTED...");
  }
  
  delay(500);
}