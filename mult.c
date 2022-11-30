#include "gmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Función para multiplicar dos numeros grandes
void mult(int n, int m){
    mpz_t a, b, r;

    // Inicializamos las variables mpz_t
    mpz_init(a);
    mpz_init(b);
    mpz_init(r);

    //Transformamos las variables int a enteros de GMP.
    mpz_set_ui(a, n);
    mpz_set_ui(b, m);
    mpz_set_ui(r, 0);

    //Calculamos el producto de a y b que se guarda en r
    mpz_mul(r, a, b); // r = a * b

    // Imprimimos el resultado en pantalla
    gmp_printf("%Zd * %Zd = %Zd\n", a, b, r);

    // Limpiamos las variables mpz_t
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(r);

}

int main(int argc, char * argv[]){
    int n, m;

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

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    tiempo1 = clock();
    mult(n,m);
    tiempo2 = clock();
    printf("\n\tTiempo de ejecución: %f\n" , ( (double)tiempo2 - (double)tiempo1 ) / ( (double)CLOCKS_PER_SEC ) );
    printf("\n");

    return 1;
}