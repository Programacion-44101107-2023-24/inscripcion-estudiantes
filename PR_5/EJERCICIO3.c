#include <stdio.h>
#include <math.h>

// Función que calcula el valor de y dado x en la función diente de sierra
float diente_de_sierra(float x) {
    // Reducir x al intervalo [0, 2]
    x = fmod(x, 2.0);

    // Si x es negativo, ajustarlo al rango positivo
    if (x < 0) {
        x += 2.0;
    }

    // Calcular el valor de la función diente de sierra
    if (x <= 1.0) {
        return x;
    } else {
        return 2.0 - x;
    }
}

int main() {
    // Datos de prueba
    float datos[6] = {0.5, 1.0, 1.3, 4.2, -1.3, -4.2};
    
    // Calcular y mostrar los resultados
    for (int i = 0; i < 6; i++) {
        float x = datos[i];
        float y = diente_de_sierra(x);
        printf("x: %.1f, y: %.1f\n", x, y);
    }

    return 0;
}