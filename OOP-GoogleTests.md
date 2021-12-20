# Práctica 11. Programación Orientada a Objetos. Google Tests.

# Factor de ponderación: 10

### Objetivos
Los objetivos de esta práctica son que el alumnado:
* Desarrolle programas sencillos en C++ utilizando clases, así como todas las características del lenguaje estudiadas anteriormente
* Conozca el framework de testing de Google (Google Tests) y sea capaz de desarrollar tests unitarios sencillos
* Conozca la herramienta CMake y sepa usarla para construir sus programas ejecutables
* Incluya en sus programas comentarios adecuados en el formato requerido por Doxygen
* Aloje todo el código fuente de sus programas en repositorios privados de GitHub
* Sepa depurar sus programas usando la interfaz de depuración del VSC


### Rúbrica de evaluacion de esta práctica
Todo el código que se presente a evaluación ha de cumplir los estándares definidos en la 
[Guía de Estilo de Google para C++](https://google.github.io/styleguide/cppguide.html).

Se señalan a continuación otros aspectos (la lista no es exhaustiva) que se tendrán en cuenta a la hora de evaluar esta práctica.
El alumnado ha de acreditar que:

* Conoce los conceptos expuestos en el material de referencia de esta práctica.
* Ha realizado todos los ejercicios propuestos, así como que es capaz de desarrollar otros de complejidad similar.
* Es capaz de escribir un fichero CMakeLists.txt para automatizar el proceso de compilación de sus programas.
* Todos sus programas se estructuran en directorios diferentes para cada "proyecto" haciendo que cada uno de
  ellos contenga un fichero `CMakeLists.txt` con la configuración de despliegue del proyecto.
* Se ha programado un conjunto mínimo de tests unitarios que comprueban el correcto funcionamiento de las
  funciones y métodos que se desarrollan para resolver los ejercicios.
* Todas las prácticas realizadas hasta la fecha se encuentran alojadas en repositorios de
[GitHub](https://github.com/).
* Los programas deben contener comentarios adecuados en el formato requerido por 
  [Doxygen](https://www.doxygen.nl/index.html).
* Sus programas se compilan correctamente utilizando la utilidad `make` y un fichero `Makefile`.
* Todos los identificadores que utilice en su programa (constantes, variables, etc.) deberán ser
  siempre significativos. No utilice nunca identificadores de una única letra, tal vez con la excepción de las variables que utilice para iterar en un bucle.
* Sabe editar y modificar sus programas usando VSC con una conexión remota a la máquina virtual Linux de la asignatura.
* Ha realizado todos sus ejercicios en la máquina virtual Ubuntu de la asignatura.
* Todos los programas que desarrolla, antes de su ejecución imprimen en pantalla un mensaje indicando la finalidad del programa así como la información que precisará del usuario para su correcta ejecución.
* Todos sus programas contienen comentarios adecuados en el formato requerido por Doxygen.
* Todos los ficheros de código del proyecto correspondiente a esta práctica están alojados en un repositorio
  de GitHub
* Conoce las técnicas básicas de depuración usando VSC y su depurador integrado.

### La plataforma de testing de Google
Tal como recoge la
[Wikipedia](https://es.wikipedia.org/wiki/Desarrollo_guiado_por_pruebas),
El desarrollo dirigido por tests (TDD, *Test Driven Development* por sus siglas en inglés) es una práctica de 
ingeniería de software que involucra otras dos técnicas: 
escribir las pruebas primero (Test First Development) y 
[Refactorización](https://es.wikipedia.org/wiki/Refactorizaci%C3%B3n)
(Refactoring) o reestructuración del código.
Para escribir las pruebas generalmente se utilizan las pruebas unitarias (unit test en inglés). 

El TDD se basa en la repetición de un ciclo de desarrollo muy corto que
involucra la repetición de tres pasos:
1. En primer lugar el desarrollador escribe un caso de prueba (test) que falla (a propósito) y que define una mejora deseada (habitualmente una nueva función o método)
2. A continuación se desarrolla el código (de la función) que hace que la prueba pase satisfactoriamente 
3. Finalmente refactoriza el nuevo código hasta obtener un resultado satisfactorio

Esta imagen representa este ciclo repetitivo característico del TDD.

![TDD cycle](https://raw.githubusercontent.com/ULL-ESIT-IB-2021-2022/P11-OOP-GoogleTests/main/red-green-refactor.png "Red-Green-Refactor")

El propósito del desarrollo guiado por pruebas es lograr un código limpio que funcione correctamente.
La idea es que los requisitos sean traducidos a pruebas (tests), y de este modo, cuando las pruebas pasen 
se garantizará que el software cumple con los requisitos que se han establecido.


Las "unidades" de código para las que se realizan tests habitualmente son clases, funciones o grupos ellas. 
Supongamos por ejemplo que se está implementando una función (unidad de código) que calcula la suma de dos números enteros.
Una prueba (test unitario) es un código que valida la corrección de esa función: se podría comprobar que lo
que reciba la función sean realmente dos parámetros, y que esos dos parámetros sean números, y que lo que
devuelva la función sea otro número, y que ese número corresponda realmente con la suma. 
Todas estas podrían ser posibles pruebas unitarias que se realicen sobre la función.
Las pruebas unitarias  se suelen realizar utilizando entornos de pruebas (testing) especializados.

Existen diversas plataformas para el desarrollo de tests unitarios en C++.
Algunas de las de uso más extendido son
[Boost.Test](https://www.boost.org/doc/libs/1_49_0/libs/test/doc/html/index.html),
[CppUnit](https://sourceforge.net/projects/cppunit/),
[Cute](https://cute-test.com/)
aunque hay
[muchas otras](https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C++)

En esta práctica se propone utilizar el framework 
[Google Test](https://en.wikipedia.org/wiki/Google_Test),
(también conocido como gtest) que es una librería de pruebas unitarias (*unit tests*) para C++.
El entorno permite que los tests se ejecuten de una en uno o todos a la vez. 
Google Tests puede ser utilizado en 
[Visual Studio Code](https://docs.microsoft.com/es-es/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2019), 
aunque en este documento se propone un uso de la plataforma de modo independiente de VSC.

El primer paso para usar gtest es su instalación. 
Siga para ello los siguientes pasos:

```
$ git clone https://github.com/google/googletest.git -b release-1.10.0
$ cd googletest/
$ mkdir build
$ cd build/
$ cmake .. -DBUILD_GMOCK=OFF
$ make
$ sudo make install
```
que se explican en el documento 
[Standalone CMake Project](https://github.com/google/googletest/blob/master/googletest/README.md#standalone-cmake-project).
El comando `sudo make install` (obsérvese que se ejecuta con privilegios de *root*) 
instalará gtest en el directorio `/usr/local/` del sistema , de modo que en los directorios
```
/usr/local/include
/usr/local/lib
```
se alojan los ficheros de cabecera (`*.h`) y las librerías (`*.a`) necesarios para usar gtest.
Una vez instalada la librería puede eliminar el directorio `googletest` en el que copió el repositorio.

El repositorio de esta práctica contiene un directorio `gtests` con el siguiente contenido:
```
gtests
  ├── CMakeLists.txt
  ├── src
  │   ├── addition.cc
  │   ├── addition.h
  │   ├── date.cc
  │   ├── date_client_program.cc
  │   ├── date.h
  │   ├── factorial.cc
  │   ├── factorial.h
  │   ├── formula.cc
  │   ├── formula.h
  │   ├── main_program.cc
  │   ├── multiply.cc
  │   ├── multiply.h
  │   ├── sample2.cc
  │   ├── sample2.h
  │   ├── square_root.cc
  │   └── square_root.h
  └── test
      ├── gtest_main.cc
      ├── sample2_unittest.cc
      ├── test_addition.cc
      ├── test_date.cc
      ├── test_factorial.cc
      ├── test_formula.cc
      ├── test_multiply.cc
      └── test_square_root.cc
```
Siguiendo la costumbre habitual, el subdirectorio `src` contiene el código fuente del proyecto, que en este
caso es un proyecto ficticio que se usa para ilustrar el uso de tests unitarios.
A modo de ejemplo, el programa principal del proyecto `main_program.cc` (véase su código fuente)
invoca a diferentes funciones de carácter matemático que han sido
desarrolladas por el usuario (ficheros `src/*.cc` y `src/*.h`).

Compile el proyecto cuya configuración viene especificada en el fichero `CMakeLists.txt` ejecutando en el directorio
`gtests`:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```
Esta secuencia de comandos creará en el subdirectorio `build` sendos programas ejecutables: `user_program` y `runTests`.
El primero de ellos corresponde con el programa principal del usuario.
Pruebe a ejecutarlo y revise el código de las diferentes funciones que utiliza ese programa.

Por otra parte, el programa `runTests` ejecuta todos los tests unitarios que se han desarrollado para comprobar el correcto
funcionamiento de las diferentes funciones que intervienen en el programa del usuario.
Pruebe asimismo a ejecutarlo.
Ambos programas se pueden compilar de forma independiente ejecutando en el diectorio `build`:

```
$ make user_program
```
o bien:
```
$ make runTests
```

Estudie el contenido del fichero `CMakeLists.txt` y observe en el mismo (comandos `add_executable(runTests ...)`
y `add_executable(user_program)`) los ficheros que están involucrados en cada uno de los dos programas
anteriores.

Lo que más interesa estudiar a continuación es el contenido del directorio `tests`.
En ese directorio, el programa `gtest_main.cc` invoca la ejecución de todos los tests mientras que los
diferentes ficheros `test_*.cc` contienen los tests correspondientes a las diferentes funciones del usuario
que utiliza el programa `main_program.cc`.

Todos los ficheros del directorio `tests` contienen la línea
```
include <gtest/gtest.h>
```

de inclusión del fichero de cabecera donde se definen las macros y funciones de la librería de testing de
Google que se enlaza (*link*) con el programa.
Cada uno de esos ficheros contiene uno o más tests que tienen la siguiente estructura:
```
TEST(TestSuiteName, TestName) {
  ... test body ...
}
```
El primer parámetro de la macro TEST (`TestSuiteName`) es el nombre que se le da a un conjunto de tests
relacionados mientras que el segundo parámetro es el nombre que se le ha dado al test.

El test del fichero `test_date` es un ejemplo que comprueba métodos de una clase definida por el
usuario.
En este caso el test comprueba un par de métodos de la clase `Date`.

Los ficheros `test/sample2_unittest.cc` y  `src/sample2.*` están tomados de
[Googletest Samples](https://github.com/google/googletest/blob/master/googletest/docs/samples.md) 
donde se pueden hallar ejemplos adicionales de tests.

Estudie los tests que figuran en el directorio `gtests/test` para las diferentes funciones del ejemplo,
conjuntamente con la documentación del 
[Googletest Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)
para aprender sobre los diferentes tipos de 
[aserciones](https://es.wikipedia.org/wiki/Aserci%C3%B3n_(inform%C3%A1tica))
y comparaciones que soporta la plataforma para realizar sus tests.

En todos los programas C++ que desarrolle de ahora en adelante, utilice siempre gtests para comprobar la
corrección de todas sus funciones y métodos.
El enfoque (TDD) le ayudará a hallar los bugs de forma temprana de modo que podrá solucionarlos con un menor
coste en tiempo y esfuerzo.
La técnica de *testing* es fundamental para detectar cuanto antes potenciales errores.
Las funciones que han sido comprobadas mediante tests unitarios son siempre más fiables.
Para cada función que escriba de ahora en adelante, comience siempre por escribir antes que el código de la
función, al menos dos tests: uno para las situaciones "normales" y otro para situaciones "extremas".

La regla a seguir de ahora en adelante es **Convierta en un hábito la escritura de tests para sus programas**.
Desarrolle siempre sus funciones iterando el famoso ciclo TDD que ya se ha expuesto en este documento:
* Escriba un test que falle y que define una mejora deseada o una nueva función
* Escirba el código (función, método) que haga que la prueba pase satisfactoriamente 
* Finalmente refactoriza el nuevo código hasta obtener un resultado satisfactorio

Es fácil encontrar en la web mucha documentación sobre TDD. 
A modo de ejemplo e introducción se recomienda el estudio de
[Mejorar la calidad del código mediante la prueba unitaria](https://www.mql5.com/es/articles/1579).

#####################################
### Trabajo previo
Antes de realizar los ejercicios de esta práctica, estudie detenidamente el Capítulo 12 (epígrafes 12.1-12.15) del
[tutorial learncpp](https://www.learncpp.com/cpp-tutorial/81-welcome-to-object-oriented-programming/).
Muchos de los ejemplos de ese tutorial son los mismos que se utilizan en las clases de la asignatura,
cuyo material (transparencias y códigos de ejemplo) debiera Ud. también estudiar.

Ponga especial atención en estos ejercicios en seguir las normas de *Buenas prácticas* de programación a la
hora de diseñar programas orientados a objetos que se indican en las transparencias de la asignatura.

### Ejercicios
* Al realizar los ejercicios cree dentro de su repositorio de esta práctica un directorio diferente
con nombre significativo (personas, rectangulos, circulos p. ej.) para cada uno de ellos 
y con un contenido similar al que se ha entregado para la aplicación de ejemplo `fibonacci_sum`.
* Tómese como ejemplo el primero de los ejercicios y haga que cada uno de sus programas conste de 3 ficheros:
  * Un fichero `personas.cc` (programa principal) que contendrá la función `main` e incluirá el fichero de cabecera `persona.h`.
  * El fichero `persona.h` que contendrá las declaraciones correspondientes a la clase `Persona`.
  * El fichero `persona.cc` que contendrá el código (definiciones) correspondientes a la clase `Persona`.
  * Obviamente si el programa principal (`personas.cc`) utiliza otras clases, debería incluir (`#include`) los
  correspondientes ficheros de cabecera.
  * Modifique estos nombres de ficheros para adaptarlos al ejercicio en cuestión.
* La compilación del programa correspondiente a cada ejercicio se automatizará con un fichero `CMakeLists.txt`
que se utilizará con `cmake`.
Así pues, la estructura de directorios y sus contenidos correspondiente al primero de los ejercicios
propuestos sería la siguiente:
```
01-persona
    ├── build           // Directorio inicialmente vacío para alojar el programa ejecutable
    ├── CMakeLists.txt  // Fichero de configuración para cmake
    └── src             // Directorio contenedor del código fuente del ejercicio
        ├── persona.cc
        ├── persona.h
        └── persona_main.cc
```
* Desarrolle cada ejercicio de forma incremental, probando cada una de las funciones que va Ud.
desarrollando. 
* Utilice el depurador integrado de VSC para depurar los programas de modo que funcionen correctamente.
* Todos estos programas han de tomar su entrada (si es que hay alguna) como parámetros pasados por línea de comandos.
* Para cada una de las clases que se pide desarrollar, desarrolle también un programa cliente (el que
contendrá la función *main()*) que declare objetos de la clase en cuestión y compruebe el correcto
funcionamiento de los métodos de la clase.

1. Desarrolle una clase `Persona` cuyos objetos han de contener al menos atributos para representar nombre,
apellidos y la edad de la persona.
Incluya asimismo un método *Print()* que permita imprimir en pantalla la información de una instancia de la
clase.

Para este ejercicio se ha incluido un directorio `01-persona` que incluye un esqueleto básico para la clase a
desarrollar así como un fichero `CMakeLists.txt` para su compilación.

2. Desarrolle una clase `Rectangulo` que contemple como atributos la anchura y altura del rectángulo.
Incluya métodos que permitan calcular el área y el perímetro del rectángulo representado y un método
*Display()* que permita mostrar la información correspondiente a un objeto rectánculo de la clase.

3. Desarrolle una clase `CuentaBancaria` que contemple como atributos 
* El número de la cuenta (20 dígitos)
* El nombre del titular
* El saldo de la cuenta

Incluya asimismo al menos los siguientes métodos:
* Un constructor que tome como parámetros el el número de cuenta, el titular y el saldo
* *Depositar* que permita aumentar el saldo de la cuenta en una cierta cantidad
* *Extraer* que permita retirar una cierta cantidad de dinero
* *Mostrar* que permita mostrar los detalles de la cuenta
* *Impuestos* que calcule un impuesto del 5% sobre el saldo de la cuenta

4. Desarrolle una clase `Point2D` para representar puntos en el espacio bidimensional a través de sus
coordenadas. 
Incluya al menos los siguientes métodos:
* *Show()* para mostrar en pantalla las coordenadas del punto
* *Move* para cambiar las coordenadas del punto
* *Distance* para calcular la 
[distancia](https://www.mathwarehouse.com/algebra/distance_formula/index.php)
entre dos puntos
* *Middle* para calcular el 
[punto medio](https://en.wikipedia.org/wiki/Midpoint)
del segmento que une dos puntos

5. Diseñe una clase `Circulo` que permita representar círculos utilizando como atributos el centro 
y el radio del círculo.
Incluya métodos *Area*, *Perimetro* y *Print* que permitan respectivamente calcular el área, el perímetro del
círculo así como imprimir en pantalla la información relativa al círculo en cuestión.
Incluya asimimsmo un método *EsInterior* que determine si un punto del espacio cartesiano `(x, y)` está o no
dentro del círculo.

6. Desarrolle una clase `Vector3D` para representar vectores en el espacio tridimensional.
La clase contemplará métodos al menos para:
* Imprimir en pantalla las componentes de un vector en un formato adecuado 
* Sumar un par de vectores
* Calcular el producto de un número real por un vector
* Calcular el producto escalar de dos vectores
* Calcular el módulo de un vector 
* Normalizar un vector

7. Desarrolle una clase `Calcula` que permita la realización de diferentes cálculos con números enteros.
Incluya los siguientes métodos en la clase:
* *Factorial* que permita calcular el factorial de un número
* *Suma* que calcule la suma de los primeros `n` números: `1 + 2 + 3 + ... + n`.
* *EsPrimo* que permita determinar si un determinado número es primo
* *SonPrimosRelativos* que permita determinar si dos números son
[mutuamente primos](https://en.wikipedia.org/wiki/Coprime_integers),
es decir, si su único divisor común es el 1
* *TablaMultiplicar* que imprima en pantalla la tabla de multiplicar de un determinado número
* *TodasTablasMultiplicar* que imprima en un fichero todas las tablas de multiplicación entera para 1, 2, ..., 9.
La función *main* del programa que usara esta clase podría contener sentencias como:
```
main() {
  Calcula calcula; 
  std::cout << calcula.Factorial(5) << std::endl; 
  std::cout << calcula.Suma(100) << std::endl; 
  std::cout << calcula.EsPrimo(13) << std::endl; 
  std::cout << calcula.SonPrimosRelativos(13, 17) << std::endl; 
}
```

8. La clase Fecha.

Desarrolle una clase `Fecha` que permita representar y gestionar fechas.
Incorpore en la clase los miembros de datos y métodos que considere adecuados para la finalidad que se
persigue en este ejercicio.
Incluya un método que permita determinar si el año correspondiente a una fecha es un año bisiesto o
no.
Resuelva el problema 
[Valid Dates](https://jutge.org/problems/P58459_en)
de Jutge y súbalo a la plataforma para su evaluación.
A partir de la solución de ese problema haga que el constructor de la clase `Fecha` solo admita una fecha si
es válida.

Realice un programa cliente `fechas.cc` que tome como parámetro una fecha, un número y un nombre de fichero:
```
./fechas - Gestión de fechas
Modo de uso: ./fechas dd/mm/aa N fichero_salida.txt
Pruebe ./fechas --help para más información
```
El programa deberá imprimir en el fichero de salida (tercer parámetro) las N (segundo parámetro) fechas cronológicamente posteriores a la
introducida (primer parámetro) con una separación de un día entre fechas sucesivas.

### Referencias
* [CMake](https://es.wikipedia.org/wiki/CMake)
* [Introduction to modern CMake for beginners](https://www.internalpointers.com/post/modern-cmake-beginner-introduction)
* [Welcome to object-oriented programming - Tutorial learnCPP](https://www.learncpp.com/cpp-tutorial/81-welcome-to-object-oriented-programming/).
*	[Class code and header files](https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)
* [Header guards](https://www.learncpp.com/cpp-tutorial/header-guards/)
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* [Comments](https://google.github.io/styleguide/cppguide.html#Comments)
* [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html)
* [Doxygen](https://en.wikipedia.org/wiki/Doxygen)
