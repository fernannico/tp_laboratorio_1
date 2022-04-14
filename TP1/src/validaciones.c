
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

float ValidarIngresoNumeroPositivo(char * mensaje, char * mensajeError)
{
	float numeroValidado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numeroValidado);

	while(numeroValidado < 1)
	{
		printf("%s", mensajeError);
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroValidado);
	}

	return numeroValidado;
}

int EjecutarMenu(float kilometros, float aerolineasPrecio, float latamPrecio, int NumeroIngresado)
{
	printf("\n----------\n----------\n");
	printf("\n1. Ingresar Kilómetros: (km= %.2f)\n", kilometros);
	printf("\n2. Ingresar Precio de Vuelos: (Aerolíneas= %.2f, Latam= %.2f)", aerolineasPrecio, latamPrecio);
	printf("\n- Precio vuelo Aerolíneas: ");
	printf("\n- Precio vuelo Latam: \n");
	printf("\n3. Calcular todos los costos:");
	printf("\na) Tarjeta de débito (descuento 10%%)");
	printf("\nb) Tarjeta de crédito (interés 25%%)");
	printf("\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
	printf("\nd) Mostrar precio por km (precio unitario)");
	printf("\ne) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
	printf("\n4. Informar Resultados\n");
	printf("\n5. Carga forzada de datos: \n");
	printf("\n6. Salir\n");
	printf("elija una opcion: ");
	scanf("%d", &NumeroIngresado);
	printf("\n----------\n----------\n");

	return NumeroIngresado;
}

void MostrarResultados(float precioFinalDebito, float precioFinalCredito, float precioEnBitcoins, float precioUnitario)
{
	printf("\na) Precio con tarjeta de débito: $ %.2f", precioFinalDebito);
	printf("\nb) Precio con tarjeta de crédito: $ %.2f", precioFinalCredito);
	printf("\nc) Precio pagando con bitcoin : %.8f BTC", precioEnBitcoins);
	printf("\nd) Precio unitario: $ %.2f", precioUnitario);
}
