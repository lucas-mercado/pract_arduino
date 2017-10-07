#include <DHT.h>

int pin = 2;
DHT sensor(pin,DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
  delay(500);
  // put your main code here, to run repeatedly:
  float temperatura = sensor.readTemperature();
  String temp = String(temperatura,DEC);
  Serial.println("Temperatura: "+temp);

  float humedad = sensor.readHumidity();
  String hum = String(humedad,DEC);
  Serial.println("Humedad : "+hum);

}
