#include "Reutilizable.h"
// Funciones reutilizables
int opcionCadena(char cadena[]){ //Como el strcmp, pero tendría que precargar mis fokin palabras 
		//Se usa solamente en este programa, se debe de tener una referencia al intentar comparar la cadena de entrada
	char trampa[] = "TRAMPA"; //long: 5
	char superTrampa[] = "SUPER TRAMPA" ; //long: 12
	char instrucciones[] = "INSTRUCCIONES"; //long: 13
	char menu[] = "MENU"; //long: 4
	char salir[] = "SALIR"; //long: 5
	char guardarPartida[] = "GUARDAR PARTIDA"; //long: 15
	
	int longitud = 0;
	while(cadena[longitud] != '\0'){
		longitud++;
	}
	
	int iguales = 1;
	if(longitud <= 15){ //Suponiendo que es guardar partida
		for(int i=0;i<longitud;i++){
			if(cadena[i] != guardarPartida[i]){
				iguales++;	
				break;	
			}
		}
		if(iguales){
			return 1;
		}
	}		
}
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

void limpiarConsola() {
    printf("\033[H\033[J");
}
void mostrarTablero(char tablero[][MAX_COLUMNAS], int filas, int columnas) {
    printf("    ");
    for (int col = 0; col < columnas; col++) {
        printf("%d ", col + 1);
    }
    printf("\n");
    for (int i = 0; i < filas; i++) {
    	
        printf("%c |", 65 + i);
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
    printf("Presiona [ENTER] para continuar");
    c = getchar();
    mostrarCursor();  // Vuelve a mostrarlo después

    if (c != '\n') {
        limpiarBuffer();
        return false;
    }
	limpiarConsola();
    return true;
}
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}