
void setup() {
//Designamos los pines correspondientes como salidas
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
//Ponemos "1" y "0" según corresponda
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
//Esperamos un tiempo
delay(5000);
//Ponemos un "1" en las dos patillas a nivel bajo
digitalWrite(6,HIGH);
digitalWrite(10,HIGH);


}

void loop() {
//No queremos funcionamiento en bucle
}
