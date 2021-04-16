/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"

int main(void)
{
	float operandoA;
	float operandoB;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMult;
	float resultadoFactA;
	float resultadoFactB;
	int opcion;

	do
	{
		if(utn_getNumeroInt(&opcion, "\nCALCULADORA\n"
			"1)Ingresar 1er Operando\n"
			"2)Ingresar 2do Operando\n"
			"3)Calcular todas las operaciones\n"
			"4)Resultados\n"
			"5)salir\n", "Opcion Invalida\n",1,5,2)==0)
		{
			switch(opcion)
			{
			case 1:
				utn_getNumeroFloat(&operandoA,"Ingrese 1er valor:\n","Dato invalido\n",-10000,10000,2);
				printf("\n---------------------------\n"
						" NUMERO A INGRESADO: %.2f"
						"\n--------------------------\n",operandoA);
				break;
			case 2:
				utn_getNumeroFloat(&operandoB,"Ingrese 2do valor:\n","Dato invalido\n",-10000,10000,2);
				printf("\n--------------------------\n"
						" NUMERO B INGRESADO: %.2f"
						"\n-------------------------\n",operandoB);
				break;
			case 3:
				cal_suma(operandoA, operandoB,&resultadoSuma);
				cal_resta(operandoA, operandoB,&resultadoResta);
				cal_division(operandoA, operandoB, &resultadoDivision);
				cal_multiplicacion(operandoA, operandoB, &resultadoMult);
				cal_factorial(operandoA,&resultadoFactA);
				cal_factorial(operandoB, &resultadoFactB);
				break;
			case 4:
				printf("\nRESULTADO SUMA: %.2f",resultadoSuma);
				printf("\nRESULTADO RESTA: %.2f",resultadoResta);
				if(operandoB !=0)
				{
					printf("\nRESULTADO DIVISION: %.2f",resultadoDivision);
				}
				else
				{
					printf("\nNO ES POSIBLE DIVIDIR POR CERO");
				}
				printf("\nRESULTADO MULTIPLICACION: %.2f",resultadoMult);
				printf("\nRESULTADO FACTORIAL 1ER OPERANDO: %.2f",resultadoFactA);
				printf("\nRESULTADO FACTORIAL 2DO OPERANDO: %.2f\n",resultadoFactB);
				break;
			case 5:
				printf("\n ¡GOODBYE!");
				break;
			}
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
