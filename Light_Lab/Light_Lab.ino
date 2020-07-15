int ldr_pin = A0;
int analogValue = 0;
int LED_RED = 4;
int LED_GREEN = 5;
void setup() {
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}
void loop() {
  analogValue = analogRead(ldr_pin);
  Serial.println(analogValue);
  if(analogValue >= 700&&analogValue <= 1000) { 
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, HIGH);
  }
  else if(analogValue >= 401&&analogValue <= 700) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
  }
  else {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, LOW);
  }
   
 delay(100);
    
 

  
 

}
