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

int clienteConMasPrestamos(Cliente* array,int limite)
{
	int retorno=-1;
	int i;
	int numMax=0;
	int indiceMax;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].prestamosTotales > numMax)
			{
				numMax = array[i].prestamosTotales;
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

int informePrestamosA2(Prestamo* array,int limite,int valor)
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

void informePrestamosB(Prestamo* array,int limite)
{
	int cont=1;
	int i;
	int flag=1;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].cuotas == 12 && strncmp(array[i].estado,"Saldado",8) == 0)
			{
				if(flag)
				{
					printf("\nLos prestamos de 12 cuotas saldados son:");
					flag=0;
				}
				imprimirPrestamo(array);
				cont = 0;
			}
		}
		if(cont)
		{
			printf("\nNo hay prestamos de 12 cuotas saldados");
		}
	}
}

int informePrestamosC(Prestamo* array,int limite,int valor)
{
	int retorno=-1;
	int i;
	int contador=0;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].cuotas == valor && strncmp(array[i].estado,"Activo",8) == 0)
			{
				contador++;
			}
		}
		retorno = contador;
	}
	return retorno;
}
