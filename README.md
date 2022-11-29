# **Laboratorio 3**
* `mult.c` - Programa para multiplicar números grandes implementado con GMP
* `gcd.c` - Programa para obtener el máximo común divisor de números grandes utilizando el algoritmo Euclidiano e implementado con GMP
* `expmod.c` - Programa para calcular la potencia de números grandes implementado con GMP
* `factoring.c` Programa para obtener la factorización de números grandes utilizando el algoritmo Trial Division y Sieve de Eratothenes implementado con GMP

## Requisitos para compilación y ejecución

Se requiere de una distribución de Linux para ejecutar el programa, este fué creado y testeado en ese ambiente.

### Librerias utilizadas

* `GMP` - GNU Multiple Precision Arithmetic Library

Para utilizar esta librería se puede ingresar a https://gmplib.org/ y seguir los pasos que se especifican en el manual para su descarga e instalación.

Para las distros basadas en Debian como Ubuntu es más facil ya que se puede instalar con el siguiente comando
```
sudo apt-get install libgmp3-dev
```

## Como compilar
Para compilar solo se utiliza gcc, luego el nombre del programa en c y según lo especificado ocupando el comando -o se puede cambiar el nombre del programa compilado a 'bfnp', el ultimo atributo '-lgmp' es para cargar la libreria GMP
```
gcc 'nombre_del_programa'.c -o bfnp -lgmp
```
## Como ejecutar
```
./bfnp <número_1> ... <número_n>
```
Según lo requiera el programa, de todas maneras si se ejecuta sin ingresar ningúna variable se mostrará en consola como ejecutarlo de la manera correcta.

