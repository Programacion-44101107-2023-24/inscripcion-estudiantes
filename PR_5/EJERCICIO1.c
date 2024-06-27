#include <stdio.h>

int leer_real_intervalo3(float a, float b, float *x) {
    int intentos = 3;
    if (a == b) {
        *x = a;
        return 0;
    } else {
        if (a > b) {
            float temp = a;
            a = b;
            b = temp;
        }
        while (intentos > 0) {
            printf("\nIntroduzca número en [%.2f, %.2f] (Intentos restantes: %d): ", a, b, intentos);
            scanf("%f", x);
            if (*x >= a && *x <= b) {
                return 0;
            }
            intentos--;
        }
        return -1; // Error después de 3 intentos fallidos
    }
}

int main() {
    float a, b, x;
    int resultado;
    printf("Introduzca el primer extremo del intervalo: ");
    scanf("%f", &a);
    printf("Introduzca el segundo extremo del intervalo: ");
    scanf("%f", &b);
    resultado = leer_real_intervalo3(a, b, &x);
    if (resultado == 0) {
        printf("Número introducido: %.2f\n", x);
    } else {
        printf("Error: número no introducido correctamente después de 3 intentos.\n");
    }
    return 0;
}