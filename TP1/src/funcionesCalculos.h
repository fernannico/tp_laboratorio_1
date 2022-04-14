
/// @brief calcula el monto final de un monto al que se le aplica un descuento, indicando el monto inicial y el descuento a aplicar
/// @param totalInicial es el monto inicial sin descuento
/// @param descuentoPorcentaje es el porcentaje de descuento a aplicar (en numero entero, no de 0 a 1)
/// @return retorna el monto final con descuento aplicado
float CalcularDescuentos(float totalInicial, float descuentoPorcentaje);

/// @brief calcula el monto final de un monto al que se le aplica un aumento, indicando el monto inicial y el aumento a aplicar
/// @param totalInicial es el monto inicial sin aumento
/// @param aumentoPorcentaje es el porcentaje de aumento a aplicar (en numero entero, no de 0 a 1)
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

/// @brief realiza los calculos de esta biblioteca y muestra en pantalla los valores correspondientes
/// @param descuentoDebito es el porcentaje de descuento a aplicar en caso de pagar con debito (en numero entero, no de 0 a 1)
/// @param aumentoCredito es el porcentaje de aumento a aplicar en caso de pagar con credito (en numero entero, no de 0 a 1)
/// @param bitcoin cotizacion de 1 bitcoin
/// @param kilometros valor de los kilometros totales
/// @param aerolineasPrecio precio total del vuelo para la empresa aerolineas
/// @param latamPrecio precio total del vuelo para la empresa latam
void HacerCargaForzada(float descuentosDebito, float aumentoCredito, float bitcoin, float kilometros, float aerolineasPrecio, float latamPrecio);
