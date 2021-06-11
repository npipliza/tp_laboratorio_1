/*
 * parser.h
 *
 *  Created on: 6 jun. 2021
 *      Author: npipliza
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna [1] si salio OK [0] error
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief  Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int Retorna [1] si salio OK [0] error
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
