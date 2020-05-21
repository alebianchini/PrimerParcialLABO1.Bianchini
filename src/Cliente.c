/*
 * Cliente.c
 *
 *  Created on: 16 may. 2020
 *      Author: Alejo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "utn.h"

int initClientes(Cliente* array, int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
			array[i].prestamosActivos = 0;
			array[i].prestamosSaldados = 0;
			array[i].prestamosTotales = 0;
		}
	}
	return retorno;
}

int altaCliente(Cliente* array,int limite,int indice,int* id)
{
	int retorno=-1;
	Cliente bufferCliente;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nNombre del Cliente?\n","\nDato invalido\n",2) == 0 &&
		   utn_getNombre(bufferCliente.apellido, NOMBRE_LEN,"\nApellido del Cliente?\n","\nDato invalido\n",2) == 0 &&
		   utn_getDni(bufferCliente.cuil, CUIL_LEN,"\nC.U.I.L del Cliente?\n","\nDato invalido\n",2) == 0)
		{
			retorno=0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			bufferCliente.prestamosActivos = 0;
			bufferCliente.prestamosSaldados = 0;
			bufferCliente.prestamosTotales = 0;
			array[indice] = bufferCliente;
			(*id)++;
		}
	}
	return retorno;
}

int imprimirCliente(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID CLIENTE: %d - NOMBRE: %s - APELLIDO: %s - CUIL: %s - PRESTAMOS ACTIVOS: %d",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->cuil,pElemento->prestamosActivos);
	}
	return retorno;
}

int imprimirClienteSaldado(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID CLIENTE: %d - NOMBRE: %s - APELLIDO: %s - CUIL: %s - PRESTAMOS SALDADOS: %d",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->cuil,pElemento->prestamosSaldados);
	}
	return retorno;
}

int imprimirClienteMaxPrestamos(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID CLIENTE: %d - NOMBRE: %s - APELLIDO: %s - CUIL: %s - PRESTAMOS GENERADOS: %d",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->cuil,pElemento->prestamosTotales);
	}
	return retorno;
}

int imprimirClientes(Cliente* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		printf("\n****LISTA DE CLIENTES****\n");
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			imprimirCliente(&array[i]);
		}
	}
	return retorno;
}

int getIndiceVacio(Cliente* array,int limite)
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

int getIndiceLleno(Cliente* array,int limite)
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

int buscarIdCliente(Cliente* array,int limite,int valorBuscado)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int modificarCliente(Cliente* array,int limite,int indice)
{
	int retorno=-1;
	int seguir;
	int opcion;
	Cliente bufferCliente;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		do
		{
			if(!utn_getNumero(&opcion,"\n\n1.Modificar nombre"
									"\n2.Modificar apellido"
									"\n3.Modificar C.U.I.L\n",
									"\nError opcion invalida\n",1,3,3))
			{
				switch(opcion)
				{
				case 1:
					if(utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nNombre del cliente?\n","\nDato invalido\n",3) == 0)
					{
						retorno=0;
						strncpy(array[indice].nombre,bufferCliente.nombre,NOMBRE_LEN);
					}
					break;
				case 2:
					if(utn_getNombre(bufferCliente.apellido, NOMBRE_LEN,"\nApellido del cliente?\n","\nDato invalido\n",3) == 0)
					{
						retorno=0;
						strncpy(array[indice].apellido,bufferCliente.apellido,NOMBRE_LEN);
					}
					break;
				case 3:
					if(utn_getDni(bufferCliente.cuil, CUIL_LEN,"\nC.U.I.L del Cliente?\n","\nDato invalido\n",3) == 0)
					{
						retorno=0;
						strncpy(array[indice].cuil,bufferCliente.cuil,CUIL_LEN);
					}
					break;
				}
			}
			utn_getNumero(&seguir,"\nDesea realizar otra modificación sobre este cliente?\n '1': SI - '0': NO\n","\nNumero invalido\n",0, 1, 4);
		}while(seguir == 1);
	}
	return retorno;
}

int bajaCliente(Cliente* array,int limite,int indice)
{
	int retorno=-1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		array[indice].prestamosActivos = 0;
		array[indice].prestamosSaldados = 0;
		array[indice].prestamosTotales = 0;
		retorno=0;
	}
	return retorno;
}
