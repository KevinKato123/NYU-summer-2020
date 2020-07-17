vc #include <SoftwareSerial.h>
SoftwareSerial mySerialPort(4, 5); //Rx, Tx
char msgIn, msgOut; 
//bool isKevin = false; 
void setup() {
  Serial.begin(9600);//Serial communication for serial monitor
  mySerialPort.begin(9600);//Communication between serial monitor and software serial pins
}

void loop() { 
  //While I have data in the buffer, run this loop
  //Eg. If I sen "hello", run this loop 5 times one for each character
  while(mySerialPort.available()){
    //if (isKevin) {
    //isKevin = false;
    msgIn = mySerialPort.read();//read each character 1 at a time
    Serial.print(msgIn);
    delay(2);
  }
  //while I have data in Serial buffer
  while(Serial.available()){ 
  //if(!isKevin) 
    //Serial.print("Kevin: ");
    //isKevin = true;
 
    msgOut = Serial.read();
    mySerialPort.write(msgOut); //Read each character in order to send 
    mySerialPort.write(msgOut); //Sebd the characters
    Serial.print(msgOut);
    delay(2); }
   }
    
