
int ldr_pin = A0; 
int analogValue = 0;





void setup() {
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(ldr_pin);
  Serial.println("LDR Value is: ");
  Serial.println(analogValue);
  delay(50);
}
