#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarTablero(int arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        arr[0][i] = -1;         // Fila superior
        arr[n - 1][i] = -1;     // Fila inferior
        arr[i][0] = -1;         // Columna izquierda
        arr[i][n - 1] = -1;     // Columna derecha
    }
}

void dibujarTablero(int arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));  
    int n;
    printf("Ingrese el tamaño del tablero: ");
    scanf("%d", &n);

    int arr[100][100]; 

    // Inicializar y dibujar el tablero
    inicializarTablero(arr, n);
    dibujarTablero(arr, n);

    return 0;
}
