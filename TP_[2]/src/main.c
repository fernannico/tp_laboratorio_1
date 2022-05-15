/*
 ============================================================================
 Name        : TP2.c
 Author      : nicolas Ivan Fernandez
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "inputs.h"

int main(void) {
	setbuf(stdout, NULL);

	Passenger listaPasajeros[TAM];

	int opcion;
	int estadosLibres;
	int retorno;
	int idMod;
	int contadorPassengers;

	contadorPassengers = 0;

	estadosLibres = initPassengers(listaPasajeros, TAM);//iniciamos todos en libres

	if(estadosLibres == 0)//si hay espacio..
	{
		do{
			printf("\n\n=============================================\n"
					"		menu: 						  \n"
					"---------------------------------------------\n"
					"	opcion 1: ALTA de un pasajero.\n"
					"---------------------------------------------\n"
					"	opcion 2: MODIFICAR un pasajero.\n"
					"---------------------------------------------\n"
					"	opcion 3: BAJA de un pasajero.\n"
					"---------------------------------------------\n"
					"	opcion 4: INFORMAR\n"
					"---------------------------------------------\n"
					"	opcion 5: FINALIZAR programa\n"
					"=============================================\n");

			if(utn_getNumero(&opcion, "ingrese una opcion: \n", "error, opcion invalida\n", 1, 5, 3) == 0)
			{
				printf("opcion %d\n", opcion);
			}

			switch(opcion)
			{
				case 1:
					retorno = addPassenger(listaPasajeros, TAM, listaPasajeros->id, listaPasajeros->name, listaPasajeros->lastName, listaPasajeros->price, listaPasajeros->typePassenger, listaPasajeros->flycode);
					switch (retorno)
					{
						case 0:
							printf("\n se ingreso al pasajero!\n");
							contadorPassengers++;
							break;
						case -1:
							printf("\n no se ingreso al pasajero. No hay espacio!\n");
							break;
					}
				break;
				case 2:
					if(contadorPassengers != 0)
					{
						printPassenger(listaPasajeros, TAM);

						if(utn_getNumero(&idMod, "\ningrese el id a modificar", "\nerror", 1, 2000, 4) == 0)
						{
							printf("\nse ingreso %d", idMod);
						}
						if((retorno = findPassengerById(listaPasajeros, TAM, idMod)) != -1)
						{
							ModificarPassenger(listaPasajeros, TAM, retorno);
						}
					}else{
						printf("\nno hay pasajeros de alta.");
					}
				break;
				case 3:
					if(contadorPassengers != 0)
					{
						printPassenger(listaPasajeros, TAM);
						if(utn_getNumero(&idMod, "\ningrese el id a borrar", "\nerror", 1, 2000, 4) == 0)
						{
							printf("\nse ingreso %d", idMod);
						}
						if((retorno = findPassengerById(listaPasajeros, TAM, idMod)) != -1)
						{
							removePassenger(listaPasajeros, TAM, idMod);
							retorno = retorno+1;
							printf("\npasajero %d dado de baja", retorno);
							contadorPassengers--;
						}
					}else{
						printf("\nno hay pasajeros de alta.");
					}

				break;
				case 4:
					if(contadorPassengers != 0)
					{
						InformarPassengers(listaPasajeros, TAM);
					}else{
						printf("\nno hay pasajeros de alta.");
					}
				break;
				case 5:
					printf("\nsaliendo del programa...");
				break;
				default:
					printf("se ingresó una opcion invalida: ");
				break;
			}
		}while(opcion != 5);
	}

	return EXIT_SUCCESS;
}


