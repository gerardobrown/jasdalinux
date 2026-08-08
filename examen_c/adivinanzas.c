#include <stdio.h>
#include <string.h>

void jugar() {
    char preguntas[5][100] = {
        "Tiene ciudad, no tiene casas; tiene bosques y no tiene arboles; tiene rios y no tiene agua. Que es?",
        "Blanca por dentro, verde por fuera, si quieres que te lo diga, espera",
        "Oro parece, plata no es, quien no lo sepa, bien tonto es",
        "Cien mujeres, un solo camison, todas se tapan con el mismo camison. Que es?",
        "Vuela sin alas, silba sin boca, y no se ve, ni se toca. Que es?"
    };
    char respuestas[5][30] = {"mapa", "pera", "platano", "cuerda_de_tender_ropa", "viento"};
    char respuestaUsuario[30];
    int puntaje = 0;
    int i;

    for (i = 0; i < 5; i++) {
        printf("\nAdivinanza %d: %s\n", i + 1, preguntas[i]);
        printf("Respuesta: ");
        scanf("%s", respuestaUsuario);


        if (strcmp(respuestaUsuario, respuestas[i]) == 0) {
            printf("Correcto!\n");
            puntaje++;
        } else {
            printf("Incorrecto. Era: %s\n", respuestas[i]);
        }
    }

    printf("\nAcertaste %d de 5 adivinanzas\n", puntaje);

    char nombre[50];
    printf("Ingresa tu nombre para guardar tu puntuacion: ");
    scanf("%s", nombre);

    FILE *archivo = fopen("historial.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }
    fprintf(archivo, "%s - %d/5\n", nombre, puntaje);
    fclose(archivo);
}

void verHistorial() {
    FILE *archivo = fopen("historial.txt", "r");
    if (archivo == NULL) {
        printf("\nNo hay historial todavia.\n");
        return;
    }

    char linea[100];
    printf("\n--- Historial de jugadores ---\n");
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
    fclose(archivo);
}

void borrarHistorial() {
    FILE *archivo = fopen("historial.txt", "w");
    if (archivo == NULL) {
        printf("Error al borrar el historial\n");
        return;
    }
    fclose(archivo);
    printf("\nHistorial borrado correctamente.\n");
}

int main() {
    int opcion = 0;

    while (opcion != 4) {
        printf("\n===== MENU =====\n");
	printf("ADVERTENCIA: NO USES LA TECLA ESPACIADORA, USA _\n");
        printf("1. Jugar a las adivinanzas\n");
        printf("2. Ver historial de jugadores\n");
        printf("3. Borrar historial de jugadores\n");
        printf("4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                jugar();
                break;
            case 2:
                verHistorial();
                break;
            case 3:
                borrarHistorial();
                break;
            case 4:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\nOpcion invalida, intenta de nuevo\n");
        }
    }

    return 0;
}
