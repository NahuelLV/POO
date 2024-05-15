#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarTablero(int arr[][100], int n, int pirataX, int pirataY, int tesoroX, int tesoroY) {
    for (int i = 0; i < n; i++) {
        arr[0][i] = -1;         // Fila superior
        arr[n - 1][i] = -1;     // Fila inferior
        arr[i][0] = -1;         // Columna izquierda
        arr[i][n - 1] = -1;     // Columna derecha
        arr[n-1][0] = 3;        // Esquina inferior izquierda
        arr[n-n][n-1] = 3;      // Esquina superior derecha
    }
    pirataX = rand() % (n-2)+1;
   pirataY = rand() % (n-2)+1;
    
   tesoroX = rand() % (n-2)+1;
   tesoroY = rand() % (n-2)+1;
    
    
    while(arr[pirataX][pirataY] == arr[tesoroX][tesoroY]){
     tesoroX = rand() % (n-2)+1;
     tesoroY = rand() % (n-2)+1;
     break;
    }
arr[pirataX][pirataY] = 2;
arr[tesoroX][tesoroY] = 5;    
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
    int pirataX;
    int pirataY;
    int tesoroX;
    int tesoroY;
    srand(time(NULL));  
    printf("Hola, Bienvenido al juego del pirata!,\n Tu objetivo es encontrar el tesoro, quiere empezar?,y/n:");
    scanf("%s", &opcion);
    if(opcion == 'Y' || opcion == 'y'){
        printf("Ingrese el tamaño del tablero, este va a determinar tamaño del mapa de juego(Max = 100): ");
    scanf("%d", &n);
    int arr[100][100]; 

    // Inicializar y dibujar el tablero
    inicializarTablero(arr, n, pirataX, pirataY,tesoroX, tesoroY);
    dibujarTablero(arr, n);
    }
   else if(opcion == 'N' || opcion == 'n'){
    printf("Bueno, que tenga un buen dia");
    return 0;
   }
   
   char movimiento;
   for(int i = 0; i < n*2; i++){
   printf("Ingrese hacia donde quieres moverte en el tablero(N-S-E-O)");
    scanf("%s", &movimiento);
    if(movimiento == 'N' || movimiento == 'n'){
        
    }
   }
    return 0;
}
