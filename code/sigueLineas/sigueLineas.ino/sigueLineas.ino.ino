//Definimos patillaje
#define MIA 5
#define MIB 6
#define MDA 9
#define MDB 10
#define sDerecha 3
#define sIzquierda 2
//Declaramos la variable global valorLeido que recogerá la lectura de los sensores
int valorLeido;
//Escribimos las funciones de movimiento de velocidad controlada
void alto(){
digitalWrite(MIA,LOW);
digitalWrite(MIB,LOW);
digitalWrite(MDA,LOW);
digitalWrite(MDB,LOW); 
}

void adelante( int velocidad){
analogWrite(MIA,velocidad);
digitalWrite(MIB,LOW);
analogWrite(MDA,velocidad);
digitalWrite(MDB,LOW);
}

void izquierda(int velocidad){
digitalWrite(MIA,LOW);
digitalWrite(MIB,LOW);
analogWrite(MDA,velocidad);
digitalWrite(MDB,LOW);
}

void derecha(int velocidad){
analogWrite(MIA,velocidad);
digitalWrite(MIB,LOW);
digitalWrite(MDA,LOW);
digitalWrite(MDB,LOW);
}
//No la utilizamos en este caso, pero puede ser útil para modificaciones posteriores
void atras(int velocidad){
analogWrite(MIB,velocidad);
digitalWrite(MIA,LOW);
analogWrite(MDB,velocidad);
digitalWrite(MDA,LOW);
}
//Función de lectura de sensores siguelíneas leeSuelo()
int leeSuelo(){
//Los sensores dan 1 para negro, 0 para blanco. Valor recoge el total de las lecturas
int valor=0;
//Si pisamos por la derecha, sumamos 1
if (digitalRead(sDerecha)==HIGH){
 valor=valor+1;
}
//Si pisamos por la derecha, sumamos 2
if (digitalRead(sIzquierda)==HIGH){
valor=valor+2;
}
return valor;
}

//Configuración
void setup() {
//Pines en modo lectura/escritura
pinMode(MIA,OUTPUT);
pinMode(MIB,OUTPUT);
pinMode(MDA,OUTPUT);
pinMode(MDB,OUTPUT);
pinMode(sDerecha, INPUT);
pinMode(sIzquierda, INPUT);
valorLeido=0;
}
//Masaylo empieza su singladura
void loop() {
//Llamamos a la función de lectura de los sensores
valorLeido=leeSuelo();
//Decidimos según lectura
switch(valorLeido){
case 3:
alto();
break;
case 1:
derecha(150);
break;
case 2:
izquierda(150);
break;
case 0:
adelante(130);
break;
}
}

