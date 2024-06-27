#include <stdio.h>

// Definición de la estructura para el registro de tiempo
typedef struct {
    int horas;
    int minutos;
    int segundos;
    int centesimas;
} Tiempo;

// Función para leer un registro de tiempo desde teclado
Tiempo leerTiempo() {
    Tiempo tiempo;

    printf("Introduce horas (0-23): ");
    scanf("%d", &tiempo.horas);
    printf("Introduce minutos (0-59): ");
    scanf("%d", &tiempo.minutos);
    printf("Introduce segundos (0-59): ");
    scanf("%d", &tiempo.segundos);
    printf("Introduce centésimas de segundo (0-99): ");
    scanf("%d", &tiempo.centesimas);

    return tiempo;
}

// Función para calcular el tiempo transcurrido entre dos registros de tiempo
Tiempo calcularTiempoTranscurrido(Tiempo inicio, Tiempo fin) {
    Tiempo transcurrido;

    // Convertir ambos tiempos a centésimas de segundo para facilitar el cálculo
    long totalInicio = inicio.horas * 360000 + inicio.minutos * 6000 + inicio.segundos * 100 + inicio.centesimas;
    long totalFin = fin.horas * 360000 + fin.minutos * 6000 + fin.segundos * 100 + fin.centesimas;

    // Si el segundo tiempo es anterior al primero, considerar que es el día siguiente
    if (totalFin < totalInicio) {
        totalFin += 8640000;  // 24 horas en centésimas de segundo
    }

    // Calcular diferencia en centésimas de segundo
    long diferencia = totalFin - totalInicio;

    // Convertir la diferencia de nuevo a horas, minutos, segundos y centésimas de segundo
    transcurrido.horas = diferencia / 360000;
    diferencia %= 360000;
    transcurrido.minutos = diferencia / 6000;
    diferencia %= 6000;
    transcurrido.segundos = diferencia / 100;
    transcurrido.centesimas = diferencia % 100;

    return transcurrido;
}

// Función para imprimir un registro de tiempo
void imprimirTiempo(Tiempo tiempo) {
    printf("%02d:%02d:%02d.%02d\n", tiempo.horas, tiempo.minutos, tiempo.segundos, tiempo.centesimas);
}

int main() {
    Tiempo tiempoInicio, tiempoFin, tiempoTranscurrido;

    printf("Introduce el tiempo inicial:\n");
    tiempoInicio = leerTiempo();

    printf("Introduce el tiempo final:\n");
    tiempoFin = leerTiempo();

    // Calcular tiempo transcurrido
    tiempoTranscurrido = calcularTiempoTranscurrido(tiempoInicio, tiempoFin);

    printf("Tiempo transcurrido:\n");
    imprimirTiempo(tiempoTranscurrido);

    return 0;
}