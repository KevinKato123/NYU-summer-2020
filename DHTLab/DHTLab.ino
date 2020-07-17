#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
int LED_RED = 16;
int LED_GREEN = 5;
int LED_BLUE = 2;
void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  Serial.begin(9600);
  Serial.println("Temp is: ");
  dht.begin();
}
void loop() {
  float t = dht.readTemperature(true);
  float mapValue = map(t,0, 110, 0, 255);
  Serial.printf("\n Temp: %f", t);
  delay(2000);
}
