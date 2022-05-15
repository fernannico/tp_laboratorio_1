/*
 * ArrayPassenger.c
 *
 *  Created on: 12 may. 2022
 *      Author: nicolas ivan fernandez
 */

#include "ArrayPassenger.h"

static int ObtenerID(void);
static int ObtenerID(void) {
	static int idIncremental = 1;
	return idIncremental++;
}

int initPassengers(Passenger list[], int len)			//YA
{
	int retorno;
	retorno = -1;

	if(len > 0 && list != NULL)
	{
		retorno = 0;
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = LIBRE;
		}
	}

	return retorno;
}

int addPassenger(Passenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
	Passenger unPasajero;

	int retorno;
	retorno = HayarEspacioLibre(list, len);

	if(len > 0 && list != NULL && retorno != -1)
	{
		unPasajero = PedirUnPassanger();
		unPasajero.id = ObtenerID();
		unPasajero.isEmpty = OCUPADO; //cada vez que ingrese un pasajero, ya lo muestre como ocupado

		list[retorno] = unPasajero;
		retorno = 0;
	}
	return retorno;
}

int findPassengerById(Passenger list[], int len, int id)
{
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int removePassenger(Passenger list[], int len, int id)
{
	int retorno;
	retorno = -1;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty== OCUPADO && list[i].id== id)
		{
			list[i].isEmpty= LIBRE;

			retorno = 0;
			break;
		}
	}
	return retorno;
}

void InformarPassengers(Passenger list[], int len)
{
	int opcion;
	int subOpcion;
	int index;

	do
	{
		if(utn_getNumero(&opcion, "\nelija una opcion a informar: "
						"\n1 Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero"
						"\n2 Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
						"\n3 Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
						"\n 0 salir del menu de informes...", "\nerror, reintente:", 0, 3, 3) == 0)
		{
			switch (opcion)
			{
				case 0:
					printf("saliendo del programa");
				break;
				case 1:
					if(utn_getNumero(&subOpcion, "\nelija una opcion: "
							"\n0 - pasajeros por apellido y tipo de pasajero de manera descendente."
							"\n1 - pasajeros por apellido y tipo de pasajero de manera ascendente", "error, reintente: ", 0, 1, 3) == 0)
					{
						index = sortPassengers(list, len, subOpcion);
						if(index == 0)
						{
							if(printPassenger(list, len) == 0)
							{
								printf("se han ordenado!");
							}
						}else{
							printf("error!");
						}
					}
				break;
				case 2:
					InformarPromedios(list, len);
				break;
				case 3:
					if(utn_getNumero(&subOpcion, "\nelija una opcion: "
												"\n0 - Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ de manera descendente."
												"\n1 - Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ de manera ascendente", "error, reintente: ", 0, 1, 3) == 0)
					{
						index = sortPassengersByCode(list, len, subOpcion);
						if(index == 0)
						{
							if(printPassenger(list, len) == 0)
							{
								printf("se han ordenado!");
							}
						}else{
							printf("error!");
						}
					}
				break;
			}
		}

	}while (opcion != 0);
}

int sortPassengers(Passenger list[], int len, int order)
{
	int retorno;
	int i;
	int j;
	retorno = -1;
	Passenger auxiliar;

	//order int [1] indicate UP (mM) - [0] indicate DOWN (Mm)
	if(list != NULL && len > 0)
	{
		retorno = 0;
		switch (order)
		{
			case 1:
				for(i = 0; i < (len - 1); i++)
				{
					for(j = i+1; j < len; j++ )
					{
						if(strcmp(list[i].lastName,list[j].lastName)>0)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
						}else{
							if(strcmp(list[i].lastName, list[j].lastName) == 0)
							{
								if(list[i].typePassenger > list[j].typePassenger)
								{
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
								}
							}
						}
					}
				}
			break;
			case 0:
				for(i = 0; i < (len - 1); i++)
				{
					for(j = i+1; j < len; j++ )
					{
						if(strcmp(list[i].lastName,list[j].lastName)<0)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
						}else{
							if(strcmp(list[i].lastName, list[j].lastName) == 0)
							{
								if(list[i].typePassenger < list[j].typePassenger)
								{
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
								}
							}
						}
					}
				}
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int printPassenger(Passenger list[], int length)
{
	int retorno;
	retorno = -1;
	if(list != NULL && length > 0)
	{
		retorno = 0;
		for(int i=0; i< length; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				MostrarUnPasajero(list[i]);
			}
		}
	}
	return retorno;
}

int sortPassengersByCode(Passenger list[], int len, int order)
{
	int i;
	int j;
	int retorno;
	retorno = -1;

	Passenger auxiliar;

	if(list != NULL && len > 0)
	{
		switch (order)
		{
			case 1:
				for(i = 0; i < (len - 1); i++)
				{
					for(j = i+1; j < len; j++ )
					{
						if(list[j].statusFlight == 1)
						{
							if(strcmp(list[i].flycode,list[j].flycode)>0)
							{
								auxiliar = list[i];
								list[i] = list[j];
								list[j] = auxiliar;
							}
						}
					}
				}
			retorno = 0;
			break;
			case 0:
				for(i = 0; i < (len - 1); i++)
				{
					for(j = i+1; j < len; j++)
					{
						if(list[j].statusFlight == 1)
						{
							if((strcmp(list[i].flycode,list[j].flycode) < 0))
							{
								auxiliar = list[i];
								list[i] = list[j];
								list[j] = auxiliar;
							}
						}
					}
				}
			retorno = 0;
			break;
		}
	}
	return retorno;
}

void InformarPromedios(Passenger list[], int len)
{
	float montoTotal;
	int totalPasajeros;
	float promedio;
	int pasajerosSobrePromedio;

	montoTotal = 0;
	totalPasajeros = 0;
	pasajerosSobrePromedio = 0;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			totalPasajeros++;
			montoTotal += list[i].price;
		}
	}

	promedio = montoTotal / totalPasajeros;

	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].price > promedio)
		{
			pasajerosSobrePromedio++;
		}
	}

	printf("\nel monto total final es de %.2f"
			"\nel promedio es de %.2f"
			"\nlos pasajeros que superan el promedio son %d\n\n", montoTotal, promedio, pasajerosSobrePromedio);
}

	//				//				///				//			//

/**
 * PROPIAS
 * */

int HayarEspacioLibre(Passenger list[], int len)
{
	int retorno;
	retorno =-1;

	for(int i=0; i < len; i++)
	{
		if(list[i].isEmpty == LIBRE)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

Passenger PedirUnPassanger()
{

	 Passenger UnPasajero;
	 Passenger auxiliar;

	if((utn_getNombre(auxiliar.name, 51, "\ningrese el nombre del pasajero: ", "\nerror, reintente (Respetar la primer mayuscula)\n", 4) == 0) &&
	(utn_getNombre(auxiliar.lastName, 51, "\ningrese el apellido del pasajero: ", "\nerror, reintente  (Respetar la primer mayuscula)\n", 4) == 0) &&
	(utn_getFloat(&auxiliar.price, 10, "\ningrese el precio: ", "\nerror, reintente\n", 4) == 0) &&
	(utn_getAlfanumerico(auxiliar.flycode, 10, "\ningrese el codigo del vuelo", "\nerror, reintente\n", 4) == 0) &&
	(utn_getNumero(&auxiliar.statusFlight, "\ningrese el estado del vuelo: "
											"\n0 - DEMORADO"
											"\n1 - ACTIVO", "\nerror, reintente: ", 0, 1, 4) == 0) &&
	(utn_getNumero(&auxiliar.typePassenger, "\ningrese el tipo de pasajero: \n "
											"\n1- TURISTA "
											"\n2- EJECUTIVO "
											"\n3- PRIMERA \n", "\n error, ingrese una opcion valida ", 1, 3, 4) == 0))
	{
		UnPasajero = auxiliar;
	}
	return UnPasajero;
}

void ModificarPassenger(Passenger list[], int len, int orden)
{
 	int ParametroAModificar;

 	if(utn_getNumero(&ParametroAModificar, "\ningrese el parametro a modificar: "
 											"\n1 Nombre"
 											"\n2 Apellido"
 											"\n3 precio"
 											"\n4 codigo de vuelo"
 											"\n5 tipo de pasajero", "", 1, 5, 4) == 0)
 	{		/**dentro del if--->			ENCONTRE EL LEGAJO*/

 		switch (ParametroAModificar)
 		{
			case 1:
				if(utn_getNombre(list[orden].name, 51, "\ningrese el nombre del pasajero: ", "\nerror, reintente (Respetar la primer mayuscula)\n", 4) == 0)
				{
					printf("\nse modifico el nombre");
				}
			break;
			case 2:
				if(utn_getNombre(list[orden].lastName, 51, "\ningrese el apellido del pasajero: ", "\nerror, reintente (Respetar la primer mayuscula)\n", 4) == 0)
				{
					printf("\nse modifico el Apellido");
				}
			break;
			case 3:
				if(utn_getFloat(&list[orden].price, 10, "\ningrese el precio: ", "\nerror, reintente\n", 4) == 0)
				{
					printf("\nse modifico el precio");
				}
			break;
			case 4:
				if(utn_getAlfanumerico(list[orden].flycode, 10, "\ningrese el codigo del vuelo", "\nerror, reintente\n", 4) == 0)
				{
					printf("\nse modifico el codigo de vuelo");
				}
			break;
			case 5:
				if(utn_getNumero(&list[orden].typePassenger, "\ningrese el tipo de pasajero: \n "
						"\n1- TURISTA "
						"\n2- EJECUTIVO "
						"\n3- PRIMERA \n", "\n error, ingrese una opcion valida ", 1, 3, 4) == 0)
				{
					printf("\nse modifico el tipo de pasajero");
				}
			break;
			default:
				printf("\nno existe ese parametro, reintentar: ");
			break;

		}

 	}
}

void MostrarUnPasajero(Passenger pasajero)
{
	printf("\n%4d %10s %10s %4.2f %10s %4d %4d %4d \n", pasajero.id, pasajero.name, pasajero.lastName, pasajero.price, pasajero.flycode, pasajero.typePassenger, pasajero.statusFlight, pasajero.isEmpty);
}

