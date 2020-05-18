/*
 * Prestamo.h
 *
 *  Created on: 16 may. 2020
 *      Author: Alejo
 */

#ifndef PRESTAMO_H_
#define PRESTAMO_H_

#define CUIL_LEN 12
typedef struct{
	float importe;
	int cuotas;
	int idPrestamo;
	int idCliente;
	char estado[8];
	char cuilCliente[CUIL_LEN];
	int isEmpty;
}Prestamo;

/**
 * \brief Inicializa el array
 * \param array Array de prestamos a ser inicializado
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int initPrestamos(Prestamo* array, int limite);
/**
 * \brief Da de alta un prestamo en una posicion del array
 * \param arrayP Array de prestamos a ser actualizado
 * \param arrayC Array de clientes
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \param idClientes cantidad de IDs de clientes existentes
 * \param id Identificador a ser asignado al prestamo
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int altaPrestamo(Prestamo* arrayP,int limite,int indice,int idClientes,int* id);
/**
 * \brief Buscar la primer posicion vacia del array
 * \param array Array de prestamos
 * \param limite Limite del array
 * \return Retorna el indice de la posicion vacia o -1 (ERROR)
 *
 */
int getIndiceVacioP(Prestamo* array,int limite);
/**
 * \brief Imprime los datos de un prestamo activo
 * \param pElemento Puntero al elemento que se busca imprimir
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirPrestamoActivo(Prestamo* pElemento);
/**
 * \brief Imprime los datos de un prestamo
 * \param pElemento Puntero al elemento que se busca imprimir
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirPrestamo(Prestamo* pElemento);
/**
 * \brief Imprime el array de prestamos activos
 * \param array Array de prestamos a ser mostrado
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirPrestamosActivos(Prestamo* array,int limite);
/**
 * \brief Imprime el array de prestamos saldados
 * \param array Array de prestamos a ser mostrado
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int imprimirPrestamosSaldados(Prestamo* array,int limite);
/**
 * \brief Imprime los prestamos de un cliente especifico
 * \param array Array de prestamos a ser mostrado
 * \param limite Limite del array
 * \param idCliente ID del cliente dueño de los prestamos
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
void imprimirPrestamosCliente(Prestamo* array,int limite,int idCliente);
/**
 * \brief Da de baja los prestamos de un cliente especifico
 * \param array Array de prestamos a ser actualizado
 * \param limite Limite del array
 * \param idCliente ID del cliente dueño de los prestamos
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int bajaPrestamosCliente(Prestamo* array,int limite,int idCliente);
/**
 * \brief Cambia el estado de un prestamo a "Saldado"
 * \param arrayC Array de prestamos a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int saldarPrestamo(Prestamo* array,int limite,int indice);
/**
 * \brief Cambia el estado de un prestamo a "Activo"
 * \param arrayC Array de prestamos a ser actualizado
 * \param limite Limite del array
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int reanudarPrestamo(Prestamo* array,int limite,int indice);
/**
 * \brief Verifica que haya al menos 1 prestamo saldado en el array
 * \param array Array de prestamos a ser recorrido
 * \param limite Limite del array
 * \return Retorna 0 si se encuentra 1 saldado o -1 si no se encuentra
 *
 */
int buscaPrestamoSaldado(Prestamo* array,int limite);
/**
 * \brief Verifica que haya al menos 1 prestamo activo en el array
 * \param array Array de prestamos a ser recorrido
 * \param limite Limite del array
 * \return Retorna 0 si se encuentra 1 activo o -1 si no se encuentra
 *
 */
int buscaPrestamoActivo(Prestamo* array,int limite);
/**
 * \brief Busca un ID en un array y devuelve la posicion en que se encuentra
 * \param array Array de Prestamos a ser recorrido
 * \param limite tamaño del array
 * \param valorBuscado ID a ser actualizado
 * \return Return (-1) si no encuentra el valor buscado o Error - (i) si encuentra el valor buscado.
 *
 */
int buscarIdPrestamo(Prestamo* array,int limite,int valorBuscado);

#endif /* PRESTAMO_H_ */
