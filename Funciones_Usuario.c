#include "Funciones_Usuario.h"
//Fase 3: Funciones del usuario
int entradaConsola(int filas, int columnas){
	// 1. Pedir una cadenaaaaa
	char entrada[100];
	int caracter, longitud = 0, aux = 0, aux2 = 0, x, y;
	
	printf("Entrada: ");
    fgets(entrada, sizeof(entrada), stdin);
    
    int i=0;
    while(entrada[i] != '\0' && entrada[i] != '\n'){ //Calcular la longtitud sin salto de linea
    	longitud++;
    	i++;
	}
	
	if(entrada[0] != '\0'){
		caracter = entrada[0];
		if((caracter >= '0' && caracter <= '9') || (caracter >= 33 && caracter <= 47)){ //Es un numero o símbolo, no valido
			return -1; 
		}else if((caracter >= 58 && caracter <= 64) || (caracter >= 91 && caracter <= 96) || (caracter >= 123 && caracter <= 126)){ //Es un caracter especial, no valido
			return -2; 
		}else if((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')){
			if(longitud >= 2){ //Se asume que es una coordenada
				if ((entrada[0] >= 'A' && entrada[0] <= 'P') || (entrada[0] >= 'a' && entrada[0] <= 'p')) {
		        x = conversor(entrada[0]); // Coordenada X, toma el acceso y se manda al puntero
		        i = 1;
		        while (i < longitud) {
		            if (esNumero(entrada[i])) {
		                aux2 = unirNumeros(conversor(entrada[i]), aux2); // Coordenada Y
		            }
		            i++;
		        }
		        y = aux2;
		        if(x > columnas || y > filas){
		        	return -4; //Fuera de rango
				}
				printf("Coordenadas: %d, %d\n", x,y);
				return 1;
    			}
			}
		}
	}else{
		return -3; //Ha ocurrido un error, la entrada está vacía 
	}
}
bool llenarTableroManualmente(char tablero[][MAX_COLUMNAS], int filas, int columnas){
    if (filas <= 0 || columnas <= 0 || filas > MAX_FILAS || columnas > MAX_COLUMNAS){
    	return false;
	}
	
	//
	
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = '~';
        }
    }
    return true;
}