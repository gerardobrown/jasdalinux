#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dado1, dado2, suma;
    int gano = 0, terminado = 0;
    int intento = 1;

    srand(time(NULL));

    printf("--- Juego del Gran 8 ---\n");
    printf("Si sale 8 ganas, si sale 7 pierdes.\n\n");

    while (!terminado) {
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
        suma = dado1 + dado2;

        printf("Intento %d: dado1=%d, dado2=%d, suma=%d\n", intento, dado1, dado2, suma);

        if (suma == 8) {
            gano = 1;
            terminado = 1;
        } else if (suma == 7) {
            gano = 0;
            terminado = 1;
        }

        intento++;
    }

    if (gano) {
        printf("\nGanaste! Salio 8.\n");
    } else {
        printf("\nPerdiste. Salio 7.\n");
    }

    return 0;
}
