#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main() {
    char tablero1[MAX_FILAS][MAX_COLUMNAS];
    char tablero2[MAX_FILAS][MAX_COLUMNAS];
    int filas = MAX_FILAS;
    int columnas = MAX_COLUMNAS;
    int activador = pantallaPrincipal();

    inicializarTablero(tablero1, filas, columnas);
    inicializarTablero(tablero2, filas, columnas);

    do {
        if (activador == 1) {
            menu(tablero1, tablero2, filas, columnas);
        } else {
            printf("Cerrando programa...\n");
            exit(0);
        }
    } while (activador == 1);

    return 0;
}
