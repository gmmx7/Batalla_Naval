#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 10
#define MAX_COLUMNAS 15

//Mostrar textos -> Funcionamiento
void mostrarOpcMenu();
void instrucciones();
void instruccionesDimensionador();
void mostrarOpcJuego();

//Funciones globales
int conversor(char caracter);//Conversor de un solo dígito
int esNumero(char caracter);
int unirNumeros(int numero, int resultado);
int convertirCadenaNumerica(char *entrada);
int convertirEntrada(char *entrada);
void limpiarConsola();
void mostrarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas);
void pausa();
char* convertirAMayusculas(char cadena[]);

//Fase 1: Menu
int menu(char tableroJugador[][MAX_COLUMNAS], char tableroComputadora[][MAX_COLUMNAS], int *filas, int *columnas);

//Fase 2: Dimensionar y crear tablero
int validarDimensiones(int filas, int columnas);
bool verificarDimensiones(int filas, int columnas);
void dimensionador(int *filas, int *columnas);
bool inicializarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas);

/*
	Fase 3: Flujo del juego
	Dos casos: Partida individual, Multijugador
*/
void juego(char tableroJugador[][MAX_COLUMNAS], char tableroComputadora[][MAX_COLUMNAS], int *filas, int *columnas);
void entradaConsola(char tablero[][MAX_COLUMNAS], int filas, int columnas);
void prepararJuego(char tableroJugador[][MAX_COLUMNAS], char tableroComputadora[][MAX_COLUMNAS], int *filas, int *columnas, int *tipoDeJuego);

//Fase 4: Gestor de funciones de usuario dentro del juego