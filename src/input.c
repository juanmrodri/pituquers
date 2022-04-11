/*
 * input.c
 *
 *  Created on: 7 abr 2022
 *      Author: juanm
 */

#include "input.h"
#include <stdio.h>

int getInt(int * pNumeroIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos){

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}

/* estas estan hechas por mi 08/04/2022 - hacerla mierda con el apunte de inputs

int UTN_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int i;
	int retorno;

	retorno=1; // salio mal

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo && reintentos>=0)
	{
		for(i=0; i<reintentos; i++)
		{
			printf("%s", mensaje);
			scanf("%d", &aux);
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

