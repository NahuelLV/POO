//Realizar un programa para calcular, leyendo 5 notas, el promedio, procentaje de notas aprobadas, promedio de las desaprobadas y cuantas notas fueron mayores o iguales a 8 

#include <stdio.h>
#include <stdlib.h>

int main() {
    float nota;
    float notaT;
    float notaD;
    int porcentaje;
    float promedio;
    float promedioD;
    int cont, acum;
    
    for(int i = 0; i < 5; i++){
    printf("Ingrese su nota: ");
    scanf("%f", &nota);
    notaT = notaT + nota;
    if(nota >= 6){
        acum += 1;
    }
    if(nota >= 8){
        cont += 1;
    }
    }
    float promedio = notaT / 5;
    printf("Su promedio es: %.2f", promedio);
    return 0;
}
