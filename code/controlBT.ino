#include<SoftwareSerial.h>
#include <BitbloqUS.h>
char valor='o';
 const byte rxPin = 12;
 const byte txPin = 13;
#define MIA 5
#define MIB 6
#define MDA 9
#define MDB 10
#define sDerecha 3
#define sIzquierda 2
#define enIzq 4
#define enDer 11
int valorLeido;
US ultrasonidos( 7,8);
 SoftwareSerial miSerial(rxPin, txPin);
void setup() {
  // put your setup code here, to run once:
     miSerial.begin(19200);
pinMode(MIA,OUTPUT);
pinMode(MIB,OUTPUT);
pinMode(MDA,OUTPUT);
pinMode(MDB,OUTPUT);
pinMode(13,OUTPUT);
pinMode(sDerecha, INPUT);
pinMode(sIzquierda, INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
valorLeido=0;
pinMode(enIzq,OUTPUT);
pinMode(enDer,OUTPUT);

}

void loop() {

if (miSerial.available()>0){
  
    valor=miSerial.read();
    
  //  Serial.println(valor);
    if (valor=='a'){
      adelante();
    }
    if (valor=='r'){
      atras();
    }
    if (valor=='i'){
      izquierda();
    }
    if (valor=='d'){
      derecha();
    }
        if (valor=='p'){
      alto();
    }
  }

}
float mideDistancia () {return ultrasonidos.read();}

int leeSuelo(){
  //Los sensores dan 1 para negro, 0 para blanco
  int valor=0;
  if (digitalRead(sDerecha)==HIGH){
  
    valor=valor+1;
  }
  if (digitalRead(sIzquierda)==HIGH){
    valor=valor+2;
  }
  return valor;
}
void alto(){
      digitalWrite(enIzq,LOW);
  digitalWrite(enDer,LOW);

  digitalWrite(MIA,LOW);
  digitalWrite(MIB,LOW);
  digitalWrite(MDA,LOW);
  digitalWrite(MDB,LOW);  


}
void adelante(){

    digitalWrite(enIzq,HIGH);
  digitalWrite(enDer,HIGH);

  digitalWrite(MIA,HIGH);
  digitalWrite(MIB,LOW);
  digitalWrite(MDA,HIGH);
  digitalWrite(MDB,LOW); 
 
}
void adelante( int velocidad){
      analogWrite(enIzq,velocidad);
  analogWrite(enDer,velocidad);
   digitalWrite(MIA,HIGH);
  digitalWrite(MIB,LOW);
  digitalWrite(MDA,HIGH);
  digitalWrite(MDB,LOW);  

}
void izquierda(){
      digitalWrite(enIzq,LOW);
  digitalWrite(enDer,HIGH);

  digitalWrite(MIA,LOW);
  digitalWrite(MIB,LOW);
  digitalWrite(MDA,HIGH);
  digitalWrite(MDB,LOW);  


}
void izquierda(int velocidad){
      analogWrite(enDer,velocidad);
  digitalWrite(enIzq,LOW);
  digitalWrite(MIA,LOW);
  digitalWrite(MIB,LOW);
  digitalWrite(MDA,HIGH);
  digitalWrite(MDB,LOW);  


}
void derecha(){
      digitalWrite(enIzq,HIGH);
  digitalWrite(enDer,LOW);

  digitalWrite(MIA,HIGH);
  digitalWrite(MIB,LOW);
  digitalWrite(MDA,LOW);
  digitalWrite(MDB,LOW);  


}
void derecha(int velocidad){
      analogWrite(enIzq,velocidad);
  digitalWrite(enDer,LOW);
  digitalWrite(MIA,HIGH);
  digitalWrite(MIB,LOW);
  digitalWrite(MDA,LOW);
  digitalWrite(MDB,LOW);  


}
void atras(){
      digitalWrite(enIzq,HIGH);
  digitalWrite(enDer,HIGH);

  digitalWrite(MIB,HIGH);
  digitalWrite(MIA,LOW);
  digitalWrite(MDB,HIGH);
  digitalWrite(MDA,LOW);  

}
void atras(int velocidad){
      analogWrite(enIzq,velocidad);
  analogWrite(enDer,velocidad);
   digitalWrite(MIB,HIGH);
  digitalWrite(MIA,LOW);
  digitalWrite(MDB,HIGH);
  digitalWrite(MDA,LOW);  

}