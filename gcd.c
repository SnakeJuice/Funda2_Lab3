#include "gmp.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gcd(mpz_t a, mpz_t b)
{
  mpz_t r;
  mpz_init(r);
  mpz_set_ui(r, 0); //r = 0
  
  // También se puede calcular con esta función para facilitar su uso
  //mpz_gcd(r, a, b);

  //Calculamos el máximo común divisor
  while (mpz_cmp_ui(b, 0) != 0)  // mpz_cmp_ui: Compare op1 and op2. Return a positive value if op1 > op2, zero if op1 = op2, or a negative value if op1 < op2. 
  {
    mpz_mod(r, a, b); // r = a mod b
    mpz_set(a, b); // a = b
    mpz_set(b, r); // b = r
  }

  gmp_printf("\nEl GCD es: %Zd \n", a);

  //Liberamos la memoria.
  mpz_clear(a);
  mpz_clear(b);
  mpz_clear(r);

}

int main(int argc, char * argv[]){
	mpz_t n, m;

	mpz_init(n);
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
  	gcd(n,m);
  	tiempo2 = clock();
  	printf("\n\tTiempo de ejecución: %f\n" , ( (double)tiempo2 - (double)tiempo1 ) / ( (double)CLOCKS_PER_SEC ) );
  	printf("\n");

  	return 0;
}
