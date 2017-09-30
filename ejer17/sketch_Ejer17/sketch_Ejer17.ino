int tam = 5,bandera=0,i;;
int secuencia[5];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  i=0;
  Serial.println("Ingrese la secuencia de nros");
  Serial.println("Forma de Ingreso---->>>>>>>>");
  Serial.println("Ingresa el primer valor y luego preciono enter");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bandera==1){
     int s = suma(secuencia,tam);
     int p = promedio(s,tam);
     String promedio = String(p,DEC);
     Serial.println("Promedio: "+promedio);
     bandera = 0;
     i=0;   
  }
}

void serialEvent(){
    if(Serial.available()){
       String valor = Serial.readString();
       Serial.println(valor);
       secuencia[i++] = valor.toInt();
       if(i==tam){
          bandera=1; 
       }   
    }
}

int suma(int secnros[],int tam){
  int suma = 0;
  for(int i=0; i<tam; i++)
      suma += secnros[i];

  return suma;    
}

float promedio(int a,int b){
    return a / b;  
}
