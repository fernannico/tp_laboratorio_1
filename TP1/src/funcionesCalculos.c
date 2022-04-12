
#include <stdio.h>
#include <stdlib.h>

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
