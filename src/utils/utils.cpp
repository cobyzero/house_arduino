#include "utils.h"
#include <WString.h>

void splitString(String texto, String partes[], int &cantidad)
{
    cantidad = 0;
    int inicio = 0;
    int fin = texto.indexOf('.');

    while (fin != -1)
    {
        partes[cantidad++] = texto.substring(inicio, fin);
        inicio = fin + 1;
        fin = texto.indexOf('.', inicio);
    }

    // Último segmento después del último '.'
    partes[cantidad++] = texto.substring(inicio);
}