#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);

  Serial.println("DHT Test:");
  dht.begin();

}

void loop() {
  float t = dht.readTemperature(true);
  float h = dht.readHumidity();
  float c = dht.convertFtoC(t);
  Serial.printf("Temp: %f", t);
  Serial.printf("\nTemp(c): %f",c);
  Serial.printf("\nHumidity: %f", h);
  Serial.println(t);
  delay(2000);

}
