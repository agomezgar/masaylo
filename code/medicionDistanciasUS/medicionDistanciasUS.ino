//Definimos los pines echo y trigger
#define trig 7
#define echo 8
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
void setup() {
//trigger es OUTPUT, echo INPUT
pinMode(trig, OUTPUT);
pinMode(echo,INPUT);
//Inicializamos el puerto serie
Serial.begin(9600);
}

void loop() {
 //Utilizamos una variable local
long distancia=dameDistancia();
//Imprimimos la variable por el puerto serie
Serial.print("Distancia: ");
Serial.println(distancia);
//Tiempo mínimo para evitar desfases
delay(100);
}
