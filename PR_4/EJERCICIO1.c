#include <stdio.h>

void mostrarTabla(int numero) {
    printf("Tabla de multiplicar del %d:\n", numero);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d", numero, i, numero * i);
        if (i < 10) {
            printf(", ");
        }
    }
    printf("\n\n");
}

int main() {
    int numero, cantidad;
    
    // Pedir al usuario el número base
    do {
        printf("Introduce un número entero entre 1 y 20: ");
        scanf("%d", &numero);
    } while (numero < 1 || numero > 20);
    
    // Pedir al usuario la cantidad de tablas anteriores y posteriores
    printf("Introduce la cantidad de tablas anteriores y posteriores: ");
    scanf("%d", &cantidad);
    
    // Mostrar las tablas de multiplicar
    for (int i = numero - cantidad; i <= numero + cantidad; i++) {
        mostrarTabla(i);
    }

    return 0;
}
