#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarTablero(int arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        arr[0][i] = -1;         // Fila superior
        arr[n - 1][i] = -1;     // Fila inferior
        arr[i][0] = -1;         // Columna izquierda
        arr[i][n - 1] = -1;     // Columna derecha
        arr[n-1][0] = 3;        // Esquina inferior izquierda
        arr[n-n][n-1] = 3;      // Esquina superior derecha
    }
    int pirataX = rand() % n;
    int pirataY = rand() % n; 
    arr[pirataX][pirataY] = 2;
        
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
    int n;
    char opcion;
    srand(time(NULL));  
    printf("Hola, Bienvenido al juego del pirata!,\n Tu objetivo es encontrar el tesoro, quiere empezar?, y/n:");
    scanf("%s", &opcion);
    if(opcion == 'Y' || opcion == 'y'){
        printf("Ingrese el tamaño del tablero, este va a determinar tamaño del mapa de juego(Max = 100): ");
    scanf("%d", &n);

    int arr[100][100]; 

    // Inicializar y dibujar el tablero
    inicializarTablero(arr, n);
    dibujarTablero(arr, n);
    }
   else if(opcion == 'N' || opcion == 'n'){
    printf("Bueno, andate a cagar");
    return 0;
   }
    return 0;
}
