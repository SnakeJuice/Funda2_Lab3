#include "gmp.h"
#include <stdio.h>
#include <stdlib.h>

void exp_bin(int n, int m){
    mpz_t a, b, r;

    // Inicializamos las variables mpz_t
    mpz_init(a);
    mpz_init(b);
    mpz_init(r);

    // Asignamos los valores del int n y m a las variables mpz_t a y b.
    mpz_set_ui(a, n);
    mpz_set_ui(b, m);
    mpz_set_ui(r, 0);

    // Imprimimos los valores de a y b en pantalla
    gmp_printf("a = %Zd y b = %Zd\n", a, b);

    mpz_set(r, a);

    //Calculamos la cantidad de numeros que tiene b en base 10
    int i = mpz_sizeinbase(b, 10);

    //TODO Calculamos el exponente binario 
    for (int i = i-2; i >= 0; i--){
        mpz_pow_ui(r, r, 2);
        if (mpz_tstbit(b, i) == 1){
            mpz_mul(r, r, a);
        }
    }

    // Imprimimos el resultado en pantalla
    gmp_printf("R_0 = %Zd\n", r);

    // Limpiamos las variables mpz_t
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(r);

}

int main(int argc, char * argv[]){
    int n, m;

    if (argc <= 2){
        printf ("Usage: %s <base> <exp> \n", argv[0]);
        return 2;
    }

    n = atoi(argv[1]);
    m = atoi(argv[2]);

    exp_bin(n,m);

    return 1;
}
