
/// @brief valida que se esté ingresando un valor mayor a 0, caso contrario anuncia un error y pide que reintentes
/// @param mensaje para escribir el mensaje inicial de pedir la entrada de un numero positivo
/// @param mensajeError para escribir el mensaje que saldra en caso que el numero sea invalido
/// @return retorna un numero positivo tras la validacion
float ValidarIngresoNumeroPositivo(char * mensaje, char * mensajeError);

/// @brief imprime el menu y pide el ingreso de una opcion del menu
/// @param kilometros para poder ver el valor de la variable "kilometros" en el menu
/// @param aerolineasPrecio para poder ver el valor de la variable aerolineas en el menu
/// @param latamPrecio para poder ver el valor de la variable "latam" en el menu
/// @param NumeroIngresado pide el ingreso de una opcion en numero entero
/// @return retorna la opcion ingresada
int EjecutarMenu(float kilometros, float aerolineasPrecio, float latamPrecio, int NumeroIngresado);

/// @brief Muestra los resultados de los 4 calculos que se hacen en funcion del precio del vuelo y los kilometros
/// @param precioFinalDebito para mostrar el resultado del descuento que se aplica si el pago se efectua con debito
/// @param precioFinalCredito para mostrar el resultado del aumento que se aplica si el pago se efectua con credito
/// @param precioEnBitcoins para mostrar la conversion del precio del vuelo en bitcoins
/// @param precioUnitario para mostrar el calculo del precio por kilometro
void MostrarResultados(float precioFinalDebito, float precioFinalCredito, float precioEnBitcoins, float precioUnitario);
