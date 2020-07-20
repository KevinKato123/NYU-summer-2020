#include "SPI.h"
#include <Adafruit_ILI9341.h>
#include <Adafruit_GFX.h>
#include "idphoto.h"
#ifdef ESP8266
#define STMPE_CS 16
#define TFT_CS   0
#define TFT_DC   15
#define SD_CS    2
#endif
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
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
  ID_DETAILS();
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
}
