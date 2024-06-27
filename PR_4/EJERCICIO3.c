#include <stdio.h>

int main() {
    int n; // Número de vértices del polígono
    printf("Introduce el número de lados del polígono (n >= 3): ");
    scanf("%d", &n);

    if (n < 3) {
        printf("El número de lados debe ser al menos 3.\n");
        return 1;
    }

    float x[n+1], y[n+1]; // Arrays para almacenar las coordenadas de los vértices

    // Leer las coordenadas de los vértices
    for (int i = 0; i < n; i++) {
        printf("Introduce las coordenadas del vértice %d (x y): ", i+1);
        scanf("%f %f", &x[i], &y[i]);
    }

    // Hacer que el último vértice sea el mismo que el primero
    x[n] = x[0];
    y[n] = y[0];

    float A = 0; // Área del polígono
    float Cx = 0, Cy = 0; // Coordenadas del centroide

    // Calcular el área y las coordenadas del centroide
    for (int i = 0; i < n; i++) {
        float factor = x[i] * y[i+1] - x[i+1] * y[i];
        A += factor;
        Cx += (x[i] + x[i+1]) * factor;
        Cy += (y[i] + y[i+1]) * factor;
    }

    A /= 2;
    Cx /= (6 * A);
    Cy /= (6 * A);

    // Asegurarse de que el área es positiva
    if (A < 0) {
        A = -A;
        Cx = -Cx;
        Cy = -Cy;
    }

    // Imprimir los resultados
    printf("El área del polígono es: %.2f\n", A);
    printf("El centroide del polígono está en: (%.2f, %.2f)\n", Cx, Cy);

    return 0;
}
