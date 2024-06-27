#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10  // Tamaño del vector de datos

typedef double tipo_vector[N];  // Definición de un tipo vector de tamaño N

// Función para generar un número aleatorio en un rango dado
float generarNumeroAleatorio(int minimo, int maximo) {
    return rand() % (maximo - minimo + 1) + minimo;
}

// Función para realizar el análisis de los datos
void analizarDatos(tipo_vector raw, float limiteInferior, float limiteSuperior) {
    int datosValidos = 0;
    float sumaValidos = 0.0;
    tipo_vector procesados = {0};
    float mediaValidos = 0.0;

    // Calcular la media de los datos válidos y contar cuántos datos son válidos
    for (int i = 0; i < N; i++) {
        if (raw[i] >= limiteInferior && raw[i] <= limiteSuperior) {
            datosValidos++;
            sumaValidos += raw[i];
        }
    }

    if (datosValidos > 0) {
        mediaValidos = sumaValidos / datosValidos;

        // Generar el conjunto de datos procesados con solo los datos válidos
        int indexProcesados = 0;
        for (int i = 0; i < N; i++) {
            if (raw[i] >= limiteInferior && raw[i] <= limiteSuperior) {
                procesados[indexProcesados++] = raw[i];
            }
        }

        // Mostrar resultados
        printf("Número de datos válidos: %d\n", datosValidos);
        printf("Media de los datos válidos: %.2f\n", mediaValidos);
        printf("Diferencia respecto a la media:\n");
        for (int i = 0; i < datosValidos; i++) {
            printf("%.2f ", procesados[i] - mediaValidos);
        }
        printf("\n");
    } else {
        printf("No hay datos válidos en el rango especificado.\n");
    }
}

int main() {
    tipo_vector raw = {0};  // Inicializar el vector de datos brutos

    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // Generar datos aleatorios para el vector raw (para propósitos de prueba)
    for (int i = 0; i < N; i++) {
        raw[i] = generarNumeroAleatorio(1, 10);  // Generar números aleatorios entre 1 y 10
    }

    // Definir los límites inferior y superior para validar los datos
    float limiteInferior, limiteSuperior;
    printf("Introduce el límite inferior para la validación de los datos: ");
    scanf("%f", &limiteInferior);
    printf("Introduce el límite superior para la validación de los datos: ");
    scanf("%f", &limiteSuperior);

    // Realizar el análisis de los datos
    analizarDatos(raw, limiteInferior, limiteSuperior);

    return 0;
}