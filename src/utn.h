/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: marian
 */

#ifndef UTN_H_
#define UTN_H_


int utn_getNumeroInt(int* pResultado,char* pTexto,char* pError, int min, int max,int reintentos);
int utn_getNumeroFloat(float* pResultado,char* pTexto,char* pError, float min, float max,int reintentos);

#endif /* UTN_H_ */
