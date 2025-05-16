#include <stdlib.h>
#include <stdbool.h>
#include "Funciones.h"

void mostrarOpcMenu(){
	printf("\n-> Menu: \n1. Nuevo Juego \n2. Instrucciones \n3.Salir");
}
int conversor(char caracter){
	int entero = caracter - '0';
	return entero;
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
			resultado = resultado * 10 + numero;
		}else if(entrada[i] == ' '){
			printf("NOOOO, un espacio :c\n");
		}else{  
			return resultado;
		}

		i++;
	}
	return resultado;
}
int menu(){
	char entrada[100];
	int opcion;
	bool autorizado = false;
	
	do{
		printf("\nOpcion: ");
		fgets(entrada, sizeof(entrada), stdin);
		opcion = convertirEntrada(entrada);
			switch(opcion){
				case 1:{
					printf("\nCargando juego...");
					autorizado = true;
					return 0;
				}
				case 2:{
					instrucciones();
					autorizado = true;
					return 1;
				}
				case 3:{
					printf("\nSaliendo del juego...");
					exit(0);
				}
				default:{
					printf("\nOpcion incorrecta papu, ingresa una opcion valida");
					break;
				}
			}
	}while(!autorizado);
	return -1;
}
void instrucciones(){
	printf("\nInstrucciones: \nDo you got plans tonight? \nI'm a couple hundred miles from Japan and I\nI was thinking I could fly to your hotel tonight\n'Cause I-I-I can't get you off my mind\nCan't get you off my mind\nCan't get you off my mind (uh)\n");
}