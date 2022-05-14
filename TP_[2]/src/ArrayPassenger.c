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
		unPasajero.isEmpty = OCUPADO; //cada vez que ingrese un alumno, ya lo muestre como ocupado

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
	//				//				///				//			//
/*
int Passenger_Baja(Passenger array[], int len, int idGen)
{
	int rtn = -1;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (Passenger_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		//USAR FUNCION GET_INT DE LIBRERIA DE INPUTS
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idGen);

		//BUSCO INDEX POR ID EN ARRAY
		while (findPassengerById(array, TAM, idGen) == -1) {
			puts("NO EXISTE ID.");

			//USAR FUNCION GET_INT DE LIBRERIA DE INPUTS
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idGen);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = findPassengerById(array, TAM, idGen);

		//PREGUNTAR SI DESEA CONTINUAR
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = LIBRE;

		//RETORNO 0 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 0;
	}

	return rtn;
}*/


/**
 * PROPIAS
 * */
void InicializarListaHarcodeos(Passenger list[])
{
	Passenger harcodeos[2000] = {{1,"Pedro", "Gomez", 1707.5, "ACT1", 2, OCUPADO}, {2,"Alan", "Gimenez", 2000.5, "ACT1", 2, OCUPADO}};

	for(int i = 0; i < 2000; i++)
	{
		list[i] = harcodeos[i];
	}
}

int HayarEspacioLibre(Passenger list[], int len)				//YA
{
	int retorno;
	retorno =-1;												//por default supone q esta lleno

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
	(utn_getNumero(&auxiliar.typePassenger, "\ningrese el tipo de pasajero: \n "
											"\n1- TURISTA "
											"\n2- EJECUTIVO "
											"\n3- PRIMERA \n", "\n error, ingrese una opcion valida ", 1, 3, 4) == 0))
	{
		UnPasajero = auxiliar;
	}
	return UnPasajero;
}

void ModificarPassenger(Passenger list[], int len, int orden)//si bien es solo para promedio, HACER QUE LA PERSONA DECIDA q cambiar.
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

void MostrarListaDePasajeros(Passenger lista[], int len)
{
	for(int i=0; i< len; i++)
	{
		if(lista[i].isEmpty == OCUPADO)
		{
			MostrarUnPasajero(lista[i]);
		}
	}
}

void MostrarUnPasajero(Passenger pasajero)
{
	printf("\n%4d %10s %10s %4.2f %10s %4d %4d \n", pasajero.id, pasajero.name, pasajero.lastName, pasajero.price, pasajero.flycode, pasajero.typePassenger, pasajero.isEmpty);
}

