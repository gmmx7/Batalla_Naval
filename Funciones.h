#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

// Constantes para tamaño máximo del tablero
#define MAX_FILAS 15
#define MAX_COLUMNAS 15

// ---------------------- Menús y pantallas ----------------------
void mostrarOpcMenu();                             // Muestra el menú principal
void instrucciones();                              // Muestra instrucciones (por ahora decorativas)
void instruccionesDimensionador();                 // Instrucciones para ingresar dimensiones
void mostrarOpcJuego();                            // Muestra opciones de juego
int pantallaPrincipal();                           // Espera ENTER para continuar desde la pantalla de inicio
void menu(char tableroJugador1[][MAX_COLUMNAS],
          char tableroJugador2[][MAX_COLUMNAS],
          int filas, int columnas);                // Muestra y controla el menú principal

// ---------------------- Funciones utilitarias ----------------------
void limpiarConsola();                             // Limpia la consola (ANSI)
void limpiarBuffer();							   // Limpia el buffer
void ocultarCursor();
void mostrarCursor();
bool enter();                                      // Espera a que el usuario presione ENTER
char convertirAMayusculas(char cadena[]);         // Convierte cadena a mayúsculas

// ---------------------- Validaciones y conversiones ----------------------
int esNumero(char caracter);                       // Verifica si un char es número
int conversor(char caracter);                      // Convierte char numérico a entero
int unirNumeros(int numero, int resultado);        // Une dígitos a un número completo
int convertirCadenaNumerica(char *entrada);        // Convierte string numérico a entero con validaciones
int convertirEntrada(char *entrada);               // Wrapper para conversión

// ---------------------- Tablero ----------------------
void mostrarTablero(char tablero[][MAX_COLUMNAS],
                    int filas, int columnas);      // Muestra el tablero

// ---------------------- Lógica del juego (declarar cuando lo agregues) ----------------------
void juego(char tablero1[][MAX_COLUMNAS],char tablero2[][MAX_COLUMNAS],int *filas, int *columnas,int modo);                              // Esta debes implementarla luego
bool inicializarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas);
int validarDimensiones(int filas, int columnas); 
#endif
