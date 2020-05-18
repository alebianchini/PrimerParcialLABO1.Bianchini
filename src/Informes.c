/*
 * Informes.c
 *
 *  Created on: 17 may. 2020
 *      Author: Alejo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Informes.h"


int clienteConMasPrestamosActivos(Cliente* array,int limite)
{
	int retorno=-1;
	int i;
	int numMax=0;
	int indiceMax;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].prestamosActivos > numMax)
			{
				numMax = array[i].prestamosActivos;
				indiceMax = i;
			}
		}
		retorno = indiceMax;
	}
	return retorno;
}

int clienteConMasPrestamosSaldados(Cliente* array,int limite)
{
	int retorno=-1;
	int i;
	int numMax=0;
	int indiceMax;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].prestamosSaldados > numMax)
			{
				numMax = array[i].prestamosSaldados;
				indiceMax = i;
			}
		}
		retorno = indiceMax;
	}
	return retorno;
}

int informePrestamosA(Prestamo* array,int limite)
{
	int retorno=-1;
	int i;
	int contador=0;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].importe > 1000)
			{
				contador++;
			}
		}
		retorno = contador;
	}
	return retorno;
}

int informePrestamosB(Prestamo* array,int limite,int valor)
{
	int retorno=-1;
	int i;
	int contador=0;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].importe == valor)
			{
				contador++;
			}
		}
		retorno = contador;
	}
	return retorno;
}
