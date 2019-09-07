#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"
#include "matematica.h"

/** \brief Suma los valores ingresados
 * \param *pResultado apunta a la direccion de memoria donde se va a alojar el resultado de la operacion
 * \param *pMensajeError muestra un mensaje en caso de no poder realizarse la operacion
 * \param num1 es el primer numero a sumar
 * \param num2 es el segundo numero a sumar
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int sumaAyB(float *pResultado,char *pMensajeError, float num1,float num2)
{
	int retorno = EXIT_ERROR;
	double buffer;

	if(pResultado != NULL)
	{
		buffer=num1+num2;
		if(buffer < LONG_MAX && buffer > LONG_MIN)
		{
			*pResultado=(float)buffer;
			retorno=EXIT_SUCCESS;
		}
		else
		{
			printf("%s",pMensajeError);
		}
	}
	else if(pResultado == NULL)
	{
		printf("%s",pMensajeError);
	}

	return retorno;
}

/** \brief Resta los valores ingresados
 * \param *pResultado apunta a la direccion de memoria donde se va a alojar el resultado de la operacion
 * \param *pMensajeError muestra un mensaje en caso de no poder realizarse la operacion
 * \param num1 es el primer numero
 * \param num2 es el segundo numero a restar
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int restaAyB(float *pResultado,char *pMensajeError, float num1,float num2)
{
	int retorno = EXIT_ERROR;
	double buffer;

	if(pResultado != NULL)
	{
		buffer=num1-num2;
		if(buffer < LONG_MAX && buffer > LONG_MIN)
		{
			*pResultado=(float)buffer;
			retorno=EXIT_SUCCESS;
		}
		else
		{
			printf("%s",pMensajeError);
		}
	}
	else if(pResultado == NULL)
	{
		printf("%s",pMensajeError);
	}

	return retorno;
}

/** \brief Divide los valores ingresados
 * \param *pResultado apunta a la direccion de memoria donde se va a alojar el resultado de la operacion
 * \param *pMensajeError muestra un mensaje en caso de no poder realizarse la operacion
 * \param num1 es el primer numero que va a ser dividido
 * \param num2 es el segundo numero que va a dividir al anterior
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int divisionAyB(float *pResultado,char *pMensajeError, float num1,float num2)
{
	int retorno = EXIT_ERROR;
	double buffer;

	if(pResultado != NULL && num2 != 0)
	{
		buffer=num1/num2;
		if(buffer < LONG_MAX && buffer > LONG_MIN)
		{
			*pResultado=(float)buffer;
			retorno=EXIT_SUCCESS;
		}
		else
		{
			printf("%s",pMensajeError);
		}
	}
	else if(pResultado == NULL)
	{
		printf("%s",pMensajeError);
	}
	else if(num2 == 0)
	{
		printf("\nError, intenta dividir por 0");

	}

	return retorno;
}

/** \brief Multiplica los valores ingresados
 * \param *pResultado apunta a la direccion de memoria donde se va a alojar el resultado de la operacion
 * \param *pMensajeError muestra un mensaje en caso de no poder realizarse la operacion
 * \param num1 es el primer numero a multiplicar
 * \param num2 es el segundo numero a multiplicar
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int multiplicacionAyB(float *pResultado,char *pMensajeError, float num1,float num2)
{
	int retorno = EXIT_ERROR;
	double buffer;

	if(pResultado != NULL)
	{
		buffer=num1*num2;
		if(buffer < LONG_MAX && buffer > LONG_MIN)
		{
			*pResultado=(float)buffer;
			retorno=EXIT_SUCCESS;
		}
		else
		{
			printf("%s",pMensajeError);
		}
	}
	else if(pResultado == NULL)
	{
		printf("%s",pMensajeError);
	}

	return retorno;
}

/** \brief Calcular el factorial del numero ingresado
 * \param *pResultado apunta a la direccion de memoria donde se va a alojar el resultado de la operacion
 * \param *pMensajeError muestra un mensaje en caso de no poder realizarse la operacion
 * \param num es el numero a calcular el factorial
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int factorialAoB(float *pResultado,char *pMensajeError, float num)
{
	int retorno = EXIT_ERROR;
	double buffer=1;

	if(pResultado != NULL && num >=0)
	{
		if(num==0)
		{
			buffer=1;
		}
		else
		{
			while(num>0 && buffer < LONG_MAX && buffer > LONG_MIN)
			{
				buffer=num*buffer;
				num--;
			}
		}
	*pResultado=(float)buffer;
	retorno = EXIT_SUCCESS;
	}
	else if(pResultado == NULL)
	{
		printf("%s",pMensajeError);
	}
	else if(num < 0)
	{
		printf("\nEl numero es menor a 0");
	}

	return retorno;
}
