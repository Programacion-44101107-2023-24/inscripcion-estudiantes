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
            *anio +=