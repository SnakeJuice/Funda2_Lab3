#include <gmp.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void expmod(mpz_t a,  mpz_t e){
	mpz_t result;
	mpz_init(result);
	mpz_set_ui(result, 0);

	
	if (mpz_cmp_si(e,0) == 0) { // Si exponente es cero
		mpz_set_ui(result, 1); // result = 1
		gmp_printf("\nEl resultado es: %Zd \n",result);
		return;
	}
	mpz_set(result, a); // result = a

	int i = mpz_sizeinbase(e, 2); // Obtenemos el tamaño del exponente en bits

	// Loop a lo largo de los bits de e del segundo bit al último
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

void factors(mpz_t n){
    int i, j;

	mpz_t *array;

    // Creamos un arreglo de tamaño n+1 e inicializamos todos sus elementos en 1
    array = (mpz_t *)malloc((mpz_get_ui(n)+1)*sizeof(mpz_t));

    for (i = 0; mpz_cmp_ui(n, i) >= 0; i++){ // Mientras i sea menor o igual a n
		mpz_init_set_ui(array[i], 1);
    }

    // Inicializamos los primeros dos números como no primos
	mpz_init_set_ui(array[0], 0);
	mpz_init_set_ui(array[1], 0);

    mpz_t root;
    mpz_init(root);

    // Calculamos la raíz cuadrada de n
    mpz_sqrt(root, n);

    // Iteramos sobre los números del 2 al sqrt(n) y si el número es primo, iteramos sobre sus múltiplos y los marcamos como no primos
    for (i = 2; mpz_cmp_ui(root,i)  >= 0; i++){
        if (mpz_cmp_ui(array[i], 1) == 0){
            for (j = i*i; mpz_cmp_ui(root,j) >= 0; j += i){
				mpz_init_set_ui(array[j], 0);
            }
        }
    }
    mpz_clear(root);

    // Creamos un arreglo para guardar los factores primos
	mpz_t *factors;

    factors = (mpz_t *)malloc((mpz_get_ui(n)+1)*sizeof(mpz_t));


    while (mpz_cmp_ui(n, 1) != 0){ // Mientras n sea diferente de 1
        for (i = 2; mpz_cmp_ui(n,i) >= 0; i++){ // Iteramos sobre los números del 2 al n
            if (mpz_cmp_ui(array[i], 1) == 0 && mpz_divisible_ui_p(n, i) != 0){ // Si el número es primo y es factor de n
                mpz_divexact_ui(n, n, i); // Dividimos n entre el número primo
                printf("%d ", i); // Imprimimos el factor primo
                break; // Salimos del ciclo
            }
        }
    }
    printf("\n");

    // Liberamos la memoria
    mpz_clear(n);

return;
}

void mult(mpz_t a, mpz_t b){
    mpz_t r;
    mpz_init(r);

    mpz_set_ui(r, 0);

    //Calculamos el producto de a y b que se guarda en r
    mpz_mul(r, a, b); // r = a * b

    // Imprimimos el resultado en pantalla
    gmp_printf("\nEl producto de a y b es: %Zd\n", r);

    // Limpiamos las variables mpz_t
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(r);

}

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

    // Inicializamos las variables mpz_t
    mpz_init(n);
    mpz_init(m);

    clock_t tiempo1, tiempo2;

    // Verificar si el primer argumento es "mult", "expmod", "gcd o "factors"
    if (strcmp(argv[1], "-mult") == 0){
        if (argc <= 3){
            printf ("Usage: %s <op1> <op2> \n", argv[0]);
            return 2;
        }
        if (argv[2][0] == '-' || argv[3][0] == '-') {
            printf("Error: Ambos operandos deben ser enteros positivos.\n");
            return 2;
        }

        // Convertimos los argumentos de entrada en enteros grandes
        mpz_set_str(n, argv[2], 10);
        mpz_set_str(m, argv[3], 10);

        tiempo1 = clock();
        // Llamamos a la función mult
        mult(n,m);
        tiempo2 = clock();

        printf("\nTiempo de ejecución: %f segundos.\n", (double)(tiempo2 - tiempo1) / CLOCKS_PER_SEC);
        printf("\n");
        return 2;
    }
    else if (strcmp(argv[1], "-expmod") == 0){
        if (argc <= 3){
            printf ("Usage: %s <op1> <op2> \n", argv[0]);
            return 2;
        }
        if (argv[2][0] == '-' || argv[3][0] == '-') {
            printf("Error: Ambos operandos deben ser enteros positivos.\n");
            return 2;
        }

        // Convertimos los argumentos de entrada en enteros grandes
        mpz_set_str(n, argv[2], 10);
        mpz_set_str(m, argv[3], 10);

        tiempo1 = clock();
        // Llamamos a la función expmod
        expmod(n,m);
        tiempo2 = clock();

        printf("\nTiempo de ejecución: %f segundos.\n", (double)(tiempo2 - tiempo1) / CLOCKS_PER_SEC);
        printf("\n");

        return 2;
    }
    else if (strcmp(argv[1], "-gcd") == 0){
        if (argc <= 3){
            printf ("Usage: %s <op1> <op2> \n", argv[0]);
            return 2;
        }
        if (argv[2][0] == '-' || argv[3][0] == '-') {
            printf("Error: Ambos operandos deben ser enteros positivos.\n");
            return 2;
        }
        
        // Convertimos los argumentos de entrada en enteros grandes
        mpz_set_str(n, argv[2], 10);
        mpz_set_str(m, argv[3], 10);

        tiempo1 = clock();
        // Llamamos a la función gcd
        gcd(n,m);
        tiempo2 = clock();

        printf("\nTiempo de ejecución: %f segundos.\n", (double)(tiempo2 - tiempo1) / CLOCKS_PER_SEC);
        printf("\n");

        return 2;
    }
    else if (strcmp(argv[1], "-factors") == 0){
        if (argc <= 2){
            printf ("Usage: %s <n> \n", argv[0]);
            return 2;
        }
        if (argv[2][0] == '-') {
            printf("Error: Ambos operandos deben ser enteros positivos.\n");
            return 2;
        }

        // Convertimos los argumentos de entrada en enteros grandes
        mpz_set_str(n, argv[2], 10);

        tiempo1 = clock();
        // Llamamos a la función factors
        factors(n);
        tiempo2 = clock();

        printf("\nTiempo de ejecución: %f segundos.\n", (double)(tiempo2 - tiempo1) / CLOCKS_PER_SEC);
        printf("\n");

        return 2;
    }
    else{
        printf("Error: El primer argumento debe ser 'mult', 'expmod', 'gcd' o 'factors'.\n");
        return 2;
    }
    
    printf("\n");

    return 1;
}