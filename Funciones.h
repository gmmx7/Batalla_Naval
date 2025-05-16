#include <stdio.h>
#include <stdbool.h>

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
int menu();

//Fase 2: Creación de tableros
int validarDimensiones(int filas, int columnas);
bool verificarDimensiones(int filas, int columnas);
void dimensionador();
//void mostrarMatriz(char matriz[][], int filas, int columnas);
