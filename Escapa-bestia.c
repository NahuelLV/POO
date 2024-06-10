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


int crearTablero(char dificultad,  int Tablero[][0]) {
    printf("F)Facil\nM)Media\nD)Dificil\nElija la dificultad: ");
    scanf("%s", &dificultad);
     //seleccion de dificultades, F facil, M media, D dificil
    
        //FACIL: 20X20, MEDIA 12X12, DIFICL 8X8;
    if (dificultad == 'F' || dificultad == 'f') {
            for (int i = 0; i < 20; i++){
        for(int j=0;j < 20; j++){
            Tablero[i][j]=1;
            printf(" %d ", Tablero[i][j]);
        }
        printf("\n");
   }
        }
     if (dificultad == 'M' || dificultad == 'm') {
            for (int i = 0; i < 12; i++){
        for(int j=0;j < 12; j++){
            Tablero[i][j]=1;
        }
   }
        }
         if (dificultad == 'D' || dificultad == 'd') {
            for (int i = 0; i < 8; i++){
        for(int j=0;j < 8; j++){
            Tablero[i][j]=1;
        }
   }
        } else {
        printf("Elija un valor valido");
        return 0;
     }

}

int main() {
    int Tablero[0][0];
    char dificultad;
    crearTablero(dificultad, Tablero);
}
