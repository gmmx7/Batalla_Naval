#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define MAX_FILAS 10
#define MAX_COLUMNAS 15

int main(){
	char tableroJugador[MAX_FILAS][MAX_COLUMNAS];
    char tableroComputadora[MAX_FILAS][MAX_COLUMNAS];

    int filas, columnas;
    bool inicializados = false;
    
	int request;
	do{
		printf("--------Batalla Naval--------");
		mostrarOpcMenu();
		request = menu(&filas, &columnas);
		
		if(request == 1){//Juego en curso
			printf("\nPreparando juego...");
			inicializarTablero(tableroJugador, filas, columnas);
            inicializarTablero(tableroComputadora, filas, columnas);
			printf("\nTablero de %d filas x %d columnas\n", filas, columnas);
			inicializados = true;
			if(inicializados){
				printf("\nTableros inicializados...");
			}
		}
		if(request == 3){
			exit(0);
		}
        if(request == -1){
            printf("\nHa ocurrido un error.\n");
            exit(1);
        }
        
	}while(request == 2);
	
	return 0;
}