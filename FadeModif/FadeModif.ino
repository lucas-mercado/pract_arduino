/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 This example code is in the public domain.
 */

int array_pin[] = {3,6,9,10,11,5};
int brightness = 0;    // how bright the LED is
int brightness2= 255; 
int fadeAmount = 5;    // how many points to fade the LED by
int cant_pin = 6;

// the setup routine runs once when you press reset:
void setup() {
   for(int i= 0 ; i < cant_pin ; i++){
        pinMode(array_pin[i],OUTPUT);  
   }
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  for(int i=0 ; i < cant_pin ; i++){
    analogWrite(array_pin[i],brightness);
  }
  // change the brightness for next time through the loop:
  brightness += fadeAmount;
  brighness2 -= fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }

  if(brightness2 == 0){
    brighness2 = 255;
  }
  
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

