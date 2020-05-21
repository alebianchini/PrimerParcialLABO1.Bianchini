/*
 * Prestamo.c
 *
 *  Created on: 16 may. 2020
 *      Author: Alejo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Prestamo.h"

int initPrestamos(Prestamo* array, int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return retorno;
}

int altaPrestamo(Prestamo* arrayP,int limite,int indice,int idClientes,int* id)
{
	int retorno=-1;
	Prestamo bufferPrestamo;
	if(arrayP != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL && idClientes >=1)
	{
		if(utn_getNumero(&bufferPrestamo.idCliente,"\nIngrese el ID del Cliente: ","\nID invalido\n",1, idClientes-1, 2) == 0 &&
		   utn_getNumeroFlotante(&bufferPrestamo.importe,"\nIngrese el importe del Prestamo: ","\nimporte invalido\n",1, 500000, 2) == 0 &&
		   utn_getNumero(&bufferPrestamo.cuotas,"\nIngrese la cantidad de cuotas: ","\nnumero invalido\n",0, 12, 2) == 0)
		{
			retorno=0;
			bufferPrestamo.idPrestamo = *id;
			bufferPrestamo.isEmpty = 0;
			strncpy(bufferPrestamo.estado,"Activo",8);
			arrayP[indice] = bufferPrestamo;
			(*id)++;
		}
	}
	return retorno;
}

int getIndiceVacioP(Prestamo* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int imprimirPrestamoActivo(Prestamo* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID PRESTAMO: %d - IMPORTE: $%2.f - CUOTAS: %d - ID DEL CLIENTE: %d - CUIL DEL CLIENTE: %s",pElemento->idPrestamo,pElemento->importe,pElemento->cuotas,pElemento->idCliente,pElemento->cuilCliente);
	}
	return retorno;
}

int imprimirPrestamo(Prestamo* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID PRESTAMO: %d - IMPORTE: $%2.f - CUOTAS: %d - ID DEL CLIENTE: %d - ESTADO: %s",pElemento->idPrestamo,pElemento->importe,pElemento->cuotas,pElemento->idCliente,pElemento->estado);
	}
	return retorno;
}

int imprimirPrestamosActivos(Prestamo* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		printf("\n****LISTA DE PRESTAMOS ACTIVOS****\n");
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(strncmp(array[i].estado,"Activo",8) == 0)
			{
				imprimirPrestamoActivo(&array[i]);
			}
		}
	}
	return retorno;
}

int imprimirPrestamosSaldados(Prestamo* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		printf("\n****LISTA DE PRESTAMOS SALDADOS****\n");
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(strncmp(array[i].estado,"Saldado",8) == 0)
			{
				imprimirPrestamoActivo(&array[i]);
			}
		}
	}
	return retorno;
}

void imprimirPrestamosCliente(Prestamo* array,int limite,int idCliente)
{
	int i;
	if(array != NULL && limite > 0 && idCliente >=1)
	{
		printf("\nPRESTAMOS DEL CLIENTE SELECCIONADO:");
		for(i=0;i<limite;i++)
		{
			if(array[i].idCliente == idCliente && array[i].isEmpty == 0)
			{
				imprimirPrestamo(&array[i]);
			}
		}
	}
}

int bajaPrestamosCliente(Prestamo* array,int limite,int idCliente)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0 && idCliente >=1)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].idCliente == idCliente)
			{
			array[i].isEmpty = 1;
			strncpy(array[i].estado,"Anulado",8);
			}
		}
	}
	return retorno;
}

int saldarPrestamo(Prestamo* array,int limite,int indice)
{
	int retorno=-1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		strncpy(array[indice].estado,"Saldado",8);
		retorno=0;
	}
	return retorno;
}

int reanudarPrestamo(Prestamo* array,int limite,int indice)
{
	int retorno=-1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		strncpy(array[indice].estado,"Activo",8);
		retorno=0;
	}
	return retorno;
}

int buscaPrestamoSaldado(Prestamo* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(strncmp(array[i].estado,"Saldado",8) == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int buscaPrestamoActivo(Prestamo* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(strncmp(array[i].estado,"Activo",8) == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int buscaPrestamoGenerado(Prestamo* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int buscarIdPrestamo(Prestamo* array,int limite,int valorBuscado)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].idPrestamo == valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
