#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

#define MAX_FILAS 10
#define MAX_COLUMNAS 15

int main() {
    char tableroJugador[MAX_FILAS][MAX_COLUMNAS];
    char tableroComputadora[MAX_FILAS][MAX_COLUMNAS];
    int filas = 0, columnas = 0, tipoDeJuego = 0;;
    int request;

    do {
        limpiarConsola();
        printf("--------Batalla Naval--------\n");
        mostrarOpcMenu();

        // ✅ Aquí ya pasas los tableros y las dimensiones
        request = menu(tableroJugador, tableroComputadora, &filas, &columnas);

        if (request == 1) {
            prepararJuego(tableroJugador, tableroComputadora, &filas, &columnas, &tipoDeJuego);  // ✔

            // 🔥 Aquí sí se llama a juego() porque ya tienes todo listo
            juego(tableroJugador, tableroComputadora, &filas, &columnas);
        }

        if (request == -1) {
            printf("\nHa ocurrido un error.\n");
            exit(1);
        }

    } while (request == 2); // Si pidió instrucciones

    return 0;
}