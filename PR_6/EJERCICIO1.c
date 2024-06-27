#include <stdio.h>

// Función para calcular el máximo de dos números enteros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función para calcular el máximo común divisor usando el algoritmo de Euclides
int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para mostrar el menú y leer la opción del usuario
int mostrarMenu() {
    int opcion;
    printf("\nMenu de Opciones:\n");
    printf("1. Calcular y mostrar el máximo de dos números enteros\n");
    printf("2. Calcular y mostrar el máximo común divisor de los datos\n");
    printf("3. Cambiar los números leídos por otros\n");
    printf("4. Finalizar ejecución\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    return opcion;
}

// Función principal
int main() {
    int num1, num2;
    int opcion;
    int salir = 0;

    // Leer los dos números enteros iniciales
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    // Bucle principal del menú
    while (!salir) {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                printf("El máximo de %d y %d es %d\n", num1, num2, max(num1, num2));
                break;
            case 2:
                printf("El MCD de %d y %d es %d\n", num1, num2, mcd(num1, num2));
                break;
            case 3:
                printf("Ingrese el nuevo primer número: ");
                scanf("%d", &num1);
                printf("Ingrese el nuevo segundo número: ");
                scanf("%d", &num2);
                break;
            case 4:
                salir = 1;
                printf("Finalizando la ejecución...\n");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    }

    return 0;
}