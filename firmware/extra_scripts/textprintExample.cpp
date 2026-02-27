#include <Arduino.h>
#include <Wire.h>
#include <SSD1306.h>
#include <Fragments.h>

#define I2C_SDA 15
#define I2C_SCL 16

OLED oled(128, 64);

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  oled.begin();
}

void loop() {
  Serial.println("ESP32-S3 funzionante!");
  oled << "Hello World!" << 64 << 16; // Print "Hello World!" at the center of the screen
  oled.inflate(); // Render the items on the display
  delay(1000); // Wait for 1 second
  oled.clearScr(); // Clear the screen
  oled.rectangle(15, 15, 100, 30, 5, 2, false); // Draw a rectangle at (15, 15) with width 100, height 30, 5px corner radius, and 2px thickness
  oled << "Hello World!" << 30 << 25; // Print "Hello World!" inside the rectangle
  oled.inflate(); // Render the items on the display
  delay(1000);
}