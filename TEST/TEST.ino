#include <DHT.h>
#include <DHT_U.h>

#include <SPI.h>
#include <Wire.h>      // this is needed even tho we aren't using it

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ILI9341.h> // Hardware-specific library
#include <Adafruit_STMPE610.h> // Touch sensor

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
TS_Point p;

#define box 40

//LED

#define LED_PIN 14

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);

void drawQUESTION();
void drawButton(char *string, int xpos, int ypos);
bool detectTouch(int xpos, int ypos, int width, int height);



bool detectTouch(int xpos, int ypos, int width, int height) {
  p = ts.getPoint();
  delay(50);
  //Check if within bounds
  if (p.x < TS_MINX && p.x > TS_MAXX && p.y > TS_MINY && p.y < TS_MAXY) {
    p.x = map(p.x, TS_MINX, TS_MAXX,0, tft.width());
    p.y = map(p.y, TS_MINY, TS_MAXY,0, tft.height());

    Serial.print("X = "); Serial.print(p.x);
    Serial.print("\tY = "); Serial.print(p.y);
    Serial.print("\tPressure = "); Serial.println(p.z);
//          
    if (p.x > xpos && p.x < xpos+width && p.y > ypos && p.y < ypos + height) {
      Serial.println("Detected");
      return true;
    }
    
  }
  return false;
}





void drawButton(char *string, int xpos, int ypos) {
 //positionx , positiony, width, height
tft.drawRect(xpos, ypos, box*4, box*1.5, ILI9341_GREEN);
  tft.setTextColor(ILI9341_BLUE);
  tft.setTextSize(3);
  tft.setCursor(xpos+box*1.35, ypos+box*0.5);
  tft.print(string);
  yield();

}


void drawQUESTION{ 
  tft.fillScreen(ILI9341_WHITE);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.setCursor(box *2, 2);
  tft.print("LED CONTROL");
  drawButton("TRUE", box*1, box*2);
  drawButton("FALSE", box*1, box*4);
  while (1) {

    //True Button
    if(detectTouch(box*1,box*4, box*4,box*1.5)) {
      delay(150);
      if(detectTouch(box*1,box*4, box*4,box*1.5)) {
        Serial.print("Detected LED");
        digitalWrite(LED_PIN, !(digitalRead(LED_PIN))
        continue;

      }
    }
      
    // False BUTTON
    if (detectTouch(box*1,box*6, box*4,box*1.5)) {
      delay(150);
      if (detectTouch(box*1,box*6, box*4,box*1.5)) {
      Serial.print("Detected back");
        drawWelcome();
        break;
    }
  
  }
  delay(10);
  
}
}


void drawWelcome() {

  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_MAGENTA);
  tft.setTextSize(3);
  tft.setCursor(box*1.5, box*1);
  tft.print("WELCOME");
  drawButton("START", box*1,box*2);
  yield();
  while(1) {
  //              xpos   ypos  width   height
  if (detectTouch(box*1,box*4,box*4,box*1.5)) {
    delay(200);
    if (detectTouch(box*1,box*4,box*4,box*1.5)) {
      drawLED();
      break;
    }
  }
  delay(10);
}
}




void setup() {

  Serial.begin(115200);
  ts.begin();
  tft.begin();
  pinMode(LED_PIN, OUTPUT);
  tft.fillScreen(ILI9341_BLACK);
  drawWelcome();

}
  

void loop() {
  

    
  }








































----------------------------------------------------------------------------------------------------------------------
//Question 2 
void drawQ1() {
  tft.fillScreen(ILI9341_WHITE);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(2);
  tft.setCursor(box *2, 2);
  tft.print("Question 2"); 
  setTextSize(1);   
  setTextColor(ILI9341_GREEN); 
  tft.setCursor(box *3, 2); 
  tft.print("People in Britian speak British, true or false"); 
  drawButton("TRUE", box*1, box*2);
  drawButton("FALSE", box*1, box*4);
  while (1) {

    //True Button
    if(detectTouch(box*1,box*4, box*4,box*1.5)) {
      delay(150);
      if(detectTouch(box*1,box*4, box*4,box*1.5)) {
        Serial.print("True");
        tft.setTextSize(1)
        tft.setTextColor(ILI9341_GREEN);
        tft.setCursor(box *1, box *2);
        tft.print("WRONG ANSWER");
        drawWelcome(); 
        break;

      }
    }
      
    // False BUTTON
    if (detectTouch(box*1,box*6, box*4,box*1.5)) {
      delay(150);
      if (detectTouch(box*1,box*6, box*4,box*1.5)) {
      Serial.print("False");
       tft.setTextSize(1)
        tft.setTextColor(ILI9341_GREEN);
        tft.setCursor(box *1, box *2);
        tft.print("RIGHT ANSWER");
        drawWelcome();
        break;
    }
  
  }
  delay(10);
}
