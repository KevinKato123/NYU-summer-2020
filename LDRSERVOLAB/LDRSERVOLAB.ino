#include <Servo.h>
Servo myservo;
int ldr_pin = A0; 
int analogValue = 0;
int pwm = 4;
void setup() {
  Serial.begin(9600);
  myservo.attach(pwm);
}
void loop() {
  analogValue = analogRead(ldr_pin);
  Serial.println(analogValue);
  analogValue = map(analogValue, 0 , 1024 , 0 , 180);
  myservo.write(analogValue);
//  if(analogValue <= 1024&&analogValue >= 768) {
//    myservo.write(180);
//  }
//  else if(analogValue <= 767&&analogValue >= 511) {
//    myservo.write(135);
//  }
//  else if(analogValue <= 510&&analogValue >= 254) {
//    myservo.write(90);
//  }
//  else if(analogValue <= 253&&analogValue >= 0) {
//    myservo.write(45);
//  }
//  else{
//    myservo.write(0);
//  }

}
