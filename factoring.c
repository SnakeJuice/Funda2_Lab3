#include "gmp.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void factoring(int a){
  mpz_t n;

  // Inicializamos las variables mpz_t.
  mpz_init(n);

  // Asignamos los valores del int n a mpz_t a.
  mpz_set_ui(n, a);

  // Mostramos el numero a factorizar.
  gmp_printf("El numero a factorizar es: %Zd\n", n);
}


int main(int argc, char * argv[]){
  int a;

  double time_spent = 0.0;
  clock_t begin = clock();


  if (argc <= 1){
    printf ("Usage: %s <n> \n", argv[0]);
    return 2;
  }

  a = atoi(argv[1]);
  factoring(a);

  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The elapsed time is %f seconds\n", time_spent);

  return 0;
}