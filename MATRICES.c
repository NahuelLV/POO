#include <stdio.h>
#include <stdlib.h>

int main() {
    int ejercicio;
    printf("Ingrese el ejercicio que desea realizar: ");
    scanf("%d", &ejercicio);
    
    switch(ejercicio) {
        case 1: {
            int matriz[2][2];
            printf("Ingrese los elementos de la matriz 2x2:\n");
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    printf("Elemento [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matriz[i][j]);
                }
            }
              
            printf("Traspuesta de la matriz 2x2:\n");
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < 2; i++) {
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
            break;
        }
        
        case 2: {
            int matriz[3][3];
            int det = 0;
            printf("Ingrese los elementos de la matriz 3x3:\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("Elemento [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matriz[i][j]);
                }
            }
            // Cálculo del determinante
            det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
            printf("Determinante: %d\n", det);
            break;
        }
        
        case 3: {
            int matriz[3][3];
            int adjunta[3][3];
            printf("Ingrese los elementos de la matriz 3x3:\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("Elemento [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matriz[i][j]);
                }
            }
            // Cálculo de la matriz adjunta
            adjunta[0][0] = matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1];
            adjunta[0][1] = -(matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]);
            adjunta[0][2] = matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0];
            adjunta[1][0] = -(matriz[0][1] * matriz[2][2] - matriz[0][2] * matriz[2][1]);
            adjunta[1][1] = matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0];
            adjunta[1][2] = -(matriz[0][0] * matriz[2][1] - matriz[0][1] * matriz[2][0]);
            adjunta[2][0] = matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1];
            adjunta[2][1] = -(matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0]);
            adjunta[2][2] = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
            
            printf("Matriz adjunta:\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%d ", adjunta[i][j]);
                }
                printf("\n");
            }
            break;
        }
        
        case 4: {
            int matriz[3][3];
            int inversa[3][3];
            printf("Ingrese los elementos de la matriz 3x3:\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("Elemento [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matriz[i][j]);
                }
            }
            // Cálculo de la matriz inversa
            int det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
            if (det == 0) {
                printf("La matriz no tiene inversa.\n");
            } else {
                inversa[0][0] = (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) / det;
                inversa[0][1] = -(matriz[0][1] * matriz[2][2] - matriz[0][2] * matriz[2][1]) / det;
                inversa[0][2] = (matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1]) / det;
                inversa[1][0] = -(matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) / det;
                inversa[1][1] = (matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0]) / det;
                inversa[1][2] = -(matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0]) / det;
                inversa[2][0] = (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]) / det;
                inversa[2][1] = -(matriz[0][0] * matriz[2][1] - matriz[0][1] * matriz[2][0]) / det;
                inversa[2][2] = (matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0]) / det;
                
                printf("Matriz inversa:\n");
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        printf("%d ", inversa[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
        }
        
        case 5: {
            int matrizA[2][2], matrizB[2][2], producto[2][2];
            printf("Ingrese los elementos de la primera matriz 2x2:\n");
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    printf("Elemento [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matrizA[i][j]);
                }
            }
            printf("Ingrese los elementos de la segunda matriz 2x2:\n");
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    printf("Elemento [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matrizB[i][j]);
                }
            }
            // Cálculo del producto de las matrices
            producto[0][0] = matrizA[0][0] * matrizB[0][0] + matrizA[0][1] * matrizB[1][0];
            producto[0][1] = matrizA[0][0] * matrizB[0][1] + matrizA[0][1] * matrizB[1][1];
            producto[1][0] = matrizA[1][0] * matrizB[0][0] + matrizA[1][1] * matrizB[1][0];
            producto[1][1] = matrizA[1][0] * matrizB[0][1] + matrizA[1][1] * matrizB[1][1];
            
            printf("Producto de las matrices:\n");
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    printf("%d ", producto[i][j]);
                }
                printf("\n");
            }
            break;
        }
        
        case 6: {
            int matriz[3][4];
            printf("Ingrese los coeficientes del sistema de ecuaciones 3x3:\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("Elemento [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matriz[i][j]);
                }
            }
            // Resolver el sistema de ecuaciones con el método de Gauss (aquí iría la lógica)
            printf("Resultado del sistema de ecuaciones:\n");
            // Mostrar el resultado del sistema de ecuaciones
            break;
        }
        
        case 7: {
            int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            printf("Meses con 30 días:\n");
            for (int i = 0; i < 12; i++) {
                if (dias_por_mes[i] == 30) {
                    printf("Mes %d\n", i + 1);
                }
            }
            break;
        }
        
        default:
            printf("Ejercicio no válido.\n");
            break;
    }
    
    return 0;
}
