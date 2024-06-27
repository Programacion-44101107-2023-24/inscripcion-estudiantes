#include <stdio.h>

// Función para comprobar si un año es bisiesto
int esBisiesto(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    return 0;
}

// Función para validar una fecha
int validarFecha(int dia, int mes, int anio) {
    if (anio < 1)
        return 0;
    if (mes < 1 || mes > 12)
        return 0;
    if (dia < 1)
        return 0;

    // Número de días en cada mes
    int diasEnMes[] = {31, (esBisiesto(anio) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (dia > diasEnMes[mes - 1])
        return 0;
    return 1;
}

// Función para sumar n días a una fecha
void sumarDias(int *dia, int *mes, int *anio, int n) {
    int diasEnMes[] = {31, (esBisiesto(*anio) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    *dia += n;

    while (*dia > diasEnMes[*mes - 1]) {
        *dia -= diasEnMes[*mes - 1];
        *mes += 1;
        if (*mes > 12) {
            *mes = 1;
            *anio += 1;
            diasEnMes[1] = esBisiesto(*anio) ? 29 : 28; // Recalcular febrero
        }
    }
}

// Función para mostrar el menú y leer la opción del usuario
int mostrarMenu() {
    int opcion;
    printf("\nMenu de Opciones:\n");
    printf("1. Cambiar fecha\n");
    printf("2. Sumar n días a la fecha\n");
    printf("3. Mostrar fecha\n");
    printf("4. Finalizar ejecución\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    return opcion;
}

// Función principal
int main() {
    int dia, mes, anio;
    int opcion;
    int salir = 0;

    // Leer la fecha inicial
    do {
        printf("Ingrese el día: ");
        scanf("%d", &dia);
        printf("Ingrese el mes: ");
        scanf("%d", &mes);
        printf("Ingrese el año: ");
        scanf("%d", &anio);
    } while (!validarFecha(dia, mes, anio));

    // Bucle principal del menú
    while (!salir) {
        opcion = mostrarMenu();

        switch (opcion) {
            case 1:
                do {
                    printf("Ingrese el nuevo día: ");
                    scanf("%d", &dia);
                    printf("Ingrese el nuevo mes: ");
                    scanf("%d", &mes);
                    printf("Ingrese el nuevo año: ");
                    scanf("%d", &anio);
                } while (!validarFecha(dia, mes, anio));
                break;
            case 2: {
                int n;
                printf("Ingrese el número de días a sumar: ");
                scanf("%d", &n);
                sumarDias(&dia, &mes, &anio, n);
                break;
            }
            case 3:
                printf("La fecha es: %02d/%02d/%04d\n", dia, mes, anio);
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