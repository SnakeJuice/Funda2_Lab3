# **Laboratorio 3**
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
Para compilar solo se utiliza gcc, luego el nombre del programa en c y según lo especificado ocupando el comando -o se puede cambiar el nombre del programa compilado a 'bfnp', el ultimo atributo '-lgmp' es para cargar la librería GMP
```
gcc 'nombre_del_programa'.c -o bfnp -lgmp
```
## Como ejecutar
```
./bfnp -función <número_1> <número_2>
```

Se pueden seleccionar las siguientes funciones:

* `-mult` - Función para multiplicar números grandes implementado con GMP
* `-gcd` - Función para obtener el máximo común divisor de números grandes utilizando el algoritmo Euclidiano e implementado con GMP
* `-expmod` - Función para calcular la potencia de números grandes implementado con GMP.
* `-factors` Función para obtener los factores primos de un número utilizando el algoritmo Trial Division y Sieve de Eratothenes implementado con GMP.

En el caso de necesitar ver como se ejecuta cada función

```
./bfnp -h
```