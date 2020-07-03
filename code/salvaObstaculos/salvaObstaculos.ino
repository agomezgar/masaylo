//Asignamos una referencia a cada pin
#define MIA 5
#define MIB 6
#define MDA 9
#define MDB 10
#define trig 7
#define echo 8
//FUNCIÓN DE MEDICIÓN DE DISTANCIA
long dameDistancia(){
long espacio;
long tiempo;
//Apagamos (para evitar falsas lecturas) y encendemos Trigger durante 10 us
digitalWrite(trig,LOW);
delayMicroseconds(4);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
//Medimos el tiempo en us que tarda en volver el pulso y realizamos el cálculo.
tiempo=pulseIn(echo,HIGH);
espacio=tiempo/58.309;
//La función devuelve un valor de tipo long correspondiente a la distancia en cm.
return espacio;
}
//FUNCIONES DE MOVIMIENTO

void adelante (){
digitalWrite(MIA,HIGH);
digitalWrite(MIB,LOW);
digitalWrite(MDA,HIGH);
digitalWrite(MDB,LOW);
}

void izquierda (){
 digitalWrite(MIA,LOW);
digitalWrite(MIB,LOW);
digitalWrite(MDA,HIGH);
digitalWrite(MDB,LOW);
}

void derecha(){
digitalWrite(MIA,HIGH);
digitalWrite(MIB,LOW);
digitalWrite(MDA,LOW);
digitalWrite(MDB,LOW);
}

void atras(){
digitalWrite(MIA,LOW);
digitalWrite(MIB,HIGH);
digitalWrite(MDA,LOW);
digitalWrite(MDB,HIGH);  
}
void alto(){
digitalWrite(MIA,LOW);
digitalWrite(MIB,LOW);
digitalWrite(MDA,LOW);
digitalWrite(MDB,LOW);
}

//FUNCIONES DE MOVIMIENTO DE VELOCIDAD REGULADA
void adelante(int valor){
analogWrite(MIA,valor);
digitalWrite(MIB,LOW);
analogWrite(MDA,valor);
digitalWrite(MDB,LOW);
}

void atras(int valor){
digitalWrite(MIA,LOW);
analogWrite(MIB,valor);
digitalWrite(MDA,LOW);
analogWrite(MDB,valor);
}
void izquierda(int valor){
digitalWrite(MIA,LOW);
digitalWrite(MIB,LOW);
digitalWrite(MDA,LOW);
analogWrite(MDB,valor);
}
void derecha(int valor){
analogWrite(MIA,valor);
digitalWrite(MIB,LOW);
digitalWrite(MDA,LOW);
digitalWrite(MDB,LOW);
}


void setup() {
//Declaramos cada pin en el modo en que corresponda
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(MIA,OUTPUT);
pinMode(MIB,OUTPUT);
pinMode(MDA,OUTPUT);
pinMode(MDB,OUTPUT);
}
void loop() {
//Medimos la distancia y la asignamos a una variable local
long distancia=dameDistancia();
if (distancia>30){
//No hay obstáculos a la vista
adelante();
}else if (distancia<20){
//Obstáculo ineludible, paro, atrás y derecha
alto();
delay(500);
atras();
delay(2000);
derecha();
delay(500);
}else{
//Obstáculo entre 20 y 30 cm. Proceder con cautela
adelante(150);
}
//Damos tiempo para evitar problemas de desfases
delay(100);
}
