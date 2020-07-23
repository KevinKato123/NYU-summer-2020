#include <ESP8266WiFi.h> 
#include "NTPClientUpdated.h" 
#include <WiFiUDP.h>
#include <OpenWeatherMapCurrent.h>
#include <OpenWeatherMapForecast.h> 

#define WIFI_SSID "KATO HOME"
#define WIFI_PASS "Kohiba2305" 
#define MAX_FORECAST
WiFiUDP ntpUDP;
const long utcOffsetInSeconds = -7 * 3600;
NTPClientUpdated timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

String timeStamp;
String dateStamp;

String OPEN_WEATHER_MAP_LANGUAGE = "en";
String OPEN_WEATHER_MAP_APPID = "e1f3f1aabc8e64d4fb1d9ee66f0f144d"; 
String OPEN_WEATHER_MAP_LOCATION = "California,CA,US";
const boolean IS_METRIC = false; 

OpenWeatherMapCurrentData currentWeather; 
OpenWeatherMapForecastData forecasts[MAX_FORECAST];

void connectWiFi() {
  if(WiFi.status() == WL_CONNECTED) return; 
  Serial.print(WIFI_SSID);
  Serial.print("/");
  Serial.println(WIFI_PASS); 
  Serial.print("Connecting to WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while(WiFi.status() != WL_CONNECTED){
    delay(500); 
    Serial.print(".");
  }
  Serial.println("\nConnected to Wifi");
}

void updateWeatherData(){
 
  OpenWeatherMapCurrent *currentWeatherClient = new OpenWeatherMapCurrent();
  currentWeatherClient->setMetric(IS_METRIC);
  currentWeatherClient->setLanguage(OPEN_WEATHER_MAP_LANGUAGE);
  currentWeatherClient->updateCurrent(&currentWeather, OPEN_WEATHER_MAP_APPID, OPEN_WEATEHR_MAP_LOCATION); 
  delete currentWeatherClient; 
  currentWeatherClient = nullptr; 
  
  OpenWeatherMapForecast *forecastClient = new OpenWeatherMapForecast();
  forecastClient->setMetric(IS_METRIC);
  forecastClient->setLanguage(OPEN_WEATHER_MAP_LANGUAGE);
  forecastClient->updateForecasts(forecasts, OPEN_WEATHER_MAP_APPID, OPEN_WEATHER_MAP_LOCATION); 
  delete forecastClient;
  forecastClient = nullptr; 

  delay(100); 
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("\n\n\n");
  connectWiFi();
  timeClient.begin(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!timeClient.forceUpdate()){
      timeClient.forceUpdate(); 
  }
  updateWeatherData();
  
  timeStamp = timeClient.getFormattedTime();
  dateStamp = timeClient.getFormattedDate();
  Serial.print("Time: ");
  Serial.println(timeStamp);
  Serial.print("Date: ");
  Serial.println(dateStamp);
  delay(100); 

}
