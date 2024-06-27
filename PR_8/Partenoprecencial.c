#include <stdio.h>

#define MAX_N 10  // Máximo número de filas y columnas para la imagen (ajustable según necesidad)

// Definición de la estructura para la imagen
typedef struct {
    int filas;
    int columnas;
    float pixels[MAX_N][MAX_N];  // Matriz de píxeles
} Imagen;

// Función para calcular la polución media de la imagen
float calcularPolucionMedia(Imagen imagen) {
    float suma = 0.0;
    int totalPixels = imagen.filas * imagen.columnas;

    for (int i = 0; i < imagen.filas; i++) {
        for (int j = 0; j < imagen.columnas; j++) {
            suma += imagen.pixels[i][j];
        }
    }

    return suma / totalPixels;
}

// Función para imprimir las coordenadas de los píxeles con polución superior al 25% de la media
void imprimirPixelesSuperiores(Imagen imagen, float polucionMedia) {
    float umbral = 1.25 * polucionMedia;

    printf("Polución media: %.3f\n", polucionMedia);
    printf("Pixeles con polución superior al 25%% de la media (%.3f):\n", umbral);

    for (int i = 0; i < imagen.filas; i++) {
        for (int j = 0; j < imagen.columnas; j++) {
            if (imagen.pixels[i][j] > umbral) {
                printf("\t(%d,%d)\n", i + 1, j + 1);  // Sumamos 1 a i y j para mostrar coordenadas humanamente legibles
            }
        }
    }
}

int main() {
    Imagen imagen;
    float polucionMedia;

    // Lectura de dimensiones de la imagen
    printf("Introduce el número de filas (NF): ");
    scanf("%d", &imagen.filas);
    printf("Introduce el número de columnas (NC): ");
    scanf("%d", &imagen.columnas);

    // Lectura de los píxeles de la imagen
    printf("Introduce los valores de los píxeles:\n");
    for (int i = 0; i < imagen.filas; i++) {
        printf("Fila %d: ", i + 1);
        for (int j = 0; j < imagen.columnas; j++) {
            scanf("%f", &imagen.pixels[i][j]);
        }
    }

    // Calcular la polución media de la imagen
    polucionMedia = calcularPolucionMedia(imagen);

    // Imprimir los píxeles con polución superior al 25% de la media
    imprimirPixelesSuperiores(imagen, polucionMedia);

    return 0;
}