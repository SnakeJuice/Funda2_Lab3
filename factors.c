#include "gmp.h"
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

    mpz_t root;
    mpz_init(root);

    // Calculamos la raíz cuadrada de n
    mpz_sqrt(root, n);

    // Iteramos sobre los números del 2 al sqrt(n) y si el número es primo, iteramos sobre sus múltiplos y los marcamos como no primos
    for (i = 2; i <= mpz_get_ui(root); i++){
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

    // Creamos un arreglo para guardar los factores primos
    int *factors = (int *)malloc((mpz_get_ui(n)+1)*sizeof(int));


    while (mpz_cmp_ui(n, 1) != 0){ // Mientras n sea diferente de 1
        for (i = 2; i <= mpz_get_ui(n); i++){ // Iteramos sobre los números del 2 al n
            if (array[i] == 1 && mpz_divisible_ui_p(n, i) != 0){ // Si el número es primo y es factor de n
                mpz_divexact_ui(n, n, i); // Dividimos n entre el número primo
                printf("%d ", i); // Imprimimos el factor primo
                break; // Salimos del ciclo
            }
        }
    }
    printf("\n");

    // Liberamos la memoria
    free(array);
    free(factors);
    mpz_clear(n);
    mpz_clear(root);

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