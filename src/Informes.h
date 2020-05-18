/*
 * Informes.h
 *
 *  Created on: 17 may. 2020
 *      Author: Alejo
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Cliente.h"
#include "Prestamo.h"

/**
 * \brief Busca en el array de Clientes, el cliente con mayor cantidad de prestamos activos
 * \param array Array de clientes a ser recorrido
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int clienteConMasPrestamosActivos(Cliente* array,int limite);
/**
 * \brief Busca en el array de Clientes, el cliente con mayor cantidad de prestamos saldados
 * \param array Array de clientes a ser recorrido
 * \param limite Limite del array
 * \return Retorna 0 (EXITO) o -1 (ERROR)
 *
 */
int clienteConMasPrestamosSaldados(Cliente* array,int limite);
/**
 * \brief Cuenta la cantidad de importes mayores a $1000 en el array de Prestamos
 * \param array Array de prestamos a ser recorrido
 * \param limite Limite del array
 * \return Retorna la cantidad encontrada o -1 (ERROR)
 *
 */
int informePrestamosA(Prestamo* array,int limite);
/**
 * \brief Cuenta la cantidad de importes mayores al valor ingresado por el usuario, en el array de Prestamos
 * \param array Array de prestamos a ser recorrido
 * \param limite Limite del array
 * \param valor Es el valor ingresado por el usuario
 * \return la cantidad encontrada o -1 (ERROR)
 *
 */
int informePrestamosB(Prestamo* array,int limite,int valor);

#endif /* INFORMES_H_ */
