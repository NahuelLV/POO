#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void inicializarTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
                tablero[i][j] = '-'; 
        }
    }
}

//Funcion que imprime el tablero
void imprimirTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %2c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void jugada(char tablero[3][3], int f, int c){
    int jugador;
    for(int i; i < 3; i++){ 
        printf("Ingrese donde quiere poner su figura(El primer numero es el de la fila y el segundo el de la columna:\n");
            scanf("%d", &f);
            scanf("%d", &c);
            printf(" %2c ", tablero[f][c]);

}
}

int main() {
    int n, f, c;               //Declaramos variables necesarias
    char opcion;
   
    srand(time(NULL));  
    printf("¡Hola, bienvenido al TA-TE-TI!\n¿Quieres empezar? (y/n): ");
    scanf(" %c", &opcion);
    if (opcion == 'Y' || opcion == 'y') {
        printf("REGLAS:\n Tienes que juntar tres de tus formas(O-X) en forma diagonal,vertical o horizontal\n");
        char tablero[3][3]; 
        inicializarTablero(tablero);
        imprimirTablero(tablero);
        jugada(tablero, f, c);
    } else if (opcion == 'N' || opcion == 'n') {
        printf("Bueno, que tenga un buen día.\n");
    }
    return 0;
}
