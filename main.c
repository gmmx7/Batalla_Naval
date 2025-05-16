#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(){
	int request;
	do{
		printf("--------Batalla Naval--------");
		mostrarOpcMenu();
		request = menu();
		
        if (request == -1) {
            printf("\nHa ocurrido un error.\n");
            exit(1);
        }
        
	}while(request == 1);
	
	return 0;
}