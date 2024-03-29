# Robot educativo Masaylo
Estoy intentando desarrollar un robot compatible con Arduino impreso en 3D, Masaylo, de tipo Low-Cost, propulsado por motores DC de los típicos que podemos encontrar en cualquier Aula-Taller de Tecnología.
A medida que progresemos intentaremos dotar al proyecto de una estructura algo más modular y coherente.

## Apariencia general

<img src="./Images/masayloGeneral.png" width="400" height="300">
Utilizaremos: un Arduino nano con su correspondiente shield de expansión, un módulo L298N para gobernar dos motores DC, una rueda loca de 25x13 cm (o similar), un módulo sensor de ultrasonidos de tipo HC-SR04, dos sensores de infrarrojos de tipo FC-51 y un módulo BT modelo HC-05 o HC-06 que posiblemente habrá que tunear mediante comandos AT (o no; lo fundamental es saber a qué velocidad vamos a comunicarnos con él, y el código original espera que trabajemos a 19200 baudios; si es más cómodo para vosotros, podéis modificar el código para que trabaje a 9600 baudios).

## BOM (Bill of Materials; qué necesitamos)
La lista de objetos impresos en 3D, electrónica y tornillería varia la he dejado en el documento ![BOM.md](./BOM.md) que tenéis en la raíz del repositorio

## Instrucciones de montaje
El montaje mecánico del robot es relativamente sencillo. Se incluyen todas las indicaciones en el documento ![Montaje](./montaje.md)

## Conexionado/pinout
El Masaylo es lo suficientemente sencillo para que el profe de Tecnología o aficionado a la Robótica elija su propio conexionado, de modo acorde a la Electrónica de que disponga (La única electrónica realmente necesaria es la shield de Arduino, el microcontrolador y el L298N o similar; el resto de sensores son optativos y sustituibles). No obstante, los códigos que se adjuntarán con diversos tutoriales están preparados para el siguiente ![pinout](./pinout/pinoutMasaylo.pdf)
