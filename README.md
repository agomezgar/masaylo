# Robot educativo Masaylo
Estoy intentando desarrollar un robot compatible con Arduino impreso en 3D, Masaylo, de tipo Low-Cost, propulsado por motores DC de los típicos que podemos encontrar en cualquier Aula-Taller de Tecnología.
A medida que progresemos intentaremos dotar al proyecto de una estructura algo más modular y coherente.

## Apariencia general
![Test Image 1](https://github.com/agomezgar/masaylo/blob/master/Images/masayloGeneral.png?s=50)
Utilizaremos: un Arduino nano con su correspondiente shield de expansión, un módulo L298N para gobernar dos motores DC, una rueda loca de 25x13 cm (o similar), un módulo sensor de ultrasonidos de tipo HC-SR04, dos sensores de infrarrojos de tipo FC-51 y un módulo BT modelo HC-05 o HC-06 que posiblemente habrá que tunear mediante comandos AT (o no; lo fundamental es saber a qué velocidad vamos a comunicarnos con él, y el código original espera que trabajemos a 19200 baudios; si es más cómodo para vosotros, podéis modificar el código para que trabaje a 9600 baudios).

## BOM (Bill of Materials; qué necesitamos)
Para empezar, aquí os dejo el [BOM generado por Fritzing](https://github.com/agomezgar/masaylo/blob/master/BOM.pdf)

