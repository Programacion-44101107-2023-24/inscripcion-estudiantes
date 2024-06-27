#include <stdio.h>

int main() {
    int limite;
    int num = 1; // Variable para los números naturales sucesivos

    // Pedir al usuario el límite
    printf("Introduce el número límite: ");
    scanf("%d", &limite);

    // Controlar el número de filas
    for (int fila = 1; num <= limite; fila++) {
        // Imprimir los números en la fila actual
        for (int columna = 0; columna < fila; columna++) {
            if (num > limite) {
                break;
            }
            printf("%d\t", num);
            num++;
        }
        printf("\n"); // Nueva línea después de cada fila
    }

    return 0;
}
