/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: marian
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int esNumero(char* pCadena);
static int myGets(char* pCadena,int limite);
static int getInt(int* pResultado);
static int esNumeroDecimal(char* cadena);
static int getFloat(float* pResultado);

/*
 * \brief esNumero: Verifica si la cadena ingresada es numerica
 * \param char* pCadena: cadena de caracteres a verificar
 * \return retorno 1 (VERDADERO) si la cadena es numerica y 0 (FALSO) si no lo es
 */
static int esNumero(char* pCadena)
{
	int retorno=1;
	int i=0;
	if(pCadena !=NULL && strlen(pCadena) > 0)
	{
		retorno=1;
		if(pCadena[0] == '-')
		{
			while(pCadena[i] != '\0')
			{
				if(pCadena[i] < '0' || pCadena[i] > '9')
				{
					retorno=0;
					break;
				}
				i++;
			}
		}
	}
	return retorno;
}
/*
 * \brief esNumeroDecimal: Verifica si la cadena ingresada es numerica con decimales
 * \param char* pCadena: cadena de caracteres a verificar
 * \return retorno 1 (VERDADERO) si la cadena es numerica  y 0 (FALSO) si no lo es
 */
static int esNumeroDecimal(char* cadena)
{
	int retorno=-1;
	int i=0;
	if(cadena !=NULL && strlen(cadena)>0)
	{
		while(cadena[i] == '.' || cadena [i]== ',')
		{
			continue;

			if(cadena[i] > '0' && cadena[i] < '9')
			{
				retorno=0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

/*
 * \brief myGets: Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'limite -1' caracteres.
 * \param *pCadena: Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param limite: Define el tamaño de la cadena.
 * \return retorno 0 (EXITO) si obtiene una cadena y -1 (ERROR) si no.
 */

static int myGets(char* pCadena,int limite)
{
	int retorno=-1;
	if(pCadena !=NULL && limite>0 && fgets(pCadena,limite,stdin)==pCadena)
	{
		__fpurge(stdin);
		if(pCadena[strlen(pCadena)-1]=='\n')
		{
			pCadena[strlen(pCadena)-1]='\0';
		}
		retorno=0;
	}
	return retorno;
}
/*
 * brief getInt: Verifica si la cadena ingresada sea numerica.
 * \param *pResultado: Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return retorno 0 (EXITO) si se obtiene el numero entero y -1 (ERROR) si no
 */

static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[64];
	if(pResultado !=NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumero(buffer))
		{
			*pResultado= atoi(buffer);
			retorno=0;
		}
	}
	return retorno;
}

/*
 * brief getFloat: Verifica si la cadena ingresada sea numerica con decimales.
 * \param *pResultado: Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return retorno 0 (EXITO) si se obtiene el numero entero y -1 (ERROR) si no
 */
static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[64];
	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumeroDecimal(buffer))
		{
			*pResultado= atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}

/*
 * brief utn_getNumeroInt:
 * param *pResultado: Puntero a varible donde se escribira el valor ingresado en el caso de ser correcto
 * param *pTexto:Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * param *pError:Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea valido.
 * param min:Valor minimo admitido
 * param max:Valor maximo admitido
 * param reintentos:Cantidad de veces que se le volvera a pedir al usuario que ingrese un dato en caso de error.
 * return Retorno 0 si esta todo ok, -1 si no pudo obtener el dato
 */

int utn_getNumeroInt(int* pResultado,char* pTexto,char* pError, int min, int max,int reintentos)
{
	int retorno=-1;
	int bufferInt;
	if(pResultado != NULL && pTexto != NULL && pError !=NULL && min <=max && reintentos >=0)
	{
		do
		{
			printf("%s",pTexto);
			if(getInt(&bufferInt)==0 && bufferInt >= min && bufferInt <=max)
			{
				*pResultado= bufferInt;
				retorno=0;
				break;
			}
			else
			{
				printf("%s",pError);
				reintentos --;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
/*
 * brief utn_getNumeroFloat :
 * param *pResultado: Puntero a varible donde se escribira el valor ingresado en el caso de ser correcto
 * param *pTexto:Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * param *pError:Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea valido.
 * param min:Valor minimo admitido
 * param max:Valor maximo admitido
 * param reintentos:Cantidad de veces que se le volvera a pedir al usuario que ingrese un dato en caso de error.
 * return Retorno 0 si esta todo ok, -1 si no pudo obtener el dato
 */

int utn_getNumeroFloat(float* pResultado,char* pTexto,char* pError, float min, float max,int reintentos)
{
	int retorno=-1;
	float bufferFloat;
	if(pResultado != NULL && pTexto != NULL && pError !=NULL && min <=max && reintentos >=0)
	{
		do
		{
			printf("%s",pTexto);
			if(getFloat(&bufferFloat)== 0 && bufferFloat >= min && bufferFloat <=max)
			{
				*pResultado= bufferFloat;
				retorno=0;
				break;
			}
			else
			{
				printf("%s",pError);
				reintentos --;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
