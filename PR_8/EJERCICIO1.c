#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 10
#define COLUMNAS 10
#define PUNTOS_ALEATORIOS 20

typedef int Matriz[FILAS][COLUMNAS];  // Definición del tipo de dato Matriz

// Funciones
void inicializarMatriz(Matriz matriz);
void mostrarMatriz(Matriz matriz);
void colorearPuntosAleatorios(Matriz matriz);
int contarVecinosColoreados(Matriz matriz, int fila, int columna);
int contarPuntosConVecinosColoreados(Matriz matriz);

int main() {
    Matriz matriz;

    inicializarMatriz(matriz);
    colorearPuntosAleatorios(matriz);
    printf("Matriz original:\n");
    mostrarMatriz(matriz);

    int puntosConVecinosColoreados = contarPuntosConVecinosColoreados(matriz);

    printf("\nTotal de puntos coloreados con vecinos coloreados: %d\n", puntosConVecinosColoreados);

    return 0;
}

void inicializarMatriz(Matriz matriz) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = 0;  // Inicializar la matriz con 0 (no coloreado)
        }
    }
}

void mostrarMatriz(Matriz matriz) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void colorearPuntosAleatorios(Matriz matriz) {
    srand(time(NULL));

    int puntosColoreados = 0;
    while (puntosColoreados < PUNTOS_ALEATORIOS) {
        int fila = rand() % FILAS;
        int columna = rand() % COLUMNAS;

        // Asegurarse de que el punto no esté ya coloreado
        if (matriz[fila][columna] == 0) {
            matriz[fila][columna] = 1;
            puntosColoreados++;
        }
    }
}

int contarVecinosColoreados(Matriz matriz, int fila, int columna) {
    int contador = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nuevaFila = fila + i;
            int nuevaColumna = columna + j;

            // Verificar que la posición esté dentro de los límites de la matriz
            if (nuevaFila >= 0 && nuevaFila < FILAS && nuevaColumna >= 0 && nuevaColumna < COLUMNAS) {
                // Verificar si el vecino está coloreado
                if (matriz[nuevaFila][nuevaColumna] == 1) {
                    contador++;
                }
            }
        }
    }

    // Restar el propio punto si está coloreado
    contador -= matriz[fila][columna];

    return contador;
}
/// @brief 
/// @param matriz 
/// @return 
int contarPuntosConVecinosColoreados(Matriz matriz) {
    int puntosConVecinosColoreados = 0;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 1 && contarVecinosColoreados(matriz, i, j) > 0) {
                puntosConVecinosColoreados++;
            }
        }
    }

    return puntosConVecinosColoreados;
}