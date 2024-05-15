#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main(){
    srand(time(NULL));  // Declaramos las variables basicas para el juego
    char *posibilidades[3] = {"piedra","papel","tijeras"};
    int jugada;
    int jugada_maquina;
    int jugada_valida = 0;
    printf("Bienvenido al juego!!\n");
    printf("Reglas: 0 = piedra - 1 = papel - 2 = tijeras\n");
    
    int resultado = 0;      // Declaramos las variables necesarias
    int resultado_vueltaM = 0;
    int resultado_rondaM = 0;
    int resultado_vueltaU = 0;
    int resultado_rondaU = 0;
 
    for(int i = 0; i < 5; i++){  // Se pide ingresar la jugada del usuario
       for(int j = 0; j < 3; j++) {
        printf("Ingrese su jugada:");
        scanf("%d", &jugada);
        printf("Elegiste: %s\n", posibilidades[jugada]);
        jugada_maquina = rand() % 3;
     printf("La máquina elige: %s\n", posibilidades[jugada_maquina]);
     
    if (jugada == jugada_maquina) {
        resultado = 0;   // Calculamos si es empate
    } else if ((strcmp(posibilidades[jugada], "piedra") == 0 && strcmp(posibilidades[jugada_maquina], "tijeras") == 0) ||
               (strcmp(posibilidades[jugada], "tijeras") == 0 && strcmp(posibilidades[jugada_maquina], "papel") == 0) ||
               (strcmp(posibilidades[jugada], "papel") == 0 && strcmp(posibilidades[jugada_maquina], "piedra") == 0)) {
        resultado = 1; //Calculamos si es gana el usuario
    } else {
        resultado = -1; // Calculamos si es gana la maquina
    }
    if (resultado == 0) {       // Se muestran el resultado de la vuelta
        printf("¡Empataste la vuelta!\n");
    } else if (resultado == 1) {
        printf("¡Ganaste la vuelta!\n");
        resultado_vueltaU += 1;
    } else {
        printf("¡Perdiste la vuelta!\n");
        resultado_vueltaM += 1;
    }
    
    
    if(resultado_vueltaM == 2){    // Se muestra como va la partida
        resultado_rondaM += 1;
        printf("El resultado va: maquina %d ronda/s - usuario %d ronda/s\n", resultado_rondaM, resultado_rondaU);
        resultado_vueltaM = 0;
       resultado_vueltaU = 0;
    }else if(resultado_vueltaU == 2){
        resultado_rondaU += 1;
        printf("El resultado va: maquina %d ronda/s - usuario %d ronda/s\n", resultado_rondaM, resultado_rondaU);
        resultado_vueltaM = 0;
       resultado_vueltaU = 0;
    }
    
    if(resultado_rondaM == 3){  // Se muestra el ganador de la partida
        printf("El resultado quedo: maquina %d ronda/s - usuario %d ronda/s\n", resultado_rondaM, resultado_rondaU);
         printf("GANO la Maquina!!");
    }else if(resultado_rondaU == 3){
        printf("El resultado quedo: maquina %d ronda/s - usuario %d ronda/s\n", resultado_rondaM, resultado_rondaU);
        printf("GANO el Usuario!!");
    }
     if(resultado_rondaM == 3 || resultado_rondaU == 3)
        break; // Detener el juego si se ha alcanzado el límite de rondas
    }}
    return 0;
}
 
