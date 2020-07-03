//Asignamos una referencia a cada pin
#define MIA 5
#define MIB 6
#define MDA 9
#define MDB 10
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

void setup() {
//Declaramos todos los pines como salidas digitales
pinMode(MIA,OUTPUT);
pinMode(MIB,OUTPUT);
pinMode(MDA,OUTPUT);
pinMode(MDB,OUTPUT);
atras();
}

void loop() {
//Se llama a cada función en el orden deseado y duración especificada
izquierda();
delay((int)random(500,2000));
adelante();
delay((int)random(500,2000));
derecha();
delay((int)random(500,2000));
adelante();
delay((int)random(500,2000));
alto();
delay((int)random(500,2000));

atras();
delay((int)random(500,2000));

}
