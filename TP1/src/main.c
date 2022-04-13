
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "funcionesCalculos.h"

							/*Se deben realizar todas las validaciones necesarias para que el programa funcione
							correctamente. Por ej: no se puede realizar cálculos si no hay vuelos ingresados.*/

//testeo de github
int main(void) {
	setbuf(stdout, NULL);

	int NumeroIngresado;
	float kilometros;
	float aerolineasPrecio;
	float latamPrecio;
	float bitcoin;
	float precioFinalDebitoAerolineas;
	float precioFinalDebitoLatam;
	float precioFinalCreditoAerolineas;
	float precioFinalCreditoLatam;
	float precioEnBitcoinsAerolineas;
	float precioEnBitcoinsLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciaPrecios;
	int flagOpcionCuatro;

	kilometros = 0;
	aerolineasPrecio = 0;
	latamPrecio = 0;
	bitcoin = 4606954.55;
	flagOpcionCuatro = 0;

	do{
		printf("\n----------\n----------\n");
		printf("\n1. Ingresar Kilómetros: (km= %.2f)\n", kilometros);
		printf("\n2. Ingresar Precio de Vuelos: (Aerolíneas= %.2f, Latam= %.2f)", aerolineasPrecio, latamPrecio );
		printf("\n- Precio vuelo Aerolíneas: ");
		printf("\n- Precio vuelo Latam: \n");
		printf("\n3. Calcular todos los costos:");
		printf("\na) Tarjeta de débito (descuento 10%%)");
		printf("\nb) Tarjeta de crédito (interés 25%%)");
		printf("\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
		printf("\nd) Mostrar precio por km (precio unitario)");
		printf("\ne) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
		printf("\n4. Informar Resultados\n");
		printf("\n5. Carga forzada de datos: ");
		printf("\n6. Salir");
		scanf("%d", &NumeroIngresado);
		ValidarMenu(NumeroIngresado, 1,6);

		printf("\n----------\n----------\n");

		switch(NumeroIngresado){
			case 1:
				printf("\n1. Ingresar Kilómetros: (km=x)\n");
				scanf("%f", &kilometros);
				kilometros = ValidarIngreso(kilometros);
			break;
			case 2:
				printf("2. Ingresar Precio de Vuelos:\n ");
				//funcion pedir enteros
				//ver de poner la fx validar dentro de pedir enteross

				printf("- Precio vuelo Aerolíneas: ");
				scanf("%f", &aerolineasPrecio);
				aerolineasPrecio = ValidarIngreso(aerolineasPrecio);
				printf("- Precio vuelo Latam: ");
				scanf("%f", &latamPrecio);
				latamPrecio = ValidarIngreso(latamPrecio);
			break;
			case 3:
				if(kilometros != 0 && aerolineasPrecio != 0 && latamPrecio != 0){
					precioFinalDebitoAerolineas = CalcularDescuentos(aerolineasPrecio, 10);
					precioFinalDebitoLatam = CalcularDescuentos(latamPrecio, 10);
					precioFinalCreditoAerolineas = CalcularAumentos(aerolineasPrecio, 25);
					precioFinalCreditoLatam = CalcularAumentos(latamPrecio, 25);
					precioEnBitcoinsAerolineas = ConvertirPesosABtc(aerolineasPrecio, bitcoin);
					precioEnBitcoinsLatam = ConvertirPesosABtc(latamPrecio, bitcoin);
					precioUnitarioAerolineas = CalcularPrecioPorKm(aerolineasPrecio, kilometros);
					precioUnitarioLatam = CalcularPrecioPorKm(latamPrecio, kilometros);
					diferenciaPrecios = CalcularDiferenciaDePrecios(latamPrecio, aerolineasPrecio);
					flagOpcionCuatro = 1;
				}else{
					printf("\nfaltan datos para poder hacer calculos\n");
				}
			break;
			case 4:
				if(flagOpcionCuatro == 1){
					printf("\nKMs Ingresados: %.2f km", kilometros);
					printf("\n\nPrecio Aerolíneas: $ %.2f", aerolineasPrecio);
					printf("\na) Precio con tarjeta de débito: $ %.2f", precioFinalDebitoAerolineas);
					printf("\nb) Precio con tarjeta de crédito: $ %.2f", precioFinalCreditoAerolineas);
					printf("\nc) Precio pagando con bitcoin : %.8f BTC", precioEnBitcoinsAerolineas);
					printf("\nd) Precio unitario: $ %.2f", precioUnitarioAerolineas);

					printf("\n\n“Precio Latam: $ %.2f", latamPrecio);
					printf("\na) Precio con tarjeta de débito: $ %.2f", precioFinalDebitoLatam);
					printf("\nb) Precio con tarjeta de crédito: $ %.2f", precioFinalCreditoLatam);
					printf("\nc) Precio pagando con bitcoin : %.8f BTC", precioEnBitcoinsLatam);
					printf("\nd) Precio unitario: $ %.2f", precioUnitarioLatam);

					printf("\n\nLa diferencia de precio es: $ %.2f", diferenciaPrecios);
				}else{
					printf("\nfaltan datos para poder mostrar los calculos\n");
				}
			break;
			case 5:
				kilometros = 7090;
				aerolineasPrecio = 162965;
				latamPrecio = 159339;

				//funcion void carga forzada y los int son las 3 variables de arriba
				precioFinalDebitoAerolineas = CalcularDescuentos(aerolineasPrecio, 10);
				precioFinalDebitoLatam = CalcularDescuentos(latamPrecio, 10);
				precioFinalCreditoAerolineas = CalcularAumentos(aerolineasPrecio, 25);
				precioFinalCreditoLatam = CalcularAumentos(latamPrecio, 25);
				precioEnBitcoinsAerolineas = ConvertirPesosABtc(aerolineasPrecio, bitcoin);
				precioEnBitcoinsLatam = ConvertirPesosABtc(latamPrecio, bitcoin);
				precioUnitarioAerolineas = CalcularPrecioPorKm(aerolineasPrecio, kilometros);
				precioUnitarioLatam = CalcularPrecioPorKm(latamPrecio, kilometros);
				diferenciaPrecios = CalcularDiferenciaDePrecios(latamPrecio, aerolineasPrecio);

				printf("\nKMs Ingresados: %.2f km", kilometros);

				printf("\n\nPrecio Aerolíneas: $ %.2f", aerolineasPrecio);
				printf("\na) Precio con tarjeta de débito: $ %.2f", precioFinalDebitoAerolineas);
				printf("\nb) Precio con tarjeta de crédito: $ %.2f", precioFinalCreditoAerolineas);
				printf("\nc) Precio pagando con bitcoin : %.8f BTC", precioEnBitcoinsAerolineas);
				printf("\nd) Precio unitario: $ %.2f", precioUnitarioAerolineas);

				printf("\n\n“Precio Latam: $ %.2f", latamPrecio);
				printf("\na) Precio con tarjeta de débito: $ %.2f", precioFinalDebitoLatam);
				printf("\nb) Precio con tarjeta de crédito: $ %.2f", precioFinalCreditoLatam);
				printf("\nc) Precio pagando con bitcoin : %.8f BTC", precioEnBitcoinsLatam);
				printf("\nd) Precio unitario: $ %.2f", precioUnitarioLatam);

				printf("\n\nLa diferencia de precio es: $ %.2f", diferenciaPrecios);
			break;
		}
	}while(NumeroIngresado != 6);

	return EXIT_SUCCESS;
}



