//Asignamos una referencia a cada pin
#define MIA 5
#define MIB 6
#define MDA 9
#define MDB 10
//FUNCIONES DE MOVIMIENTO DE VELOCIDAD REGULADA
void adelante(int valor){
analogWrite(5,valor);
digitalWrite(6,LOW);
analogWrite(9,valor);
digitalWrite(10,LOW);
}

void atras(int valor){
digitalWrite(5,LOW);
analogWrite(6,valor);
digitalWrite(9,LOW);
analogWrite(10,valor);
}
void izquierda(int valor){
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(9,LOW);
analogWrite(10,valor);
}
void derecha(int valor){
analogWrite(5,valor);
digitalWrite(6,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
}
void alto(){
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
}
void setup() {
//Declaramos todos los pines como salidas digitales
pinMode(MIA,OUTPUT);
pinMode(MIB,OUTPUT);
pinMode(MDA,OUTPUT);
pinMode(MDB,OUTPUT);
//Se llama a cada función en el orden deseado y duración especificada
//adelante rápido, ligero y lento
adelante(255);
delay(2000);
adelante(200);
delay(2000);
adelante(150);
delay(2000);
//derecha lenta
derecha(150);
delay(500);
//atrás lenta y media
atras(150);
delay(2000);
atras(200);
delay(2000);
//izquierda rápida
izquierda(255);
delay(500);
//Paramos
alto();
}

void loop() {
//No trabajamos en bucle en este ejemplo
}
