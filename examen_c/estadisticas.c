#include <stdio.h>
#include <math.h>

int main() {
    float notas[5];
    float media, mediana, rango, varianza, desviacion;
    float suma = 0, sumaCuadrados = 0;
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("Calificacion %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    // media
    for (i = 0; i < 5; i++) {
        suma += notas[i];
    }
    media = suma / 5;

    // ordenar (burbuja, con 5 datos no importa que no sea el metodo mas rapido)
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (notas[j] > notas[j + 1]) {
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }

    // mediana, con 5 datos ya ordenados es el de en medio
    mediana = notas[2];

    // moda, con solo 5 datos lo hago facil comparando contra todos
    float moda = -1;
    int maxRepeticiones = 0;
    for (i = 0; i < 5; i++) {
        int contador = 0;
        for (j = 0; j < 5; j++) {
            if (notas[j] == notas[i]) {
                contador++;
            }
        }
        if (contador > maxRepeticiones) {
            maxRepeticiones = contador;
            moda = notas[i];
        }
    }

    rango = notas[4] - notas[0];

    for (i = 0; i < 5; i++) {
        sumaCuadrados += (notas[i] - media) * (notas[i] - media);
    }
    varianza = sumaCuadrados / 5;
    desviacion = sqrt(varianza);

    printf("\n--- Estadisticas ---\n");
    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    if (maxRepeticiones > 1) {
        printf("Moda: %.2f (se repite %d veces)\n", moda, maxRepeticiones);
    } else {
        printf("Moda: no hay moda, todos los valores son distintos\n");
    }
    printf("Rango: %.2f\n", rango);
    printf("Varianza: %.2f\n", varianza);
    printf("Desviacion estandar: %.2f\n", desviacion);

    return 0;
}
