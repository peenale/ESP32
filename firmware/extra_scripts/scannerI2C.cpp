#include <Arduino.h>
#include <Wire.h>
#include <SSD1306.h>
#include <Fragments.h>

#define I2C_SDA 15
#define I2C_SCL 16

void setup() {
Serial.begin(115200);
  while (!Serial); // Wait for serial monitor to initialize
  
  Serial.println("\n--- Starting I2C Scanner ---");
  
  // Initialize I2C using your custom pins!
  Wire.begin(I2C_SDA, I2C_SCL);
}

void loop() {
  byte error, address;
  int nDevices = 0;

  Serial.println("Scanning for I2C devices...");

  // Ping every possible I2C address from 1 to 127
  for(address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("SUCCESS: I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      } 
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    } else if (error == 4) {
      Serial.print("ERROR: Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }    
  }
  
  if (nDevices == 0) {
    Serial.println("FAILED: No I2C devices found.");
  } else {
    Serial.println("Scan complete.\n");
  }
  
  delay(4000); // Wait 4 seconds before scanning again
}