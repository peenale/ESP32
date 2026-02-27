# (E)super Serious Project (32)

## Embedded Voice Assistant - Hardware Project

An embedded voice assistant based on the **ESP32-S3**, capable of capturing audio via a MEMS microphone, processing voice commands through an **external API**, and returning audio responses via speaker. The device features an OLED display for visual feedback and external memory support via SD card.

> **NOTE:** The API for voice recognition and response generation is yet to be defined (e.g., OpenAI Whisper, Google Speech-to-Text, Anthropic Claude, etc.).

---

## Hardware Components

This ESP32 project uses the following hardware modules:

| # | Component | Description | Interface / Notes |
|---|---|---|---|
| 1 | Microcontroller | ESP32-S3 WiFi BT Development Board | Arduino IDE / PlatformIO |
| 2 | Speaker | Keyestudio SC8002B Voice Module Amplifier | DAC / PWM Audio |
| 3 | SD Reader | Micro SD Mini TF Card Reader Module | SPI |
| 4 | OLED Display | 0.96" SSD1306 OLED Display Module | I2C / SPI |
| 5 | Microphone | INMP441 MEMS Omnidirectional Microphone | I2S |

---

## Documentation

For datasheets, library links, and board environment details, please refer to the [`DOCS.md`](./DOCS.md) file.

---

Can't even write a simple readme smh
> peenale  
