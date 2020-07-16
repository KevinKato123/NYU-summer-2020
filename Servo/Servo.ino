#include <Servo.h>
//Servo myservo; //Object of Servo Class
int pwm = 4;

void setup() {
   //myservo.attach(pwm); //Pin 4 on board

   //myservo.write(90);
  pinMode(pwm, OUTPUT);

  analogWriteRange(255);
}

void loop() {
  // put your main code here, to run repeatedly:

  //myservo.write(90);
  analogWrite(pwm,127);
  delay(1000);
  //myservo.write(0);
  analogWrite(pwm, 0);
  delay(1000);
  //myservo.write(180);
  analogWrite(pwm, 255);
  delay(1000);

  //1. Convert the angle to duty cycle
  //2. analogWrite(pwm, DutyCycyle)

}
