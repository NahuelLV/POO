#include <stdio.h>
#include <stdlib.h>


int main() {
int ejercicio;
printf("Ingrese el ejercicio que desea realizar: ");
 scanf("%d", &ejercicio);
 switch(ejercicio){
     case 1:
    // Declaración de variables
    int numeros[4];
    int suma = 0;
    float media;

    // Solicitar al usuario que ingrese los números
    printf("Por favor, ingrese 4 números:\n");

    // Leer los números ingresados por el usuario y calcular la suma
    for (int i = 0; i < 4; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        suma += numeros[i];
    }

    // Calcular la media aritmética
    media = (float)suma / 4;

    // Mostrar en pantalla los números ingresados por el usuario y la media calculada
    printf("\nLos números ingresados son: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\nLa media aritmética es: %.2f\n", media);
    break;
    
    case 2:
     // Declaración de variables
    int num[5];

    // Solicitar al usuario que ingrese los números
    printf("Por favor, ingrese 5 números:\n");

    // Leer los números ingresados por el usuario y almacenarlos en un arreglo
    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Mostrar los números en el orden contrario al que se introdujeron
    printf("\nLos números en el orden contrario son:\n");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    break;
    
    case 3:
    int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes;

    // Solicitar al usuario que indique un mes
    printf("Por favor, ingrese el número de mes (1=enero, 12=diciembre): ");
    scanf("%d", &mes);

    // Validar que el mes ingresado esté dentro del rango válido (1-12)
    if (mes >= 1 && mes <= 12) {
        // Obtener el número de días del mes ingresado
        int num_dias = dias_por_mes[mes - 1]; // Restamos 1 porque los índices de los arreglos comienzan desde 0

        // Mostrar en pantalla el número de días del mes ingresado
        printf("El mes %d tiene %d días.\n", mes, num_dias);
    } else {
        // Si el mes ingresado no está dentro del rango válido, mostrar un mensaje de error
        printf("Error: El número de mes ingresado no es válido.\n");
    }
break;
    

}
    return 0;
}
