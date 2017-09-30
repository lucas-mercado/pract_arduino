float a,b,longitud=100,width_display = 400,heigth_display = 400;

void setup(){
    size(400,400);
}

void draw(){
    a = (width_display / 2.0)-50;
    b = (heigth_display / 2.0)-50;
    rect(a,b,longitud,longitud);
}

void mousePressed(){
      if(mouseX > a && mouseX< (a+longitud) && mouseY > b && mouseY < (b+longitud))
          println("esta dentro");
      else
          println("Esta afuera");
}