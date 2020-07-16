int LED_RED = 2;
int LED_GREEN= 5;
int LED_BLUE = 4;
void setup() {
  analogWriteRange(255);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED_RED,255);
  delay(500);
  analogWrite(LED_RED,0); 
  for(int i = 255 ; 1 >= 0; i--){
    analogWrite(LED_RED,255-i);
    analogWrite(LED_BLUE, 255 - (i/2));
    analogWrite(LED_GREEN, 255 - (i/4));
    
  }
  delay(500);
}
