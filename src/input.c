/*
 * input.c
 *
 *  Created on: 7 abr 2022
 *      Author: juanm
 */

#include "input.h"
#include <stdio.h>
#include <stdlib.h>

// firma de la func. static

static int getInt(int* pResultado);

//

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int i;
	int retorno;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo && reintentos>=0)
	{
		for(i=0; i<reintentos; i++)
		{
			printf("%s", mensaje);
			if(getInt(&aux)==1)
				{
					if(aux>=minimo && aux<=maximo)
						{
							break;
						}
						fflush(stdin);

						reintentos--;
						printf(mensajeError);
				}
		}

		if(reintentos==0)
		{
			retorno=1; // salio mal
		}
		else
		{
			retorno=0;
			*pResultado = aux;
		}

	}

	return retorno;
}

static int getInt(int* pResultado)
{
	char buffer[64];
	scanf("%s",buffer);

	printf("\nEstamos en la static func.\n");

	*pResultado = atoi(buffer);

	return -1;
}

/* estas estan hechas por mi 08/04/2022 - hacerla mierda con el apunte de inputs



int UTN_getChar(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
		char aux;
		int i;
		int retorno;

		retorno=1; // salio mal

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo && reintentos>=0)
		{
			for(i=0; i<reintentos; i++)
			{
				printf("%s", mensaje);
				scanf("%c", &aux);
				if(aux>=minimo && aux<=maximo)
				{
					retorno=0; // salio bien
					*pResultado=aux;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					retorno=1;
				}
			}
		}
		return retorno;
}

 */

