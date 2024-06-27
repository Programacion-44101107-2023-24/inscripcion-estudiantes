#include <stdio.h>

#define MAX 100
#define RANGE 100

// Función para contar duplicados
void contarDuplicados(int vector[], int n, int contador[]) {
    for (int i = 0; i < RANGE; i++) {
        contador[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        contador[vector[i]]++;
    }
}

// Función para imprimir el resultado
void imprimirResultado(int contador[]) {
    printf("Número de repeticiones:\n");
    for (int i = 0; i < RANGE; i++) {
        if (contador[i] > 1) {
            printf("Número %d: %d veces\n", i, contador[i]);
        }
    }
}

// Función principal
int main() {
    int vector[MAX];
    int contador[RANGE];
    int n;

    // Leer el tamaño del vector
    printf("Ingrese el número de elementos en el vector (máximo %d): ", MAX);
    scanf("%d", &n);

    // Validar el tamaño del vector
    if (n > MAX) {
        printf("El tamaño del vector no puede ser mayor que %d.\n", MAX);
        return 1;
    }

    // Leer los elementos del vector
    printf("Ingrese los elementos del vector (en el rango [0, 99]):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
        // Validar el rango de cada elemento
        if (vector[i] < 0 || vector[i] >= RANGE) {
            printf("Elemento fuera de rango. Debe estar entre 0 y 99.\n");
            return 1;
        }
    }

    // Contar duplicados
    contarDuplicados(vector, n, contador);

    // Imprimir el resultado
    imprimirResultado(contador);

    return 0;
}