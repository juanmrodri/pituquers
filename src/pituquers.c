/*
 ============================================================================
 Name        : pituquers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"

/* esto va con las funciones que hice

int UTN_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int UTN_getChar(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

*/

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int main(void) {
	setbuf(stdout, NULL);

	int edad;
	int alturaDelDomicilio;
	int validacionRetorno;
	int opcionDelMenu;

	while(opcionDelMenu!=3)
	{
		printf("1) Ingresar edad\n");
		printf("2) Ingresar altura\n");
		printf("3) Salir\n");

		validacionRetorno = utn_getNumber(&opcionDelMenu,"Ingrese la opcion que quiera:\n"
					,"La opcion es incorrecta:\n",3,1,1);
		if(validacionRetorno == 0)
		{
			switch(opcionDelMenu)
			{
				case 1:
					validacionRetorno = utn_getNumber(&edad,"Ingrese la edad entre 18 y 99:\n"
								,"La edad es incorrecta:\n",99,18,2);
						if(validacionRetorno == 0)
						{
							printf("%d", edad);
						}
						else
						{
							printf("La edad no fue ingresada bien\n");
						}
					break;
				case 2:
					validacionRetorno = utn_getNumber(&alturaDelDomicilio,"Ingrese la altura de su casa:\n"
								,"La altura de su casa es incorrecta:\n",60000,1,2);
						if(validacionRetorno == 0)
						{
							printf("%d", alturaDelDomicilio);
						}
						else
						{
							printf("La altura no fue ingresada bien\n");
					}
					break;

				case 3:
					printf("Nos vimos\n");
					break;
			}
		}
	}
	return 0;
}

