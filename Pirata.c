#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Funcion en la cual damos posicion al pirata y el tesoro
void generarrandoms(int n, char tablero[][n], int *pirataX, int *pirataY, int *tesoroX, int *tesoroY) {
    *pirataX = rand() % (n - 2) + 1;  // posición aleatoria en X del pirata
    *pirataY = rand() % (n - 2) + 1;  // posición aleatoria en Y del pirata

    *tesoroX = rand() % (n - 2) + 1;  // posición aleatoria en X del tesoro
    *tesoroY = rand() % (n - 2) + 1;  // posición aleatoria en Y del tesoro

    while (*pirataX == *tesoroX && *pirataY == *tesoroY) {
        *tesoroX = rand() % (n - 2) + 1;
        *tesoroY = rand() % (n - 2) + 1;
    }

    tablero[*pirataX][*pirataY] = 'P';  // Posición del pirata
    tablero[*tesoroX][*tesoroY] = 'T';  // Posición del tesoro
}

//Funcion en la que damos posicion al agua y los puentes
void inicializarTablero(int n, char tablero[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                tablero[i][j] = 'A'; // Borde del tablero
            } else {
                tablero[i][j] = '*';  // Interior del tablero
            }
        }
    }
    tablero[n - 1][0] = 'E';    // Esquina inferior izquierda
    tablero[0][n - 1] = 'E';    // Esquina superior derecha
}

//Funcion que imprime el tablero
void imprimirTablero(int n, char tablero[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %2c ", tablero[i][j]);
        }
        printf("\n");
    }
}

//Funcion la cual verifica si ganaste o perdiste
int verificar(int n, char tablero[][n], int pirataX, int pirataY, int tesoroX, int tesoroY) {
    if (tablero[pirataX][pirataY] == 'A') {
        printf("El pirata cayó al agua, ¡PERDISTE!\n"); //Verifica si perdiste
        return 0;
    }
    
    if (pirataX == tesoroX && pirataY == tesoroY) {
        printf("El pirata encontró el tesoro, ¡GANASTE!\n"); //Verifica si ganaste
        return 0;
    }
    return 1; // Continuar el juego
}


//Funcion que permite el movimiento del pirata
void moverse(int n, char tablero[][n], int *pirataX, int *pirataY, int tesoroX, int tesoroY) {
    char movimiento;
    int cantidad = (n * 2) + 1;
    for (int i = 0; i < n * 2; i++) {
        cantidad -= 1;
        printf("Sus movimientos totales son: %d\n", cantidad);
        printf("Ingrese hacia donde quieres moverte en el tablero (N-S-E-O): ");
        scanf(" %c", &movimiento);
        
        tablero[*pirataX][*pirataY] = '-';  // Limpia la posición actual del pirata

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
        if (tablero[*pirataX][*pirataY] == 'A') {
            printf("El pirata cayó al agua, ¡PERDISTE!\n");
            return;
        }

        tablero[*pirataX][*pirataY] = 'P';  // Nueva posición del pirata
        
        imprimirTablero(n, tablero);
        if (verificar(n, tablero, *pirataX, *pirataY, tesoroX, tesoroY) == 0) {
            return; // Terminar el juego si se cumple alguna condición
        }
    }
    printf("Se agotaron los movimientos, ¡PERDISTE!\n");
}

int main() {
    int n;               //Declaramos variables necesarias
    char opcion;
    int pirataX, pirataY, tesoroX, tesoroY;

    srand(time(NULL));  
    printf("¡Hola, bienvenido al juego del pirata!\n Tu objetivo es encontrar el tesoro, ¿quieres empezar? (y/n): ");
    scanf(" %c", &opcion);

    if (opcion == 'Y' || opcion == 'y') {
        printf("MAPA:\n * = terreno desconocido\n A = agua(Si caes en el moriras)\n E = los puentes de las esquinas\n P = pirata(el jugador)\n T = tesoro(tu objetivo es encontrarlo)\n - = camino que ya recorriste\n");
        printf("Ingrese el tamaño del tablero (Máximo = 100): ");
        scanf("%d", &n);

        char tablero[n][n]; 
        inicializarTablero(n, tablero);
        generarrandoms(n, tablero, &pirataX, &pirataY, &tesoroX, &tesoroY);
        imprimirTablero(n, tablero);  // Imprimir el tablero después de colocar el pirata y el tesoro
        moverse(n, tablero, &pirataX, &pirataY, tesoroX, tesoroY);
    } else if (opcion == 'N' || opcion == 'n') {
        printf("Bueno, que tenga un buen día.\n");
    }

    return 0;
}
