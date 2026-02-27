#include <Arduino.h>
#include <Wire.h>
#include <SSD1306.h>
#include <Fragments.h>
#include "logo.h"

#define I2C_SDA 15
#define I2C_SCL 16

OLED oled(128, 64);

void setup()
{
  Wire.begin(15, 16);
  oled.begin();       // Hardware init
  oled.clearScr();    // Clear display RAM (see note on 'inflate' below!)
  oled.print("Hello!", 0, 0);
  oled<<"This also prints"<<20<<30;
  oled.draw(logo, 0, 0, 128, 64);
  oled.inflate();
}

void loop()
{
  
}