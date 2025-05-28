#include "Juego.h"
//Fase 2: Inicialización del juego y tableros
void juego(char tablero1[][MAX_COLUMNAS], char tablero2[][MAX_COLUMNAS], int *filas, int *columnas, int modo) {
    bool tableroCreado = false;
    char entrada[100];
    int f = 0, c = 0, validacion;

    limpiarConsola();
    instruccionesDimensionador();

    // Entrada y validación de dimensiones
    do {
        printf("\nFilas: ");
        fgets(entrada, sizeof(entrada), stdin);
        f = convertirEntrada(entrada);

        printf("Columnas: ");
        fgets(entrada, sizeof(entrada), stdin);
        c = convertirEntrada(entrada);

        validacion = validarDimensiones(f, c);

        switch (validacion) {
            case 1:{
            	printf(">>>Numero de filas invalido :c (debe estar entre 5 y 10).\n");
				break;
			}
            case 2:{
            	printf(">>>Numero de columnas invalido :c (debe estar entre 5 y 15).\n");
				break;
			} 
            case -1:{
            	printf(">>>SUPER ERROR PAPU, intenta nuevamente.\n");
                break;
			}
		}
    } while (validacion != 0);

            // Actualizar variables externas por referencia
    *filas = f;
    *columnas = c;

    // Inicialización e impresión de tablero
    limpiarConsola();
    printf("Dimensiones validas \n%d x %d :D \nInicializando tablero...\n", *filas, *columnas);
    enter();

    tableroCreado = inicializarTablero(tablero1, *filas, *columnas);
			
	if(tableroCreado){
		limpiarConsola();
    	printf("Tu tablero ha sido inicializado:\n");
        mostrarTablero(tablero1, *filas, *columnas);
        enter();
        limpiarConsola();
        switch (modo) {
        	case 1: { // Modo solitario: Usuario vs Computadora
	        	printf("Estamos en modo solitario.\n");
	        	int salida = entradaConsola(f,c);
	        	printf("DEBUG >> entradaConsola retorno: %d\n", salida); 
            	switch(salida){
            		case 1:{
            			printf("Coordenadas impresas.\n");
						break;
					}
				}
	        	break;
        	}
	        case 2:{
	            // Modo multijugador: aún sin implementar
	            printf("Estamos en modo multijugador.\n");
	            enter();
        		limpiarConsola();
	            break;
	        	}
	        default:{
	        		printf("Opcion no valida.");
				break;
			}
		}
	}	
}
bool inicializarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas) {
    if (filas <= 0 || columnas <= 0 || filas > MAX_FILAS || columnas > MAX_COLUMNAS){
    	return false;
	}
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = '~';
        }
    }
    return true;
}
int validarDimensiones(int filas, int columnas){
	if((filas >= 5 && filas <= 10) && (columnas >= 5 && columnas <= 15)){
		return 0; //Dimension dentro del rangooooo
	}else if((filas >= 5 && filas <= 10) != (columnas >= 5 && columnas <= 15)){
		if(filas < 5 || filas > 10){
			return 1; //Error en el numero de filas, es menor a 5 o mayor a 10
		}else if(columnas < 5 || columnas > 15){
			return 2; //Error en el numero de columnas, es menor a 5 o mayor a 15
		}
	}
	return -1;
}