/*
 ============================================================================
 Name        : ParcialLabo1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Cliente.h"
#include "Prestamo.h"
#include "Informes.h"

#define CANTIDAD_CLIENTES 51
#define CANTIDAD_PRESTAMOS 51
#define CUIL_LEN 12

int main(void) {
setbuf(stdout, NULL);

Cliente arrayClientes[CANTIDAD_CLIENTES];
Prestamo arrayPrestamos[CANTIDAD_PRESTAMOS];
int idClientes=1;
int idPrestamos=1;
int opcion;
int auxiliarIndiceC;
int auxiliarIndiceP;
int auxiliarId;
int pregunta;
float valorInforme;
int valorInformeC;

initClientes(arrayClientes,CANTIDAD_CLIENTES);
initPrestamos(arrayPrestamos,CANTIDAD_PRESTAMOS);
do
{
	if(getIndiceLleno(arrayClientes, CANTIDAD_CLIENTES) != 0)
	{
		printf("Por favor, cargue un primer cliente");
		auxiliarIndiceC = getIndiceVacio(arrayClientes,CANTIDAD_CLIENTES);
		if(auxiliarIndiceC >= 0)
		{
			if(altaCliente(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndiceC,&idClientes) == 0)
			{
				printf("\nCarga realizada con exito\n");
			}
		}
	}
	else if(!utn_getNumero( &opcion,"\n\n1.Dar de alta un cliente"
						"\n2.Modificar un cliente"
						"\n3.Dar de baja un cliente"
						"\n4.Dar de alta un prestamo"
						"\n5.Saldar prestamo"
						"\n6.Reanudar prestamo"
						"\n7.Imprimir clientes"
						"\n8.Imprimir prestamos activos"
						"\n9.Mostrar el cliente con mas prestamos activos y el cliente con mas saldados"
						"\n10.Mostrar los informes sobre prestamos"
						"\n11.Salir\n\n",
						"\nError opcion invalida",1,11,2))
	{
		switch(opcion)
		{
		case 1:
			auxiliarIndiceC = getIndiceVacio(arrayClientes,CANTIDAD_CLIENTES);
			if(auxiliarIndiceC >= 0)
			{
				if(altaCliente(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndiceC,&idClientes) == 0)
				{
					printf("\nCarga realizada con exito\n");
				}
			}
			else{
				printf("\nNO HAY MAS LUGAR\n");
			}
			break;
		case 2:
			imprimirClientes(arrayClientes,CANTIDAD_CLIENTES);
			if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a modificar: ","\nID invalido",1,idClientes-1,2) == 0)
			{
				auxiliarIndiceC = buscarIdCliente(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
				if( auxiliarIndiceC >= 0 && modificarCliente(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndiceC) == 0)
				{
					printf("\nModificacion realizada con exito\n");
				}
			}
			break;
		case 3:
			imprimirClientes(arrayClientes,CANTIDAD_CLIENTES);
			if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a ser eliminado: ","\nID invalido",0,idClientes-1,2) == 0)
			{
				auxiliarIndiceC = buscarIdCliente(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
				imprimirPrestamosCliente(arrayPrestamos,CANTIDAD_PRESTAMOS,auxiliarId);
				if(utn_getNumero(&pregunta,"\n\nDesea confirmar la baja del cliente y sus prestamos?\n '1': SI - '0': NO\n","\nNumero invalido\n",0, 1, 3) == 0  && pregunta == 1)
				{
					if(auxiliarIndiceC >= 0 && bajaCliente(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndiceC) == 0 &&
						bajaPrestamosCliente(arrayPrestamos,CANTIDAD_PRESTAMOS,auxiliarId) == 0)
					{
					printf("\nBaja realizada con exito\n");
					}
				}
				else{
					printf("\nBaja cancelada\n");
				}
			}
			break;
		case 4:
			imprimirClientes(arrayClientes,CANTIDAD_CLIENTES);
			auxiliarIndiceP = getIndiceVacioP(arrayPrestamos,CANTIDAD_PRESTAMOS);
			if(auxiliarIndiceP >= 0)
			{
				if(altaPrestamo(arrayPrestamos,CANTIDAD_PRESTAMOS,auxiliarIndiceP,idClientes,&idPrestamos) == 0)
				{
					auxiliarIndiceC = buscarIdCliente(arrayClientes,CANTIDAD_CLIENTES,arrayPrestamos[auxiliarIndiceP].idCliente);
					if(auxiliarIndiceC >= 0){
						arrayClientes[auxiliarIndiceC].prestamosActivos++;
						arrayClientes[auxiliarIndiceC].prestamosTotales++;
						strncpy(arrayPrestamos[auxiliarIndiceP].cuilCliente,arrayClientes[auxiliarIndiceC].cuil,CUIL_LEN);
						printf("\nCarga realizada con exito\nID del prestamo generado: %d\n",idPrestamos-1);
					}
				}
			}
			else{
				printf("\nNO HAY MAS LUGAR\n");
			}
			break;
		case 5:
			if(buscaPrestamoActivo(arrayPrestamos,CANTIDAD_PRESTAMOS) == 0)
			{
				imprimirPrestamosActivos(arrayPrestamos,CANTIDAD_PRESTAMOS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del prestamo a Saldar: ","\nID invalido",0,idPrestamos-1,2) == 0)
				{
					auxiliarIndiceP = buscarIdPrestamo(arrayPrestamos,CANTIDAD_PRESTAMOS,auxiliarId);
					auxiliarIndiceC = buscarIdCliente(arrayClientes,CANTIDAD_CLIENTES,arrayPrestamos[auxiliarIndiceP].idCliente);
					printf("\n****Cliente dueño del prestamo:");
					imprimirCliente(&arrayClientes[auxiliarIndiceC]);
					if(utn_getNumero(&pregunta,"\n\nDesea confirmar el cambio de estado del prestamo?\n '1': SI - '0': NO\n","\nNumero invalido\n",0, 1, 3) == 0  && pregunta == 1)
					{
						if(auxiliarIndiceP >= 0 && saldarPrestamo(arrayPrestamos,CANTIDAD_PRESTAMOS,auxiliarIndiceP) == 0)
						{
							arrayClientes[auxiliarIndiceC].prestamosActivos--;
							arrayClientes[auxiliarIndiceC].prestamosSaldados++;
							printf("\nCambio realizado con exito\n");
						}
					}
					else{
						printf("\nCambio cancelado\n");
					}
				}
			}
			else{
				printf("\n****NO HAY PRESTAMOS ACTIVOS****\n");
			}
			break;
		case 6:
			if(buscaPrestamoSaldado(arrayPrestamos,CANTIDAD_PRESTAMOS) == 0)
			{
				imprimirPrestamosSaldados(arrayPrestamos,CANTIDAD_PRESTAMOS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del prestamo a reanudar: ","\nID invalido",0,idPrestamos-1,2) == 0)
				{
					auxiliarIndiceP = buscarIdPrestamo(arrayPrestamos,CANTIDAD_PRESTAMOS,auxiliarId);
					auxiliarIndiceC = buscarIdCliente(arrayClientes,CANTIDAD_CLIENTES,arrayPrestamos[auxiliarIndiceP].idCliente);
					printf("\n****Cliente dueño del prestamo:");
					imprimirCliente(&arrayClientes[auxiliarIndiceC]);
					if(utn_getNumero(&pregunta,"\n\nDesea confirmar el cambio de estado del prestamo?\n '1': SI - '0': NO\n","\nNumero invalido\n",0, 1, 3) == 0  && pregunta == 1)
					{
						if(auxiliarIndiceP >= 0 && reanudarPrestamo(arrayPrestamos,CANTIDAD_PRESTAMOS,auxiliarIndiceP) == 0)
						{
							arrayClientes[auxiliarIndiceC].prestamosActivos++;
							arrayClientes[auxiliarIndiceC].prestamosSaldados--;
							printf("\nCambio realizado con exito\n");
						}
					}
					else{
						printf("\nCambio cancelado\n");
					}
				}
			}
			else{
				printf("\n****NO HAY PRESTAMOS SALDADOS****\n");
			}
			break;
		case 7:
			imprimirClientes(arrayClientes,CANTIDAD_CLIENTES);
			break;
		case 8:
			if(buscaPrestamoActivo(arrayPrestamos,CANTIDAD_PRESTAMOS) == 0)
			{
				imprimirPrestamosActivos(arrayPrestamos,CANTIDAD_PRESTAMOS);
			}
			else{
				printf("\n****NO HAY PRESTAMOS ACTIVOS****\n");
			}
			break;
		case 9:
			if(buscaPrestamoActivo(arrayPrestamos,CANTIDAD_PRESTAMOS) == 0)
			{
				auxiliarIndiceC = clienteConMasPrestamosActivos(arrayClientes,CANTIDAD_CLIENTES);
				printf("\nEl cliente con mas prestamos activos es:");
				imprimirCliente(&arrayClientes[auxiliarIndiceC]);
			}
			else{
				printf("\n****NO HAY PRESTAMOS ACTIVOS****\n");
			}
			if(buscaPrestamoSaldado(arrayPrestamos,CANTIDAD_PRESTAMOS) == 0)
			{
				auxiliarIndiceC = clienteConMasPrestamosSaldados(arrayClientes,CANTIDAD_CLIENTES);
				printf("\nEl cliente con mas prestamos saldados es:");
				imprimirClienteSaldado(&arrayClientes[auxiliarIndiceC]);
			}
			else{
				printf("\n****NO HAY PRESTAMOS SALDADOS****\n");
			}
			if(buscaPrestamoGenerado(arrayPrestamos,CANTIDAD_PRESTAMOS) == 0)
			{
				auxiliarIndiceC = clienteConMasPrestamos(arrayClientes,CANTIDAD_CLIENTES);
				printf("\nEl cliente con mas prestamos generados es:");
				imprimirClienteMaxPrestamos(&arrayClientes[auxiliarIndiceC]);
			}
			else{
				printf("\n****NO HAY PRESTAMOS GENERADOS****\n");
			}
			break;
		case 10:
			//nota para el profesor: Aquí en este punto sinceramente no entendi si habia que mostrar la cantidad de importes mayores a 1000
			// o la cantidad de importes iguales a un valor ingresado por el usuario(que sea mayor a 1000), asi que por las dudas hice las dos cosas
			// además tampoco especifica que solo sean prestamos activos, por ende tambien tuve en cuenta los saldados.
			if(buscaPrestamoGenerado(arrayPrestamos,CANTIDAD_PRESTAMOS) == 0)
			{
				if(utn_getNumeroFlotante(&valorInforme,"\nContar los prestamos con un importe igual a que valor?","\nValor invalido",1000,500000,3) == 0 &&
				   utn_getNumero(&valorInformeC,"\nContar los prestamos activos con una cantidad de cuotas igual a que valor?","\nValor invalido",1,12,3) == 0)
				{
					valorInforme = informePrestamosA2(arrayPrestamos,CANTIDAD_PRESTAMOS,valorInforme);
					printf("\nLa cantidad de prestamos igual al importe ingresado es: %2.f",valorInforme);
					valorInforme = informePrestamosA(arrayPrestamos,CANTIDAD_PRESTAMOS);
					printf("\nLa cantidad de prestamos con un importe mayor a $1000 es: %2.f",valorInforme);
					informePrestamosB(arrayPrestamos,CANTIDAD_PRESTAMOS);
					valorInformeC = informePrestamosC(arrayPrestamos,CANTIDAD_PRESTAMOS,valorInformeC);
					printf("\nLa cantidad de prestamos activos con esa cantidad de cuotas es: %d",valorInformeC);
				}
			}
			else{
				printf("\n****NO HAY PRESTAMOS GENERADOS****\n");
			}
		}
	}
}while(opcion != 11);

return EXIT_SUCCESS;
}
