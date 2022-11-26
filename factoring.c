#include "gmp.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void factoring(int n){
    mpz_t a;

    // Inicializamos las variables mpz_t.
    mpz_init(a);

    // Asignamos los valores del int n a mpz_t a.
    mpz_set_ui(a, n);

    // Mostramos el numero a factorizar.
    gmp_printf("El numero a factorizar es: %Zd\n", a);
}


int main(int argc, char * argv[]){
  int n;

  double time_spent = 0.0;
  clock_t begin = clock();


  if (argc <= 1){
    printf ("Usage: %s <n> \n", argv[0]);
    return 2;
  }

  n = atoi(argv[1]);
  factoring(n);

  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The elapsed time is %f seconds\n", time_spent);

  return 0;
}