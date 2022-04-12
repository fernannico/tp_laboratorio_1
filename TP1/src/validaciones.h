
/*#ifndef FUNCIONESCALCULOS_H_
#define FUNCIONESCALCULOS_H_*/

/// @brief para validar el limite de opciones que permite el menu
/// @param numeroAValidar numero ingresado para validar
/// @param minimo minumo numero del rango a usar
/// @param maximo maximo numero del rango a usar
/// @return el numero ingresado validado
int ValidarMenu(int numeroAValidar, int minimo, int maximo);

/// @brief para validar que se este ingresando un dato mayor que 0
/// @param numeroIngresado numero ingresado a validar
/// @return retorna el numero correcto tras la validacion
float ValidarIngreso(float numeroIngresado);
