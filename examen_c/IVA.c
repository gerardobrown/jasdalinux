#include <stdio.h>

int main() {
    float precio, sinIva, iva;

    printf("Precio con IVA incluido: Q");
    scanf("%f", &precio);

    sinIva = precio / 1.12;
    iva = precio - sinIva;

    printf("\nPrecio sin IVA: Q%.2f\n", sinIva);
    printf("Monto del IVA (12%%): Q%.2f\n", iva);

    return 0;
}
