/*
  Calibration

  Demonstrates one technique for calibrating sensor input. The sensor readings
  during the first five seconds of the sketch execution define the minimum and
  maximum of expected values attached to the sensor pin.

  The sensor minimum and maximum initial values may seem backwards. Initially,
  you set the minimum high and listen for anything lower, saving it as the new
  minimum. Likewise, you set the maximum low and listen for anything higher as
  the new maximum.

  The circuit:
  - analog sensor (potentiometer will do) attached to analog input 0
  - LED attached from digital pin 9 to ground

  created 29 Oct 2008
  by David A Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Calibration
*/

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 9;        // pin that the LED is attached to
const int ledPin1 = 11;

// variables:
int sensorValue = 0,sensorValue2 = 1023 ;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value


void setup() {
  // turn on LED to signal the start of the calibration period:
  pinMode(13, OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  digitalWrite(13, HIGH);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }

  }

  // signal the end of the calibration period
  digitalWrite(13, LOW);
}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);
  sensorValue2 = sensorValue;
  // apply the calibration to the sensor reading
  sensorValue  = map(sensorValue, sensorMin, sensorMax, 0, 255);//le da valores entre 0 y 255.mapeando con 0 y 1024. 
  sensorValue2 = map(sensorValue2,sensorMin, sensorMax, 0, 255);//como el potenciometro trabajo en el rango 0 y 1024 y para los led necesitamos entre 0 y 255
  
  // in case the sensor value is outside the range seen during calibration
  sensorValue  = constrain(sensorValue, 0, 255);//este permite optar por un valor X entre a y b;
  sensorValue2 = constrain(sensorValue2, 255, 0);// si x este menor que a toma a sino, si x es mayor b toma b.
  //en este caso cuando el valor sensorValue,sensorValue2 aumenta se acerca a 255, en el otro caso se acerca a 0 
  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue);
  analogWrite(ledPin1,sensorValue2);  
}
