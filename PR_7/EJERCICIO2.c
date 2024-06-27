#include <stdio.h>

#define MAX 100  // Grado máximo del polinomio

typedef double tipo_polinomio[MAX];

// Función para leer un polinomio
void leerPolinomio(tipo_polinomio polinomio, int *grado) {
    printf("Ingrese el grado del polinomio: ");
    scanf("%d", grado);
    
    printf("Ingrese los coeficientes del polinomio (del término independiente al término de mayor grado):\n");
    for (int i = 0; i <= *grado; i++) {
        printf("Coeficiente de x^%d: ", i);
        scanf("%lf", &polinomio[i]);
    }
}

// Función para derivar un polinomio
void derivarPolinomio(tipo_polinomio polinomio, tipo_polinomio derivada, int grado) {
    for (int i = 1; i <= grado; i++) {
        derivada[i - 1] = polinomio[i] * i;
    }
    derivada[grado] = 0; // El término de mayor grado de la derivada es cero
}

// Función para imprimir un polinomio
void imprimirPolinomio(tipo_polinomio polinomio, int grado) {
    for (int i = 0; i <= grado; i++) {
        if (polinomio[i] != 0) {
            if (i != 0 && polinomio[i] > 0) printf(" + ");
            else if (polinomio[i] < 0) printf(" - ");
            if (i == 0 || (polinomio[i] != 1 && polinomio[i] != -1)) printf("%.1lf", fabs(polinomio[i]));
            if (i > 0) printf("x");
            if (i > 1) printf("^%d", i);
        }
    }
    printf("\n");
}

// Función principal
int main() {
    tipo_polinomio polinomio = {0};
    tipo_polinomio derivada = {0};
    int grado;

    // Leer el polinomio
    leerPolinomio(polinomio, &grado);

    // Derivar el polinomio
    derivarPolinomio(polinomio, derivada, grado);

    // Imprimir el polinomio original
    printf("P(x) = ");
    imprimirPolinomio(polinomio, grado);

    // Imprimir el polinomio derivado
    printf("dP/dx = ");
    imprimirPolinomio(derivada, grado - 1);

    return 0;
}