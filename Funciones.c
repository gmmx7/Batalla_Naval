#include "Funciones.h"

// Mostrar Textos
void mostrarOpcMenu() {
    printf("\n-> Menu: \n1. Nuevo Juego \n2. Multijugador  \n3. Instrucciones \n4. Salir\n");
}

void instrucciones() {
    printf("\nInstrucciones:\nDo you got plans tonight?\nI'm a couple hundred miles from Japan and I\nI was thinking I could fly to your hotel tonight\n'Cause I-I-I can't get you off my mind\nCan't get you off my mind\nCan't get you off my mind (uh)\n");
}

void instruccionesDimensionador() {
    printf("-> Bienvenido al dimensionador!\n\tPara crear el juego necesitamos un numero de filas y\n\tcolumnas mayores que 5 y menores a 15\n**Ingresa tus datos!\n");
}

void mostrarOpcJuego() {
    printf("\n-> Opciones de juego: \n1. Partida en solitario \n2. Multijugador \n3. Regresar al inicio\n");
}

// Funciones reutilizables
int conversor(char caracter) {
	if(esNumero(caracter)){
		return caracter - '0';
	}else if(caracter >= 'A' && caracter <= 'Z'){
		return caracter - 'A';
	}else if(caracter >= 'a' && caracter <= 'z'){
		return caracter - 'a';
	}else{
		return -1;
	}
}

int esNumero(char caracter) {
    return caracter >= '0' && caracter <= '9';
}

int unirNumeros(int numero, int resultado) {
    return resultado * 10 + numero;
}

int convertirCadenaNumerica(char *entrada) { //Solo funciona en el menú !NO SE IMPLEMENTE EN ALGUNA OTRA FUNCIÓN!
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

void limpiarConsola() {
    printf("\033[H\033[J");
}

void mostrarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas) {
    printf("     ");
    for (int col = 0; col < columnas; col++) {
        printf("%d ", col + 1);
    }
    printf("\n");
    for (int i = 0; i < filas; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < columnas; j++) {
            printf(" %c", tablero[i][j]);
        }
        printf("\n");
    }
}

void ocultarCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // ocultar cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void mostrarCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = TRUE;  // volver a mostrar cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

bool enter() {
    int c;

    ocultarCursor();  // Oculta el cursor
    printf("\nPresiona ENTER para continuar...");
    c = getchar();
    mostrarCursor();  // Vuelve a mostrarlo después

    if (c != '\n') {
        limpiarBuffer();
        return false;
    }

    return true;
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fase 1: Menu
void menu(char tableroJugador1[][MAX_COLUMNAS], char tableroJugador2[][MAX_COLUMNAS], int filas, int columnas) {
    char entrada[100];
    int opcion;
    bool autorizado = false;
    int modoDeJuego = 0;

    do {
        mostrarOpcMenu();
        printf("\nOpcion: ");
        fgets(entrada, sizeof(entrada), stdin);
        opcion = convertirEntrada(entrada);

        switch (opcion) {
            case 1: // Juego en solitario
                autorizado = true;
                modoDeJuego = 1;
                limpiarConsola();
                juego(tableroJugador1, tableroJugador2, &filas, &columnas, modoDeJuego);
                
                break;
            case 2: // Multijugador
                autorizado = true;
                modoDeJuego = 2;
                limpiarConsola();
                juego(tableroJugador1, tableroJugador2, &filas, &columnas, modoDeJuego);
                break;
            case 3: // Instrucciones
                limpiarConsola();
                instrucciones();
                break;
            case 4: // Salir
                printf("\nSaliendo del juego...\n");
                exit(0);
            default:
                limpiarConsola();
                printf("Opcion incorrecta papu, ingresa una opcion valida\n");
                break;
        }

        if (!autorizado) {
            enter();
            limpiarConsola();
        }

    } while (!autorizado);
}

int pantallaPrincipal() {
    bool juegoIniciado = false;
    juegoIniciado = enter();

    if (juegoIniciado) {
        return 1;
    } else {
        return 0;
    }
}

//Fase 2: Inicialización del juego y tableros
void juego(char tablero1[][MAX_COLUMNAS], char tablero2[][MAX_COLUMNAS], int *filas, int *columnas, int modo) {
    bool tableroCreado = false;
    char entrada[100];
    int f = 0, c = 0, validacion = -1;

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
        switch (modo) {
        	case 1: { // Modo solitario: Usuario vs Computadora
        	printf("Estamos en modo solitario");
        	
        	break;
        	}
        case 2:{
            // Modo multijugador: aún sin implementar
            printf("Estamos en modo multijugador");
            break;
        	}
		}
	}	
}

bool inicializarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas) {
    if (filas <= 0 || columnas <= 0 || filas > MAX_FILAS || columnas > MAX_COLUMNAS)
        return false;

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
			return 1; //Error en el numero de filas, es menor a 5 o mayor a 15
		}else if(columnas < 5 || columnas > 15){
			return 2; //Error en el numero de columnas, es menor a 5 o mayor a 15
		}
	}
	return -1;
}

//Fase 3: Funciones del usuario
int entradaConsola(char tablero[][MAX_COLUMNAS], int filas, int columnas){
	// 1. Pedir una cadenaaaaa
	char entrada[100];
	int caracter, longitud = 0, aux = 0, aux2 = 0, x, y;
	
	printf("\nEntrada: ");
    fgets(entrada, sizeof(entrada), stdin);
    
    int i=0;
    while(entrada[i] != '\0' && entrada[i] != '\n'){ //Calcular la longtitud sin salto de linea
    	longitud++;
    	i++;
	}
	
	if(entrada[0] != '\0'){
		caracter = entrada[0];
		if((caracter >= '0' && caracter <= '9') || (caracter >= 33 && caracter <= 47)){
			return -1; //Es un numero o símbolo, no valido
		}else if((caracter >= 58 && caracter <= 64) || (caracter >= 91 && caracter <= 96) || (caracter >= 123 && caracter <= 126)){
			return -2; //Es un caracter especial, no valido
		}else if((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')){
			if(longitud >= 2){ //Se asume que es una coordenada
				if ((entrada[0] >= 'A' && entrada[0] <= 'P') || (entrada[0] >= 'a' && entrada[0] <= 'p')) {
		        x = conversor(entrada[0]); // Coordenada X, se manda toma el acceso y se manda al puntero
				
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
		        return 1; 
    			}
			}
			
			
			if(longitud >= 12){
				for(int i = 0;i < longitud;i++){
					if(entrada[i] == 'TRAMPA' || entrada[i] == 'trampa'){
						return 2;
					}
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