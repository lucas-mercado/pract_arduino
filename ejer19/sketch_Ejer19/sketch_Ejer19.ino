int tam = 5,bandera=0,i,mayor,menor;
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
  if(bandera==1){//empezar a realizar las operaciones cuando esten cargado todos los datos en el arreglo.
     mayorYmenor(secuencia,tam);
     String valorMayor = String(mayor,DEC);
     Serial.println("Mayor : "+valorMayor);
     String valorMenor = String(menor,DEC);
     Serial.println("Menor : "+valorMenor);
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

void mayorYmenor(int sec[], int tam){
    int ma,me;
    for(int i=0; i < tam; i++){
          ma = sec[i];
          me = sec[i];
          for(int j=0 ; j < tam ; j++){ 
            if(ma < sec[j]){
               ma = sec[j]; 
            }
            if(me > sec[j]){
               me = sec[j];  
            }
          } 
    }
    mayor=ma;
    menor=me;  
}
