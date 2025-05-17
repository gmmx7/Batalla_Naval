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
void mostrarOpcJuego(){
	printf("\n-> Opciones de juego: \n1. Partida en solitario \n2. Multijugador \n3. Regresar al inicio");
}

//Funciones globales
int conversor(char caracter) {
	return caracter - '0';
}
int esNumero(char caracter) {
	return caracter >= '0' && caracter <= '9';
}
int unirNumeros(int numero, int resultado) {
	return resultado * 10 + numero;
}
int convertirCadenaNumerica(char *entrada) {
	int i = 0, resultado = 0;
	char caracter;

	if (entrada[i] == '\n') {
		printf("NOOOO, papu, un salto de línea :c\n");
		return -1;
	}

	while (entrada[i] != '\0') {
		if (entrada[i] == '\n') break;

		caracter = entrada[i];

		if (esNumero(caracter)) {
			resultado = unirNumeros(conversor(caracter), resultado);
		} else if (caracter == ' ') {
			printf("NOOOO, un espacio :c\n");
			return -1;
		} else {
			printf("Caracter inválido :c : %c\n", caracter);
			return -1;
		}
		i++;
	}

	return resultado;
}
int convertirEntrada(char *entrada) {
	return convertirCadenaNumerica(entrada);
}
void limpiarConsola(){
    printf("\033[H\033[J");
}
void mostrarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas){
	//Imprimir el 1 2 3 4 5 ... (solo es algo de adorno pues)
	printf("   ");
	for(int col = 0;col < columnas;col++){
		printf("%d ",col);
	}
	printf("\n");
	//aquí se maneja la matriz real
	for(int i=0;i<filas;i++){
		printf("%2d |", i);
		for(int j=0;j<columnas;j++){
			printf(" %c", tablero[i][j]);
		}
		printf("\n");
	}
}
void pausa(){
    printf("\nPresiona ENTER para continuar...");
    while (getchar() != '\n');
}
char* convertirAMayusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - 32;
        }
    }
}

//Fase 1: Menu
int menu(char tableroJugador[][MAX_COLUMNAS], char tableroComputadora[][MAX_COLUMNAS], int *filas, int *columnas) {
    char entrada[100];
    int opcion;
    bool autorizado = false;

    do {
        printf("\nOpción: ");
        fgets(entrada, sizeof(entrada), stdin);
        opcion = convertirEntrada(entrada);

        switch (opcion) {
            case 1: {
                autorizado = true;
                dimensionador(filas, columnas); // 🔧 Aquí defines dimensiones
                return 1;
            }
            case 2: {
                limpiarConsola();
                autorizado = true;
                instrucciones();
                return 2;
            }
            case 3: {
                printf("\nSaliendo del juego...\n");
                return 3;
            }
            default: {
                limpiarConsola();
                printf("Opción incorrecta papu, ingresa una opción válida\n");
                mostrarOpcMenu();
                break;
            }
        }
    } while (!autorizado);

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
bool inicializarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas){
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = '~';  // Agua
        }
    }
    return true;
}

/*
	Fase 3: Flujo del juego
	Dos casos: Partida individual, Multijugador
*/
void juego(char tableroJugador[][MAX_COLUMNAS], char tableroComputadora[][MAX_COLUMNAS], int *filas, int *columnas){
	char entrada[100];
	int  tipoDeJuego;
	char opcion;
	bool autorizado = false;
	do{
		mostrarOpcJuego();
		printf("\nOpcion: ");
		fgets(entrada, sizeof(entrada), stdin);
		opcion = convertirEntrada(entrada);
		switch(opcion){
			case 1:{
				//Partida en solitario
				tipoDeJuego = 1;
				printf("----------PARTIDA EN SOLITARIO--------");
				prepararJuego(tableroJugador, tableroComputadora, filas, columnas, &tipoDeJuego);
				break;
			}
			case 2:{
				//Multijugador
				break;
			}
		}
	}while(!autorizado);
}
void entradaConsola(char tablero[][MAX_COLUMNAS], int filas, int columnas){
    char entrada[100];
    int fila, columna, completado, barcos = 0;
    bool autorizado = false;
	
	completado = (filas * columnas) * 0.25;
	
    do {
        printf("\n-> Entrada: "); //Coordenadas b13
        fgets(entrada, sizeof(entrada), stdin);

        if (entrada[0] == '\n' || entrada[1] == '\0') {
            printf("Entrada invalida: muy corta.\n");
            continue;
        }
        
        char letra = entrada[0];

        if (letra >= 'A' && letra <= 'Z') {
            fila = letra - 'A';
        } else if (letra >= 'a' && letra <= 'z') {
            fila = letra - 'a';
        } else {
            printf("Primera parte inválida: debe ser una letra.\n");
            continue;
        }

        // Convertimos el resto como número
        int numero = convertirCadenaNumerica(&entrada[1]);

        if (numero < 0) {
            printf("Numero invalido.\n");
            continue;
        }

        columna = numero;

        if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
            tablero[fila][columna] = 'B';  // Colocamos el barco
            barcos++;
            if(barcos == completado){
            	autorizado = true;
			}
			limpiarConsola();
			mostrarTablero(tablero,filas,columnas);
			pausa();
			limpiarConsola();
        } else {
            printf("Coordenadas fuera de rango.\n");
        }
    } while (!autorizado);
}
void prepararJuego(char tableroJugador[][MAX_COLUMNAS], char tableroComputadora[][MAX_COLUMNAS], int *filas, int *columnas, int *tipoDeJuego){
	bool iniciadoTablero1 = false;
	bool iniciadoTablero2 = false;
	switch (*tipoDeJuego) {
	    case 1: {
	        printf("Preparando juego...");
	        dimensionador(filas, columnas);
	        bool iniciadoTablero1 = inicializarTablero(tableroJugador, *filas, *columnas);
	
	        if (!iniciadoTablero1) {
	            printf("\nTablero de %d filas x %d columnas iniciado...\n", *filas, *columnas);
	        }
	
	        limpiarConsola();
	        printf("-> Tablero vacío iniciado...\n");
	        mostrarTablero(tableroJugador, *filas, *columnas);
	
	        printf("\n-> Iniciando rellenado...\n");
	        pausa();
	        limpiarConsola();
	        break;
	    }
	    case 2: {
	        printf("Preparando multijugador...");
	        break;
	    }
	    default: {
	        printf("Ha ocurrido un error al iniciar el juego.");
	        break;
	    }
	}
}

//Fase 4: Gestor de funciones de usuario dentro del juego