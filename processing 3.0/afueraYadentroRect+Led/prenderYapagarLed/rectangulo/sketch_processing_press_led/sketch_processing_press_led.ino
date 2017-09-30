/**
 * Este Sketch resive un caracter 
 * Si caracter es H prende el pin_led.
 * Si caracter es L a apaga el pin_led.
 */

int  pin_led = 13;
char valor = ' '; 

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(valor == 'H')
     digitalWrite(pin_led,HIGH);   
  if(valor == 'L')
     digitalWrite(pin_led,LOW);
}

void serialEvent(){
    if(Serial.available()){
        valor = (char)Serial.read();  
    }  
}
