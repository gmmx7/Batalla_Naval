#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdbool.h>
#include "Uso.h"
#include "Reutilizable.h"
#include "Juego.h"
#define MAX_FILAS 10
#define MAX_COLUMNAS 15
void menu(char tableroJugador1[][MAX_COLUMNAS], char tableroJugador2[][MAX_COLUMNAS], int filas, int columnas);
int pantallaPrincipal();
#endif