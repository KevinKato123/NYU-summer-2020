int LED_RED = 2;  
int LED_GREEN = 5;
int LED_BLUE = 4;
void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}
void loop() {
  digitalWrite(LED_RED, LOW);
  delay(500);
  digitalWrite(LED_RED, HIGH);
  
  digitalWrite(LED_BLUE, LOW);
  delay(500);
  digitalWrite(LED_BLUE, HIGH);

  digitalWrite(LED_GREEN, LOW);
  delay(500);
  digitalWrite(LED_GREEN, HIGH);
  }
