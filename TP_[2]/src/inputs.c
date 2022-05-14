/*
 * inputs.c
 *
 *  Created on: 12 may. 2022
 *      Author: nicolas Ivan Fernandez
 */
#include "inputs.h"

static int esNumerica(char * cadena, int limite);
static int getInt(int * pResultado);
static int isValidNombre(char* pBuffer, int limite);
static int isValidAlfanumerico(char *pBuffer, int limite);
static int getString(char* pBuffer, int limite);
static int isValidFloat(char *pBuffer, int limite);

int utn_getNumero(int * pResultado, char* mensaje, char * mensajeError, int minimo, int maximo, int reintentos)//se guarda el valor de la variable puntero '*' si lo que se devuelve esta tod0 bien
{
    int retorno = -1;
    int bufferInt;

    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s", mensajeError);
		fflush(stdin);
		reintentos--;
    }while(reintentos >= 0);
    return retorno;
}

static int getInt(int * pResultado)
{
    int retorno = -1;
    char bufferString[50];
    if(pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString, sizeof(bufferString)) == 1)
    {
       retorno = 0;
       *pResultado = atoi(bufferString);
    }
    return retorno;
}

int myGets(char * cadena, int size)
{
	int retorno = -1;
	char bufferString[5000];

	if(cadena != NULL && size > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= size)
			{
				strncpy(cadena, bufferString, size);
				retorno = 0;
			}
		}
	}
    return retorno;
}

static int esNumerica(char * cadena, int limite)
{
    int retorno = -1; //error
    int i;

    if(cadena != NULL && limite > 0)
    {
    	retorno = 1;
    	for(i = 0; i<limite && cadena [i] != '\0';i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
    }
    return retorno;
}

//								////								////								////								//

int utn_getNombre(char pNombre[], int limite, char* msg, char* msgErr, int reintentos)
{
    int retorno=-1;
    char bufferNombre [4900];
    if (pNombre != NULL && limite > 0 && msg != NULL && msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            fflush(stdin);
            if (getString(bufferNombre, limite) == 0 && isValidNombre(bufferNombre, limite))
            {
                strncpy(pNombre, bufferNombre, limite);
                retorno = 0;
                break;
            }else{
                printf("%s",msgErr);
            }

        }while (reintentos >= 0);
    }
    return retorno;
}

static int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    int cantidadEspacios = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 && pBuffer[0]>='A' && pBuffer[0]<='Z')
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
        	if(pBuffer[i]==' ' && cantidadEspacios == 0)
            {
                cantidadEspacios++;
            }else{
            	if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] != ' ') && !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' && pBuffer[i-1] == ' '))
				{
					retorno = 0;
					break;
				}
            }
        }
    }
    return retorno;
}
static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferStr [limite];
    if (pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(bufferStr, limite, stdin);
        len = strlen(bufferStr);
        if(len != limite-1 || bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1]= '\0';
        }
        retorno=0;
        strncpy(pBuffer, bufferStr, limite);
    }
    return retorno;
}

//								////								////								////								//

int utn_getAlfanumerico(char *pAlfanumerico, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pAlfanumerico != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 && isValidAlfanumerico(buffer, limite))
            {
                strncpy(pAlfanumerico, buffer, limite);
                retorno = 0;
                break;
            }else{
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

static int isValidAlfanumerico(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(!(   (tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z') || (pBuffer[i] >= '0' && pBuffer[i] <= '9')))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

//								////								////								////								//

int utn_getFloat(float *pFloat, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferFloat[4096];
    if( pFloat != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if(getString(bufferFloat, limite) == 0 && isValidFloat(bufferFloat, limite))
            {
                *pFloat = atof(bufferFloat);
                retorno = 0;
                break;
            }else{
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

static int isValidFloat(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contadorDePuntos = 0;
    if((pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0) && (((pBuffer[0] == '-' || pBuffer[0] == '+') && pBuffer[1] != '.') || (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]=='.' && contadorDePuntos==0)
            {
                contadorDePuntos++;
            }else{
            	if(!(pBuffer[i]>='0' && pBuffer[i]<='9'))
				{
					retorno = 0;
					break;
				}
            }
        }
    }
    return retorno;
}

//								////								////								////								//

int PedirEntero(char * mensaje)
{
	int numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numero);

	return numero;
}

int PedirEnteroValidado(char * mensaje, char * mensajeError, int minimo, int maximo)
{
	int numero;

	numero = PedirEntero(mensaje);
	while(numero < minimo || numero > maximo)
	{
		printf("%s\n", mensajeError);
		fflush(stdin);
		numero = PedirEntero(mensaje);
	}

	return numero;
}

float PedirFlotante(char * mensaje)
{
	float numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numero);

	return numero;
}

float PedirFloatValidado(char * mensaje, char * mensajeError, float minimo, float maximo)
{
	float numero;

	numero = PedirFlotante(mensaje);
	while(numero < minimo || numero > maximo)
	{
		printf("%s\n", mensajeError);
		fflush(stdin);
		numero = PedirFlotante(mensaje);
	}

	return numero;
}

void pedirString(char * mensaje, char * string)
{
	printf("%s", mensaje);
    fflush(stdin);
    gets(string);
}

