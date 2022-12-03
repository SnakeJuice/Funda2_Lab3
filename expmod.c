#include "gmp.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void expmod(mpz_t a,  mpz_t e){
	mpz_t result;
	mpz_init(result);
	mpz_set_ui(result, 0);


	if (mpz_cmp_si(e,0) == 0) { // If exponent is zero
		mpz_set_ui(result, 1); // result = 1
		gmp_printf("\nEl resultado es: %Zd \n",result);
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
	mpz_clear(a);
	mpz_clear(e);

	//Imprimimos el resultado.
	gmp_printf("\nEl resultado es: %Zd \n", result);

	//Liberamos la memoria.
	mpz_clear(result);

}


int main(int argc, char * argv[]){
	mpz_t a, e;

	mpz_init(a);
	mpz_init(e);

	clock_t tiempo1, tiempo2;

	if (argc <= 2){
		printf ("Usage: %s <base> <exp> \n", argv[0]);
		return 2;
	}

	// Verificamos que los números sean positivos
	if (argv[1][0] == '-' || argv[2][0] == '-') {
		printf("Error: Ambos operandos deben ser enteros positivos.\n");
		return 2;
	}

	// Convertimos de string a mpz_t
	mpz_set_str(a, argv[1], 10);
	mpz_set_str(e, argv[2], 10);
	
	tiempo1 = clock();
	expmod(a,e);
	tiempo2 = clock();
	printf("\n\n\tTiempo de ejecución: %f\n" , ( (double)tiempo2 - (double)tiempo1 ) / ( (double)CLOCKS_PER_SEC ) );
	printf("\n");

	return 0;
}