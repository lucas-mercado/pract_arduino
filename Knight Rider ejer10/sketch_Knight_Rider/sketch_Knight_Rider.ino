int pins_led[] = {2,4,7,8,12,13};
int tam = 6,pausa = 30;
void setup() {
  // put your setup code here, to run once:
  for(int i=0 ; i < tam ;i++){
      pinMode(pins_led[i],OUTPUT);  
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<tam; i++){
     digitalWrite(pins_led[i],HIGH);
     delay(pausa);
     digitalWrite(pins_led[i],LOW);
     delay(pausa);   
  }

  for(int i= tam-1; i >=0 ; i-- ){
     digitalWrite(pins_led[i],HIGH);
     delay(pausa);
     digitalWrite(pins_led[i],LOW);
     delay(pausa);
  }
}
