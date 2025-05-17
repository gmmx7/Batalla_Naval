#include <stdlib.h>
#include <stdbool.h>
#include "Funciones.h"

//Mostrar textos -> Funcionamiento
void mostrarOpcMenu(){
	printf("\n-> Menu: \n1. Nuevo Juego \n2. Instrucciones \n3. Salir");
}
void instrucciones(){
	printf("\nInstrucciones: \nDo you got plans tonight? \nI'm a couple hundred miles from Japan and I\nI was thinking I could fly to your hotel tonight\n'Cause I-I-I can't get you off my mind\nCan't get you off my mind\nCan't get you off my mind (uh)\n");
}
void instruccionesDimensionador(){
	printf("-> Bienvenido al dimensionador!\n\tPara crear el juego necesitamos un numero de filas y\n\tcolumnas mayores que 5 y menores a 15\n********Ingresa tus datos!");
}

//Funciones globales
int conversor(char caracter){//Conversor de un solo dígito
	int entero = caracter - '0';
	return entero;
}
int unirNumeros(int numero, int resultado){
	return resultado * 10 + numero;
}
int convertirEntrada(char entrada[]){
	int i = 0, resultado = 0, numero = 0;
	char caracter;
	
	if(entrada[i] == '\n'){
		printf("NOOOO, papu, un salto de linea :c\n");
		return -1;
	}
	
	while(entrada[i] != '\0'){
		if(entrada[i] == '\n'){
			break;
		}
		if(entrada[i] >= '0' && entrada[i] <= '9'){
			caracter = entrada[i];
			numero = conversor(caracter);
			resultado = unirNumeros(numero, resultado);
		}else if(entrada[i] == ' '){
			printf("NOOOO, un espacio :c\n");
			return -1;
		}else{  
			printf("Caracter inválido :c : %c\n", entrada[i]);
			return -1;
		}
		i++;
	}
	return resultado;
}
void limpiarConsola(){
    printf("\033[H\033[J");
}

//Fase 1: Menu
int menu(int *filas, int *columnas){
	char entrada[100];
	int opcion;
	bool autorizado = false;
	
	do{
		printf("\nOpcion: ");
		fgets(entrada, sizeof(entrada), stdin);
		opcion = convertirEntrada(entrada);
			switch(opcion){
				case 1:{
					autorizado = true;
					printf("Preparando juego...");
					//Pedir dimensiones y validar
					dimensionador(filas, columnas);
					return 1;
				}
				case 2:{
					limpiarConsola();
					autorizado = true;
					instrucciones();
					return 2;
				}
				case 3:{
					printf("\nSaliendo del juego...\n");
					return 3;
				}
				default:{
					limpiarConsola();
					printf("Opcion incorrecta papu, ingresa una opcion valida");
					mostrarOpcMenu();
					break;
				}
			}
	}while(!autorizado);
	return -1;
}

//Fase 2: Creación de tableros
int validarDimensiones(int filas, int columnas){
	if((filas >= 5 && filas <= 10) && (columnas >= 5 && columnas <= 15)){
		return 0; //Dimension dentro del rangooooo
	}else if((filas >= 5 && filas <= 10) != (columnas >= 5 && columnas <= 15)){
		if(filas < 5 || filas > 10){
			return 1; //Error en el numero de filas, es menor a 5 o mayor a 15
		}else if(columnas < 5 || columnas > 15){
			return 2; //Error en el numero de columnas, es menor a 5 o mayor a 15
		}
	}
	return -1;
}
bool verificarDimensiones(int filas, int columnas) {
	int posibleError = validarDimensiones(filas, columnas);

	switch(posibleError){
		case 0:
			printf("\nDimensiones aceptadas.");
			return true;
		case 1:
			limpiarConsola();
			printf("\nERROR -> Dimensiones no aceptadas :c\nTu error esta en las FILAS\nIngresa de nuevo las dimensiones :D\n");
			break;
		case 2:
			limpiarConsola();
			printf("\nERROR -> Dimensiones no aceptadas :c\nTu error esta en las COLUMNAS\nIngresa de nuevo las dimensiones :D\n");
			break;
		default:
			limpiarConsola();
			printf("\nERROR -> Dimensiones super rechazadas :c\nLas filas y columnas son menores o mayores del rango\nIngresa de nuevo las dimensiones :D\n");
			break;
	}
	return false;
}
void dimensionador(int *filas, int *columnas){
	char entrada1[10], entrada2[10];
	int posibleError;
	bool dimensionadorActivado = false;
	
	limpiarConsola();
	do{
		
		instruccionesDimensionador();
		printf("\nIngresa las dimensiones: ");
		printf("\nFilas: ");
		fgets(entrada1, sizeof(entrada1), stdin);
		*filas = convertirEntrada(entrada1);

		printf("\nColumnas: ");
		fgets(entrada2, sizeof(entrada2), stdin);
		*columnas = convertirEntrada(entrada2);

		dimensionadorActivado = verificarDimensiones(*filas, *columnas);
	}while(!dimensionadorActivado);
}

void inicializarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas){
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = '~';  // Agua
        }
    }
}

/*
void mostrarMatriz(char matriz[][], int filas, int columnas){
	for(int i=0;i<filas;i++){
		printf(" %s ", matriz[i][]);
		for(int j=0;i<columnas;j++){
			printf(" %s", );
		}
	}
}
*/