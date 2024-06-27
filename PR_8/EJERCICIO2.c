#include <stdio.h>

#define MAX_FILAS 5
#define MAX_COLUMNAS 5

void leerMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int *filas, int *columnas) {
    printf("Introduce el número de filas (máximo %d): ", MAX_FILAS);
    scanf("%d", filas);
    printf("Introduce el número de columnas (máximo %d): ", MAX_COLUMNAS);
    scanf("%d", columnas);

    printf("Introduce los elementos de la matriz fila por fila:\n");
    for (int i = 0; i < *filas; i++) {
        for (int j = 0; j < *columnas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void sumaMatrices(int matriz1[MAX_FILAS][MAX_COLUMNAS], int filas1, int columnas1,
                  int matriz2[MAX_FILAS][MAX_COLUMNAS], int filas2, int columnas2,
                  int resultado[MAX_FILAS][MAX_COLUMNAS], int *filas_resultado, int *columnas_resultado) {
    if (filas1 != filas2 || columnas1 != columnas2) {
        printf("No se pueden sumar las matrices porque tienen dimensiones diferentes.\n");
        *filas_resultado = 0;
        *columnas_resultado = 0;
        return;
    }

    *filas_resultado = filas1;
    *columnas_resultado = columnas1;

    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas1; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void productoMatrices(int matriz1[MAX_FILAS][MAX_COLUMNAS], int filas1, int columnas1,
                      int matriz2[MAX_FILAS][MAX_COLUMNAS], int filas2, int columnas2,
                      int resultado[MAX_FILAS][MAX_COLUMNAS], int *filas_resultado, int *columnas_resultado) {
    if (columnas1 != filas2) {
        printf("No se pueden multiplicar las matrices debido a dimensiones incompatibles.\n");
        *filas_resultado = 0;
        *columnas_resultado = 0;
        return;
    }

    *filas_resultado = filas1;
    *columnas_resultado = columnas2;

    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < columnas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    int matriz1[MAX_FILAS][MAX_COLUMNAS], matriz2[MAX_FILAS][MAX_COLUMNAS];
    int filas1, columnas1, filas2, columnas2;
    int resultado[MAX_FILAS][MAX_COLUMNAS];
    int filas_resultado, columnas_resultado;

    // Leer matriz 1
    leerMatriz(matriz1, &filas1, &columnas1);

    // Leer matriz 2
    leerMatriz(matriz2, &filas2, &columnas2);

    // Calcular suma de matrices
    sumaMatrices(matriz1, filas1, columnas1, matriz2, filas2, columnas2,
                 resultado, &filas_resultado, &columnas_resultado);

    // Imprimir suma de matrices si es posible
    if (filas_resultado > 0 && columnas_resultado > 0) {
        printf("Suma de matrices:\n");
        for (int i = 0; i < filas_resultado; i++) {
            for (int j = 0; j < columnas_resultado; j++) {
                printf("%d ", resultado[i][j]);
            }
            printf("\n");
        }
    }

    // Calcular producto de matrices
    productoMatrices(matriz1, filas1, columnas1, matriz2, filas2, columnas2,
                     resultado, &filas_resultado, &columnas_resultado);

    // Imprimir producto de matrices si es posible
    if (filas_resultado > 0 && columnas_resultado > 0) {
        printf("\nProducto de matrices:\n");
        for (int i = 0; i < filas_resultado; i++) {
            for (int j = 0; j < columnas_resultado; j++) {
                printf("%d ", resultado[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}