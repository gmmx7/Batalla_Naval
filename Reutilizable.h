#ifndef REUTILIZABLE_H
#define REUTILIZABLE_H
#include <windows.h>
#include "menu.h"
#define MAX_FILAS 10
#define MAX_COLUMNAS 15
int opcionCadena(char cadena[]);
int conversor(char caracter);
int esNumero(char caracter);
int unirNumeros(int numero, int resultado);
int convertirCadenaNumerica(char *entrada);
int convertirEntrada(char *entrada);
void limpiarConsola();
void mostrarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas);
void ocultarCursor();
void mostrarCursor();
bool enter();
void limpiarBuffer();
#endif
