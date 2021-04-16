/*
 * BibliotecaTP1.c
 *
 *  Created on: 16 abr. 2021
 *      Author: npipliza
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @fn float sumar(float, float)
 * @brief suma numero1 y numero2
 *
 * @param numero1
 * @param numero2
 * @return suma
 */
float sumar(float numero1, float numero2)
{
	float suma = 0;

	suma = numero1 + numero2;
	return suma;
}

/**
 * @fn float restar(float, float)
 * @brief resta numero1 y numero2
 *
 * @param numero1
 * @param numero2
 * @return resta
 */
float restar(float numero1, float numero2)
{
	float resta = 0;

	resta = (float)numero1 - numero2;
	return resta;
}

/**
 * @fn float dividir(float, float)
 * @brief divide numero1 por numero2
 *
 * @param numero1
 * @param numero2
 * @return resultado
 */
float dividir(float numero1, float numero2)
{
	float resultado;

	if(numero2 != 0)
	{
		resultado = (float)numero1 / numero2;
	}
	return resultado;
}

/**
 * @fn float multiplicar(float, float)
 * @brief multiplica numero1 por numero2
 *
 * @param numero1
 * @param numero2
 * @return multiplicacion
 */
float multiplicar(float numero1, float numero2)
{
	float multiplicacion;

	multiplicacion = numero1 * numero2;
	return multiplicacion;
}

/**
 * @fn int factorial1(float)
 * @brief hace el factorial de numero1
 *
 * @param numero1
 * @return resultado
 */
int factorial1(float numero1)
{
	int resultado = 1;
	int I;

	if(numero1 == 0)
	{
		resultado = 1;
	}
	else
	{
		for(I = 1; I <= numero1; I ++)
		{
			resultado = resultado * I;
		}
	}

	return resultado;
}

/**
 * @fn int factorial2(float)
 * @brief hace el factorial de numero2
 *
 * @param numero2
 * @return resultado
 */
int factorial2(float numero2)
{
	int resultado = 1;
	int I;

	if(numero2 == 0)
	{
		resultado = 1;
	}
	else
	{
		for(I = 1; I <= numero2; I ++)
		{

			resultado = resultado * I;
		}
	}

	return resultado;
}
