#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void limpiarPantalla() {
#if defined( _WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}


void inicializarTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = '-'; 
        }
    }
}

// Función que imprime el tablero
void imprimirTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("     %2c    ", tablero[i][j]);
        }
        printf("\n\n");
    }
}

int jugada(char tablero[3][3]) {
    int f, c;
    char jugador_actual = 'X'; // Variable para alternar turnos entre jugadores
    for(int cant = 0; cant < 9; cant ++) {
        printf("Turno del jugador %c. Ingrese donde quiere poner su figura (fila y columna, separadas por un espacio(El numero de las filas y columnas van de 0 a 2)): ", jugador_actual);
        scanf("%d %d", &f, &c);
        if (f < 0 || f >= 3 || c < 0 || c >= 3) {
            printf("Posición fuera del rango válido. Intente nuevamente.\n");
            continue; // Permite al jugador repetir su jugada
            }else if(f != 0 || f != 1 || f != 2 || c != 0 || c != 1 || c != 2){
            printf("Pelotudo son numeros, lee las intrucciones y reglas\n");
            return 0;
        }
        // Verificar si la posición está ocupada
        if (tablero[f][c] != '-') {
            printf("La posición seleccionada ya está ocupada. Intente nuevamente.\n");
            continue; // Permite al jugador repetir su jugada
        }

        // Realizar la jugada para el jugador actual
        tablero[f][c] = jugador_actual;
        limpiarPantalla();
        // Imprimir el tablero actualizado
        imprimirTablero(tablero);

        // Cambiar al siguiente jugador
        jugador_actual = (jugador_actual == 'X') ? 'O' : 'X';
        
        if(tablero[0][0] == 'X' && tablero[0][1] == 'X' && tablero[0][2] == 'X' 
        || tablero[1][0] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X' 
        || tablero[2][0] == 'X' && tablero[2][1] == 'X' && tablero[2][2] == 'X' 
        || tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X'
        || tablero[2][0] == 'X' && tablero[1][1] == 'X' && tablero[0][2] == 'X'
        || tablero[0][0] == 'X' && tablero[1][0] == 'X' && tablero[2][0] == 'X'
        || tablero[0][1] == 'X' && tablero[1][1] == 'X' && tablero[2][1] == 'X'
        || tablero[0][2] == 'X' && tablero[1][2] == 'X' && tablero[2][2] == 'X'){
            printf("El ganador del juego es el jugador 1, FELICIDADES!");
            return 0;
        } 
        if(tablero[0][0] == 'O' && tablero[0][1] == 'O' && tablero[0][2] == 'O' 
        || tablero[1][0] == 'O' && tablero[1][1] == 'O' && tablero[1][2] == 'O' 
        || tablero[2][0] == 'O' && tablero[2][1] == 'O' && tablero[2][2] == 'O' 
        || tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O'
        || tablero[2][0] == 'O' && tablero[1][1] == 'O' && tablero[0][2] == 'O'
        || tablero[0][0] == 'O' && tablero[1][0] == 'O' && tablero[2][0] == 'O'
        || tablero[0][1] == 'O' && tablero[1][1] == 'O' && tablero[2][1] == 'O'
        || tablero[0][2] == 'O' && tablero[1][2] == 'O' && tablero[2][2] == 'O'){
            printf("El ganador del juego es el jugador 2, FELICIDADES!");
            return 0;
        }
    }
}





int main() {
    char opcion;
    srand(time(NULL));  
    printf("¡Hola, bienvenido al TA-TE-TI!\n¿Quieres empezar? (s/n): ");
    scanf(" %c", &opcion);
    if (opcion == 'S' || opcion == 's') {
        printf("REGLAS:\n Tienes que juntar tres de tus formas(O-X) en forma diagonal, vertical u horizontal\n\n");
        char tablero[3][3]; 
        inicializarTablero(tablero);
        imprimirTablero(tablero);
        jugada(tablero);
    } else if (opcion == 'N' || opcion == 'n') {
        printf("Bueno, que tenga un buen día.\n");
    }
    return 0;
}
