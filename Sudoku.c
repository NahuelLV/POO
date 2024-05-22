#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void inicializarTablero(int n, int tablero[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                tablero[i][j] = rand() % 9; 
        }
    }
}

//Funcion que imprime el tablero
void imprimirTablero(int n, int tablero[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %2d ", tablero[i][j]);
        }
        printf("\n");
    }
}



int main() {
    int n;               //Declaramos variables necesarias
    char opcion;
   
    srand(time(NULL));  
    printf("¡Hola, bienvenido al sudoku!\n Tu objetivo es completar todas las casillas, ¿quieres empezar? (y/n): ");
    scanf(" %c", &opcion);

    if (opcion == 'Y' || opcion == 'y') {
        printf("REGLAS:\n Necesitas completar las casillas vacias sin repetir un mismo numero por fila, columna y cuadrado(El cuadrado seria de 3x3 desde la casilla a completar)\n");
        printf("Ingrese el tamaño del tablero (Máximo = 9): ");
        scanf("%d", &n);

        int tablero[n][n]; 
        inicializarTablero(n, tablero);
        imprimirTablero(n, tablero);  
    } else if (opcion == 'N' || opcion == 'n') {
        printf("Bueno, que tenga un buen día.\n");
    }

    return 0;
}
