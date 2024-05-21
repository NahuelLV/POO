#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generarrandoms(int n, int arr[][n], int *pirataX, int *pirataY, int *tesoroX, int *tesoroY) { 
    *pirataX = rand() % (n - 2) + 1;  // posición aleatoria en X del pirata
    *pirataY = rand() % (n - 2) + 1;  // posición aleatoria en Y del pirata
    
    *tesoroX = rand() % (n - 2) + 1;  // posición aleatoria en X del tesoro
    *tesoroY = rand() % (n - 2) + 1;  // posición aleatoria en Y del tesoro
    
    while (*pirataX == *tesoroX && *pirataY == *tesoroY) {
        *tesoroX = rand() % (n - 2) + 1;
        *tesoroY = rand() % (n - 2) + 1;
    }

    arr[*pirataX][*pirataY] = 2;  // Posición del pirata
    arr[*tesoroX][*tesoroY] = 5;  // Posición del tesoro
}

void inicializarTablero(int n, int arr[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                arr[i][j] = -1; // Borde del tablero
            } else {
                arr[i][j] = 0;  // Interior del tablero
            }
        }
    }
    arr[n - 1][0] = 3;    // Esquina inferior izquierda
    arr[0][n - 1] = 3;    // Esquina superior derecha
}

void imprimirTablero(int n, int arr[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

int verificar(int n, int arr[][n], int pirataX, int pirataY, int tesoroX, int tesoroY) {
    if (arr[pirataX][pirataY] == -1) {
        printf("El pirata cayó al agua, ¡PERDISTE!\n");
        return 0;
    }
    
    if (pirataX == tesoroX && pirataY == tesoroY) {
        printf("El pirata encontró el tesoro, ¡GANASTE!\n");
        return 0;
    }
}

void moverse(int n, int arr[][n], int *pirataX, int *pirataY, int tesoroX, int tesoroY) {
    char movimiento;
    int cantidad = (n * 2) + 1;
    for (int i = 0; i < n * 2; i++) {
        cantidad -= 1;
        printf("Sus movimientos totales son: %d\n", cantidad);
        printf("Ingrese hacia donde quieres moverte en el tablero (N-S-E-O): ");
        scanf(" %c", &movimiento);
        
        arr[*pirataX][*pirataY] = 0;  // Limpia la posición actual del pirata

        if (movimiento == 'N' || movimiento == 'n') {
            *pirataX -= 1;  // Norte - se mueve hacia arriba
        } else if (movimiento == 'S' || movimiento == 's') {
            *pirataX += 1;  // Sur - se mueve hacia abajo
        } else if (movimiento == 'E' || movimiento == 'e') {
            *pirataY += 1;  // Este - se mueve hacia la derecha
        } else if (movimiento == 'O' || movimiento == 'o') {
            *pirataY -= 1;  // Oeste - se mueve hacia la izquierda
        } else {
            printf("Movimiento no válido. Intente de nuevo.\n");
            continue;
        }

        // Verificar la nueva posición antes de establecerla
        if (arr[*pirataX][*pirataY] == -1) {
            printf("El pirata cayó al agua, ¡PERDISTE!\n");
            return;
        }

        arr[*pirataX][*pirataY] = 2;  // Nueva posición del pirata
        imprimirTablero(n, arr);
        verificar(n, arr, *pirataX, *pirataY, tesoroX, tesoroY);
    }
}

int main() {
    int n;
    char opcion;
    int pirataX, pirataY, tesoroX, tesoroY;

    srand(time(NULL));  
    printf("¡Hola, bienvenido al juego del pirata! Tu objetivo es encontrar el tesoro, ¿quieres empezar? (y/n): ");
    scanf(" %c", &opcion);

    if (opcion == 'Y' || opcion == 'y') {
        printf("Ingrese el tamaño del tablero (Máximo = 100): ");
        scanf("%d", &n);

        int arr[n][n]; 
        inicializarTablero(n, arr);
        generarrandoms(n, arr, &pirataX, &pirataY, &tesoroX, &tesoroY);
        imprimirTablero(n, arr);  // Imprimir el tablero después de colocar el pirata y el tesoro
        moverse(n, arr, &pirataX, &pirataY, tesoroX, tesoroY);
    } else if (opcion == 'N' || opcion == 'n') {
        printf("Bueno, que tenga un buen día.\n");
    }

    return 0;
}
