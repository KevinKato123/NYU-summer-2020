#include "SPI.h"
#include <Adafruit_ILI9341.h>
#include <Adafruit_GFX.h>
#include <Adafruit_STMPE610.h>
#include "idphoto.h"
#include "Idphoto2.h"
#ifdef ESP8266
#define STMPE_CS 16
#define TFT_CS   0
#define TFT_DC   15
#define SD_CS    2
#endif
#define TS_MAXX 100
#define TS_MINX 3800
#define TS_MINY 100
#define TS_MAXY 3750
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);
bool detectTouch() {
  TS_Point p = ts.getPoint();
  if (p.x < TS_MINX && p.x > TS_MAXX && p.y < TS_MAXY && p.y > TS_MINY) {
    p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());
  }
}
    void drawIDCARD() {
      tft.fillScreen(ILI9341_BLACK);
      tft.setCursor(0, 150);
      yield();
      tft.setTextColor(ILI9341_BLUE); tft.setTextSize(2);
      tft.println("Viewpoint School");
      tft.setTextColor(ILI9341_GREEN); tft.setTextSize(2);
      tft.println("Kevin Kato");
      tft.setTextColor(ILI9341_RED); tft.setTextSize(2);
      tft.println("I am 15, and born on December 26, 2004.");}
       void ID_PIC(){
          tft.drawRGBBitmap(0, 0, ID_CARDE, ID_CARDE_WIDTH, ID_CARDE_HEIGHT);
        }
      void drawIDPIC() {
        ID_PIC();
        tft.drawRGBBitmap(0, 0, ID_CARDE, ID_CARDE_WIDTH, ID_CARDE_HEIGHT);
        delay(5000);}
       
        void setup() {
          tft.begin();
          Serial.begin(115200);
          uint8_t x = tft.readcommand8(ILI9341_RDMODE);
          Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
          x = tft.readcommand8(ILI9341_RDMADCTL);
          Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
          x = tft.readcommand8(ILI9341_RDPIXFMT);
          Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
          x = tft.readcommand8(ILI9341_RDIMGFMT);
          Serial.print("Image Format: 0x"); Serial.println(x, HEX);
          x = tft.readcommand8(ILI9341_RDSELFDIAG);
          Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX);
          ID_PIC();
          tft.drawRGBBitmap(0, 0, ID_CARD, ID_CARD_WIDTH, ID_CARD_HEIGHT);
        }
        void ID_DETAILS() {
          tft.fillScreen(ILI9341_BLACK);
          tft.setCursor(0, 150);
          yield();
          tft.setTextColor(ILI9341_BLUE); tft.setTextSize(2);
          tft.println("Viewpoint School");
          tft.setTextColor(ILI9341_GREEN); tft.setTextSize(2);
          tft.println("Kevin Kato");
          tft.setTextColor(ILI9341_RED); tft.setTextSize(2);
          tft.println("I am 15, and born on December 26, 2004.");
        }
        void loop(void) {
          if (detectTouch()) {
            delay(200);
            if (detectTouch()) {
              drawIDPIC();
              delay(500);
              drawIDCARD();
              yield();
            }
          }
        }
