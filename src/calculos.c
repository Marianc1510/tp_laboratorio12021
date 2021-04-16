/*
 * calculos.c
 *
 *  Created on: 16 abr. 2021
 *      Author: marian
 */

#include <stdio_ext.h>
#include <stdlib.h>

/*
 * \brief suma: Realiza la suma de dos valores pasado por parametro
 * \param float operando1: se registra el valor obtenido por consola
 * \param float operando2: se registra el valor obtenido por consola
 * \param float* pResultado: direccion de memoria donde se alojara el resultado de dicha operacion
 * \return retorno: 0 (EXITO) si se logro realizar la operacion, -1 (ERROR) si no se logro
 */
int cal_suma(float operando1,float operando2,float* pResultado)
{
	int retorno=-1;
	if(pResultado != NULL )
	{
		*pResultado = operando1 + operando2;
		retorno=0;
	}
	return retorno;
}

/*
 * \brief resta: Realiza la resta de dos valores pasado por parametro
 * \param float operando1: se registra el valor obtenido por consola
 * \param float operando2: se registra el valor obtenido por consola
 * \param float* pResultado: direccion de memoria donde se alojara el resultado de dicha operacion
 * \return retorno: 0 (EXITO) si se logro realizar la operacion, -1 (ERROR) si no se logro
 */
int cal_resta(float valor1,float valor2,float* pResultado)
{
	int retorno=-1;
	if(pResultado !=NULL)
	{
		*pResultado= valor1 - valor2;
		retorno=0;
	}
	return retorno;
}

/*
 * \brief division: Realiza la division de dos valores pasado por parametro
 * \param float operando1: se registra el valor obtenido por consola
 * \param float operando2: se registra el valor obtenido por consola
 * \param float* pResultado: direccion de memoria donde se alojara el resultado de dicha operacion
 * \return retorno: 0 (EXITO) si se logro realizar la operacion, -1 (ERROR) si no se logro
 */
int cal_division(float valor1,float valor2,float* pResultado)
{
	int retorno=-1;
	if(pResultado !=NULL && valor2 != 0)
	{
		*pResultado = valor1 / valor2;
		retorno=0;
	}
	return retorno;
}

/*
 * \brief multiplicacion: realiza la multiplicacion de dos valores pasado por parametro
 * \param float operando1: se registra el valor obtenido por consola
 * \param float operando2: se registra el valor obtenido por consola
 * \param float* pResultado: direccion de memoria donde se alojara el resultado de dicha operacion
 * \return retorno: 0 (EXITO) si se logro realizar la operacion, -1 (ERROR) si no se logro
 */
int cal_multiplicacion(float valor1,float valor2,float* pResultado)
{
	int retorno=-1;
	if(pResultado !=NULL)
	{
		*pResultado = valor1 * valor2;
		retorno=0;
	}
	return retorno;
}

/*
 * \brief factorial: realiza la factorizacion del valor pasado por parametro
 * \param float operando1: se registra el valor obtenido por consola
 * \param float* pResultado: direccion de memoria donde se alojara el resultado de dicha operacion
 * \return retorno: 0 (EXITO) si se logro realizar la operacion, -1 (ERROR) si no se logro
 */
int cal_factorial(float operando,float* pResultado)
{
	int retorno=-1;
	int auxNumero=1;
	int i;
	if(pResultado !=NULL )
	{
		for(i=operando; i >=1; i--)
		{
			auxNumero= auxNumero * i;
		}
		*pResultado=  auxNumero;
		retorno=0;
	}
	return retorno;
}
