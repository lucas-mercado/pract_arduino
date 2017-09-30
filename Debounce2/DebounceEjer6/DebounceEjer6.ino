/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  - Note: On most Arduino boards, there is already an LED on the board connected
    to pin 13, so you don't need any extra components for this example.

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/

const int buttonPin=2,ledPinA = 13,ledPin = 4;
int ledState = LOW,buttonState,lastButtonState=HIGH;
String msg = "";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // set initial LED state
  digitalWrite(ledPin, ledState);
  digitalWrite(ledPinA,ledState);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH && msg.equals("HIGH")) {
        ledState = !ledState;
        msg = "";
      }
    }
  }

  // set the LED:
      digitalWrite(ledPin, ledState);
      digitalWrite(ledPinA,ledState);
    

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}

void serialEvent(){
    if(Serial.available()){
       char inChar = (char)Serial.read();
       msg += inChar;         
    }
}

int cadenasIguales(String a,String b){
    if(a.length()== b.length()){
        for(int i=0 ; i < a.length();i++){
            if(a.charAt(i) != b.charAt(i))
                return 0;  
        }
    }
    else{
        return 0;  
    }  
    return 1;
}