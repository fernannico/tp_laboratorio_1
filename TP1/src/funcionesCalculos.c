
#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculos.h"
#include "validaciones.h"

float CalcularDescuentos(float totalInicial, float descuentoPorcentaje)
{
	float totalConDescuento;

	totalConDescuento = totalInicial - (totalInicial * descuentoPorcentaje / 100);

	return totalConDescuento;
}

float CalcularAumentos(float totalInicial, float aumentoPorcentaje)
{
	float totalConAumento;

	totalConAumento = totalInicial + (totalInicial * aumentoPorcentaje / 100);

	return totalConAumento;
}

float ConvertirPesosABtc(float monto, float CotizacionBitcoin)
{
	float bitcoinsFinal;

	bitcoinsFinal = monto / CotizacionBitcoin;

	return bitcoinsFinal;
}

float CalcularPrecioPorKm(float monto, float kilometros)
{
	float precioUnitario;

	precioUnitario = monto / kilometros;

	return precioUnitario;
}

float CalcularDiferenciaDePrecios(float precioUno, float precioDos)
{
	float resto;
	if(precioUno > precioDos){
		resto = precioUno - precioDos;
	}else{
		resto = precioDos - precioUno;
	}

	return resto;
}

void HacerCargaForzada(float descuentosDebito, float aumentoCredito, float bitcoin, float kilometros, float aerolineasPrecio, float latamPrecio)
{
	float precioFinalDebitoAerolineas;
	float precioFinalCreditoAerolineas;
	float precioEnBitcoinsAerolineas;
	float precioUnitarioAerolineas;
	float precioFinalDebitoLatam;
	float precioFinalCreditoLatam;
	float precioEnBitcoinsLatam;
	float precioUnitarioLatam;
	float diferenciaPrecios;

	precioFinalDebitoAerolineas = CalcularDescuentos(aerolineasPrecio, descuentosDebito);
	precioFinalCreditoAerolineas = CalcularAumentos(aerolineasPrecio, aumentoCredito);
	precioEnBitcoinsAerolineas = ConvertirPesosABtc(aerolineasPrecio, bitcoin);
	precioUnitarioAerolineas = CalcularPrecioPorKm(aerolineasPrecio, kilometros);
	precioFinalDebitoLatam = CalcularDescuentos(latamPrecio, descuentosDebito);
	precioFinalCreditoLatam = CalcularAumentos(latamPrecio, aumentoCredito);
	precioEnBitcoinsLatam = ConvertirPesosABtc(latamPrecio, bitcoin);
	precioUnitarioLatam = CalcularPrecioPorKm(latamPrecio, kilometros);
	diferenciaPrecios = CalcularDiferenciaDePrecios(latamPrecio, aerolineasPrecio);

	printf("\nKMs Ingresados: %.2f km", kilometros);
	printf("\n\nPrecio Aerolíneas: $ %.2f", aerolineasPrecio);
	MostrarResultados(precioFinalDebitoAerolineas, precioFinalCreditoAerolineas, precioEnBitcoinsAerolineas, precioUnitarioAerolineas);
	printf("\n\n“Precio Latam: $ %.2f", latamPrecio);
	MostrarResultados(precioFinalDebitoLatam, precioFinalCreditoLatam, precioEnBitcoinsLatam, precioUnitarioLatam);
	printf("\n\nLa diferencia de precio es: $ %.2f", diferenciaPrecios);
}
