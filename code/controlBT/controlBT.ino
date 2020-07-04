//Incluimos la librería SoftwareSerial
#include<SoftwareSerial.h>
//Definimos el pinout
 const byte rxPin = 12;
 const byte txPin = 13;
#define MIA 5
#define MIB 6
#define MDA 9
#define MDB 10
//Declaramos una variable de tipo char
char valor;
//Declaramos un puerto serie emulado al que llamaremos miSerial en los pines especificados
SoftwareSerial miSerial(rxPin, txPin);
void setup() {
  // La velocidad del puerto serie debe ser acorde a la del módulo BT
miSerial.begin(19200);
pinMode(MIA,OUTPUT);
pinMode(MIB,OUTPUT);
pinMode(MDA,OUTPUT);
pinMode(MDB,OUTPUT);
}

void loop() {
//Comprobamos si se ha recibido información nueva
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

void alto(){
  digitalWrite(MIA,LOW);
  digitalWrite(MIB,LOW);
  digitalWrite(MDA,LOW);
  digitalWrite(MDB,LOW);  


}
void adelante(){
  digitalWrite(MIA,HIGH);
  digitalWrite(MIB,LOW);
  digitalWrite(MDA,HIGH);
  digitalWrite(MDB,LOW); 
 
}

void izquierda(){
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
  digitalWrite(MIB,HIGH);
  digitalWrite(MIA,LOW);
  digitalWrite(MDB,HIGH);
  digitalWrite(MDA,LOW);  
}
