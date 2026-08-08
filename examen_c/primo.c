#include <stdio.h>

int main() {
    int numero, i, esPrimo = 1;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if (numero < 2) {
        printf("El numero %d no es primo ni compuesto\n", numero);
    } else if (numero == 2) {
        printf("El numero %d es primo\n", numero);
    } else {
        for (i = 2; i * i <= numero; i++) {
            if (numero % i == 0) {
                esPrimo = 0;
                break;
            }
        }

        if (esPrimo == 1) {
            printf("El numero %d es primo\n", numero);
        } else {
            printf("El numero %d es compuesto\n", numero);
        }
    }

    return 0;
}
