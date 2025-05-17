#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 10
#define MAX_COLUMNAS 15

//Mostrar textos -> Funcionamiento
void mostrarOpcMenu();
void instrucciones();
void instruccionesDimensionador();

//Funciones globales
int conversor(char caracter);
int unirNumeros(int numero, int resultado);
int convertirEntrada(char entrada[]);
void limpiarConsola();

//Fase 1: Menu
int menu(int *filas, int *columnas);

//Fase 2: Creación de tableros
int validarDimensiones(int filas, int columnas);
bool verificarDimensiones(int filas, int columnas);
void dimensionador();
void inicializarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas);
//void iniciandoTablero(tableroJugador, tableroComputadora);
//void mostrarMatriz(char matriz[][], int filas, int columnas);
