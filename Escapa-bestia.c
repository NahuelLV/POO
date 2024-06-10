#include <stdio.h>
#include <stdlib.h>

void limpiarPantalla() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

char crearTablero(char *dificultad) {
    printf("F)Facil\nM)Media\nD)Dificil\nElija la dificultad: ");
    scanf(" %c", dificultad);  // Note the space before %c to consume any leading whitespace
    printf("\n");
    return *dificultad;
}

void inicializarTablero(char dificultad, char Tablero[][20]) {
    int size = 0;

    if (dificultad == 'F' || dificultad == 'f') {
        size = 20;
    } else if (dificultad == 'M' || dificultad == 'm') {
        size = 12;
    } else if (dificultad == 'D' || dificultad == 'd') {
        size = 8;
    } else {
        printf("Elija un valor valido\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                Tablero[i][j] = '|'; // Borde del tablero
            } else {
                Tablero[i][j] = '*';
            }
        }
    }
}

void imprimirTablero(char dificultad, char Tablero[][20]) {
    int size = 0;

    if (dificultad == 'F' || dificultad == 'f') {
        size = 20;
    } else if (dificultad == 'M' || dificultad == 'm') {
        size = 12;
    } else if (dificultad == 'D' || dificultad == 'd') {
        size = 8;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %2c ", Tablero[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char dificultad;
    char Tablero[20][20];  // Maximum size board

    crearTablero(&dificultad);
    inicializarTablero(dificultad, Tablero);
    imprimirTablero(dificultad, Tablero);

    return 0;
}
