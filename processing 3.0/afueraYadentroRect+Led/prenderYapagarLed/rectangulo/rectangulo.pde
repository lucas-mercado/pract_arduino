/**
* Este Sketch dibuja un rectangulo en el centro del Display.
* Lo que hace es mandar un caracter por el puerto.
* Si esta clikeando con el mouse dentro del rectangulo manda el caracter 'H'
* Si esta clikeando con el mouse fuera del rectangulo manda el caracter 'L' 
**/
import processing.serial.*;

Serial port;
float a,b,longitud=100,width_display = 400,heigth_display = 400;

void setup(){
    size(400,400);
    println(Serial.list()[0]);//muestra la lista de puertos.
    port = new Serial(this,Serial.list()[0],9600);//abre un puerto con velocidad 9600
}

void draw(){
    //dibujo el rectangulo
    a = (width_display / 2.0)-50;
    b = (heigth_display / 2.0)-50;
    rect(a,b,longitud,longitud);
}

void mousePressed(){
      //se fija si presiona dentro o fuera del rectangulo.
      if(mouseX > a && mouseX< (a+longitud) && mouseY > b && mouseY < (b+longitud)){
          println("esta dentro");
          port.write('H');
      }    
      else{
          port.write('L');
          println("Esta afuera");
      }    
}