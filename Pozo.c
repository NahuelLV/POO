#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T         "\x1b[31m"
#define ROJO_F         "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T     "\x1b[33m"
#define AMARILLO_F     "\x1b[43m"
#define AZUL_T         "\x1b[34m"
#define AZUL_F         "\x1b[44m"
#define MAGENTA_T      "\x1b[35m"
#define MAGENTA_F      "\x1b[45m"
#define CYAN_T         "\x1b[36m"
#define CYAN_F         "\x1b[46m"
#define BLANCO_T       "\x1b[37m"
#define BLANCO_F       "\x1b[47m"
#define RESET_COLOR    "\x1b[0m"

void limpiarPantalla() {
#if defined( _WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

//Funcion en la cual damos posicion al pirata y el tesoro
void generarrandoms(char tablero[][9], int *pirataX, int *pirataY, int *tesoroX, int *tesoroY) {
    *jugadorX = 0;  // posición aleatoria en X del pirata
    *jugadorY = 0;  // posición aleatoria en Y del pirata

    *salidaX = 9;  // posición aleatoria en X del tesoro
    *salidaY = 9;  // posición aleatoria en Y del tesoro

    tablero[*jugadorX][*jugadorY] = 'J';  // Posición del pirata
    tablero[*salidaX][*salidaY] = 'S';  // Posición del tesoro
}

//Funcion en la que damos posicion al agua y los puentes
void inicializarTablero(char tablero[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
           tablero[i][j] = '*';  // Interior del tablero
            }
        }
    }


//Funcion que imprime el tablero
void imprimirTablero(int n, char tablero[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            switch (tablero[i][j]) {
                case 'J':
                    printf(AZUL_F " %2c " RESET_COLOR, tablero[i][j]);
                    break;
                case 'S':
                    printf(VERDE_F " %2c " RESET_COLOR, tablero[9][9]);
                    break;
                default:
                    printf(" %2c ", tablero[i][j]);
            }
        }
        printf("\n");
    }
}

//Funcion la cual verifica si ganaste o perdiste
int verificar(char tablero[][9], int pirataX, int pirataY, int tesoroX, int tesoroY) {
    if (tablero[pirataX][pirataY] == '0') {
        printf(ROJO_T "Caiste en un pozo, ¡PERDISTE!\n" RESET_COLOR); //Verifica si perdiste
        return 0;
    }
    
    if (jugadorX == salidaX && jugadorY == salidaY) {
        printf(AMARILLO_T "Lograste salir, ¡GANASTE!\n" RESET_COLOR); //Verifica si ganaste
        return 0;
    }
    return 1; // Continuar el juego
}


//Funcion que permite el movimiento del pirata
void moverse(char tablero[][9], int *pirataX, int *pirataY, int tesoroX, int tesoroY) {
    char movimiento;
    int cantidad;
    for (int i = 0; i < 9 * 2; i++) {
        cantidad -= 1;
        printf("\nMAPA:\n * = terreno desconocido\n A = agua(Si caes en el moriras)\n E = los puentes de las esquinas\n P = pirata(el jugador)\n T = tesoro(tu objetivo es encontrarlo)\n - = camino que ya recorriste\n");
        printf("Sus movimientos totales son: %d\n", cantidad);
        printf("Ingrese hacia donde quieres moverte en el tablero (N-S-E-O): ");
        scanf(" %c", &movimiento);
        
        tablero[*pirataX][*pirataY] = '-';  // Limpia la posición actual del pirata
        limpiarPantalla();
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
            cantidad += 1;
            continue;
        }

        // Verificar la nueva posición antes de establecerla
        if (tablero[*pirataX][*pirataY] == 'A') {
            printf(ROJO_T "El pirata cayó al agua, ¡PERDISTE!\n" RESET_COLOR);
            return;
        }

        tablero[*pirataX][*pirataY] = 'P';  // Nueva posición del pirata
        
        imprimirTablero(n, tablero);
        if (verificar(n, tablero, *pirataX, *pirataY, tesoroX, tesoroY) == 0) {
            return; // Terminar el juego si se cumple alguna condición
        }
        if(cantidad == 0){
        printf(ROJO_T "Se agotaron los movimientos, ¡PERDISTE!\n" RESET_COLOR);
        return;
        }
    }}

int main() {
    //Declaramos variables necesarias
    char opcion;
    int pirataX, pirataY, tesoroX, tesoroY;

    srand(time(NULL));  
    printf("¡Hola, bienvenido al juego del pirata!\n Tu objetivo es encontrar el tesoro, ¿quieres empezar? (s/n): ");
    scanf(" %c", &opcion);

    if (opcion == 'S' || opcion == 's') {
        printf("Ingrese el tamaño del tablero (Máximo = 20 y minimo = 4): ");
        scanf("%d", &n);
         if(n < 4 || n > 20){
            printf("Tamaño no valido, reinicie el programa\n");
            return 0;
        }
        char tablero[9][9]; 
        inicializarTablero(tablero);
        generarrandoms(n, tablero, &pirataX, &pirataY, &tesoroX, &tesoroY);
        imprimirTablero(n, tablero);  // Imprimir el tablero después de colocar el pirata y el tesoro
        moverse(n, tablero, &pirataX, &pirataY, tesoroX, tesoroY);
    } else if (opcion == 'N' || opcion == 'n') {
        printf("Bueno, que tenga un buen día.\n");
    }
      else{
          printf("Reinicie el programa e ingrese el valor indicado");
          return 0;
          
      }

    return 0;
}
