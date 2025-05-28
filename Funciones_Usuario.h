#ifndef FUNCIONES_USUARIO_H
#define FUNCIONES_USUARIO_H
#include <stdio.h>
#include "Juego.h"
#define MAX_FILAS 10
#define MAX_COLUMNAS 15
bool llenarTableroManualmente(char tablero[][MAX_COLUMNAS],int filas, int columnas);
int entradaConsola(int filas, int columnas);
#endif