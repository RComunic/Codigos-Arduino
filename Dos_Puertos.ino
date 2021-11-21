#include <SoftwareSerial.h>

SoftwareSerial MySerial(2,3); // (RX,TX) 

void setup(){
  Serial.begin(9600);
  MySerial.begin(9600);
}

void loop(){

  if(MySerial.available()){
    Serial.print((char)MySerial.read());
  }
  if(Serial.available()){
     MySerial.print((char)Serial.read());
  }
}

  
    
