#include "gmp.h"
#include <stdio.h>
#include <stdlib.h>

//Función para multiplicar dos numeros grandes
void mult(int n, int m){
    mpz_t a, b, r;

    // Inicializamos las variables mpz_t
    mpz_init(a);
    mpz_init(b);
    mpz_init(r);

    // Asignamos los valores del int n y m a las variables mpz_t a y b.
    mpz_set_ui(a, n);
    mpz_set_ui(b, m);
    mpz_set_ui(r, 0);

    /*
    //Verificamos que a y b sean primos
    if (mpz_probab_prime_p(a, 25) == 0 && mpz_probab_prime_p(b, 25) == 0){
        printf("Ambos no son primos. Por lo tanto no se puede realizar la multiplicacion\n");
        return;
    }

    if (mpz_probab_prime_p(a, 25) == 0){
        gmp_printf("El primero numero %Zd no es primo\n", a);
        printf("Por lo tanto no se puede realizar la multiplicacion\n");
        return;
    }

    if (mpz_probab_prime_p(b, 25) == 0)
    {
        gmp_printf("El segundo numero %Zd no es primo\n", b);
        printf("Por lo tanto no se puede realizar la multiplicacion\n");
        return;
    }
    */

    //Calculamos el producto de a y b que se guarda en r
    mpz_mul(r, a, b);

    // Imprimimos el resultado en pantalla
    gmp_printf("%Zd * %Zd = %Zd\n", a, b, r);

    // Limpiamos las variables mpz_t
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(r);

}

int main(int argc, char * argv[]){
    int n, m;

    if (argc <= 2){
        printf ("Usage: %s <op1> <op2> \n", argv[0]);
        return 2;
    }

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    mult(n,m);

    return 1;
}