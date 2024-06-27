#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Punto;

void calcularCircunferencia(Punto p1, Punto p2, Punto p3, Punto *centro, double *radio) {
    double x1 = p1.x, y1 = p1.y;
    double x2 = p2.x, y2 = p2.y;
    double x3 = p3.x, y3 = p3.y;

    double denom = 2 * ((x1 - x3) * (y1 - y2) - (x1 - x2) * (y1 - y3));
    if (denom == 0) {
        printf("Los puntos dados son colineales, no se puede calcular una circunferencia.\n");
        return;
    }

    centro->x = ((y1 - y3) * (y1 * y1 - y2 * y2 + x1 * x1 - x2 * x2) + (y1 - y2) * (y1 * y1 - y3 * y3 + x1 * x1 - x3 * x3)) / denom;
    centro->y = ((x1 - x3) * (x1 * x1 - x2 * x2 + y1 * y1 - y2 * y2) + (x1 - x2) * (x1 * x1 - x3 * x3 + y1 * y1 - y3 * y3)) / denom;

    *radio = sqrt((x1 - centro->x) * (x1 - centro->x) + (y1 - centro->y) * (y1 - centro->y));
}

int main() {
    Punto p1, p2, p3;
    Punto centro;
    double radio;

    // Lectura de los puntos
    printf("Introduce las coordenadas del primer punto (x1 y1): ");
    scanf("%lf %lf", &p1.x, &p1.y);
    printf("Introduce las coordenadas del segundo punto (x2 y2): ");
    scanf("%lf %lf", &p2.x, &p2.y);
    printf("Introduce las coordenadas del tercer punto (x3 y3): ");
    scanf("%lf %lf", &p3.x, &p3.y);

    // Calcular centro y radio de la circunferencia
    calcularCircunferencia(p1, p2, p3, &centro, &radio);

    // Mostrar resultados
    printf("\nCentro de la circunferencia: (%.2f, %.2f)\n", centro.x, centro.y);
    printf("Radio de la circunferencia: %.2f\n", radio);

    return 0;
}