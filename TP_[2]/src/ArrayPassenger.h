/*
 *
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

#define LIBRE 0
#define OCUPADO 1
#define TAM 2000

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}typedef Passenger;

/// @brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera (isEmpty) en TRUE
		/// en todas las posiciones del array.
/// @param list Passenger* Pointer to array of passenger
/// @param len int de longitud del Array
/// @return Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
/// ejemplo: r = initPassengers(arrayPassengers, ELEMENTS);
int initPassengers(Passenger  list[], int len);

/// @brief Agrega en un array de pasajeros existente los valores recibidos como parámetro en la primer posición libre.
/// @param list passenger
/// @param len int
/// @param id int
/// @param name[] char
/// @param lastName[] char
/// @param price float
/// @param typePassenger int
/// @param flycode char
/// @return Devuelve (-1) si hay error [Longitud no válida o puntero NULL o sin espacio libre] - (0) si está bien
/// ejemplo: r = addPassenger(arrayPassenger,ELEMENTS,id,name,lastName,price,typePassenger,flycode);
int addPassenger(Passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);

/// @brief  Busca un pasajero recibiendo como parámetro de búsqueda su Id.
/// @param list Passenger
/// @param len int
/// @param id int
/// @return Devolver la posición del índice del pasajero, o (-1) si [Longitud no válida o puntero NULL recibido o pasajero no encontrado]
/// /// ejemplo: int index = findPassengerId(arrayPassengers, ELEMENTS,9);
int findPassengerById(Passenger list[], int len, int id);

/// @brief Eliminar un Pasajero por Id (colocar el indicador isEmpty en 1) (put isEmpty Flag in 1)
/// @param list Passenger
/// @param len int
/// @param id int
/// @return Retorna (-1) si Error [Longitud no válida o puntero NULL o si no puede encontrar un pasajero] - (0) si está bien
/// ejemplo: r = removePassenger(arrayPassengers, ELEMENTS,20);
int removePassenger(Passenger list[], int len, int id);

void InformarPassengers(Passenger list[], int len);

/// @brief Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente. indicar orden ARRIBA o ABAJO
/// @param list Passenger
/// @param len int
/// @param order int [1] indica ARRIBA - [0] indica ABAJO
/// @return Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
/// ejemlpo: r = sortPassengersByName(arrayPassengers, ELEMENTS, 1);
int sortPassengers(Passenger list[], int len, int order);

/// @brief Imprime el array de pasajeros de forma encolumnada.
/// @param list Passenger
/// @param length int
/// @return int
/// ejemplo: r = printPassenger(arrayPassengers, ELEMENTS);
int printPassenger(Passenger list[], int length);

/// @brief Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente.
/// @param list Passenger
/// @param len int
/// @param order int [1] indica ARRIBA - [0] indica ABAJO
/// @return Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
/// ejemplo: r = sortPassengersByCode(arrayPassengers, ELEMENTS, 1);
int sortPassengersByCode(Passenger list[], int len, int order);

Passenger PedirUnPassanger();

int HayarEspacioLibre(Passenger list[], int len);

void ModificarPassenger(Passenger list[], int len, int orden);

void MostrarUnPasajero(Passenger pasajero);

void InformarPromedios(Passenger list[], int len);



#endif /* ARRAYPASSENGER_H_ */
