#include "gmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Función para multiplicar dos numeros grandes
void mult(mpz_t a, mpz_t b){
    mpz_t r;
    mpz_init(r);

    mpz_set_ui(r, 0);

    //Calculamos el producto de a y b que se guarda en r
    mpz_mul(r, a, b); // r = a * b

    // Imprimimos el resultado en pantalla
    gmp_printf("\nEl producto de a y b es: %Zd", r);

    // Limpiamos las variables mpz_t
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(r);

}

int main(int argc, char * argv[]){
    mpz_t n, m;

    // Inicializamos las variables mpz_t
    pz_init(n);
    mpz_init(m);

    clock_t tiempo1, tiempo2;


    if (argc <= 2){
        printf ("Usage: %s <op1> <op2> \n", argv[0]);
        return 2;
    }

        // Verificamos que los números sean positivos
    if (argv[1][0] == '-' || argv[2][0] == '-') {
        printf("Error: Ambos operandos deben ser enteros positivos.\n");
        return 2;
    }

    // Convertimos de string a mpz_t
    mpz_set_str(n, argv[1], 10);
    mpz_set_str(m, argv[2], 10);

    tiempo1 = clock();
    mult(n,m);
    tiempo2 = clock();
    printf("\n\n\tTiempo de ejecución: %f\n" , ( (double)tiempo2 - (double)tiempo1 ) / ( (double)CLOCKS_PER_SEC ) );
    printf("\n");

    return 1;
}