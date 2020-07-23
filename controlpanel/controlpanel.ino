#include <Adafruit_GFX.h>
#include <DHT.h>
#include <Adafruit_STMPE610.h>
#include <Adafruit_ILI9341.h>
#define STMPE_CS 16
#define TFT_CS 0
#define TFT_DC 15
#define SD_CS 2
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);
#define TS_MAXX 100
#define TS_MINX 3800
#define TS_MINY 100
#define TS_MAXY 3750
#define box 40
#define LED_PIN 14
TS_Point p;
void drawButton(char *string, int xpos, int ypos);
void drawWelcome();
void drawLED();
void drawButton(char *string, int xpos, int ypos) {
  tft.drawRect(xpos, ypos, box * 4, box * 1.5, ILI9341_WHITE);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.setCursor(xpos + box * 0.5, ypos + box * 0.5);
  tft.print(string);
}
void drawWelcome() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_MAGENTA);
  tft.setTextSize(3);
  tft.setCursor(box * 1.5, box * 1);
  tft.print("WELCOME");
  drawButton("DHT", box * 1, box * 2);
  drawButton("LED", box * 1, box * 4);
  while (1) {
    if (detectTouch(box * 1, box * 4, box * 4, box * 1.5)) {
      delay(100);
      if (detectTouch(box * 1, box * 4, box * 4, box * 1.5)) {
        drawLED();
        break;
      }
    }
    delay(10);
  }
}

void drawLED() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(3);
  tft.setCursor(box * 2, 2);
  tft.print("LED");
  drawButton("LED 1/0", box * 1, box * 4);
  drawButton("Back", box * 1, box * 6);
  while (1) {
    if (detectTouch(box * 1, box * 4, box * 4, box * 1.5)) {
      Serial.println("IO");
      delay(100);
      if (detectTouch(box * 1, box * 4, box * 4, box * 1.5)) {
        Serial.print("IO DETECTED");
        digitalWrite(LED_PIN, !(digitalRead(LED_PIN));
        continue; 
      }
    }
    if (detectTouch(box * 1, box * 6, box * 4, box * 1.5)) {
      delay(25);
      if (detectTouch(box * 1, box * 6, box * 4, box * 1.5)) {
        drawWelcome();
        break;
      }
    }
    delay(10);
  }
}
bool detectTouch(int xpos, int ypos, int width, int height) {
  p = ts.getPoint();
  if (p.x < TS_MINX && p.x > TS_MAXX && p.y > TS_MINY && p.y < TS_MAXY) {
    p.x = map(p.x, TS_MAXX, TS_MINX, 0, tft.width());
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());
    Serial.print("X = "); Serial.print(p.x);
    Serial.print("\tY = "); Serial.print(p.y);
    Serial.print("\tPressure = "); Serial.println(p.z);
    if (p.x > xpos && p.x < xpos + width && p.y > ypos && p.y > ypos + height) {
      Serial.print("DETECTED");
      return true;
    }
  }
  return false;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ts.begin();
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  pinMode(LED_PIN, OUTPUT);
  drawWelcome();
}
void loop() {

  delay(50);
}
