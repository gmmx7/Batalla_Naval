#include "Menu.h"
// Fase 1: Menu
void menu(char tableroJugador1[][MAX_COLUMNAS], char tableroJugador2[][MAX_COLUMNAS], int filas, int columnas) {
    char entrada[100];
    int opcion;
    bool autorizado = false; //Se eliminó la variable de modo de jueg0
	
    do {
    	//limpiarConsola();
        mostrarOpcMenu();
        printf("Opcion: ");
        fgets(entrada, sizeof(entrada), stdin);
        opcion = convertirEntrada(entrada);

        switch (opcion) {
            case 1: // Juego en solitario
                autorizado = true;
                limpiarConsola();
                juego(tableroJugador1, tableroJugador2, &filas, &columnas, 1);
                
                break;
            case 2: // Multijugador
                autorizado = true;
                limpiarConsola();
                juego(tableroJugador1, tableroJugador2, &filas, &columnas, 2);
                break;
            case 3: // Instrucciones
                limpiarConsola();
                instrucciones();
                break;
            case 4: // Salir
                printf("Saliendo del juego...\n");
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