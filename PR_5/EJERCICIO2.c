#include <stdio.h>
#include <math.h>

// Función para convertir coordenadas cartesianas a esféricas
void cartesianas_a_esfericas(float x, float y, float z, float *r, float *theta, float *phi) {
    *r = sqrt(x*x + y*y + z*z);
    if (*r != 0) {
        *theta = acos(z / *r);
    } else {
        *theta = 0;
    }
    *phi = atan2(y, x);
}

int main() {
    // Datos de prueba
    float datos[5][3] = {
        {0, 0, 0},
        {-1, -1, 0},
        {1, 1, 1},
        {1, 1, -1},
        {0, 0, -1}
    };
    
    // Variables para almacenar los resultados
    float r, theta, phi;
    
    // Convertir y mostrar los resultados
    for (int i = 0; i < 5; i++) {
        cartesianas_a_esfericas(datos[i][0], datos[i][1], datos[i][2], &r, &theta, &phi);
        printf("Coordenadas Cartesianas: (x, y, z) = (%.2f, %.2f, %.2f)\n", datos[i][0], datos[i][1], datos[i][2]);
        printf("Coordenadas Esféricas: (r, θ, φ) = (%.2f, %.2f, %.2f)\n", r, theta, phi);
        printf("\n");
    }

    return 0;
}