/*
 * Cliente.h
 *
 *  Created on: 16 may. 2020
 *      Author: Alejo
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define NOMBRE_LEN 51
#define CUIL_LEN 12

typedef struct{
	char nombre[NOMBRE_LEN];
	char apellido[NOMBRE_LEN];
	char cuil[CUIL_LEN];
	int id;
	int prestamosActivos;
	int prestamosSaldados;
	int prestamosTotales;
	int isEmpty;
}Cliente;

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser inicializado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int initClientes(Cliente* array, int limite);
/**
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int altaCliente(Cliente* array,int limite,int indice,int* id);
/**
 * \brief Imprime los datos de un cliente mostrando los prestamos activos
 * \param pElemento Puntero al elemento que se busca imprimir
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirCliente(Cliente* pElemento);
/**
 * \brief Imprime los datos de un cliente mostrando los prestamos saldados
 * \param pElemento Puntero al elemento que se busca imprimir
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirClienteSaldado(Cliente* pElemento);
/**
 * \brief Imprime los datos de un cliente mostrando los prestamos generados
 * \param pElemento Puntero al elemento que se busca imprimir
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirClienteMaxPrestamos(Cliente* pElemento);
/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser mostrado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirClientes(Cliente* array,int limite);
/**
 * \brief Buscar la primer posicion vacia del array
 * \param array Array de clientes
 * \param limite Limite del array
 * \return Retorna el indice de la posicion vacia o -1 (ERROR)
 *
 */
int getIndiceVacio(Cliente* array,int limite);
/**
 * \brief Corrobora que haya al menos UN indice ocupado en el array
 * \param array Array de clientes
 * \param limite Limite del array
 * \return Retorna 0 si hay algun indice ocupado en el array, en caso contrario -1.
 *
 */
int getIndiceLleno(Cliente* array,int limite);
/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int modificarCliente(Cliente* array,int limite,int indice);
/**
 * \brief Busca un ID en un array y devuelve la posicion en que se encuentra
 * \param array cliente Array de cliente
 * \param limite tamaño del array
 * \param valorBuscado ID a ser actualizado
 * \return Return (-1) si no encuentra el valor buscado o Error - (i) si encuentra el valor buscado.
 *
 */
int buscarIdCliente(Cliente array[],int limite,int valorBuscado);
/**
 * \brief Da de baja un cliente y sus prestamos en una posicion del array
 * \param arrayC Array de clientes a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser dada de baja
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int bajaCliente(Cliente* arrayC,int limite,int indice);



#endif /* CLIENTE_H_ */
