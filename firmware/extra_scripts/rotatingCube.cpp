#include <Arduino.h>
#include <Wire.h>
#include <SSD1306.h>
#include <Fragments.h>

#define I2C_SDA 15
#define I2C_SCL 16

float cube[8][3] = {
    {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
    {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}
};

int edges[12][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

float angle = 0;
int fps = 0;

int SCREEN_WIDTH = 128, SCREEN_HEIGHT = 64;

OLED oled(SCREEN_WIDTH, SCREEN_HEIGHT);

const int cx = SCREEN_WIDTH / 2;  
const int cy = SCREEN_HEIGHT / 2; 

void setup() {
    Serial.begin(115200);
    
    // Inizializza I2C prima di oled.begin()
    Wire.begin(I2C_SDA, I2C_SCL);
    
    oled.begin();
    oled.clearScr();
    oled.setPowerMode(PERFORMANCE_MODE);
}

void loop() {
    unsigned long start = millis();
    float rotated[8][3];

    for (int i = 0; i < 8; i++) {
        float x = cube[i][0];
        float y = cube[i][1];
        float z = cube[i][2];

        float x1 = x * cos(angle) + z * sin(angle);
        float z1 = -x * sin(angle) + z * cos(angle);

        float y1 = y * cos(angle) - z1 * sin(angle);
        float z2 = y * sin(angle) + z1 * cos(angle);

        rotated[i][0] = x1;
        rotated[i][1] = y1;
        rotated[i][2] = z2;
    }

    oled.clearScr();

    for (int i = 0; i < 12; i++) {
        int p1 = edges[i][0];
        int p2 = edges[i][1];

        float d = 3.5;  
        float s = 25.0; 

        int x0 = (rotated[p1][0] / (rotated[p1][2] + d)) * s + cx;
        int y0 = (rotated[p1][1] / (rotated[p1][2] + d)) * s + cy;
        int x1 = (rotated[p2][0] / (rotated[p2][2] + d)) * s + cx;
        int y1 = (rotated[p2][1] / (rotated[p2][2] + d)) * s + cy;

        oled.line(x0, y0, x1, y1, 1);
    }

    // FIX: La funzione print richiede (testo, x, y)
    // Usiamo il coordinata y=24 per stare nel display da 32px
    oled.print(String(fps) + " fps", 0, 24);

    oled.inflate();
    
    angle += 0.05;
    
    unsigned long duration = millis() - start;
    if (duration > 0) {
        fps = 1000 / duration;
    }
    
    delay(10); 
}