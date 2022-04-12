
/*#ifndef FUNCIONESCALCULOS_H_
#define FUNCIONESCALCULOS_H_
*/

/// @brief calcula el monto final de un monto al que se le aplica un descuento, indicando el monto inicial y el descuento a aplicar
/// @param totalInicial es el monto inicial sin descuento
/// @param descuentoPorcentaje es el porcentaje de descuento a aplicar (en numero entero)
/// @return retorna el monto final con descuento aplicado
float CalcularDescuentos(float totalInicial, float descuentoPorcentaje);

/// @brief calcula el monto final de un monto al que se le aplica un aumento, indicando el monto inicial y el aumento a aplicar
/// @param totalInicial es el monto inicial sin aumento
/// @param aumentoPorcentaje es el porcentaje de aumento a aplicar (en numero entero)
/// @return retorna el monto final con aumento aplicado
float CalcularAumentos(float totalInicial, float aumentoPorcentaje);

/// @brief pasar un monto en pesos a bitcoins.
/// @param monto el monto en pesos que se quiere convertir
/// @param CotizacionBitcoin cotizacion de 1 bitcoin
/// @return la cantidad de btc que equivale al monto ingresado
float ConvertirPesosABtc(float monto, float CotizacionBitcoin);

/// @brief calcular el precio por kilometro unitario
/// @param monto el monto total
/// @param kilometros kilometros totales
/// @return precio de un solo kilometro
float CalcularPrecioPorKm(float monto, float kilometros);

/// @brief calcula el resto entre el numero mayor contra el menor
/// @param precioUno 1 de los 2 montos necesarios para hacer la resta
/// @param precioDos el 2do de los 2 montos necesarios para hacer la resta
/// @return retorna el resultado de la resta (diferencia)
float CalcularDiferenciaDePrecios(float precioUno, float precioDos);


