#include "gmp.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gcd(int n, int m)
{
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
  //gmp_printf("a = %Zd y b = %Zd\n", a, b);
  
  // También se puede calcular con esta función para facilitar su uso
  //mpz_gcd(r, a, b);

  //Calculamos el máximo común divisor
  while (mpz_cmp_ui(b, 0) != 0)  // mpz_cmp_ui: Compare op1 and op2. Return a positive value if op1 > op2, zero if op1 = op2, or a negative value if op1 < op2. 
  {
    mpz_mod(r, a, b);
    mpz_set(a, b);
    mpz_set(b, r);
  }

  gmp_printf("El GCD es: %Zd \n", a);

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

  n = atoi(argv[1]);
  m = atoi(argv[2]);

  tiempo1 = clock();
  gcd(n,m);
  tiempo2 = clock();
  printf("\n\tTiempo de ejecución: %f\n" , ( (double)tiempo2 - (double)tiempo1 ) / ( (double)CLOCKS_PER_SEC ) );
  printf("\n");

  return 0;
}
