/*
 * inputs.h
 *
 *  Created on: 12 may. 2022
 *      Author: nicolas Ivan Fernandez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INPUTS_H_
#define INPUTS_H_

int myGets(char * cadena, int size);

int utn_getNumero(int * pResultado, char* mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

int utn_getNombre(char pNombre[], int limite, char* msg, char* msgErr, int reintentos);

int utn_getAlfanumerico(char pAlfanumerico[], int limite, char *mensaje, char *mensajeError, int reintentos);

int utn_getFloat(float *pFloat, int limite, char *mensaje, char *mensajeError, int reintentos);

int PedirEntero(char * mensaje);

int PedirEnteroValidado(char * mensaje, char * mensajeError, int minimo, int maximo);

float PedirFlotante(char * mensaje);

float PedirFloatValidado(char * mensaje, char * mensajeError, float minimo, float maximo);

void pedirString(char * mensaje, char * string);

#endif /* INPUTS_H_ */
