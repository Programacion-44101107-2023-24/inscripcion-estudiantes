#include <stdio.h>

// Función recursiva para calcular el cociente de dos números
int divisionRecursiva(int dividendo, int divisor) {
    // Caso base: si el dividendo es menor que el divisor, el cociente es 0
    if (dividendo < divisor) {
        return 0;
    } else {
        // Llamada recursiva: sumar 1 al resultado de la división del dividendo-resto por el divisor
        return 1 + divisionRecursiva(dividendo - divisor, divisor);
    }
}

int main() {
    int dividendo, divisor;

    // Lectura del dividendo y divisor por teclado
    printf("Introduce el dividendo y el divisor (positivos): ");
    scanf("%d %d", &dividendo, &divisor);

    // Verificar que el divisor sea positivo
    if (divisor <= 0) {
        printf("El divisor debe ser un número positivo.\n");
        return 1;
    }

    // Calcular el cociente usando recursividad
    int cociente = divisionRecursiva(dividendo, divisor);

    printf("El cociente de %d dividido por %d es %d.\n", dividendo, divisor, cociente);

    return 0;
}