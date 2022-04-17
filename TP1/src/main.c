#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "funcionesCalculos.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	float kilometros;
	float aerolineasPrecio;
	float latamPrecio;
	float descuentoDebito;
	float precioFinalDebitoAerolineas;
	float precioFinalDebitoLatam;
	float aumentoCredito;
	float precioFinalCreditoAerolineas;
	float precioFinalCreditoLatam;
	float bitcoin;
	float precioEnBitcoinsAerolineas;
	float precioEnBitcoinsLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciaPrecios;
	int flagOpcionCuatro;

	kilometros = 0;
	aerolineasPrecio = 0;
	latamPrecio = 0;
	descuentoDebito = 10;
	aumentoCredito = 25;
	bitcoin = 4606954.55;
	flagOpcionCuatro = 0;

	do{
		numeroIngresado = EjecutarMenu(kilometros, aerolineasPrecio, latamPrecio, numeroIngresado);

		switch(numeroIngresado)
		{
			case 1:
				kilometros = ValidarIngresoNumeroPositivo("\n1. Ingresar Kilómetros: ", "ingresaste un kilometraje invalido, reintentar: \n");
			break;
			case 2:
				printf("2. Ingresar Precio de Vuelos:\n ");
				aerolineasPrecio = ValidarIngresoNumeroPositivo("- Precio vuelo Aerolíneas: ", "ingresaste un precio invalido, reintentar: \n");
				latamPrecio = ValidarIngresoNumeroPositivo("- Precio vuelo Latam: ", "ingresaste un precio invalido, reintentar: \n");
			break;
			case 3:
				if(kilometros != 0 && aerolineasPrecio != 0 && latamPrecio != 0)
				{
					precioFinalDebitoAerolineas = CalcularDescuentos(aerolineasPrecio, descuentoDebito);
					precioFinalCreditoAerolineas = CalcularAumentos(aerolineasPrecio, aumentoCredito);
					precioEnBitcoinsAerolineas = ConvertirPesosABtc(aerolineasPrecio, bitcoin);
					precioUnitarioAerolineas = CalcularPrecioPorKm(aerolineasPrecio, kilometros);
					precioFinalDebitoLatam = CalcularDescuentos(latamPrecio, descuentoDebito);
					precioFinalCreditoLatam = CalcularAumentos(latamPrecio, aumentoCredito);
					precioEnBitcoinsLatam = ConvertirPesosABtc(latamPrecio, bitcoin);
					precioUnitarioLatam = CalcularPrecioPorKm(latamPrecio, kilometros);
					diferenciaPrecios = CalcularDiferenciaDePrecios(latamPrecio, aerolineasPrecio);
					flagOpcionCuatro = 1;
					printf("\nse han realizado los calculos\n");
				}else{
					printf("\nfaltan datos para poder hacer calculos\n");
				}
			break;
			case 4:
				if(flagOpcionCuatro == 1)
				{
					printf("\nKMs Ingresados: %.2f km", kilometros);
					printf("\n\nPrecio Aerolíneas: $ %.2f", aerolineasPrecio);
					MostrarResultados(precioFinalDebitoAerolineas, precioFinalCreditoAerolineas, precioEnBitcoinsAerolineas, precioUnitarioAerolineas);
					printf("\n\nPrecio Latam: $ %.2f", latamPrecio);
					MostrarResultados(precioFinalDebitoLatam, precioFinalCreditoLatam, precioEnBitcoinsLatam, precioUnitarioLatam);
					printf("\n\nLa diferencia de precio es: $ %.2f", diferenciaPrecios);
				}else{
					printf("\nfaltan datos para poder mostrar los calculos\n");
				}
			break;
			case 5:
				kilometros = 7090;
				aerolineasPrecio = 162965;
				latamPrecio = 159339;
				HacerCargaForzada(descuentoDebito, aumentoCredito, bitcoin, kilometros, aerolineasPrecio, latamPrecio);
			break;
			case 6:
				printf("Saliendo del programa");
			break;
			default:
				printf("se ingresó una opcion invalida: ");
			break;
		}
	}while(numeroIngresado != 6);

	return EXIT_SUCCESS;
}
