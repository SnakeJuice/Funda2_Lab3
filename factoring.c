#include "gmp.h"
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Create a function for sieve of eratosthenes to find prime numbers up to n and save them in an array
void sieve_of_eratosthenes(int a){
    mpz_t n;
    mpz_init(n);
    mpz_set_ui(n, a);

    int i, j;

    // Creamos un arreglo de tamaño n+1 e inicializamos todos sus elementos en 1
    int *array = (int *)malloc((mpz_get_ui(n)+1)*sizeof(int));
    for (i = 0; i <= mpz_get_ui(n); i++){
        array[i] = 1;
    }

    // Inicializamos los primeros dos números como no primos
    array[0] = 0;
    array[1] = 0;

    // Iteramos sobre los números del 2 al n y si el número es primo, iteramos sobre sus múltiplos y los marcamos como no primos
    for (i = 2; i <= sqrt(mpz_get_ui(n)); i++){
        if (array[i] == 1){
            for (j = i*i; j <= mpz_get_ui(n); j += i){
                array[j] = 0;
            }
        }
    }

    // Imprimimos todos los numeros primos
    for (i = 0; i <= mpz_get_ui(n); i++){
        if (array[i] == 1){
            printf("%d ", i);
        }
    }
    printf("\n");

    // Liberamos la memoria
    free(array);
    mpz_clear(n);

return;
}


int main(int argc, char * argv[]){
    int n;

    if(argc <= 1){
        printf("Usage: %s <n> \n", argv[0]);
        return 2;
    }

    // Verificamos que el número sea positivos
    if (argv[1][0] == '-') {
        printf("Error: El número deben ser un enteros postivo.\n");
        return 2;
    }

    n = atoi(argv[1]);

    sieve_of_eratosthenes(n);
}