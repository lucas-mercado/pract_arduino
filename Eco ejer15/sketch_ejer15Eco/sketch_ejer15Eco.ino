#include <SoftwareSerial.h>

SoftwareSerial miSerial(10,11); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  miSerial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
      Serial.write("Eco");
       
      if(miSerial.available()){//resive miSerial y se lo manda de nuevo a Serial.
          Serial.write(miSerial.read());  
      }
      
      if(Serial.available()){//resive Serial y se lo manda de nuevo miSerial.
          miSerial.write(Serial.read());  
      }
}
