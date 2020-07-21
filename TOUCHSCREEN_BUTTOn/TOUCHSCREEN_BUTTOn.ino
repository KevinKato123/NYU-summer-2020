#include <Adafruit_GFX.h>
#include <Adafruit_STMPE610.h>
#include <Adafruit_ILI9341.h>
//ESP8266
#define STMPE_CS 16
#define TFT_CS 0
#define TFT_DC 15
#define SD_CS 2
// This is calibration data for the raw touch data to the screen coordinates
#define TS_MAXX 100
#define TS_MINX 3800
#define TS_MINY 100
#define TS_MAXY 3750
Adafruit_ILI9341 tft = Adafruit_ILI9341 (TFT_CS, TFT_DC);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);
#define BoxSize 40
TS_Point p;
void drawButton() {
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(BoxSize * 1, BoxSize * 1, BoxSize * 4, BoxSize * 2, ILI9341_WHITE);
  tft.setCursor(BoxSize * 1.5, BoxSize * 1.5);
  tft.setTextSize(1);
  tft.setTextColor(ILI9341_BLACK);
  tft.println("TOUCH HERE");
}
  void drawPress() {
    tft.setCursor(BoxSize * 1.5, BoxSize * 5.5);
    tft.setTextSize(2);
    tft.setTextColor(ILI9341_GREEN);
    Serial.println("DETECTED");
    tft.println("PRESSED");
    tft. printf("X: %d | Y: %d", p.x, p.y);
    delay(5000);
  }
  bool detectTouch() {
    TS_Point p = ts.getPoint();
    bool flag = false;
    if (p.x < TS_MINX && p.x > TS_MAXX && p.y < TS_MAXY && p.y > TS_MINY) {
      p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
      p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());

      Serial.print("X = "); Serial.print(p.x);
      Serial.print("Y = "); Serial.print(p.y);
      Serial.print("\tPressure = "); Serial.println(p.z);

      if (p.x > BoxSize * 1 && p.x < BoxSize * 5 && p.y < BoxSize * 1 && p.y > BoxSize * 3){
      return = true;
      }
      return = false;
  }
    
  void setup() {
    Serial.begin(115200);
    if (!ts.begin()) {
      Serial.print("Error : STMPE Error");
    }
    tft.begin();
    drawButton();

  }

  void loop() {
    if(detectTouch()){
      delay(200);
        if(detectTouch()){
        drawpress(p.x, p.y);
        delay(500);
        drawButton();
        yield();
        }
    }
      delay(350);

    }
  }
