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

	int edadIngresada;
	int alturaDelDomicilio;
	int respuestaIngresada;

	edadIngresada = 0;
	alturaDelDomicilio = 0;

	do
	{
		printf(""
		"1) ingresar edad (%d)\n"
		"2) Ingresar altura (%d)\n"
		"3) Salir\n",edadIngresada, alturaDelDomicilio);
		if(utn_getNumber(&respuestaIngresada, "Por favor elija una opcion \n", "Error! no se pudo guardar la seleccion\n", 1, 3, 2)==0)
		{
			switch(respuestaIngresada)
			{
				case 1:
					utn_getNumber(&edadIngresada, "Por favor ingrese su edad ", "Error! en edad ingresada\n", 18, 90, 2);
				break;
				case 2:
					utn_getNumber(&alturaDelDomicilio, "Por favor ingrese su altura de domicilio ", "Error! en altura ingresada\n", 1, 17000, 2);
				break;
			}

		}
		else
		{
			printf("\nPor favor elija una de las 2 opciones!\n\n");
		}


	}while(respuestaIngresada!=3);

	printf("\nAdios!!!\n");

	return EXIT_SUCCESS;
}

