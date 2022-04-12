
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int ValidarMenu(int numeroAValidar, int minimo, int maximo)
{
	int numero;
	while(numeroAValidar < minimo || numeroAValidar > maximo)
	{
		printf("ingresaste un mal dato, ingresa del 1 al 6");
		printf("\n1. Ingresar Kilómetros: (km=x)\n");
		printf("\n2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)");
		printf("\n	 - Precio vuelo Aerolíneas:");
		printf("\n	 - Precio vuelo Latam: \n");
		printf("\n3. Calcular todos los costos:");
		printf("\n	 a) Tarjeta de débito (descuento 10%%)");
		printf("\n	 b) Tarjeta de crédito (interés 25%%)");
		printf("\n	 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
		printf("\n	 d) Mostrar precio por km (precio unitario)");
		printf("\n	 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
		printf("\n4. Informar Resultados");
		printf("\n“Latam:");
		printf("\na) Precio con tarjeta de débito: r");
		printf("\nb) Precio con tarjeta de crédito: r");
		printf("\nc) Precio pagando con bitcoin : r");
		printf("\nd) Precio unitario: r");
		printf("\nAerolíneas:");
		printf("\na) Precio con tarjeta de débito: r");
		printf("\nb) Precio con tarjeta de crédito: r");
		printf("\nc) Precio pagando con bitcoin : r");
		printf("\nd) Precio unitario: r");
		printf("\nLa diferencia de precio es : r“\n\n");
		printf("\n5. Carga forzada de datos");
		printf("\n6. Salir");
		scanf("%d", &numeroAValidar);
		numero = numeroAValidar;
	}
	return numero;
}

float ValidarIngreso(float numeroIngresado)
{
	float numeroValidado;

	while(numeroIngresado < 1)
	{
		printf("no ingresaste un valor valido, hagalo para continuar:");
		scanf("%f", &numeroIngresado);
	}

	numeroValidado = numeroIngresado;

	return numeroValidado;
}
