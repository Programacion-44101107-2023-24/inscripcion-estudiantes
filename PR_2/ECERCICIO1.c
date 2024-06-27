#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    float v1x, v1y, v1z; /* Componentes del vector 1 */
    float v2x, v2y, v2z; /* Componentes del vector 2 */
    float sx, sy, sz;    /* Componentes de la suma de vectores */
    float e;             /* Producto escalar */
    float px, py, pz;    /* Componentes del producto vectorial */

    do
    {
        system("cls||clear"); // Limpiar la pantalla en Windows (cls) y en Unix/Linux/MacOS (clear)
        printf("SUMA VECTORIAL, PRODUCTO ESCALAR Y VECTORIAL\n");
        printf("============================================\n\n");
        printf("Introducir componentes de v1:\n");
        printf("\tv1.x: ");
        scanf(" %f", &v1x);
        printf("\tv1.y: ");
        scanf(" %f", &v1y);
        printf("\tv1.z: ");
        scanf(" %f", &v1z);
        printf("Introducir componentes de v2:\n");
        printf("\tv2.x: ");
        scanf(" %f", &v2x);
        printf("\tv2.y: ");
        scanf(" %f", &v2y);
        printf("\tv2.z: ");
        scanf(" %f", &v2z);

        /* Calcular la suma de vectores */
        sx = v1x + v2x;
        sy = v1y + v2y;
        sz = v1z + v2z;

        /* Calcular el producto escalar */
        e = v1x * v2x + v1y * v2y + v1z * v2z;

        /* Calcular el producto vectorial */
        px = v1y * v2z - v1z * v2y;
        py = v1z * v2x - v1x * v2z;
        pz = v1x * v2y - v1y * v2x;

        /* Mostrar los resultados */
        printf("\nSuma de vectores: (%.1f, %.1f, %.1f)", sx, sy, sz);
        printf("\nProducto escalar: %.1f", e);
        printf("\nProducto vectorial: (%.1f, %.1f, %.1f)", px, py, pz);
        printf("\nDesea efectuar una nueva operación (S/N)? ");
        scanf(" %c", &c);
    } while (c != 'N' && c != 'n');

    return 0;
}
