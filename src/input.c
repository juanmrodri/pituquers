/*
 * input.c
 *
 *  Created on: 7 abr 2022
 *      Author: juanm
 */

#include "input.h"
#include <stdlib.h>

// firma de las func. static

static int getInt(int* pResultado);

static int isNumeric(char* cadena);

static int myGets(char* cadena, int longitud);

//



int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int i;
	int ret;

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				//scanf("%d",&aux);
				if(getInt(&aux) == 0 && aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					ret=0; // salio bien
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=1; // salio mal
		}

	return ret;
}

static int getInt(int* pResultado)
{
	int ret;
	char buffer[4096];

	ret=1;

	if(myGets(buffer,sizeof(buffer))==0 && isNumeric(buffer))
	{
		ret=0;
		*pResultado = atoi(buffer);
	}
	return ret;
}

static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);

	cadena[strlen(cadena)-1]='\0'; // arregla el enter que se agrega al final, para que fgets cargue correctamente la cadena

	return 0;
}

static int isNumeric(char* cadena)
{
	int ret=1;
	int i=0; // me tomo esta licencia aca

	if(cadena[0] == '-') // negativos
	{
		i = 1;
	}
	for( ; cadena[i] !='\0'; i++)
	{
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			ret = 0;
			break;
		}
	}

	return ret;
}


/*

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int i;
	int ret;
	//char bufferCadenaAux[16];

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0; i<reintentos; i++)
			{
				printf("%s", mensaje);
				if(getInt(&aux)==0)
				{
					if(aux>=minimo && aux<=maximo)
					{
						break;
					}
						reintentos--;
						printf(mensajeError);
				}
			}


			if(reintentos==0)
			{
				ret=1; // salio mal
			}
			else
			{
				ret=0;
				*pResultado = aux;
			}
		}

	return ret;
}

*/
