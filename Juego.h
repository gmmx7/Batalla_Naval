#ifndef JUEGO_H
#define JUEGO_H
#include <stdlib.h>
#include "menu.h"
#include "Funciones_Usuario.h"
//Fase 2: Inicialización del juego y tableros
void juego(char tablero1[][MAX_COLUMNAS], char tablero2[][MAX_COLUMNAS], int *filas, int *columnas, int modo);
bool inicializarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas);
int validarDimensiones(int filas, int columnas); 
#endif