#include "gmp.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void expmod(int q,  int p){

  mpz_t a,e,result;

  //Inicializamos las variables.
  mpz_init(result);
  mpz_init(a);
  mpz_init(e);

  //Transformamos las variables int a enteros de GMP.
  mpz_set_ui(a, q); //a = q
  mpz_set_ui(e, p); //e = p


  if (mpz_cmp_si(e,0) == 0) { // If exponent is zero
    mpz_set_ui(result, 1); // result = 1
    gmp_printf("El resultado de %Zd^%Zd es: %Zd \n", a,e,result);
    return;
  }
  mpz_set(result, a); // result = a

  int i = mpz_sizeinbase(e, 2); // Obtenemos el tamaño del exponente en bits

  // Loop a lo largo de los bits de e del segundo bit más alto al más bajo
  for (i - 2; i >= 0; i--) {
    mpz_mul(result,result,result); // result = (result)^2
    if (mpz_tstbit(e, i)) { // Es el i-ésimo bit de e igual a 1?
      mpz_mul(result,result,a);// result = result * a
    }
  }

  //Imprimimos el resultado.
  gmp_printf("El resultado de %Zd^%Zd es: %Zd \n", a,e,result);

  //Liberamos la memoria.
  mpz_clear(a);
  mpz_clear(e);
  mpz_clear(result);

}


int main(int argc, char * argv[]){
  int a, e;

  clock_t tiempo1, tiempo2;

  if (argc <= 2){
    printf ("Usage: %s <base> <exp> \n", argv[0]);
    return 2;
  }

  a = atoi(argv[1]);
  e = atoi(argv[2]);
 
  tiempo1 = clock();
  expmod(a,e);
  tiempo2 = clock();
  printf("\n\tTiempo de ejecución: %f\n" , ( (double)tiempo2 - (double)tiempo1 ) / ( (double)CLOCKS_PER_SEC ) );
  printf("\n");

  return 0;
}